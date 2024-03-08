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

enum class MemType : uint8_t
{
    UnAlloc,
    Allocated
};

class MemCell{
public:
    uint8_t data;
    MemType status;
};

class Memory{
public:
    using Page = std::array<MemCell, 0x1000>;
    using PageDir = std::map<uint32_t, Page>;
    using Mem = std::map<uint32_t, PageDir>;

    uint8_t  read8(uint32_t addr);
    uint16_t read16(uint32_t addr);
    uint32_t read32(uint32_t addr);
    uint64_t read64(uint32_t addr);

    void write8(uint32_t addr, uint8_t data);
    void write16(uint32_t addr, uint16_t data);
    void write32(uint32_t addr, uint32_t data);
    void write64(uint32_t addr, uint64_t data);


    void dump();

private:
    bool existPage(Address addr);
    void allocPage(Address addr);

private:
    Mem m_mem;
};

#endif
