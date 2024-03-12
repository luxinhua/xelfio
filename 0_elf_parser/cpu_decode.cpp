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

void Core::decode_add()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " + "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
}
void Core::decode_sll()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " << "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // logical shift left ";
}
void Core::decode_slt()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << " int32_t " << m_core_registers[m_inst.rv32i.R.rs1].second
              << " < "
              << " int32_t " << m_core_registers[m_inst.rv32i.R.rs2].second
              << " ? "
              << m_core_registers[m_inst.rv32i.R.rd].second << "=1 "
              << ": "
              << m_core_registers[m_inst.rv32i.R.rd].second << "=0 ";
}
void Core::decode_sltu()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << " uint32_t " << m_core_registers[m_inst.rv32i.R.rs1].second
              << " < "
              << " uint32_t " << m_core_registers[m_inst.rv32i.R.rs2].second
              << " ? "
              << m_core_registers[m_inst.rv32i.R.rd].second << "=1 "
              << ": "
              << m_core_registers[m_inst.rv32i.R.rd].second << "=0 ";
}
void Core::decode_xor()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " ^ "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // arithmetic or ";
}
void Core::decode_srl()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " >> "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // logical shift right ";
}
void Core::decode_sra()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " >> "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // arithmetic shift left";
}
void Core::decode_or()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " | "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // logical or ";
}
void Core::decode_and()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " | "
              << m_core_registers[m_inst.rv32i.R.rs2].second << " // logical and ";
}

void Core::decode_reg_inst()
{
    switch (m_inst.rv32i.R.func3)
    {
        case 0:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "ADD " ; decode_add(); break;
                case 0x20 : m_inst.opName = "SUB " ; decode_sub(); break;
            }
            break;
        case 1:   m_inst.opName = "SLL "  ; decode_sll();  break;
        case 2:   m_inst.opName = "SLT "  ; decode_slt();  break;
        case 3:   m_inst.opName = "SLTU"  ; decode_sltu(); break;
        case 4:   m_inst.opName = "XOR "  ; decode_xor();  break;
        case 5:
            switch (m_inst.rv32i.R.func7) {
                case 0    : m_inst.opName = "SRL " ; decode_srl();  break;
                case 0x20 : m_inst.opName = "SRA " ; decode_sra(); break;
            }
            break;
        case 6:  m_inst.opName = "OR  "  ; decode_or();  break;
        case 7:  m_inst.opName = "AND "  ; decode_and(); break;
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

void Core::decode_jal()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.I.rd].second
              << ", offset("
              << std::hex << m_inst.imm << ")"; // offset range + - 1MB
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.UJ.rd].second << " = pc + 4 ; "
              << "pc = pc + " << std::hex << m_inst.imm;
}

void Core::decode_jal_inst()
{
    m_inst.opName = "jal";

    m_inst.imm = int32_t(m_inst.rv32i.UJ.imm_10_1 | (m_inst.rv32i.UJ.imm_11 << 11) | \
                         (m_inst.rv32i.UJ.imm_19_12 << 12) | (m_inst.rv32i.UJ.imm_20 << 20) << 12) >> 11;

    decode_jal();
}

void Core::decode_jalr()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.I.rd].second
              << ", label("
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = pc + 4 ; "
              << "pc = " + m_core_registers[m_inst.rv32i.I.rs1].second << " + " << std::hex << m_inst.imm;
}

