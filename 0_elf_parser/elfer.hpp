#ifndef __ELFER_H__
#define __ELFER_H__

#include "elf_header.hpp"
#include "section_header_table.hpp"
#include "program_header_table.hpp"
#include "section.hpp"
#include "segment.hpp"
#include "memory.hpp"
#include <string>

class Elfer{
public:
    Elfer(std::string file):m_filename(file)  {}
    ~Elfer() = default;

    void load();
    void dump();

    void loadSegment2Mem();

    void mapSegmentsAndSections();
    bool isSectionInSegment(ProgramHeader, SectionHeader);

private:
    uint8_t read8(Elf64_Off offset);

private:

    ElfHeader m_elfHeader;
    ProgramHeaderTable m_programHeaderTable;
    SectionHeaderTable m_sectionHeaderTable;
    Sections m_sections;
    Segments m_segments;
    Memory   m_mem;

    std::string m_filename;
};

#endif