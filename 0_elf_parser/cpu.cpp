#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::parser_branch_inst()
{
    switch (m_inst.S.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BEQ"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BNE"  ;     break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BLT"  ;     break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BGE"  ;     break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BLTU" ;     break;
        case 7:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "BGEU" ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "Branch";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.imm_4_0
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.imm_11_5 << std::endl;

}

void Core::parser_load_inst()
{
    switch (m_inst.I.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LB"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LH"  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LW"  ;     break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LBU" ;     break;
        case 5:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LHU" ;     break;
        case 6:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LWU" ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "LD" ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "load";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.imm_11_0 << std::endl;
}

void Core::parser_store_inst()
{
    switch (m_inst.S.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SB"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SH"  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SW"  ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SD"  ;     break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "store";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.imm_4_0
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.S.imm_11_5 << std::endl;
}

void Core::execute_addi(){
    // addi x3, x3, 0x678    // x3 + 0x678 --> x3  , x3 寄存器寻址
    m_core_registers[m_inst.I.rd].first = m_core_registers[m_inst.I.rs1].first + m_inst.I.imm_11_0;
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

void Core::parser_imm_inst()
{
    switch (m_inst.I.func3)
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

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.imm_11_0 << std::endl;
}

void Core::parser_reg_inst()
{
    switch (m_inst.R.func3)
    {
        case 0:
            if (m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADD " ;
            }
            else if (m_inst.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SUB " ;
            }
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLL "  ;     break;
        case 2:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLT "  ;     break;
        case 3:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLTU"  ;     break;
        case 4:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "XOR "  ;     break;
        case 5:
            if (m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRL " ;
            }
            else if (m_inst.R.func7 == 0x20)
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

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs2 << std::endl;
}

void Core::parser_fence_inst()
{

}

void Core::parser_system_inst()
{
    switch (m_inst.R.func3)
    {
        case 0:
            if (m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ECALL "  ;
            }
            else if(m_inst.R.func7 == 1)
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

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.imm_11_0 << std::endl;
}

void Core::parser_imm32_inst()
{
    switch (m_inst.R.func3)
    {
        case 0:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADDIW"  ;     break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SLLIW"  ;     break;
        case 5:
            if(m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRLIW"  ;
            }
            else if (m_inst.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRAIW"  ;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "IMM32";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.func7 << std::endl;

}

void Core::parser_op32_inst()
{
    switch (m_inst.R.func3)
    {
        case 0:
            if (m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "ADDW"  ;
            }
            else if(m_inst.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SUBW"  ;
            }
            break;
        case 1:    std::cout << std::setw(10) << std::left << std::setfill(' ') << "SLLW"  ;     break;
        case 5:
            if (m_inst.R.func7 == 0)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRLW"  ;
            }
            else if(m_inst.R.func7 == 0x20)
            {
                std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "SRAW"  ;
            }
            break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "OP32";
            break;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.rs2
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.R.func7 << std::endl;
}

void Core::parser_auipc_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "AUIPC"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.imm_31_12 << std::endl;

    execute_auipc();
}

void Core::execute_auipc()
{
    m_core_registers[m_inst.U.rd].first = m_pc + (m_inst.U.imm_31_12 << 12);
}

void Core::parser_jal_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "JAL"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.imm_31_12 << std::endl;
}

void Core::parser_jalr_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "JALR"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.rs1
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.I.imm_11_0 << std::endl;
}

void Core::parser_lut_inst()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "LUT"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.rd
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.U.imm_31_12 << std::endl;
}

void Core::fetch()
{
    std::cout << std::endl;
    std::cout << std::setw(3)  << std::left << std::setfill(' ')  << "PC:" << std::hex << m_pc << std::endl;
    std::cout << std::setw(80) << std::left << std::setfill('-') << "-" << std::endl;
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "Fetch   :";

    /** check pc align with byte. */
    if ((m_pc % 2) != 0)
    {
        std::runtime_error("illegal pc pointer !");
    }

    /** read pc m_inst */
    m_inst.DoubleWord = m_mem->read32(m_pc);
    std::cout << std::setw(10) << std::left << std::setfill(' ')  << "pc"
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_pc
              << std::setw(10) << std::left << std::setfill(' ') << std::hex << m_inst.DoubleWord << std::endl;

    m_fetch_bubble = false;
    m_fetch_stall = false;
}

void Core::execute()
{
    std::cout << std::setw(10) << std::left << std::setfill(' ') << "execute :";

    if (m_fetch_stall)
    {
        m_pc -= INST_LEN;
    }

    if (m_fetch_bubble || m_inst.DoubleWord == 0)
    {
        std::cout << "Get fetch bubble" << std::endl;
        return;
    }

    std::cout << std::setw(10) << std::left << std::setfill(' ') << m_inst.DoubleWord;

    switch (static_cast<InstOpCode>(m_inst.common.opcode))
    {
        case InstOpCode::REG    : parser_reg_inst()   ; break;
        case InstOpCode::IMM    : parser_imm_inst()   ; break;
        case InstOpCode::LUT    : parser_lut_inst()   ; break;
        case InstOpCode::BRANCH : parser_branch_inst(); break;
        case InstOpCode::STORE  : parser_store_inst() ; break;
        case InstOpCode::LOAD   : parser_load_inst()  ; break;
        case InstOpCode::SYSTEM : parser_system_inst(); break;
        case InstOpCode::AUIPC  : parser_auipc_inst() ; break;
        case InstOpCode::JAL    : parser_jal_inst()   ; break;
        case InstOpCode::JALR   : parser_jalr_inst()  ; break;
        case InstOpCode::IMM32  : parser_imm32_inst() ; break;
        case InstOpCode::OP32   : parser_op32_inst()  ; break;
        default:
            std::cout << std::setw(10) << std::left << std::setfill(' ') <<   "UNKNOW OpCode !!!!!!!!!!!   "  << FORMAT << m_inst.common.opcode
                    << " INST: " << FORMAT << m_inst.DoubleWord  << std::endl;
            break;
    };

    m_pc += INST_LEN;
}

void Core::print_core_registers()
{
    uint32_t line_cout{0};

    std::cout << std::setw(80) << std::left << std::setfill('-') << "-";

    for (auto& reg : m_core_registers)
    {
        if ((line_cout++ % 5) == 0)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(6) << std::left << std::setfill(' ') << reg.second.second
                  << ":"
                  << std::setw(10) << std::left << std::setfill(' ') << reg.second.first ;
    };

    std::cout << std::endl;
    std::cout << std::setw(80) << std::left << std::setfill('-') << "-" << std::endl;
}

int main(int argc, char **argv)
{
    Memory mem;

    Stack  stack{0x80000000, 0x400000};

    Elfer elf{"./demo/helloworld.out"};

    elf.loadSegment2Mem(&mem);

    // elf.dump();

    uint32_t elf_entry = static_cast<uint32_t>(elf.get_entry());

    Core   core{&mem, stack, elf_entry};

    mem.dump();

    uint32_t times{5};
    while (times--) {
        core.fetch();
        core.execute();
        core.print_core_registers();
    };

    return 0;
}




