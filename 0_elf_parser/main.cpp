#include "elfer.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    // Elfer elf{"./demo/helloworld.out"};
    Elfer elf{"./demo/helloworld.out"};

    elf.load();

    elf.loadSegment2Mem();

    elf.dump();

    return 0;
}
