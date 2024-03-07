
#ifndef __ISA_PARSER_H__
#define __ISA_PARSER_H__

#include <array>
#include <iostream>

enum class InstOpCode : uint8_t
{
    // RV32I base inst set
    LUT    = 0x37,  // U

    AUIPC  = 0x17,  // U

    JAL    = 0x6F,  // UJ

    JALR   = 0x67,  // I

    BRANCH = 0x63,
    BEQ    = 0x63,  // SB
    BNE    = 0x63,  // SB
    BLT    = 0x63,  // SB
    BGE    = 0x63,  // SB
    BLTU   = 0x63,  // SB
    BGEU   = 0x63,  // SB

    LOAD   = 0x3,
    LB     = 0x3,   // I
    LH     = 0x3,   // I
    LW     = 0x3,   // I
    LBU    = 0x3,   // I
    LHU    = 0x3,   // I

    LWU    = 0x3, // I
    LD     = 0x3, // I


    STORE  = 0x23,
    SB     = 0x23,  // S
    SH     = 0x23,  // S
    SW     = 0x23,  // S

    SD     = 0x23, // S

    IMM    = 0x13,
    ADDI   = 0x13,  // I
    SLTI   = 0x13,  // I
    SLTIU  = 0x13,  // I
    XORI   = 0x13,  // I
    ORI    = 0x13,  // I
    ANDI   = 0x13,  // I
    SLLI   = 0x13,  // I
    SRLI   = 0x13,  // I
    SRAI   = 0x13,  // I

    REG    = 0x33,
    ADD    = 0x33,  // R
    SUB    = 0x33,  // R
    SLL    = 0x33,  // R
    SLT    = 0x33,  // R
    SLTU   = 0x33,  // R
    XOR    = 0x33,  // R
    SRL    = 0x33,  // R
    SRA    = 0x33,  // R
    OR     = 0x33,  // R
    AND    = 0x33,  // R

    FENCE   = 0xF,   // UJ
    FENCE_J = 0xF,  // UJ

    SYSTEM  = 0x73,
    ECALL   = 0x73, // R
    EBREA   = 0x73, // R
    CSRRW   = 0x73, // R
    CSRRS   = 0x73, // R
    CSRRC   = 0x73, // R
    CSRRSW  = 0x73, // R
    CSRRSI  = 0x73, // R
    CSRRCI  = 0x73, // R

    // RV64I base inst set, beside RV32I inst set


    // SLLI = 0X13, // R  ,  include by rv32i set
    // SRLI = 0X13, // R  ,  include by rv32i set
    // SRAI = 0X13, // R  ,  include by rv32i set

    IMM32 = 0x1B,
    ADDIW = 0x1B, // I
    SLLIW = 0x1B, // R
    SRLIW = 0x1B, // R
    SRAIW = 0x1B, // R

    OP32  = 0x3B,
    ADDW  = 0x3B, // R
    SUBW  = 0x3B, // R
    SLLW  = 0x3B, // R
    SRLW  = 0x3B, // R
    SRAW  = 0x3B, // R
};

union Instruction
{
    union{
        struct {
            uint32_t opcode  : 7;
            uint32_t reserve : 25;
        } common;
        struct{
            uint32_t opcode : 7;
            uint32_t rd     : 5;
            uint32_t func3  : 3;
            uint32_t rs1    : 5;
            uint32_t rs2    : 5;
            uint32_t func7  : 7;
        } R;
        struct{
            uint32_t opcode   : 7;
            uint32_t rd       : 5;
            uint32_t func3    : 3;
            uint32_t rs1      : 5;
            uint32_t imm_11_0 : 12;
        } I;
        struct{
            uint32_t opcode   : 7;
            uint32_t imm_4_0  : 5;
            uint32_t func3    : 3;
            uint32_t rs1      : 5;
            uint32_t rs2      : 5;
            uint32_t imm_11_5 : 7;
        } S;
        struct{
            uint32_t opcode   : 7;
            uint32_t imm_11   : 1;
            uint32_t imm_4_1  : 4;
            uint32_t func3    : 3;
            uint32_t rs1      : 5;
            uint32_t rs2      : 5;
            uint32_t imm_10_5 : 6;
            uint32_t imm_12   : 1;
        } SB;
        struct{
            uint32_t opcode     : 7;
            uint32_t rd         : 5;
            uint32_t imm_31_12  : 20;
        } U;
        struct{
            uint32_t opcode    : 7;
            uint32_t rd        : 5;
            uint32_t imm_19_12 : 20;
            uint32_t imm_11    : 20;
            uint32_t imm_10_1  : 20;
            uint32_t imm_20    : 20;
        } UJ;
    };
    union{
        struct{
            uint32_t opcode : 7;
            uint32_t rd     : 5;
            uint32_t func3  : 3;
            uint32_t rs1    : 5;
            uint32_t rs2    : 5;
            uint32_t func7  : 7;
        } R;
        struct{
            uint32_t opcode   : 7;
            uint32_t rd       : 5;
            uint32_t func3    : 3;
            uint32_t rs1      : 5;
            uint32_t imm_11_0 : 12;
        } I;
        struct{
            uint32_t opcode   : 7;
            uint32_t imm_4_0  : 5;
            uint32_t func3    : 3;
            uint32_t rs1      : 5;
            uint32_t rs2      : 5;
            uint32_t imm_11_5 : 7;
        } S;
    }rv64i;

