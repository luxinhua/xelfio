#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::fetch()
{
    std::cout << "fetch " << "address " << m_pc << "  " << std::hex << m_mem->read32(m_pc)  << std::endl;
}

void Core::decode()
{
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




