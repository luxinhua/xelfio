#include "cpu.hpp"
#include "elfer.hpp"

using namespace std;

void Core::fetch()
{
    std::cout << std::endl;
    std::cout << std::setw(3)  << std::left << std::setfill(' ')  << "PC:" << std::hex << m_pc << std::endl;
    std::cout << std::setw(80) << std::left << std::setfill('-') << "-" << std::endl;

    if (m_core_registers[zero].first != 0)
    {
        m_core_registers[zero].first = 0;
    }

    if (m_core_registers[sp].first < (m_stack.m_base - m_stack.m_size))
    {
        std::runtime_error("Stack OverFlow !");
    }

    /** check pc align with byte. */
    if ((m_pc % 2) != 0)
    {
        std::runtime_error("illegal pc pointer !");
    }

    /** read pc m_inst */
    m_inst.DoubleWord = m_mem->read32(m_pc);
    std::cout << std::setw(8) << std::left << std::setfill(' ') << "Fetched" << ":"
              << "instruction "
              << std::hex << m_inst.DoubleWord
              << " at address "
              << std::hex << m_pc << std::endl;

    m_fetch_bubble = false;
    m_fetch_stall = false;
}