    uint32_t DoubleWord;
};

#define   OUT_PRINT       std::cout << std::hex << std::setw(12) << std::setfill(' ')  << std::left
#define   FORMAT          std::dec << std::setw(12) << std::setfill(' ')  << std::left
#define   INST_FORMAT     std::hex << std::setw(8) << std::setfill('0')

// 0x00003197, // as auipc gp,3
// 0x6f418193, // as addi gp,gp,1780
// 0x1a018513, // as addi a0,gp,416
// 0x76018613, // as addi a2,gp,1888
// 0x40a60633, // as sub a2,a2,a0
// 0x00000593, // as addi a1,zero,0
// 0x269000ef, // as jal ra,2664
// 0x00001517, // as auipc a0,1
// 0x00f00313, // as addi t1,zero,15
// 0x00050713, // as addi a4,a0,0
// 0x02c37a63, // as bgeu t1,a2,52
// 0x00f77793, // as andi a5,a4,15
// 0x0a079063, // as bne a5,zero,160
// 0x06059e63, // as bne a1,zero,124
// 0xff067693, // as andi a3,a2,-16
// 0x00f67613, // as andi a2,a2,15
// 0x00e686b3, // as add a3,a3,a4
// 0x00b73023, // as sd a1,0(a4)
// 0x00b73423, // as sd a1,8(a4)
// 0x01070713, // as addi a4,a4,16
// 0xfed76ae3, // as bltu a4,a3,-12
// 0x00061463, // as bne a2,zero,8
// 0x40c306b3, // as sub a3,t1,a2
// 0x00269693, // as slli a3,a3,2
// 0x00000297, // as auipc t0,0
// 0x005686b3, // as add a3,a3,t0
// 0x00c68067, // as jalr zero,a3,12
// 0x00b70723, // as sb a1,14(a4)
// 0x00008067, // as jalr zero,ra,0
// 0x0ff5f593, // as andi a1,a1,255
// 0x00001517, // as auipc a0,1
// 0xc7c50513, // as addi a0,a0,-900
// 0x00050863, // as beq a0,zero,16
// 0x00002517, // as auipc a0,2
// 0xd9850513, // as addi a0,a0,-616
// 0x469000ef, // as jal ra,3176
// 0x1b1000ef, // as jal ra,2480
// 0x00050593, // as addi a1,a0,0
// 0x00000693, // as addi a3,zero,0
// 0x00000613, // as addi a2,zero,0
// 0x00000513, // as addi a0,zero,0
// 0x1740106f, // as jal zero,4468
// 0xfd010113, // as addi sp,sp,-48
// 0x1b01b783, // as ld a5,432(gp)
// 0x06078063, // as beq a5,zero,96
// 0x0087a703, // as lw a4,8(a5)
// 0x44818813, // as addi a6,gp,1096
// 0x1b01b823, // as sd a6,432(gp)
// 0x44818793, // as addi a5,gp,1096
// 0xf99ff06f, // as jal zero,-104
// 0x3147a683, // as lw a3,788(a5)
// 0x0087a703, // as lw a4,8(a5)
// 0x01f00813, // as addi a6,zero,31
// 0x08e84863, // as blt a6,a4,144
// 0x02050863, // as beq a0,zero,48
// 0x00371813, // as slli a6,a4,3
// 0x00270693, // as addi a3,a4,2
// 0x00369693, // as slli a3,a3,3
// 0x0017071b, // as addiw a4,a4,1
// 0x00e7a423, // as sw a4,8(a5)
// 0x00d787b3, // as add a5,a5,a3
// 0x00b7b023, // as sd a1,0(a5)
// 0x00000513, // as addi a0,zero,0
// 0x00008067, // as jalr zero,ra,0
// 0x44818813, // as addi a6,gp,1096
// 0x1b1000ef, // as jal ra,2480
// 0x00012503, // as lw a0,0(sp)
// 0xfe010113, // as addi sp,sp,-32
// 0x00813823, // as sd s0,16(sp)
// 0x000137b7, // as lui a5,19
// 0x00013437, // as lui s0,19
// 0x01213023, // as sd s2,0(sp)
// 0x00478793, // as addi a5,a5,4
// 0x00440713, // as addi a4,s0,4
// 0x00113c23, // as sd ra,24(sp)
// 0x00913423, // as sd s1,8(sp)
// 0x40e78933, // as sub s2,a5,a4
// 0x02e78263, // as beq a5,a4,36
// 0x40395913, // as srai s2,s2,3
// 0x00013437, // as lui s0,19
// 0x000137b7, // as lui a5,19
// 0x01878793, // as addi a5,a5,24
// 0x00840713, // as addi a4,s0,8
// 0x40e78933, // as sub s2,a5,a4
// 0x40395913, // as srai s2,s2,3
// 0x02e78063, // as beq a5,a4,32
// 0x00840413, // as addi s0,s0,8
// 0x00000493, // as addi s1,zero,0
// 0x00043783, // as ld a5,0(s0)
// 0x00148493, // as addi s1,s1,1
// 0x00840413, // as addi s0,s0,8
// 0x000780e7, // as jalr ra,a5,0
// 0xff24e8e3, // as bltu s1,s2,-16
// 0x00000793, // as addi a5,zero,0
// 0x00078863, // as beq a5,zero,16
// 0x00012537, // as lui a0,18
// 0x00008067, // as jalr zero,ra,0
// 0x00003197, // as auipc gp,3
// 0xff24e8e3, // as bltu s1,s2,-16
// 0x01813083, // as ld ra,24(sp)
// 0x00043783, // as ld a5,0(s0)
// 0x00148493, // as addi s1,s1,1
// 0x00840413, // as addi s0,s0,8
// 0x000780e7, // as jalr ra,a5,0
// 0xff24e8e3, // as bltu s1,s2,-16
// 0x00000793, // as addi a5,zero,0
// 0x00078c63, // as beq a5,zero,24
// 0x00013537, // as lui a0,19
// 0x00008067, // as jalr zero,ra,0
// 0xff010113, // as addi sp,sp,-16
// 0xff24e8e3, // as bltu s1,s2,-16
// 0x01813083, // as ld ra,24(sp)
// 0x01013403, // as ld s0,16(sp)
// 0x00813483, // as ld s1,8(sp)
// 0x00013903, // as ld s2,0(sp)
// 0x02010113, // as addi sp,sp,32
// 0x00008067, // as jalr zero,ra,0
// 0x00f00313, // as addi t1,zero,15
// 0x00012503, // as lw a0,0(sp)
// 0x00810593, // as addi a1,sp,8
// 0x00000613, // as addi a2,zero,0
// 0x06c000ef, // as jal ra,108
// 0xf75ff06f, // as jal zero,-140
// 0xff010113, // as addi sp,sp,-16
// 0x00113423, // as sd ra,8(sp)
// 0x00813023, // as sd s0,0(sp)
// 0x01010413, // as addi s0,sp,16
// 0x000127b7, // as lui a5,18
// 0x1b078513, // as addi a0,a5,432
// 0x04c000ef, // as jal ra,76
// 0x09c000ef, // as jal ra,156
// 0xfe010113, // as addi sp,sp,-32
// 0x00813c23, // as sd s0,24(sp)
// 0x02010413, // as addi s0,sp,32
// 0xfea43423, // as sd a0,-24(s0)
// 0x00000893, // as addi a7,zero,0
// 0x00000073, // as ecall
// 0x00000013, // as addi zero,zero,0
// 0x01813403, // as ld s0,24(sp)
// 0x02010113, // as addi sp,sp,32
// 0x00008067, // as jalr zero,ra,0
// 0xfe010113, // as addi sp,sp,-32
// 0x09c000ef, // as jal ra,156
// 0x00000793, // as addi a5,zero,0
// 0xff010113, // as addi sp,sp,-16
// 0x00813423, // as sd s0,8(sp)
// 0x01010413, // as addi s0,sp,16
// 0x00300893, // as addi a7,zero,3
// 0x00000073, // as ecall
// 0x00000013, // as addi zero,zero,0

#endif