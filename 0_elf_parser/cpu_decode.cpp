#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::decode_branch_inst()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | (m_inst.rv32i.SB.imm_10_5 << 5) | \
                        (m_inst.rv32i.SB.imm_11 << 11) | (m_inst.rv32i.SB.imm_12 << 12) ) << 19 ) >> 19;

    switch (m_inst.rv32i.S.func3)
    {
        case 0:    m_inst.opName = "beq"  ; decode_beq()  ;  break;
        case 1:    m_inst.opName = "bne"  ; decode_bne()  ;  break;
        case 4:    m_inst.opName = "blt"  ; decode_blt()  ;  break;
        case 5:    m_inst.opName = "bge"  ; decode_bge()  ;  break;
        case 6:    m_inst.opName = "bltu" ; decode_bltu() ;  break;
        case 7:    m_inst.opName = "bgeu" ; decode_bgeu() ;  break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "Branch";
            break;
    }
}

void Core::decode_load_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;

    switch (m_inst.rv32i.I.func3)
    {
        case 0:   m_inst.opName = "lb"  ; decode_lb() ; break;
        case 1:   m_inst.opName = "lh"  ; decode_lh() ; break;
        case 2:   m_inst.opName = "lw"  ; decode_lw() ; break;
        case 3:   m_inst.opName = "ld"  ; decode_ld() ; break;
        case 4:   m_inst.opName = "lbu" ; decode_lbu(); break;
        case 5:   m_inst.opName = "lhu" ; decode_lhu(); break;
        case 6:   m_inst.opName = "lwu" ; decode_lwu(); break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "load";
            break;
    }
}

void Core::decode_store_inst()
{
    m_inst.imm = int32_t((m_inst.rv32i.S.imm_4_0 | (m_inst.rv32i.S.imm_11_5 << 5)) << 20) >> 20;

    switch (m_inst.rv32i.S.func3)
    {
        case 0:  m_inst.opName = "sb"  ;  decode_sb();   break;
        case 1:  m_inst.opName = "sh"  ;  decode_sh();   break;
        case 2:  m_inst.opName = "sw"  ;  decode_sw();   break;
        case 3:  m_inst.opName = "sd"  ;  decode_sd();   break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "store";
            break;
    }
}

void Core::decode_imm_inst()
{
    m_inst.imm = int32_t(m_inst.rv32i.I.imm_11_0 << 20) >> 20;

    switch (m_inst.rv32i.I.func3)
    {
        case 0:  m_inst.opName = "addi"     ; decode_addi();  break;
        case 2:  m_inst.opName = "slti"     ; decode_slti();  break;
        case 3:  m_inst.opName = "sltu"     ; decode_sltu();  break;
        case 4:  m_inst.opName = "xori"     ; decode_xori();  break;
        case 6:  m_inst.opName = "ori"      ; decode_ori();   break;
        case 7:  m_inst.opName = "andi"     ; decode_andi();  break;
        case 1:  m_inst.opName = "slli"     ; decode_slli();  break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0   :  m_inst.opName = "srli"  ; decode_srli();  break;
                case 0x20:  m_inst.opName = "srai"  ; decode_srai();  break;
                default:
                    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "imm";
                    break;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM";
            break;
    }
}

void Core::decode_reg_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "ADD " ; break;
                case 0x20 : m_inst.opName = "SUB " ; decode_sub(); break;
            }
            break;
        case 1:   m_inst.opName = "SLL "  ;  break;
        case 2:   m_inst.opName = "SLT "  ;  break;
        case 3:   m_inst.opName = "SLTU"  ;  break;
        case 4:   m_inst.opName = "XOR "  ;  break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "SRL " ; break;
                case 0x20 : m_inst.opName = "SRA " ; break;
            }
            break;
        case 6:  m_inst.opName = "OR  "  ;  break;
        case 7:  m_inst.opName = "AND "  ;  break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "REG";
            break;
    }
}

void Core::decode_fence_inst()
{

}

void Core::decode_system_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            switch (m_inst.rv32i.R.func7) {
                case 0 : m_inst.opName = "ecall"  ; break;
                case 1 : m_inst.opName = "ebreak" ; break;
            }
            break;
        case 1:  m_inst.opName = "csrrw"   ;     break;
        case 2:  m_inst.opName = "csrrs"   ;     break;
        case 3:  m_inst.opName = "csrrc"   ;     break;
        case 5:  m_inst.opName = "csrrsw"  ;     break;
        case 6:  m_inst.opName = "csrrsi"  ;     break;
        case 7:  m_inst.opName = "csrrci"  ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SYSTEM";
            break;
    }
}

