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

void Elfer::loadSegment2Mem()
{
    for(auto& segment: m_programHeaderTable.get())
    {
        for(uint32_t index=0; index<segment.getMemsz(); index++ )
        {
            m_mem.writebyte(segment.getVAddr()+index, read8(segment.getOffset()+index));
        }
    }
}

uint8_t Elfer::read8(Elf64_Off offset)
{
    uint8_t data{0};
    std::ifstream fread(m_filename,std::ios::in|std::ios::binary);
    fread.seekg(std::streamoff(offset), std::ios::beg);
    fread.read((char *)&data   , sizeof(uint8_t));
    fread.close();

    return data;
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

void Elfer::load()
{
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

    m_sectionHeaderTable.loadDynamicStringTable(m_filename);
    m_sectionHeaderTable.loadDynamicSymbolTable(m_filename);

    // mapSegmentsAndSections();
}

void Elfer::dump()
{
    m_elfHeader.dump();
    m_programHeaderTable.dump();
    // m_sectionHeaderTable.dump();
    // m_sectionHeaderTable.dumpSectionStringTable();
    // m_sectionHeaderTable.dumpStringTable();
    // m_sectionHeaderTable.dumpSymbolTable();
    // m_sectionHeaderTable.dumpDynamicStringTable();
    // m_sectionHeaderTable.dumpDynamicSymbolTable();

    m_mem.dump();
}
