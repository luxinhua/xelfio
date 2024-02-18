#!/bin/bash
if [[ -f a.out ]];then
    rm a.out
fi
if [[ -f ./demo/helloworld.dump ]];then
    rm ./demo/helloworld.dump
fi
if [[ -f ./demo/helloworld.out ]];then
    rm ./demo/helloworld.out
fi

bear -- g++ *.cpp -g

cd demo
#riscv64-unknown-elf-gcc must use newlib clib , can not use riscv64-unknown-linux-gnu-gcc
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 helloworld.c lib.c -o helloworld.out
riscv64-unknown-elf-objdump -D helloworld.out > helloworld.dump
cd ..

./a.out



