#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

class Stack{
public:
    Stack(uint32_t base, uint32_t size): m_base(base), m_size(size) {}
    ~Stack() = default;

    uint32_t m_base;
    uint32_t m_size;
};



#endif