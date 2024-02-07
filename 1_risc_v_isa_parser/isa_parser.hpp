
#ifndef __ISA_PARSER_H__
#define __ISA_PARSER_H__

#include <iostream>


enum class InstOpCode : uint8_t
{
    REG    = 0x33,
    IMM    = 0x13,
    LUT    = 0x37,
    BRANCH = 0x63,
    STORE  = 0x23,
    LOAD   = 0x3,
    SYSTEM = 0x73,
    AUIPC  = 0x17,
    JAL    = 0x6F,
    JALR   = 0x67,
    IMM32  = 0x1B,
    OP32   = 0x3B,
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