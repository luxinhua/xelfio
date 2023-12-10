#ifndef __ELFER_H__
#define __ELFER_H__

#include "elf_header.hpp"
#include "section_header_table.hpp"
#include "program_header_table.hpp"
#include "section_string_table.hpp"
#include "section.hpp"
#include "segment.hpp"

class Elfer{
public:
    Elfer() = default;
    ~Elfer() = default;

    void load(std::string);
    void dump();

private:

    ElfHeader m_elfHeader;
    ProgramHeaderTable m_programHeaderTable;
    SectionHeaderTable m_sectionHeaderTable;
    SectionStringTable m_sectionStringTable;
    Sections m_sections;
    Segments m_segments;
};

#endif