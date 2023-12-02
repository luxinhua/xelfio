#ifndef __ELFER_H__
#define __ELFER_H__

#include "elf_header.hpp"
#include "section_header.hpp"
#include "segment_header.hpp"
#include "program_header.hpp"
#include "section.hpp"
#include "segment.hpp"

class Elfer{
public:
    Elfer() = default;
    ~Elfer() = default;

    void load(std::string);

private:
    void dumpHex(std::string);

private:
    ElfHeader m_elfHeader;
    ProgramHeader  m_programHeader;
    std::vector<SectionHeader> m_sectionHeaderTable;
    std::vector<SegmentHeader> m_segmentHeaderTable;
    std::vector<Section> m_sections;
    std::vector<Segment> m_segments;
};

#endif