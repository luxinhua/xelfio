#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"
#include "memory.hpp"
#include "isa_parser.hpp"

class Core{
public:
    Core(Memory * memory, Stack stack, uint32_t elf_entry): m_mem{memory}, m_stack{stack}, m_pc{elf_entry}{
        m_fetch_bubble = true;
        m_fetch_stall = true;
        m_decode_bubble = true;
        m_decode_stall = true;
        m_execute_bubble = true;
        m_execute_stall = true;
        m_writeBackMem_bubble = true;
        m_writeBackMem_stall = true;


    }
    ~Core() = default;

    void fetch();
    void decode();
    void execute();
    void writeBackMem();

    uint32_t m_pc;
    core_registers m_regs;
    Memory * m_mem;
    Stack  m_stack;

    bool m_fetch_bubble;
    bool m_fetch_stall;
    bool m_decode_bubble;
    bool m_decode_stall;
    bool m_execute_bubble;
    bool m_execute_stall;
    bool m_writeBackMem_bubble;
    bool m_writeBackMem_stall;

    Instruction m_inst;
};

#endif