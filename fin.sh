file=""

if [ $# -eq 1 ]; then
    file=$1
elif [ $# -eq 0 ]; then
    source ./work_on.txt
fi

mv $file.cpp ./done
rm $file

#python3 ./clean.py