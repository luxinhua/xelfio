#!/bin/bash
if [[ -d a.out ]];then
    rm a.out    
fi

g++ *.cpp -g

if [[ $? -eq 0 ]];then
    ./a.out
fi



