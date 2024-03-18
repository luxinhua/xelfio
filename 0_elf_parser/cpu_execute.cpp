#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

// 1	R 型指令	用于寄存器和寄存器操作
// 2	I 型指令	用于短立即数和内存载入指令load操作
// 3	S 型指令	用于内存存储store操作
// 4	B 型指令	用于有条件跳转操作
// 5	U 型指令	用于长立即数操作
// 6	J 型指令	用于无条件跳转操作

void Core::execute_beq()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;
    std::cout << "beq "
              << " rs1 " << rs1
              << " rs2 " << rs2 << std::endl;
    if (int32_t(rs1) == int32_t(rs2))
    {
        m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
        // FetchRegNew.m_stall = true;
        // DecodeRegNew.m_stall = true;
    }
}
void Core::execute_bne()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (int32_t(rs1) != int32_t(rs2))
    {
        m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
    }
}
void Core::execute_blt()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (int32_t(rs1) < int32_t(rs2))
    {
        m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
    }
}
void Core::execute_bge()
{
    int32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    int32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (int32_t(rs1) > int32_t(rs2))
    {
        DecodeReg.m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
    }
}
void Core::execute_bltu()
{
    uint32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    uint32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    std::cout << FetchReg.m_pc   << std::endl;
    std::cout << DecodeReg.m_pc  << std::endl;
    std::cout << ExecuteReg.m_pc << std::endl;

    if (uint32_t(rs1) < uint32_t(rs2))
    {
        DecodeReg.m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
    }
}
void Core::execute_bgeu()
{
    uint32_t rs1 = m_core_registers[m_inst.rv32i.SB.rs1].first;
    uint32_t rs2 = m_core_registers[m_inst.rv32i.SB.rs2].first;

    if (uint32_t(rs1) > uint32_t(rs2))
    {
        DecodeReg.m_pc = DecodeReg.m_pc + m_inst.imm;
        FetchRegNew.m_bubble = true;
        DecodeRegNew.m_bubble = true;
    }
}
void Core::execute_branch_inst()
{
    m_inst.imm = int32_t((m_inst.rv32i.SB.imm_4_1 | (m_inst.rv32i.SB.imm_10_5 << 4) |
                         (m_inst.rv32i.SB.imm_11 << 10) | (m_inst.rv32i.SB.imm_12 << 11))) << 20 >> 19;

    switch (m_inst.rv32i.S.func3)
    {
        case 0:  execute_beq()  ;  break;
        case 1:  execute_bne()  ;  break;
        case 4:  execute_blt()  ;  break;
        case 5:  execute_bge()  ;  break;
        case 6:  execute_bltu() ;  break;
        case 7:  execute_bgeu() ;  break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "Branch";
            break;
    }

    std::cout << endl;
}

void Core::execute_load_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0) << 20 >> 20;
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

void Core::execute_sb()
{
    auto address = m_core_registers[m_inst.rv32i.S.rs1].first + m_inst.imm;
    uint8_t data = m_core_registers[m_inst.rv32i.S.rs2].first;

    std::cout << "xhlu " << std::hex << "addr " << address << "  data " << data  <<  std::endl;
    std::cout << "imm " << m_inst.imm << std::endl;
    std::cout << "rs1 " << std::hex << m_core_registers[m_inst.rv32i.S.rs1].first << std::endl;
    std::cout << "rs2 " << std::hex << m_core_registers[m_inst.rv32i.S.rs2].first << std::endl;

    m_mem->write8(address, data);
}
void Core::execute_sh()
{
    auto address = m_core_registers[m_inst.rv32i.S.rs1].first + m_inst.imm;
    uint16_t data = m_core_registers[m_inst.rv32i.S.rs2].first;

    std::cout << "xhlu " << std::hex << "addr " << address << "  data " << data  <<  std::endl;
    std::cout << "imm " << m_inst.imm << std::endl;
    std::cout << "rs1 " << std::hex << m_core_registers[m_inst.rv32i.S.rs1].first << std::endl;
    std::cout << "rs2 " << std::hex << m_core_registers[m_inst.rv32i.S.rs2].first << std::endl;

    m_mem->write16(address, data);
}
void Core::execute_sw()
{
    auto address = m_core_registers[m_inst.rv32i.S.rs1].first + m_inst.imm;
    uint32_t data = m_core_registers[m_inst.rv32i.S.rs2].first;

    std::cout << "xhlu " << std::hex << "addr " << address << "  data " << data  <<  std::endl;
    std::cout << "imm " << m_inst.imm << std::endl;
    std::cout << "rs1 " << std::hex << m_core_registers[m_inst.rv32i.S.rs1].first << std::endl;
    std::cout << "rs2 " << std::hex << m_core_registers[m_inst.rv32i.S.rs2].first << std::endl;

    m_mem->write32(address, data);
}
void Core::execute_sd()
{
    auto address = m_core_registers[m_inst.rv32i.S.rs1].first + m_inst.imm;
    uint64_t data = m_core_registers[m_inst.rv32i.S.rs2].first;

    std::cout << "xhlu " << std::hex << "addr " << address << "  data " << data  <<  std::endl;
    std::cout << "imm " << m_inst.imm << std::endl;
    std::cout << "rs1 " << std::hex << m_core_registers[m_inst.rv32i.S.rs1].first << std::endl;
    std::cout << "rs2 " << std::hex << m_core_registers[m_inst.rv32i.S.rs2].first << std::endl;

    m_mem->write64(address, data);
    // m_mem->dump();
}

