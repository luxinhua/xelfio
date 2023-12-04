#ifndef __SECTION_HEADER_TABLE_H__
#define __SECTION_HEADER_TABLE_H__

#include "common.hpp"

class SectionHeader{
public:
    SectionHeader() = default;
    ~SectionHeader() = default;

private:
    

};

class SectionHeaderTable{
public:
    SectionHeaderTable() = default;
    ~SectionHeaderTable() = default;

private:
    std::vector<SectionHeader> m_sectionHeaderTable;

};

#endif