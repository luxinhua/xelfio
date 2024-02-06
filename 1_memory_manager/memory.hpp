#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <array>
#include <iostream>
#include <memory>
#include <vector>
#include <cstdint>
#include <cstdbool>
#include <map>

#include "address.hpp"

using Page = std::array<uint8_t, 0x1000>;
using PageDir = std::map<uint32_t, Page>;
using Mem = std::map<uint32_t, PageDir>;

class Memory{
public:
    uint8_t readbyte(uint32_t addr);
    void writebyte(uint32_t addr, uint8_t data);
    void write64(uint32_t addr, uint64_t data);

    void dump();

private:
    bool existPage(Address addr);
    void allocPage(Address addr);

private:
    Mem m_mem;
};

#endif
