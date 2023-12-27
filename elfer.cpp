#include "elfer.hpp"
#include "section_header_table.hpp"

 bool Elfer::isSectionInSegment(ProgramHeader segment, SectionHeader section)
 {
    bool result{false};

    /* Only PT_LOAD, PT_GNU_RELRO and PT_TLS segments can contain SHF_TLS sections.  */

    /* PT_TLS segment contains only SHF_TLS sections, PT_PHDR no sections at all. */

    /* PT_LOAD and similar segments only have SHF_ALLOC sections. */

    /* Any section besides one of type SHT_NOBITS must have file offsets within the segment.  */

    /* SHF_ALLOC sections must have VMAs within the segment. */

    /* No zero size sections at start or end of PT_DYNAMIC nor PT_NOTE.  */

    return result;
 }

void Elfer::mapSegmentsAndSections()
{
    for(auto& segment : m_programHeaderTable.get())
    {
        std::cout << "Mapping " << segment.getType();
        for(auto& section : m_sectionHeaderTable.get())
        {
            std::cout  << " " << section.get_sh_name();
            // auto sectionName = m_sectionHeaderTable.str_sh_name_in_section_string_table(section.get_sh_name());
            // if(isSectionInSegment( segment, section ))
            // {
            //     std::cout  << " " << sectionName;
            // }
        }
        std::cout << std::endl;
    }
}

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

    // mapSegmentsAndSections();
}

void Elfer::dump()
{
    m_elfHeader.dump();
    m_programHeaderTable.dump();
    m_sectionHeaderTable.dump();
    m_sectionHeaderTable.dumpSectionStringTable();
    m_sectionHeaderTable.dumpStringTable();
    m_sectionHeaderTable.dumpSymbolTable();
    m_sectionHeaderTable.dumpDynamicStringTable();
    m_sectionHeaderTable.dumpDynamicSymbolTable();
}
