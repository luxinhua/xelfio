#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

// 1	R 型指令	用于寄存器和寄存器操作
// 2	I 型指令	用于短立即数和内存载入指令load操作
// 3	S 型指令	用于内存存储store操作
// 4	B 型指令	用于有条件跳转操作
// 5	U 型指令	用于长立即数操作
// 6	J 型指令	用于无条件跳转操作


void Core::execute_branch_inst()
{
    switch (m_inst.rv32i.S.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BEQ"  ;
            execute_beq() ;
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BNE"  ;
            execute_bne() ;
            break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BLT"  ;
            execute_blt() ;
            break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BGE"  ;
            execute_bge() ;
            break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BLTU" ;
            execute_bltu();
            break;
        case 7:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BGEU" ;
            execute_bgeu();
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "Branch";
            break;
    }

    auto imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | (m_inst.rv32i.SB.imm_10_5 << 5) | \
                        (m_inst.rv32i.SB.imm_11 << 11) | (m_inst.rv32i.SB.imm_12 << 12) ) << 19 ) >> 19;

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.SB.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.SB.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::dec << imm
              << std::endl;

}

void Core::execute_load_inst()
{
    switch (m_inst.rv32i.I.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LB"  ; execute_lb() ; break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LH"  ; execute_lh() ; break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LW"  ; execute_lw() ; break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LBU" ; execute_lbu(); break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LHU" ; execute_lhu(); break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LWU" ; execute_lwu(); break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LD"  ; execute_ld() ; break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "load";
            break;
    }



    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.imm_11_0 << std::endl;
}

void Core::execute_store_inst()
{
    switch (m_inst.rv32i.S.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SB"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SH"  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SW"  ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SD"  ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "store";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.S.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.S.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.S.imm_4_0
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.S.imm_11_5 << std::endl;
}

void Core::execute_imm_inst()
{
    switch (m_inst.rv32i.I.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "ADDI  "     ; execute_addi();  break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "SLTI  "     ; execute_slti();  break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "SLTIU "     ; execute_sltu();  break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "XORI  "     ; execute_xori();  break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "ORI   "     ; execute_ori();   break;
        case 7:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "ANDI  "     ; execute_andi();  break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "SLLI  "     ; execute_slli();  break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<  "SRAI/SRLI"  ; execute_srai();  break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.imm_11_0 << std::endl;
}

void Core::execute_reg_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            if (m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADD " ;
            }
            else if (m_inst.rv32i.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SUB " ;
                execute_sub();
            }
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLL "  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLT "  ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLTU"  ;     break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "XOR "  ;     break;
        case 5:
            if (m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRL " ;
            }
            else if (m_inst.rv32i.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRA " ;
            }
            break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "OR  "  ;     break;
        case 7:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "AND "  ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "REG";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs2 << std::endl;
}

void Core::execute_fence_inst()
{

}

void Core::execute_system_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            if (m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ECALL "  ;
            }
            else if(m_inst.rv32i.R.func7 == 1)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "EBREA "  ;
            }
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRW "  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRS "  ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRC "  ;     break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRSW"  ;     break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRSI"  ;     break;
        case 7:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "CSRRCI"  ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SYSTEM";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.imm_11_0 << std::endl;
}

void Core::execute_imm32_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADDIW"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLLIW"  ;     break;
        case 5:
            if(m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRLIW"  ;
            }
            else if (m_inst.rv32i.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRAIW"  ;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM32";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.func7 << std::endl;

}

void Core::execute_op32_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            if (m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADDW"  ;
            }
            else if(m_inst.rv32i.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SUBW"  ;
            }
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') << "SLLW"  ;     break;
        case 5:
            if (m_inst.rv32i.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRLW"  ;
            }
            else if(m_inst.rv32i.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRAW"  ;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "OP32";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.R.func7 << std::endl;
}

void Core::execute_auipc_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "AUIPC"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.imm_31_12 << std::endl;

    execute_auipc();
}

void Core::execute_jal_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "JAL"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.UJ.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.UJ.imm_10_1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.UJ.imm_11
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.UJ.imm_19_12
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.UJ.imm_20 << std::endl;

    execute_jal();
}

void Core::execute_jalr_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "JALR"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.imm_11_0 << std::endl;
}

void Core::execute_lut_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "LUT"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.imm_31_12 << std::endl;
}

