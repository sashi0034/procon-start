
file=""

if [ $# -eq 1 ]; then
    file=$1
elif [ $# -eq 2 ]; then
    file=abc$1_$2
fi

cp template.cpp $file.cpp
echo file=$file > work_on.txt
