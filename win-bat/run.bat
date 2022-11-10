@echo off
rem [usage example]
rem $ ./run 238 a

set file=abc%1_%2

if "%file%" == "abc_" (
    for /f "tokens=1,* delims==" %%a in (work_on.txt) do (
        set %%a=%%b
    )
) else (
    echo file=%file%> work_on.txt
)

@echo on

g++ -o %file%.exe %file%.cpp -Winit-self -Wfloat-equal -Wno-sign-compare -Wshadow
%file%.exe

