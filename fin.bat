@echo off
set file=abc%1_%2

if "%file%" == "abc_" (
    for /f "tokens=1,* delims==" %%a in (work_on.txt) do (
        set %%a=%%b
    )
)
@echo on

move /-Y %file%.cpp .\done

py ./claer.py


