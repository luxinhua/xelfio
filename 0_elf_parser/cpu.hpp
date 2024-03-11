#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"
#include "memory.hpp"
#include "instruction.hpp"

class Core{
public:
    Core(Memory * memory, Stack stack, uint32_t elf_entry): m_mem{memory}, m_stack{stack}, m_pc{elf_entry}{
        m_inst.DoubleWord = 0;

        m_core_registers[sp].first = m_stack.m_base;


    }
    ~Core() = default;

    // 取值阶段(IF):更新PC,取指写入IR
    // 译码阶段(ID):立即数拼接扩展与rs1、rs2地址取数
    // 执行阶段(EXE):ALU计算和比较器运行
    // 访存阶段(MEM):存储器读写
    // 写回阶段(WB):寄存器组根据rd地址写入数据

    void fetch();
    void decode();
    void execute();
    void movePipe();

    void print_core_registers();

private:
    void execute_lb() ;
    void execute_lh() ;
    void execute_lw() ;
    void execute_lbu();
    void execute_lhu();
    void execute_lwu();
    void execute_ld() ;
    void execute_beq() ;
    void execute_bne() ;
    void execute_blt() ;
    void execute_bge() ;
    void execute_bltu();
    void execute_bgeu();
    void execute_auipc();
    void execute_addi();
    void execute_slti();
    void execute_sltu();
    void execute_xori();
    void execute_ori();
    void execute_andi();
    void execute_slli();
    void execute_srai();
    void execute_sub();
    void execute_jal();

    void execute_branch_inst();
    void execute_load_inst();
    void execute_store_inst();
    void execute_imm_inst();
    void execute_reg_inst();
    void execute_fence_inst();
    void execute_system_inst();
    void execute_imm32_inst();
    void execute_op32_inst();
    void execute_auipc_inst();
    void execute_jal_inst();
    void execute_jalr_inst();
    void execute_lut_inst();

    void decode_sb();
    void decode_sh();
    void decode_sw();
    void decode_sd();
    void decode_lb() ;
    void decode_lh() ;
    void decode_lw() ;
    void decode_lbu();
    void decode_lhu();
    void decode_lwu();
    void decode_ld() ;
    void decode_beq() ;
    void decode_bne() ;
    void decode_blt() ;
    void decode_bge() ;
    void decode_bltu();
    void decode_bgeu();
    void decode_auipc();
    void decode_addi();
    void decode_slti();
    void decode_sltu();
    void decode_xori();
    void decode_ori();
    void decode_andi();
    void decode_slli();
    void decode_srli();
    void decode_srai();
    void decode_sub();
    void decode_jal();

    void decode_branch_inst();
    void decode_load_inst();
    void decode_store_inst();
    void decode_imm_inst();
    void decode_reg_inst();
    void decode_fence_inst();
    void decode_system_inst();
    void decode_imm32_inst();
    void decode_op32_inst();
    void decode_auipc_inst();
    void decode_jal_inst();
    void decode_jalr_inst();
    void decode_lut_inst();

public:
    Memory * m_mem;
    Stack  m_stack;

    struct Stage{
        uint32_t m_pc;
        Instruction m_inst;
        bool m_bubble;
        bool m_stall;
    };

    struct Stage FetchReg{0};
    struct Stage FetchRegNew{0};
    struct Stage DecodeReg{0};
    struct Stage DecodeRegNew{0};
    struct Stage ExecuteReg{0};
    struct Stage ExecuteRegNew{0};

    uint32_t m_pc;

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

    std::array<std::pair<uint64_t, std::string>, 32> m_core_registers{
        /**std::pair < value, alias_name > */
        std::make_pair( 0, "zero" ),  //  x0
        std::make_pair( 0, "ra"   ),  //  x1
        std::make_pair( 0, "sp"   ),  //  x2
        std::make_pair( 0, "gp"   ),  //  x3
        std::make_pair( 0, "tp"   ),  //  x4
        std::make_pair( 0, "t0"   ),  //  x5
        std::make_pair( 0, "t1"   ),  //  x6
        std::make_pair( 0, "t2"   ),  //  x7
        std::make_pair( 0, "s0"   ),  //  x8
        std::make_pair( 0, "s1"   ),  //  x9
        std::make_pair( 0, "a0"   ),  // x10
        std::make_pair( 0, "a1"   ),  // x11
        std::make_pair( 0, "a2"   ),  // x12
        std::make_pair( 0, "a3"   ),  // x13
        std::make_pair( 0, "a4"   ),  // x14
        std::make_pair( 0, "a5"   ),  // x15
        std::make_pair( 0, "a6"   ),  // x16
        std::make_pair( 0, "a7"   ),  // x17
        std::make_pair( 0, "s2"   ),  // x18
        std::make_pair( 0, "s3"   ),  // x19
        std::make_pair( 0, "s4"   ),  // x20
        std::make_pair( 0, "s5"   ),  // x21
        std::make_pair( 0, "s6"   ),  // x22
        std::make_pair( 0, "s7"   ),  // x23
        std::make_pair( 0, "s8"   ),  // x24
        std::make_pair( 0, "s9"   ),  // x25
        std::make_pair( 0, "s10"  ),  // x26
        std::make_pair( 0, "s11"  ),  // x27
        std::make_pair( 0, "t3"   ),  // x28
        std::make_pair( 0, "t4"   ),  // x29
        std::make_pair( 0, "t5"   ),  // x30
        std::make_pair( 0, "t6"   ),  // x31
    };


};

#endif