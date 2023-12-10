#include "elfer.hpp"
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>


void Elfer::load(std::string file)
{
    m_elfHeader.load(file);
    m_programHeaderTable.load(file,
                                m_elfHeader.getProgramHeaderOffset(),
                                m_elfHeader.getProgramHeaderItemSize(),
                                m_elfHeader.getProgramHeaderItemNum());
}

void Elfer::dump()
{
    m_elfHeader.dump();
    m_programHeaderTable.dump();
}