
#include "isa_parser.hpp"
#include <iomanip>
#include <vector>

#define   OUT_PRINT       std::cout << std::hex << std::setw(12) << std::setfill(' ')  << std::left
#define   FORMAT          std::dec << std::setw(12) << std::setfill(' ')  << std::left
#define   INST_FORMAT     std::hex << std::setw(8) << std::setfill('0')

std::vector<uint32_t> binx = {
    0x00003197, // as auipc gp,3
    0x6f418193, // as addi gp,gp,1780
    0x1a018513, // as addi a0,gp,416
    0x76018613, // as addi a2,gp,1888
    0x40a60633, // as sub a2,a2,a0
    0x00000593, // as addi a1,zero,0
    0x269000ef, // as jal ra,2664
    0x00001517, // as auipc a0,1
    0x00f00313, // as addi t1,zero,15
    0x00050713, // as addi a4,a0,0
    0x02c37a63, // as bgeu t1,a2,52
    0x00f77793, // as andi a5,a4,15
    0x0a079063, // as bne a5,zero,160
    0x06059e63, // as bne a1,zero,124
    0xff067693, // as andi a3,a2,-16
    0x00f67613, // as andi a2,a2,15
    0x00e686b3, // as add a3,a3,a4
    0x00b73023, // as sd a1,0(a4)
    0x00b73423, // as sd a1,8(a4)
    0x01070713, // as addi a4,a4,16
    0xfed76ae3, // as bltu a4,a3,-12
    0x00061463, // as bne a2,zero,8
    0x40c306b3, // as sub a3,t1,a2
    0x00269693, // as slli a3,a3,2
    0x00000297, // as auipc t0,0
    0x005686b3, // as add a3,a3,t0
    0x00c68067, // as jalr zero,a3,12
    0x00b70723, // as sb a1,14(a4)
    0x00008067, // as jalr zero,ra,0
    0x0ff5f593, // as andi a1,a1,255
    0x00001517, // as auipc a0,1
    0xc7c50513, // as addi a0,a0,-900
    0x00050863, // as beq a0,zero,16
    0x00002517, // as auipc a0,2
    0xd9850513, // as addi a0,a0,-616
    0x469000ef, // as jal ra,3176
    0x1b1000ef, // as jal ra,2480
    0x00050593, // as addi a1,a0,0
    0x00000693, // as addi a3,zero,0
    0x00000613, // as addi a2,zero,0
    0x00000513, // as addi a0,zero,0
    0x1740106f, // as jal zero,4468
    0xfd010113, // as addi sp,sp,-48
    0x1b01b783, // as ld a5,432(gp)
    0x06078063, // as beq a5,zero,96
    0x0087a703, // as lw a4,8(a5)
    0x44818813, // as addi a6,gp,1096
    0x1b01b823, // as sd a6,432(gp)
    0x44818793, // as addi a5,gp,1096
    0xf99ff06f, // as jal zero,-104
    0x3147a683, // as lw a3,788(a5)
    0x0087a703, // as lw a4,8(a5)
    0x01f00813, // as addi a6,zero,31
    0x08e84863, // as blt a6,a4,144
    0x02050863, // as beq a0,zero,48
    0x00371813, // as slli a6,a4,3
    0x00270693, // as addi a3,a4,2
    0x00369693, // as slli a3,a3,3
    0x0017071b, // as addiw a4,a4,1
    0x00e7a423, // as sw a4,8(a5)
    0x00d787b3, // as add a5,a5,a3
    0x00b7b023, // as sd a1,0(a5)
    0x00000513, // as addi a0,zero,0
    0x00008067, // as jalr zero,ra,0
    0x44818813, // as addi a6,gp,1096
    0x1b1000ef, // as jal ra,2480
    0x00012503, // as lw a0,0(sp)
    0xfe010113, // as addi sp,sp,-32
    0x00813823, // as sd s0,16(sp)
    0x000137b7, // as lui a5,19
    0x00013437, // as lui s0,19
    0x01213023, // as sd s2,0(sp)
    0x00478793, // as addi a5,a5,4
    0x00440713, // as addi a4,s0,4
    0x00113c23, // as sd ra,24(sp)
    0x00913423, // as sd s1,8(sp)
    0x40e78933, // as sub s2,a5,a4
    0x02e78263, // as beq a5,a4,36
    0x40395913, // as srai s2,s2,3
    0x00013437, // as lui s0,19
    0x000137b7, // as lui a5,19
    0x01878793, // as addi a5,a5,24
    0x00840713, // as addi a4,s0,8
    0x40e78933, // as sub s2,a5,a4
    0x40395913, // as srai s2,s2,3
    0x02e78063, // as beq a5,a4,32
    0x00840413, // as addi s0,s0,8
    0x00000493, // as addi s1,zero,0
    0x00043783, // as ld a5,0(s0)
    0x00148493, // as addi s1,s1,1
    0x00840413, // as addi s0,s0,8
    0x000780e7, // as jalr ra,a5,0
    0xff24e8e3, // as bltu s1,s2,-16
    0x00000793, // as addi a5,zero,0
    0x00078863, // as beq a5,zero,16
    0x00012537, // as lui a0,18
    0x00008067, // as jalr zero,ra,0
    0x00003197, // as auipc gp,3
    0xff24e8e3, // as bltu s1,s2,-16
    0x01813083, // as ld ra,24(sp)
    0x00043783, // as ld a5,0(s0)
    0x00148493, // as addi s1,s1,1
    0x00840413, // as addi s0,s0,8
    0x000780e7, // as jalr ra,a5,0
    0xff24e8e3, // as bltu s1,s2,-16
    0x00000793, // as addi a5,zero,0
    0x00078c63, // as beq a5,zero,24
    0x00013537, // as lui a0,19
    0x00008067, // as jalr zero,ra,0
    0xff010113, // as addi sp,sp,-16
    0xff24e8e3, // as bltu s1,s2,-16
    0x01813083, // as ld ra,24(sp)
    0x01013403, // as ld s0,16(sp)
    0x00813483, // as ld s1,8(sp)
    0x00013903, // as ld s2,0(sp)
    0x02010113, // as addi sp,sp,32
    0x00008067, // as jalr zero,ra,0
    0x00f00313, // as addi t1,zero,15
    0x00012503, // as lw a0,0(sp)
    0x00810593, // as addi a1,sp,8
    0x00000613, // as addi a2,zero,0
    0x06c000ef, // as jal ra,108
    0xf75ff06f, // as jal zero,-140
    0xff010113, // as addi sp,sp,-16
    0x00113423, // as sd ra,8(sp)
    0x00813023, // as sd s0,0(sp)
    0x01010413, // as addi s0,sp,16
    0x000127b7, // as lui a5,18
    0x1b078513, // as addi a0,a5,432
    0x04c000ef, // as jal ra,76
    0x09c000ef, // as jal ra,156
    0xfe010113, // as addi sp,sp,-32
    0x00813c23, // as sd s0,24(sp)
    0x02010413, // as addi s0,sp,32
    0xfea43423, // as sd a0,-24(s0)
    0x00000893, // as addi a7,zero,0
    0x00000073, // as ecall
    0x00000013, // as addi zero,zero,0
    0x01813403, // as ld s0,24(sp)
    0x02010113, // as addi sp,sp,32
    0x00008067, // as jalr zero,ra,0
    0xfe010113, // as addi sp,sp,-32
    0x09c000ef, // as jal ra,156
    0x00000793, // as addi a5,zero,0
    0xff010113, // as addi sp,sp,-16
    0x00813423, // as sd s0,8(sp)
    0x01010413, // as addi s0,sp,16
    0x00300893, // as addi a7,zero,3
    0x00000073, // as ecall
    0x00000013, // as addi zero,zero,0
};

