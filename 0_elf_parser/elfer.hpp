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
    Elfer(std::string file):m_filename(file)  {
        m_elfHeader.load(m_filename);
        m_programHeaderTable.load(m_filename,
                                    m_elfHeader.getProgramHeaderOffset(),
                                    m_elfHeader.getProgramHeaderItemSize(),
                                    m_elfHeader.getProgramHeaderItemNum());
        m_sectionHeaderTable.load(m_filename,
                                    m_elfHeader.getSectionHeaderOffset(),
                                    m_elfHeader.getSectionHeaderItemSize(),
                                    m_elfHeader.getSectionHeaderItemNum());
        m_sectionHeaderTable.loadSectionStringTable(m_filename,
                                            m_elfHeader.getSectionStringTableIndex());
        m_sectionHeaderTable.loadStringTable(m_filename);
        m_sectionHeaderTable.loadSymbolTable(m_filename);
        // m_sectionHeaderTable.loadDynamicStringTable(m_filename);
        // m_sectionHeaderTable.loadDynamicSymbolTable(m_filename);
        // mapSegmentsAndSections();
    }
    ~Elfer() = default;

    void dump();

    void loadSegment2Mem(Memory* mem);

    void mapSegmentsAndSections();
    bool isSectionInSegment(ProgramHeader, SectionHeader);

    uint64_t get_entry();

private:
    uint8_t read8(Elf64_Off offset);

private:

    ElfHeader m_elfHeader;
    ProgramHeaderTable m_programHeaderTable;
    SectionHeaderTable m_sectionHeaderTable;
    Sections m_sections;
    Segments m_segments;
    // Memory   m_mem;

    std::string m_filename;
};

#endif