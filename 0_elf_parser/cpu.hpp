#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"
#include "memory.hpp"

class Core{
public:
    Core(Memory * memory, Stack stack, uint32_t elf_entry): m_mem{memory}, m_stack{stack}, m_pc{elf_entry}{}
    ~Core() = default;

    void fetch();
    void decode();
    void execute();
    void writeBackMem();

    uint32_t m_pc;
    core_registers m_regs;
    Memory * m_mem;
    Stack  m_stack;
};

#endif