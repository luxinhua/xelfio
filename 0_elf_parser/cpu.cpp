#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::fetch()
{
    /** check pc align with byte. */
    if ((m_pc % 2) != 0)
    {
        std::runtime_error("illegal pc pointer !");
    }

    /** read pc inst */
    m_inst.DoubleWord = m_mem->read32(m_pc);
    std::cout << "fetch " << "address " << m_pc << "  " << std::hex << m_mem->read32(m_pc)  << std::endl;

    /** set pc to next */
    m_pc += INST_LEN;
}

void Core::decode()
{
    parse_inst(m_inst.DoubleWord);
    std::cout << "decode " << std::endl;
}

void Core::execute()
{
    std::cout << "execute " << std::endl;
}

void Core::writeBackMem()
{
    std::cout << "writeBackMem " << std::endl;
}

int main(int argc, char **argv)
{
    Memory mem;

    Stack  stack;

    Elfer elf{"./demo/helloworld.out"};

    elf.loadSegment2Mem(&mem);

    elf.dump();

    uint32_t elf_entry = static_cast<uint32_t>(elf.get_entry());

    Core   core{&mem, stack, elf_entry};

    mem.dump();

    core.fetch();
    core.decode();
    core.execute();
    core.writeBackMem();

    return 0;
}




