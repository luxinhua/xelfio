#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"
#include "memory.hpp"
#include "instruction.hpp"

class Core{
public:
    Core(Memory * memory, Stack stack, uint32_t elf_entry): m_mem{memory}, m_stack{stack}, m_pc{elf_entry}{
        m_fetch_bubble = true;
        m_fetch_stall = true;
        m_execute_bubble = true;
        m_execute_stall = true;

        m_core_registers[sp].first = m_stack.m_base;
    }
    ~Core() = default;

    void fetch();
    void execute();

    void print_core_registers();

private:
    void execute_auipc();
    void execute_addi();
    void execute_slti();
    void execute_sltu();
    void execute_xori();
    void execute_ori();
    void execute_andi();
    void execute_slli();
    void execute_srai();

    void parser_branch_inst();
    void parser_load_inst();
    void parser_store_inst();
    void parser_imm_inst();
    void parser_reg_inst();
    void parser_fence_inst();
    void parser_system_inst();
    void parser_imm32_inst();
    void parser_op32_inst();
    void parser_auipc_inst();
    void parser_jal_inst();
    void parser_jalr_inst();
    void parser_lut_inst();

public:

    uint32_t m_pc;
    Memory * m_mem;
    Stack  m_stack;

    bool m_fetch_bubble;
    bool m_fetch_stall;
    bool m_execute_bubble;
    bool m_execute_stall;

    Instruction m_inst;

    enum {
        zero = 0,
        ra      ,
        sp      ,
        gp      ,
        tp      ,
        t0      ,
        t1      ,
        t2      ,
        s0      ,
        s1      ,
        a0      ,
        a1      ,
        a2      ,
        a3      ,
        a4      ,
        a5      ,
        a6      ,
        a7      ,
        s2      ,
        s3      ,
        s4      ,
        s5      ,
        s6      ,
        s7      ,
        s8      ,
        s9      ,
        s10     ,
        s11     ,
        t3      ,
        t4      ,
        t5      ,
        t6      ,
    };

    std::map<uint32_t,  std::pair<uint32_t, std::string>> m_core_registers{
        /**std::pair < value, alias_name > */
        std::make_pair( zero , std::make_pair( 0, "zero" )),  //  x0
        std::make_pair( ra   , std::make_pair( 0, "ra"   )),  //  x1
        std::make_pair( sp   , std::make_pair( 0, "sp"   )),  //  x2
        std::make_pair( gp   , std::make_pair( 0, "gp"   )),  //  x3
        std::make_pair( tp   , std::make_pair( 0, "tp"   )),  //  x4
        std::make_pair( t0   , std::make_pair( 0, "t0"   )),  //  x5
        std::make_pair( t1   , std::make_pair( 0, "t1"   )),  //  x6
        std::make_pair( t2   , std::make_pair( 0, "t2"   )),  //  x7
        std::make_pair( s0   , std::make_pair( 0, "s0"   )),  //  x8
        std::make_pair( s1   , std::make_pair( 0, "s1"   )),  //  x9
        std::make_pair( a0   , std::make_pair( 0, "a0"   )),  // x10
        std::make_pair( a1   , std::make_pair( 0, "a1"   )),  // x11
        std::make_pair( a2   , std::make_pair( 0, "a2"   )),  // x12
        std::make_pair( a3   , std::make_pair( 0, "a3"   )),  // x13
        std::make_pair( a4   , std::make_pair( 0, "a4"   )),  // x14
        std::make_pair( a5   , std::make_pair( 0, "a5"   )),  // x15
        std::make_pair( a6   , std::make_pair( 0, "a6"   )),  // x16
        std::make_pair( a7   , std::make_pair( 0, "a7"   )),  // x17
        std::make_pair( s2   , std::make_pair( 0, "s2"   )),  // x18
        std::make_pair( s3   , std::make_pair( 0, "s3"   )),  // x19
        std::make_pair( s4   , std::make_pair( 0, "s4"   )),  // x20
        std::make_pair( s5   , std::make_pair( 0, "s5"   )),  // x21
        std::make_pair( s6   , std::make_pair( 0, "s6"   )),  // x22
        std::make_pair( s7   , std::make_pair( 0, "s7"   )),  // x23
        std::make_pair( s8   , std::make_pair( 0, "s8"   )),  // x24
        std::make_pair( s9   , std::make_pair( 0, "s9"   )),  // x25
        std::make_pair( s10  , std::make_pair( 0, "s10"  )),  // x26
        std::make_pair( s11  , std::make_pair( 0, "s11"  )),  // x27
        std::make_pair( t3   , std::make_pair( 0, "t3"   )),  // x28
        std::make_pair( t4   , std::make_pair( 0, "t4"   )),  // x29
        std::make_pair( t5   , std::make_pair( 0, "t5"   )),  // x30
        std::make_pair( t6   , std::make_pair( 0, "t6"   )),  // x31
    };


};

#endif