#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::print_core_registers()
{
    uint32_t line_cout{0};

    std::cout << std::setw(100) << std::left << std::setfill('-') << "-";

    for (auto& reg : m_core_registers)
    {
        if ((line_cout++ % 6) == 0)
        {
            std::cout << std::endl;
        }
        std::cout << std::setw(6) << std::left << std::setfill(' ') << reg.second
                  << ":"
                  << std::setw(10) << std::left << std::setfill(' ') << std::hex << reg.first ;
    };

    std::cout << std::endl;
    std::cout << std::setw(100) << std::left << std::setfill('-') << "-" << std::endl;
}

void Core::movePipe()
{
    FetchReg = FetchRegNew;
    DecodeReg = DecodeRegNew;
    ExecuteReg = ExecuteRegNew;
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

    // mem.dump();

    uint32_t times{100};
    while (times--) {
        core.fetch();
        core.decode();
        core.execute();
        core.print_core_registers();
        core.movePipe();
    };

    return 0;
}




