#include "elfer.hpp"
#include "section_header_table.hpp"

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

    m_sectionHeaderTable.loadSectionStringTable(file,
                                        m_elfHeader.getSectionStringTableIndex());
    m_sectionHeaderTable.loadStringTable(file);
    m_sectionHeaderTable.loadSymbolTable(file);
    m_sectionHeaderTable.loadDynamicStringTable(file);
    m_sectionHeaderTable.loadDynamicSymbolTable(file);
}

void Elfer::dump()
{
    // m_elfHeader.dump();
    // m_programHeaderTable.dump();
    // m_sectionHeaderTable.dump();
    // m_sectionHeaderTable.dumpSectionStringTable();
    // m_sectionHeaderTable.dumpStringTable();
    // m_sectionHeaderTable.dumpSymbolTable();
    // m_sectionHeaderTable.dumpDynamicStringTable();
    m_sectionHeaderTable.dumpDynamicSymbolTable();
}