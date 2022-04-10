@echo off
set file=%1
@echo on

copy /-Y template.cpp %file%.cpp
echo file=%file%> work_on.txt
