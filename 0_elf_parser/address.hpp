#ifndef __ADDRESS_H__
#define __ADDRESS_H__

#include <cstdint>

class Address
{
public:
    Address(uint32_t addr);
    Address(uint32_t dir, uint32_t page, uint32_t offset);

    uint32_t value();

    uint32_t m_Dir;
    uint32_t m_page;
    uint32_t m_offset;
    uint32_t m_addr;
};

#endif