#include "elfer.hpp"

void Elfer::load(std::string file)
{
    m_elfHeader.load(file);
    m_programHeaderTable.load(file,
                                m_elfHeader.getProgramHeaderOffset(),
                                m_elfHeader.getProgramHeaderItemSize(),
                                m_elfHeader.getProgramHeaderItemNum());
    m_sectionHeaderTable.load(file,
                                m_elfHeader.getSectionHeaderOffset(),
                                m_elfHeader.getSectionHeaderItemSize(),
                                m_elfHeader.getSectionHeaderItemNum());
    SectionHeader stringTable = m_sectionHeaderTable.getStringSection(m_elfHeader.getStringTableIndexInSectionHeader());
    m_sectionStringTable.load(file,
                                stringTable.get_sh_offset(),
                                m_sectionHeaderTable.size());
}

void Elfer::dump()
{
    m_elfHeader.dump();
    m_programHeaderTable.dump();
    m_sectionHeaderTable.dump();
    m_sectionStringTable.dump();
}