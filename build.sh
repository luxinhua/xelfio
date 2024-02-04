#!/bin/bash
if [[ -f a.out ]];then
    rm a.out
    rm test
fi

bear -- g++ *.cpp -g

# gcc test.c -g -o test
# objdump -D test > test.dump

riscv64-unknown-linux-gnu-gcc -march=rv64i -mabi=lp64 test.c -g -o test
riscv64-unknown-linux-gnu-objdump -D test > test.dump

if [[ $? -eq 0 ]];then
    ./a.out
fi