void Core::execute_store_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.S.imm_4_0 |(m_inst.rv32i.S.imm_11_5 << 5)) << 20 >> 20;

    switch (m_inst.rv32i.S.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "sb"  ;  execute_sb();   break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "sh"  ;  execute_sh();   break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "sw"  ;  execute_sw();   break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "sd"  ;  execute_sd();   break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "store";
            break;
    }
}
void Core::execute_addi(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (rs1 + m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_slti(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    auto data =  int32_t(rs1) < int32_t(m_inst.imm) ? 1 : 0;
    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_sltiu(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    auto data =  uint32_t(rs1) < uint32_t(m_inst.imm) ? 1 : 0;
    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_xori(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (rs1 ^ m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_ori(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (rs1 | m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_andi(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (rs1 & m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_slli(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (uint32_t(rs1) << m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_srli()
{
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (uint32_t(rs1) >> m_inst.imm) & 0xFFFFFFFF;
}
void Core::execute_srai(){
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = (int32_t(rs1) >> m_inst.imm) & 0xFFFFFFFF;
}

void Core::execute_imm_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0) << 20 >> 20;

    switch (m_inst.rv32i.I.func3)
    {
        case 0:  execute_addi();  break;
        case 1:  execute_slli();  break;
        case 2:  execute_slti();  break;
        case 3:  execute_sltu();  break;
        case 4:  execute_xori();  break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0   :  m_inst.opName = "srli"  ; execute_srli();  break;
                case 0x20:  m_inst.opName = "srai"  ; execute_srai();  break;
                default:
                    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "imm";
                    break;
            }
            break;
        case 6:  execute_ori();   break;
        case 7:  execute_andi();  break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.I.imm_11_0 << std::endl;
}
void Core::execute_add()
{
    auto rs1 = m_core_registers[m_inst.rv32i.R.rs1].first;
    auto rs2 = m_core_registers[m_inst.rv32i.R.rs2].first;

    m_core_registers[m_inst.rv32i.R.rd].first = (rs1 + rs2) & 0xFFFFFFFF;
}
void Core::execute_sub()
{
    auto rs1 = m_core_registers[m_inst.rv32i.R.rs1].first;
    auto rs2 = m_core_registers[m_inst.rv32i.R.rs2].first;

    m_core_registers[m_inst.rv32i.R.rd].first = (rs1 - rs2) & 0xFFFFFFFF;
}
void Core::execute_sll ()
{
    auto rs1 = m_core_registers[m_inst.rv32i.R.rs1].first;
    auto rs2 = m_core_registers[m_inst.rv32i.R.rs2].first;

    m_core_registers[m_inst.rv32i.R.rd].first = (rs1 << rs2) & 0xFFFFFFFF;
}
void Core::execute_xor ()
{
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " ^ "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // arithmetic or ";
}
void Core::execute_slt ()
{
    auto rs1 = int32_t(m_core_registers[m_inst.rv32i.R.rs1].first);
    auto rs2 = int32_t(m_core_registers[m_inst.rv32i.R.rs2].first);

    m_core_registers[m_inst.rv32i.R.rd].first = rs1 < rs2 ? 1 : 0;
}
void Core::execute_sltu(){
    auto rs1 = uint32_t(m_core_registers[m_inst.rv32i.R.rs1].first);
    auto rs2 = uint32_t(m_core_registers[m_inst.rv32i.R.rs2].first);

    m_core_registers[m_inst.rv32i.R.rd].first = rs1 < rs2 ? 1 : 0;
}
void Core::execute_reg_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "ADD " ; execute_add();  break;
                case 0x20 : m_inst.opName = "SUB " ; execute_sub();  break;
            }
            break;
        case 1:  execute_sll ();  break;
        case 2:  execute_slt ();  break;
        case 3:  execute_sltu(); break;
        case 4:  execute_xor ();  break;
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
void Core::execute_addiw()
{
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = int64_t(rs1 + m_inst.imm);
}
void Core::execute_slliw()
{
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = int64_t(uint32_t(rs1) << m_inst.imm);
}
void Core::execute_srliw()
{
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = int64_t(uint32_t(rs1) >> m_inst.imm);
}
void Core::execute_sraiw()
{
    auto rs1 = m_core_registers[m_inst.rv32i.I.rs1].first;
    m_core_registers[m_inst.rv32i.I.rd].first = int64_t(int32_t(rs1) >> m_inst.imm);
}

void Core::execute_imm32_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;

    switch (m_inst.rv32i.R.func3)
    {
        case 0:  execute_addiw();   break;
        case 1:  execute_slliw();   break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0   :  execute_srliw();  break;
                case 0x20:  execute_sraiw();  break;
                default:
                    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "imm";
                    break;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM32";
            break;
    }
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
    execute_jal();
}

void Core::execute_jalr_inst()
{
    std::cout << std::endl;

    m_core_registers[m_inst.rv32i.I.rd].first = (DecodeReg.m_pc + 4) & 0xFFFFFFFF;

    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0) << 20 >> 20;

    m_pc = (m_core_registers[m_inst.rv32i.I.rs1].first  + m_inst.imm) & (~(uint64_t)1);

    FetchRegNew.m_bubble = true;
    DecodeRegNew.m_bubble = true;
}

void Core::execute_lut_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "LUI"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.rv32i.U.imm_31_12 << std::endl;

    m_inst.imm = int32_t(m_inst.rv32i.U.imm_31_12);

    m_core_registers[m_inst.rv32i.U.rd].first = int32_t(m_inst.imm) << 12;

}
void Core::execute_lb()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read8(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_lh()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read16(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_lw()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read32(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_lbu()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read8(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_lhu()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read16(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_lwu()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read32(address);

    m_core_registers[m_inst.rv32i.I.rd].first = data & 0xFFFFFFFF;
}
void Core::execute_ld()
{
    auto address = m_core_registers[m_inst.rv32i.I.rs1].first + m_inst.imm;
    auto data = m_mem->read64(address);

    std::cout << "xhlu " << std::hex << address << "  " << m_inst.imm << " " << std::hex << m_core_registers[m_inst.rv32i.I.rs1].first << std::endl;

    m_core_registers[m_inst.rv32i.I.rd].first = data;
}
void Core::execute_auipc()
{
    auto offset = int32_t(m_inst.rv32i.U.imm_31_12 << 12);

    m_core_registers[m_inst.rv32i.U.rd].first = (DecodeReg.m_pc + offset) & 0xFFFFFFFF;
}

void Core::execute_jal()
{
    std::cout << std::endl;

    m_core_registers[m_inst.rv32i.UJ.rd].first = (DecodeReg.m_pc + 4) & 0xFFFFFFFF;

    auto offset = int32_t((m_inst.rv32i.UJ.imm_10_1 ) | (m_inst.rv32i.UJ.imm_11 << 10) | \
                         (m_inst.rv32i.UJ.imm_19_12 << 11) | (m_inst.rv32i.UJ.imm_20 << 19)) << 12 >> 11;

    m_pc = DecodeReg.m_pc + offset;
    FetchRegNew.m_bubble = true;
    DecodeRegNew.m_bubble = true;
}

void Core::execute()
{
    m_inst = DecodeReg.m_inst;

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

    std::cout << std::setw(8) << std::left << std::setfill(' ') << "Execute" << ":";
    std::cout << std::setw(8) << std::right << std::setfill(' ') << DecodeReg.m_pc;
    std::cout << std::setw(13) << std::right << std::setfill(' ') << " instruction ";
    std::cout << std::setw(8) << std::right << std::setfill(' ') << m_inst.DoubleWord;
    std::cout << " : ";

    switch (static_cast<InstOpCode>(m_inst.common.opcode))
    {
        case InstOpCode::REG    : execute_reg_inst()   ; break;
        case InstOpCode::IMM    : execute_imm_inst()   ; break;
        case InstOpCode::LUI    : execute_lut_inst()   ; break;
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



int64_t Core::do_Syscall(int64_t op1, int64_t op2) {
  int64_t type = op2; // reg a7
  int64_t arg1 = op1; // reg a0

  switch (type) {
    case 0:
        { // print string
            uint32_t addr = arg1;
            char ch = m_mem->read8(addr);
            while (ch != '\0') {
            printf("%c", ch);
            ch = m_mem->read8(++addr);
        }
        break;
    }
    case 1: // print char
        printf("%c", (char)arg1);
        break;
    case 2: // print num
        printf("%d", (int32_t)arg1);
        break;
    case 3:
    case 93: // exit
        std::cout << "Program exit from an exit() system call" << std::endl;
        exit(0);
    case 4: // read char
        // scanf(" %c", (char*)&op1);
        std::cin >> op1;
        break;
    case 5: // read num
        // scanf(" %lld", (int64_t*)&op1);
        std::cin >> op1;
        break;
    default:
        throw std::runtime_error("Unknown syscall\n");
  }

  return op1;
}
