#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

class Stack{
    void push(uint32_t data);
    void pop();

    uint32_t base;
    uint32_t size;
};



#endif