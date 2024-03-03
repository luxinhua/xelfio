#include "cpu.hpp"

using namespace std;

void Core::fetch()
{
    std::cout << "fetch " << std::endl;
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
    Core   core{mem, stack};

    core.fetch();
    core.decode();
    core.execute();
    core.writeBackMem();

    return 0;
}