void parser_branch_inst(Instruction inst)
{
    switch (inst.S.func3)
    {
        case 0:    OUT_PRINT <<   "BEQ"  ;     break;
        case 1:    OUT_PRINT <<   "BNE"  ;     break;
        case 4:    OUT_PRINT <<   "BLT"  ;     break;
        case 5:    OUT_PRINT <<   "BGE"  ;     break;
        case 6:    OUT_PRINT <<   "BLTU" ;     break;
        case 7:    OUT_PRINT <<   "BGEU" ;     break;
        default:
            OUT_PRINT <<   "-- Branch";
            break;
    }

    OUT_PRINT   << "imm_4_0"   << FORMAT << inst.S.imm_4_0 ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.S.rs1 ;
    OUT_PRINT   << "rs2"   << FORMAT << inst.S.rs2 ;
    OUT_PRINT   << "imm_11_5" << FORMAT << inst.S.imm_11_5 << std::endl;
}

void parser_load_inst(Instruction inst)
{
    switch (inst.I.func3)
    {
        case 0:    OUT_PRINT <<   "LB"  ;     break;
        case 1:    OUT_PRINT <<   "LH"  ;     break;
        case 2:    OUT_PRINT <<   "LW"  ;     break;
        case 4:    OUT_PRINT <<   "LBU" ;     break;
        case 5:    OUT_PRINT <<   "LHU" ;     break;
        case 6:    OUT_PRINT <<   "LWU" ;     break;
        case 3:    OUT_PRINT <<   "LD" ;     break;
        default:
            OUT_PRINT <<   "-- load";
            break;
    }
    OUT_PRINT   << "rd"    << FORMAT << inst.I.rd ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.I.rs1 ;
    OUT_PRINT   << "imm_11_0"   << FORMAT << inst.I.imm_11_0   << std::endl;
}

