#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"
#include "memory.hpp"

class Core{
public:
    Core(Memory memory, Stack stack): m_mem{memory}, m_stack{stack}{}
    ~Core() = default;

    void fetch();
    void decode();
    void execute();
    void writeBackMem();

    core_registers m_regs;
    Memory m_mem;
    Stack  m_stack;
};

#endif