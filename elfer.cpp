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

    // auto stringTableSectionIndex = m_elfHeader.getStringTableIndexInSectionHeader();
    // auto stringTableSectionOffset = m_elfHeader.getSectionHeaderOffset() + m_elfHeader.getSectionHeaderItemSize() * stringTableSectionIndex;
    m_sectionStringTable.load(file,
                                0x97da600000000,
                                2);


}

void Elfer::dump()
{
    m_elfHeader.dump();
    m_programHeaderTable.dump();
    m_sectionHeaderTable.dump();
    m_sectionStringTable.dump();
}