file=""

if [ $# -eq 1 ]; then
    file=$1
elif [ $# -eq 0 ]; then
    source ./work_on.txt
fi

mv $file.cpp ./done

python3 ./clear.py
