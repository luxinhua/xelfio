#!/bin/bash
if [[ -d a.out ]];then
    rm a.out    
fi

g++ *.cpp

if [[ $? -eq 0 ]];then
    ./a.out
fi