void Core::decode_imm32_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:  m_inst.opName = "addiw"  ;     break;
        case 1:  m_inst.opName = "slltw"  ;     break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "srliw"  ; break;
                case 0x20 : m_inst.opName = "sraiw"  ; break;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM32";
            break;
    }
}

void Core::decode_op32_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "addw"  ; break;
                case 0x20 : m_inst.opName = "subw"  ; break;
            }
            break;
        case 1:    m_inst.opName = "sllw"  ; break;
        case 5:
           switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "srlw"  ; break;
                case 0x20 : m_inst.opName = "sraw"  ; break;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "OP32";
            break;
    }
}

void Core::decode_auipc_inst()
{
    m_inst.opName = "auiipc";

    decode_auipc();
}

void Core::decode_jal_inst()
{
    m_inst.opName = "jal";

    decode_jal();
}

void Core::decode_jalr_inst()
{
    m_inst.opName = "jalr";
}

void Core::decode_lut_inst()
{
    m_inst.opName = "lut";
}

void Core::decode_sb(){

}
void Core::decode_sh(){

}
void Core::decode_sw(){

}
void Core::decode_sd(){

}
void Core::decode_beq()
{

}
void Core::decode_bne()
{

}
void Core::decode_blt()
{

}
void Core::decode_bge()
{

}
void Core::decode_bltu()
{

}
void Core::decode_bgeu()
{

}
void Core::decode_lb()
{

}
void Core::decode_lh()
{

}
void Core::decode_lw()
{

}
void Core::decode_lbu()
{

}
void Core::decode_lhu()
{

}
void Core::decode_lwu()
{

}
void Core::decode_ld()
{

}
void Core::decode_addi(){
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.I.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.I.rs1].second
              << ", "
              << std::hex << m_inst.imm;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second
              << " + "
              << std::hex << m_inst.imm;
}
void Core::decode_slti(){

}
void Core::decode_sltu(){

}
void Core::decode_xori(){

}
void Core::decode_ori(){

}
void Core::decode_andi(){

}
void Core::decode_slli(){

}
void Core::decode_srli(){

}
void Core::decode_srai(){

}
void Core::decode_sub()
{

}
void Core::decode_auipc()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.U.rd].second
              << ", "
              << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.U.rd].second
              << "= pc + "
              << std::hex << m_inst.imm;
}
void Core::decode_jal()
{

}


void Core::decode()
{
    std::cout << std::setw(8) << std::left << std::setfill(' ') << "Decoded" << ":";

    m_inst = FetchReg.m_inst;
    // m_pc = FetchReg.m_pc;

    std::cout << std::setw(13) << std::left << std::setfill(' ') << "instruction" ;
    std::cout << std::setw(10) << std::left << std::setfill(' ') << m_inst.DoubleWord;
    std::cout << std::setw(12) << std::left << std::setfill(' ') << "at address" ;
    std::cout << std::setw(10) << std::left << std::setfill(' ') << FetchReg.m_pc ;
    std::cout << " : ";

    if (FetchReg.m_stall)
    {
        FetchReg.m_pc -= INST_LEN;
        return ;
    }

    if ((FetchReg.m_bubble) || m_inst.DoubleWord == 0)
    {
        std::cout << "bubble" << std::endl;
        DecodeReg.m_bubble = true;
        return ;
    }

    switch (static_cast<InstOpCode>(m_inst.common.opcode))
    {
        case InstOpCode::REG    : decode_reg_inst()   ; break;
        case InstOpCode::IMM    : decode_imm_inst()   ; break;
        case InstOpCode::LUT    : decode_lut_inst()   ; break;
        case InstOpCode::BRANCH : decode_branch_inst(); break;
        case InstOpCode::STORE  : decode_store_inst() ; break;
        case InstOpCode::LOAD   : decode_load_inst()  ; break;
        case InstOpCode::SYSTEM : decode_system_inst(); break;
        case InstOpCode::AUIPC  : decode_auipc_inst() ; break;
        case InstOpCode::JAL    : decode_jal_inst()   ; break;
        case InstOpCode::JALR   : decode_jalr_inst()  ; break;
        case InstOpCode::IMM32  : decode_imm32_inst() ; break;
        case InstOpCode::OP32   : decode_op32_inst()  ; break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "UNKNOW OpCode !!!!!!!!!!!   "
                      << std::dec << std::setw(12) << std::setfill(' ')  << std::left << m_inst.common.opcode
                      << " INST: "
                      << std::dec << std::setw(12) << std::setfill(' ')  << std::left << m_inst.DoubleWord  << std::endl;
            break;
    };

    std::cout << std::endl;

    DecodeRegNew.m_bubble = false;
    DecodeRegNew.m_stall = false;
    DecodeRegNew.m_inst = FetchReg.m_inst;
    DecodeRegNew.m_pc = FetchReg.m_pc;

}
