#include "elfer.hpp"
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>


void Elfer::load(std::string file)
{
    std::cout << __func__ << " " << file << std::endl;

    m_elfHeader.load(file);
    m_programHeaderTable.load(file, m_elfHeader.getProgramHeaderOffset(), m_elfHeader.getProgramHeaderItemSize());
}

void Elfer::dump()
{
    m_elfHeader.dump();
}