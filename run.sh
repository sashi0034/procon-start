
if [ $# -eq 1 ]; then
    file=$1
elif [ $# -eq 0 ]; then
    source ./work_on.txt
fi

g++ -o $file.exe $file.cpp -Winit-self -Wfloat-equal -Wno-sign-compare -Wshadow
./$file.exe