void parser_store_inst(Instruction inst)
{
    switch (inst.S.func3)
    {
        case 0:    OUT_PRINT <<   "SB"  ;     break;
        case 1:    OUT_PRINT <<   "SH"  ;     break;
        case 2:    OUT_PRINT <<   "SW"  ;     break;
        case 3:    OUT_PRINT <<   "SD"  ;     break;
        default:
            OUT_PRINT <<   "-- store";
            break;
    }
    OUT_PRINT   << "imm_4_0"   << FORMAT << inst.S.imm_4_0   ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.S.rs1   ;
    OUT_PRINT   << "rs2"   << FORMAT << inst.S.rs2   ;
    OUT_PRINT   << "imm_11_5" << FORMAT << inst.S.imm_11_5 << std::endl;
}

void parser_imm_inst(Instruction inst)
{
    switch (inst.I.func3)
    {
        case 0:    OUT_PRINT <<   "ADDI  "  ;     break;
        case 2:    OUT_PRINT <<   "SLTI  "  ;     break;
        case 3:    OUT_PRINT <<   "SLTIU "  ;     break;
        case 4:    OUT_PRINT <<   "XORI  "  ;     break;
        case 6:    OUT_PRINT <<   "ORI   "  ;     break;
        case 7:    OUT_PRINT <<   "ANDI  "  ;     break;
        case 1:    OUT_PRINT <<   "SLLI  "  ;     break;
        case 5:    OUT_PRINT <<   "SRAI/SRLI"  ;     break;
        default:
            OUT_PRINT <<   "-- IMM";
            break;
    }

    OUT_PRINT   << "rd"    << FORMAT << inst.I.rd    ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.I.rs1   ;
    OUT_PRINT   << "imm_11_0"   << FORMAT << inst.I.imm_11_0   << std::endl;
}

void parser_reg_inst(Instruction inst)
{
    switch (inst.R.func3)
    {
        case 0:
            if (inst.R.func7 == 0)
            {
                OUT_PRINT <<   "ADD " ;
            }
            else if (inst.R.func7 == 0x20)
            {
                OUT_PRINT <<   "SUB " ;
            }
            break;
        case 1:    OUT_PRINT <<   "SLL "  ;     break;
        case 2:    OUT_PRINT <<   "SLT "  ;     break;
        case 3:    OUT_PRINT <<   "SLTU"  ;     break;
        case 4:    OUT_PRINT <<   "XOR "  ;     break;
        case 5:
            if (inst.R.func7 == 0)
            {
                OUT_PRINT <<   "SRL " ;
            }
            else if (inst.R.func7 == 0x20)
            {
                OUT_PRINT <<   "SRA " ;
            }
            break;
        case 6:    OUT_PRINT <<   "OR  "  ;     break;
        case 7:    OUT_PRINT <<   "AND "  ;     break;
        default:
            OUT_PRINT <<   "-- REG";
            break;
    }

    OUT_PRINT   << "rd"  << FORMAT << inst.R.rd   ;
    OUT_PRINT   << "rs1" << FORMAT << inst.R.rs1  ;
    OUT_PRINT   << "rs2" << FORMAT << inst.R.rs2  << std::endl;
}

void parser_fence_inst(Instruction inst)
{

}

void parser_system_inst(Instruction inst)
{
    switch (inst.R.func3)
    {
        case 0:
            if (inst.R.func7 == 0)
            {
                OUT_PRINT <<   "ECALL "  ;
            }
            else if(inst.R.func7 == 1)
            {
                OUT_PRINT <<   "EBREA "  ;
            }
            break;
        case 1:    OUT_PRINT <<   "CSRRW "  ;     break;
        case 2:    OUT_PRINT <<   "CSRRS "  ;     break;
        case 3:    OUT_PRINT <<   "CSRRC "  ;     break;
        case 5:    OUT_PRINT <<   "CSRRSW"  ;     break;
        case 6:    OUT_PRINT <<   "CSRRSI"  ;     break;
        case 7:    OUT_PRINT <<   "CSRRCI"  ;     break;
        default:
            OUT_PRINT <<   "-- SYSTEM";
            break;
    }

    OUT_PRINT   << "rd"    << FORMAT << inst.I.rd    ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.I.rs1   ;
    OUT_PRINT   << "imm_11_0"   << FORMAT << inst.I.imm_11_0   << std::endl;
}

