@echo off
set file=abc%1_%2
@echo on

copy /-Y template.cpp %file%.cpp
echo file=%file%> work_on.txt
