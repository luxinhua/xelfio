#ifndef __SECTION_STRING_TABLE__
#define __SECTION_STRING_TABLE__

#include <cstdint>
#include <vector>
#include "common.hpp"
#include "section_header_table.hpp"

class SectionStringTable{
public:
    void load(std::string file, Elf64_Off SectionStringTableOffset, uint32_t number);
    void dump();

private:
    std::vector<std::string> m_sectionStringTable;

};

#endif