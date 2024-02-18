
#include "isa_parser.hpp"


int main(int argc, char const *argv[])
{
    Instruction inst;
    inst.DoubleWord = 0x022000ef;

    std::cout << std::hex << inst.common.opcode << std::endl;

    switch (static_cast<InstOpCode>(inst.common.opcode))
    {
    case InstOpCode::REG    :
        std::cout <<  "REG    "  << std::endl;
        break;
    case InstOpCode::IMM    :
        std::cout <<  "IMM    "  << std::endl;
        break;
    case InstOpCode::LUT    :
        std::cout <<  "LUT    "  << std::endl;
        break;
    case InstOpCode::BRANCH :
        std::cout <<  "BRANCH "  << std::endl;
        break;
    case InstOpCode::STORE  :
        std::cout <<  "STORE  "  << std::endl;
        break;
    case InstOpCode::LOAD   :
        std::cout <<  "LOAD   "  << std::endl;
        break;
    case InstOpCode::SYSTEM :
        std::cout <<  "SYSTEM "  << std::endl;
        break;
    case InstOpCode::AUIPC  :
        std::cout <<  "AUIPC  "  << std::endl;
        break;
    case InstOpCode::JAL    :
        std::cout <<  "JAL    "  << std::endl;
        break;
    case InstOpCode::JALR   :
        std::cout <<  "JALR   "  << std::endl;
        break;
    case InstOpCode::IMM32  :
        std::cout <<  "IMM32  "  << std::endl;
        break;
    case InstOpCode::OP32   :
        std::cout <<  "OP32   "  << std::endl;
        break;
    default:
        break;
    };

    return 0;
}
