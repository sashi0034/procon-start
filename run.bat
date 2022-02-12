@echo off
    rem [usage example]
    rem $ ./run 238 a
@echo on

set file=abc%1_%2
g++ -o %file%.exe %file%.cpp
%file%.exe

