#!/bin/bash
if [[ -f a.out ]];then
    rm a.out    
fi

bear -- g++ *.cpp -g

if [[ $? -eq 0 ]];then
    ./a.out
fi