void parser_imm32_inst(Instruction inst)
{
    switch (inst.R.func3)
    {
        case 0:    OUT_PRINT <<   "ADDIW"  ;     break;
        case 1:    OUT_PRINT <<   "SLLIW"  ;     break;
        case 5:
            if(inst.R.func7 == 0)
            {
                OUT_PRINT <<   "SRLIW"  ;
            }
            else if (inst.R.func7 == 0x20)
            {
                OUT_PRINT <<   "SRAIW"  ;
            }
            break;
        default:
            OUT_PRINT <<   "-- IMM32";
            break;
    }

    OUT_PRINT   << "rd"    << FORMAT << inst.R.rd    ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.R.rs1   ;
    OUT_PRINT   << "rs2"   << FORMAT << inst.R.rs2   ;
    OUT_PRINT   << "func7" << FORMAT << inst.R.func7 << std::endl;
}

void parser_op32_inst(Instruction inst)
{
    switch (inst.R.func3)
    {
        case 0:
            if (inst.R.func7 == 0)
            {
                OUT_PRINT <<   "ADDW"  ;
            }
            else if(inst.R.func7 == 0x20)
            {
                OUT_PRINT <<   "SUBW"  ;
            }
            break;
        case 1:    OUT_PRINT <<   "SLLW"  ;     break;
        case 5:
            if (inst.R.func7 == 0)
            {
                OUT_PRINT <<   "SRLW"  ;
            }
            else if(inst.R.func7 == 0x20)
            {
                OUT_PRINT <<   "SRAW"  ;
            }
            break;
        default:
            OUT_PRINT <<   "-- OP32";
            break;
    }

    OUT_PRINT   << "rd"    << FORMAT << inst.R.rd     ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.R.rs1    ;
    OUT_PRINT   << "rs2"   << FORMAT << inst.R.rs2    ;
    OUT_PRINT   << "func7" << FORMAT << inst.R.func7 << std::endl;


}

void parser_auipc_inst(Instruction inst)
{
    OUT_PRINT   << "AUIPC"  ;
    OUT_PRINT   << "rd"  << FORMAT << inst.U.rd  ;
    OUT_PRINT   << "imm_31_12" << FORMAT << inst.U.imm_31_12 << std::endl;
}

void parser_jal_inst(Instruction inst)
{
    OUT_PRINT <<   "JAL"  ;
    OUT_PRINT   << "rd"  << FORMAT << inst.U.rd  ;
    OUT_PRINT   << "imm_31_12" << FORMAT << inst.U.imm_31_12 << std::endl;
}

void parser_jalr_inst(Instruction inst)
{
    OUT_PRINT <<   "JALR"  ;
    OUT_PRINT   << "rd"    << FORMAT << inst.I.rd    ;
    OUT_PRINT   << "func3" << FORMAT << inst.I.func3 ;
    OUT_PRINT   << "rs1"   << FORMAT << inst.I.rs1   ;
    OUT_PRINT   << "imm_11_0"   << FORMAT << inst.I.imm_11_0   << std::endl;
}

void parser_lut_inst(Instruction inst)
{
    OUT_PRINT   << "LUT"  ;
    OUT_PRINT   << "rd"  << FORMAT << inst.U.rd  ;
    OUT_PRINT   << "imm_31_12" << FORMAT << inst.U.imm_31_12 << std::endl;
}

int main(int argc, char const *argv[])
{
    Instruction inst;

    for (auto & cmd: binx)
    {
        inst.DoubleWord = cmd;

        std::cout << INST_FORMAT << inst.DoubleWord << "   ";

        switch (static_cast<InstOpCode>(inst.common.opcode))
        {
            case InstOpCode::REG    : parser_reg_inst(inst)   ; break;
            case InstOpCode::IMM    : parser_imm_inst(inst)   ; break;
            case InstOpCode::LUT    : parser_lut_inst(inst)   ; break;
            case InstOpCode::BRANCH : parser_branch_inst(inst); break;
            case InstOpCode::STORE  : parser_store_inst(inst) ; break;
            case InstOpCode::LOAD   : parser_load_inst(inst)  ; break;
            case InstOpCode::SYSTEM : parser_system_inst(inst); break;
            case InstOpCode::AUIPC  : parser_auipc_inst(inst) ; break;
            case InstOpCode::JAL    : parser_jal_inst(inst)   ; break;
            case InstOpCode::JALR   : parser_jalr_inst(inst)  ; break;
            case InstOpCode::IMM32  : parser_imm32_inst(inst) ; break;
            case InstOpCode::OP32   : parser_op32_inst(inst)  ; break;
            default:
                OUT_PRINT <<   "UNKNOW OpCode !!!!!!!!!!!   "  << FORMAT << inst.common.opcode
                        << " INST: " << FORMAT << inst.DoubleWord  << std::endl;
                break;
        };
    }

    return 0;
}
