#include "elfer.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    Elfer elf{"test"};


    elf.load();

    elf.loadSegment2Mem();

    elf.dump();

    return 0;
}
