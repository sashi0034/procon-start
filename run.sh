#! /bin/bash
file=""

if [ $# -eq 1 ]; then
    file=$1
elif [ $# = 0 ]; then
    source ./work_on.txt
fi

g++ -o $file $file.cpp -Winit-self -Wfloat-equal -Wno-sign-compare -Wshadow
./$file

