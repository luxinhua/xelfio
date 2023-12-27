#!/bin/bash
if [[ -f a.out ]];then
    rm a.out    
fi

bear -- g++ *.cpp -g

gcc test.c -g -o test
objdump -D test > test.dump 

if [[ $? -eq 0 ]];then
    ./a.out
fi