void Core::execute_beq()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 == rs2)
    {
        auto offset = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19 ) >> 19 ;
        DecodeReg.m_pc += offset;
    }
}
void Core::execute_bne()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 != rs2)
    {
        auto offset = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;
        DecodeReg.m_pc += offset;
    }
}
void Core::execute_blt()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 < rs2)
    {
        auto offset = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;
        DecodeReg.m_pc += offset;
    }
}
void Core::execute_bge()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 > rs2)
    {
        auto offset = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;
        DecodeReg.m_pc += offset;
    }
}
void Core::execute_bltu()
{
    uint32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    uint32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 < rs2)
    {
        auto offset = uint32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                 (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                 (m_inst.rv32i.SB.imm_11 << 11) | \
                                 (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;
        DecodeReg.m_pc += offset;
    }
}
void Core::execute_bgeu()
{
    uint32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    uint32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (rs1 > rs2)
    {
        auto offset = uint32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                 (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                 (m_inst.rv32i.SB.imm_11 << 11) | \
                                 (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;
        DecodeReg.m_pc += offset;
    }
}


void Core::execute_lb()
{
    auto offset = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read8(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_lh()
{
    auto offset = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read16(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_lw()
{
    auto offset = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read32(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_lbu()
{
    auto offset = uint32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read8(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_lhu()
{
    auto offset = uint32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read16(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_lwu()
{
    auto offset = uint32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read32(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_ld()
{
    auto offset = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + offset;
    auto data = m_mem->read64(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}

void Core::execute_addi(){
    auto imm = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;

    m_core_registers[m_inst.rv32i.I.rd].first = rs1 + imm;
}
void Core::execute_slti(){

}
void Core::execute_sltu(){

}
void Core::execute_xori(){

}
void Core::execute_ori(){

}
void Core::execute_andi(){

}
void Core::execute_slli(){

}
void Core::execute_srai(){

}

void Core::execute_sub()
{
    auto rs1 = m_core_registers[m_inst.rv32i.R.rs1].first;
    auto rs2 = m_core_registers[m_inst.rv32i.R.rs2].first;

    m_core_registers[m_inst.rv32i.R.rd].first = rs1 - rs2;
}

void Core::execute_auipc()
{
    auto offset = int32_t(m_inst.rv32i.U.imm_31_12 << 12);

    m_core_registers[m_inst.rv32i.U.rd].first = DecodeReg.m_pc + offset;
}

void Core::execute_jal()
{
    m_core_registers[m_inst.rv32i.UJ.rd].first = DecodeReg.m_pc + 4;

    auto offset = int32_t((m_inst.rv32i.UJ.imm_10_1 | \
                          (m_inst.rv32i.UJ.imm_11 << 11) | \
                          (m_inst.rv32i.UJ.imm_19_12 << 12) | \
                          (m_inst.rv32i.UJ.imm_20 << 20)) << 12) >> 11;

    DecodeReg.m_pc += offset;

    // m_pc = DecodeReg.m_pc;
}

void Core::execute()
{
    std::cout << std::setw(8) << std::left << std::setfill(' ') << "Execute" << ":";

    m_inst = DecodeReg.m_inst;
    // m_pc = DecodeReg.m_pc;

    std::cout << std::setw(13) << std::left << std::setfill(' ') << "instruction" ;
    std::cout << std::setw(10) << std::left << std::setfill(' ') << m_inst.DoubleWord;
    std::cout << std::setw(12) << std::left << std::setfill(' ') << "at address" ;
    std::cout << std::setw(10) << std::left << std::setfill(' ') << DecodeReg.m_pc ;
    std::cout << " : ";

    if (DecodeReg.m_stall)
    {
        ExecuteReg.m_stall = true;
        return;
    }

    if (DecodeReg.m_bubble || (m_inst.DoubleWord == 0))
    {
        std::cout << "bubble" << std::endl;
        ExecuteReg.m_bubble = true;
        return;
    }

    switch (static_cast<InstOpCode>(m_inst.common.opcode))
    {
        case InstOpCode::REG    : execute_reg_inst()   ; break;
        case InstOpCode::IMM    : execute_imm_inst()   ; break;
        case InstOpCode::LUT    : execute_lut_inst()   ; break;
        case InstOpCode::BRANCH : execute_branch_inst(); break;
        case InstOpCode::STORE  : execute_store_inst() ; break;
        case InstOpCode::LOAD   : execute_load_inst()  ; break;
        case InstOpCode::SYSTEM : execute_system_inst(); break;
        case InstOpCode::AUIPC  : execute_auipc_inst() ; break;
        case InstOpCode::JAL    : execute_jal_inst()   ; break;
        case InstOpCode::JALR   : execute_jalr_inst()  ; break;
        case InstOpCode::IMM32  : execute_imm32_inst() ; break;
        case InstOpCode::OP32   : execute_op32_inst()  ; break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "UNKNOW OpCode !!!!!!!!!!!   "
                      << std::dec << std::setw(12) << std::setfill(' ')  << std::left << m_inst.common.opcode
                      << " INST: "
                      << std::dec << std::setw(12) << std::setfill(' ')  << std::left << m_inst.DoubleWord  << std::endl;
            break;
    };

    ExecuteRegNew.m_bubble = false;
    ExecuteRegNew.m_stall = false;
    ExecuteRegNew.m_inst = DecodeReg.m_inst;
    ExecuteRegNew.m_pc = DecodeReg.m_pc;
}
