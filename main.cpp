#include "elfer.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Elfer elf;

     elf.load("./a.out");

    return 0;
}