void Core::decode_jalr_inst()
{
    m_inst.opName = "jalr";

    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20) >> 20;

    decode_jalr();
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
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "int32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " == "
              << "int32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_bne()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "int32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " != "
              << "int32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_blt()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "int32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " < "
              << "int32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_bge()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "int32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " > "
              << "int32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_bltu()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "uint32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " < "
              << "uint32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_bgeu()
{
    m_inst.imm = int32_t(( (m_inst.rv32i.SB.imm_4_1) | \
                                (m_inst.rv32i.SB.imm_10_5 << 5) | \
                                (m_inst.rv32i.SB.imm_11 << 11) | \
                                (m_inst.rv32i.SB.imm_12 << 12) ) << 19) >> 19;

    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.SB.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.SB.rs2].second
              << ", "
              << std::hex << m_inst.imm << ")";
    std::cout << " //// ";
    std::cout << "uint32 " << m_core_registers[m_inst.rv32i.SB.rs1].second
              << " > "
              << "uint32 " << m_core_registers[m_inst.rv32i.SB.rs2].second
              << " ? "
              << "pc = pc + " << std::hex << m_inst.imm;
}
void Core::decode_lb()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 8 bit data, int extend";

}
void Core::decode_lh()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 16 bit data and int extend";
}
void Core::decode_lw()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 32 bit data and int extend";
}
void Core::decode_lbu()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 16 bit data and int extend";
}
void Core::decode_lhu()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 16 bit data and uint extend";
}
void Core::decode_lwu()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 32 bit data and uint extend";
}
void Core::decode_ld()
{
    m_inst.imm = int32_t( m_inst.rv32i.I.imm_11_0 << 20 ) >> 20;

    std::cout << m_inst.opName
            << " "
            << m_core_registers[m_inst.rv32i.I.rd].second
            << ", "
            << m_core_registers[m_inst.rv32i.I.rs1].second
            << ", "
            << std::hex << m_inst.imm;
    std::cout << " //// ";
    std::cout << m_core_registers[m_inst.rv32i.I.rd].second << " = "
              << m_core_registers[m_inst.rv32i.I.rs1].second << " = " << std::hex << m_inst.imm << "; // get 32 bit data and int extend";
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
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.I.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.I.rs1].second
              << ", "
              << std::hex << m_inst.imm;
    std::cout << " //// " ;
    std::cout << " int32_t " << m_core_registers[m_inst.rv32i.I.rs1].second
              << " < "
              << " int32_t " << std::hex << m_inst.imm
              << " ? "
              << m_core_registers[m_inst.rv32i.I.rd].second << "=1 "
              << ": "
              << m_core_registers[m_inst.rv32i.I.rd].second << "=0 ";
}
void Core::decode_sltiu(){
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.I.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.I.rs1].second
              << ", "
              << std::hex << m_inst.imm;
    std::cout << " //// " ;
    std::cout << " uint32_t " << m_core_registers[m_inst.rv32i.I.rs1].second
              << " < "
              << " uint32_t " << std::hex << m_inst.imm
              << " ? "
              << m_core_registers[m_inst.rv32i.I.rd].second << "=1 "
              << ": "
              << m_core_registers[m_inst.rv32i.I.rd].second << "=0 ";
}
void Core::decode_xori(){
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
              << " | "
              << std::hex << m_inst.imm << " // arithmetic or";
}
void Core::decode_ori(){
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
              << " | "
              << std::hex << m_inst.imm << " // logical or";
}
void Core::decode_andi(){
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
              << " & "
              << std::hex << m_inst.imm << " // logical and";
}
void Core::decode_slli(){
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
              << " << "
              << std::hex << m_inst.imm << " // logical shift left ";
}
void Core::decode_srli(){
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
              << " >> "
              << std::hex << m_inst.imm << " // logical right left ";
}
void Core::decode_srai(){
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
              << " >> "
              << std::hex << m_inst.imm << " // arithmetic right left ";
}
void Core::decode_sub()
{
    std::cout << m_inst.opName
              << " "
              << m_core_registers[m_inst.rv32i.R.rd].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << ", "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
    std::cout << " //// " ;
    std::cout << m_core_registers[m_inst.rv32i.R.rd].second
              << " = "
              << m_core_registers[m_inst.rv32i.R.rs1].second
              << " - "
              << m_core_registers[m_inst.rv32i.R.rs2].second;
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
              << " = pc + "
              << std::hex << m_inst.imm;
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
