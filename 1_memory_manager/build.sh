g++ *.cpp  -g

if [[ $? -eq 0 ]];then
./a.out 2>&1 | tee log
fi
