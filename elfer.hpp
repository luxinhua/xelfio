#ifndef __ELFER_H__
#define __ELFER_H__

#include "elf_header.hpp"
#include "section_header_table.hpp"
#include "segment_header_table.hpp"
#include "program_header.hpp"
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
    ProgramHeader  m_programHeader;
    SectionHeaderTable m_sectionHeaderTable;
    SegmentHeaderTable m_segmentHeaderTable;
    Sections m_sections;
    Segments m_segments;

    std::streampos m_ElfHeaderSeekLocation;
    std::streampos m_ProgramHeaderSeekLocation;
    std::streampos m_SectionHeaderTableSeekLocation;
    std::streampos m_SegmentHeaderTableSeekLocation;
};

#endif