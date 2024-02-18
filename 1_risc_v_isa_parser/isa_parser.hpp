
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

    STORE  = 0x23,
    SB     = 0x23,  // S
    SH     = 0x23,  // S
    SW     = 0x23,  // S

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
    ECALL   = 0x73, // I
    EBREA   = 0x73, // I
    CSRRW   = 0x73, // I
    CSRRS   = 0x73, // I
    CSRRC   = 0x73, // I
    CSRRSI  = 0x73, // I
    CSRRCI  = 0x73, // I

    // RV64I base inst set, beside RV32I inst set
    LWU = 0x3, // I

    LU  = 0x3, // I

    SD  = 0x23, // S

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
    struct{
        uint32_t opcode : 7;
        uint32_t reserverd : 25;
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
        uint32_t opcode : 7;
        uint32_t rd     : 5;
        uint32_t func3  : 3;
        uint32_t rs1    : 5;
        uint32_t imm    : 12;
    } I;
    struct{
        uint32_t opcode : 7;
        uint32_t imm    : 5;
        uint32_t func3  : 3;
        uint32_t rs1    : 5;
        uint32_t rs2    : 5;
        uint32_t imm_2  : 7;
    } S;
    struct{
        uint32_t opcode : 7;
        uint32_t imm    : 5;
        uint32_t func3  : 3;
        uint32_t rs1    : 5;
        uint32_t rs2    : 5;
        uint32_t imm_2  : 7;
    } B;
    struct{
        uint32_t opcode : 7;
        uint32_t rd     : 5;
        uint32_t imm    : 20;
    } U;
    struct{
        uint32_t opcode : 7;
        uint32_t rd     : 5;
        uint32_t imm    : 20;
    } J;
    uint32_t DoubleWord;
};


#endif