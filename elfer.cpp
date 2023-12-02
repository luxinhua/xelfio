#include "elfer.hpp"
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>


void Elfer::load(std::string file)
{
    std::cout << __func__ << " " << file << std::endl;

    dumpHex(file);
}


void Elfer::dumpHex(std::string file)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);
    if(!fread.is_open())
    {
        std::runtime_error("can not open");
    }

    uint16_t ch;
    uint32_t count{0U};

    while(!(fread.eof()))
    {
        if (!((count++) % 16))
        {
            std::cout << std::endl;
            std::cout << std::hex <<  std::setfill('0') << std::setw(4) << count-1 << " : ";
        }

        fread.read((char *)&ch, sizeof(ch));

        std::cout << std::hex <<  std::setfill('0') << std::setw(4) << static_cast<unsigned int>(ch) << " ";
    }

    fread.close();
}