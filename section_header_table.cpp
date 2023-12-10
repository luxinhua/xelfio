#include "section_header_table.hpp"
#include <charconv>
#include <cstdint>
#include <ios>

using namespace std;

Elf64_Word SectionHeader::get_sh_name(){
    return sh_name;
}
Elf64_Word SectionHeader::get_sh_type(){
    return sh_type;
}
Elf64_Word SectionHeader::get_sh_flags(){
    return sh_flags;
}
Elf64_Addr SectionHeader::get_sh_addr(){
    return sh_addr;
}
Elf64_Off  SectionHeader::get_sh_offset(){
    return sh_offset;
}
Elf64_Word SectionHeader::get_sh_size(){
    return sh_size;
}
Elf64_Word SectionHeader::get_sh_link(){
    return sh_link;
}
Elf64_Word SectionHeader::get_sh_info(){
    return sh_info;
}
Elf64_Word SectionHeader::get_sh_addralign(){
    return sh_addralign;
}
Elf64_Word SectionHeader::get_sh_entsize(){
    return sh_entsize;
}

void SectionHeader::load(std::string file, Elf64_Off offset, Elf64_Half size)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(offset), std::ios::beg);

    fread.read((char *)&sh_name      , sizeof(sh_name      ));
    fread.read((char *)&sh_type      , sizeof(sh_type      ));
    fread.read((char *)&sh_flags     , sizeof(sh_flags     ));
    fread.read((char *)&sh_addr      , sizeof(sh_addr      ));
    fread.read((char *)&sh_offset    , sizeof(sh_offset    ));
    fread.read((char *)&sh_size      , sizeof(sh_size      ));
    fread.read((char *)&sh_link      , sizeof(sh_link      ));
    fread.read((char *)&sh_info      , sizeof(sh_info      ));
    fread.read((char *)&sh_addralign , sizeof(sh_addralign ));
    fread.read((char *)&sh_entsize   , sizeof(sh_entsize   ));

    fread.close();
}

void SectionHeader::dump(uint32_t index)
{
    std::cout
              << std::dec << std::setw(15) << std::setfill(' ') << std::left << index
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_name
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_type
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_flags
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_addr
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_offset
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_size
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_link
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_info
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_addralign
              << std::hex << std::setw(15) << std::setfill(' ') << std::left << sh_entsize << std::endl;;
}

void SectionHeaderTable::load(std::string file,
                              Elf64_Off  SectionHeaderTableOffset,
                              Elf64_Half SectionHeaderTableItemSize,
                              Elf64_Half SectionHeaderTableItemNum)
{
    for(uint32_t index = 0; index < SectionHeaderTableItemNum; index++)
    {
        SectionHeader sectionHeader;
        sectionHeader.load(file,
                        SectionHeaderTableOffset + SectionHeaderTableItemSize * index,
                        SectionHeaderTableItemSize);
        m_sectionHeaderTable.emplace_back(sectionHeader);
    }
}

uint32_t SectionHeaderTable::size(){
    return m_sectionHeaderTable.size();
}

SectionHeader SectionHeaderTable::getStringSection(uint32_t index){
    return m_sectionHeaderTable.at(38-1);
}

void SectionHeaderTable::dump()
{
    std::cout << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left << "[No.]"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_name"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_type"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_flags"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_addr"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_offset"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_size"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_link"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_info"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_addralign"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_entsize" << std::endl;

    uint32_t index{0};

    for (auto& sectionHeader : m_sectionHeaderTable)
    {
        sectionHeader.dump(index++);
    }
}