#include "address.hpp"
#include <cstdint>
#include <stdexcept>

Address::Address(uint32_t addr):
    m_Dir(addr >> 12 >> 10 ),
    m_page((addr >> 12) & 0x3FF),
    m_offset(addr & 0xFFF),
    m_addr(addr)
{
    if (m_addr >= 0xFFFFFFFF)
    {
        std::runtime_error("invail address");
    }
}

Address::Address(uint32_t dir, uint32_t page, uint32_t offset):
    m_Dir(dir),
    m_page(page),
    m_offset(offset),
    m_addr((m_Dir << 12 << 10) | (m_page << 12) | (m_offset))
{
    if (m_addr >= 0xFFFFFFFF)
    {
        std::runtime_error("invail address");
    }
}

uint32_t Address::value()
{
    return m_addr;
}