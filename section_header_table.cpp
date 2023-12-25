#include "section_header_table.hpp"
#include <charconv>
#include <cstdint>
#include <ios>
#include <iostream>
#include <stdexcept>

using namespace std;

Elf64_Word SectionHeader::get_sh_name(){
    return sh_name;
}
Elf64_Word SectionHeader::get_sh_type(){
    return sh_type;
}
Elf64_Xword SectionHeader::get_sh_flags(){
    return sh_flags;
}
Elf64_Addr SectionHeader::get_sh_addr(){
    return sh_addr;
}
Elf64_Off  SectionHeader::get_sh_offset(){
    return sh_offset;
}
Elf64_Xword SectionHeader::get_sh_size(){
    return sh_size;
}
Elf64_Word SectionHeader::get_sh_link(){
    return sh_link;
}
Elf64_Word SectionHeader::get_sh_info(){
    return sh_info;
}
Elf64_Xword SectionHeader::get_sh_addralign(){
    return sh_addralign;
}
Elf64_Xword SectionHeader::get_sh_entsize(){
    return sh_entsize;
}

void SectionHeader::load(std::string file, Elf64_Off offset, Elf64_Xword size)
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

void SectionHeader::dump(uint32_t index, std::string name)
{
    std::cout << std::setw(10*11 + 15) << std::setfill('-') << std::left << "-" << std::endl;
    std::cout << std::dec << std::setw(8) << std::setfill(' ') << std::left << index
              << std::hex << std::setw(20) << std::setfill(' ') << std::left << name
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_type
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_flags
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_addr
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_offset
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_size
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_link
              << std::hex << std::setw(10) << std::setfill(' ') << std::left << sh_info
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

SectionHeader SectionHeaderTable::getSectionHeaderByIndex(uint32_t index){
    return m_sectionHeaderTable.at(index);
}

void SectionHeaderTable::dump()
{
    std::cout << std::endl;
    std::cout << "Section Header Table : " << std::endl;
    std::cout << std::setw(10*11+15) << std::setfill('-') << std::left << "-" << std::endl;
    std::cout << std::setw(8) << std::setfill(' ') << std::left << "[No.]"
              << std::setw(20) << std::setfill(' ') << std::left << "sh_name"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_type"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_flags"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_addr"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_offset"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_size"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_link"
              << std::setw(10) << std::setfill(' ') << std::left << "sh_info"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_addralign"
              << std::setw(15) << std::setfill(' ') << std::left << "sh_entsize" << std::endl;

    uint32_t index{0};

    for (auto& sectionHeader : m_sectionHeaderTable)
    {
        auto nameId = sectionHeader.get_sh_name();
        auto name = str_sh_name_in_section_string_table(nameId);
        sectionHeader.dump(index++, name);
    }
    std::cout << std::setw(10*11+ 15) << std::setfill('-') << std::left << "-" << std::endl;


}

void SectionHeaderTable::dumpSectionStringTable()
{
    auto index{0};
    std::cout << std::endl;
    std::cout << "Section String Table : " << std::endl;
    std::cout << std::setw(8) << std::setfill(' ') << std::left << "[No.]"
                << std::setw(8) << std::setfill(' ') << std::left << "NameId"
                << std::setw(10) << std::setfill(' ') << std::left << "Name"
                << std::endl;
    for (auto& stringName : m_sectionStringTable)
    {
        std::cout << std::setw(8) << std::setfill(' ') << std::left << std::dec << index++
                  << std::setw(8) << std::setfill(' ') << std::left << std::hex << stringName.first
                  << std::setw(10) << std::setfill(' ') << std::left << stringName.second
                  << std::endl;
    }
}

void SectionHeaderTable::loadSectionStringTable(std::string file, Elf64_Half sectionStringTableIndex)
{
    SectionHeader sectionStringTableSectionHeader = getSectionHeaderByIndex(sectionStringTableIndex);

    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(sectionStringTableSectionHeader.get_sh_offset()), std::ios::beg);

    char data{0};

    for (uint32_t index = 0; index < sectionStringTableSectionHeader.get_sh_size(); index++)
    {
        std::string tmpstr;
        auto nameId{index};

        fread.read((char *)&data, sizeof(data));

        while (data != '\0')
        {
            index++;
            tmpstr += data;
            fread.read((char *)&data, sizeof(data));
        }
        m_sectionStringTable[nameId] = tmpstr;
    }

    fread.close();
}

std::string SectionHeaderTable::str_sh_name_in_section_string_table(Elf64_Word nameId)
{
    if (1 != m_sectionStringTable.count(nameId))
    {
        std::runtime_error("there is not name string ");
    }
    return m_sectionStringTable[nameId];
}

std::string SectionHeaderTable::str_sh_name_in_string_table(Elf64_Word nameId)
{
    if (1 != m_stringTable.count(nameId))
    {
        std::runtime_error("there is not name string ");
    }
    return m_stringTable[nameId];
}



SectionHeader SectionHeaderTable::getStringTable()
{
    std::string stringTableStr{".strtab"};
    SectionHeader sectionHeaderResult;

    for (auto& sectionHeader : m_sectionHeaderTable)
    {
        auto nameId = sectionHeader.get_sh_name();
        auto name = str_sh_name_in_section_string_table(nameId);
        if (name == stringTableStr)
        {
            std::cout << "Find " <<  name << std::endl;
            sectionHeaderResult = sectionHeader;
            break;
        }
    }
    return sectionHeaderResult;
}

void SectionHeaderTable::loadStringTable(std::string file)
{
    SectionHeader stringTableSectionHeader = getStringTable();

    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(stringTableSectionHeader.get_sh_offset()), std::ios::beg);

    char data{0};

    for (uint32_t index = 0; index < stringTableSectionHeader.get_sh_size(); index++)
    {
        std::string tmpstr;
        auto nameId{index};

        fread.read((char *)&data, sizeof(data));

        while (data != '\0')
        {
            index++;
            tmpstr += data;
            fread.read((char *)&data, sizeof(data));
        }
        m_stringTable[nameId] = tmpstr+'\0';
    }

    fread.close();
}
void SectionHeaderTable::dumpStringTable()
{
    auto index{0};
    std::cout << std::endl;
    std::cout << "String Table : " << std::endl;
    std::cout << std::setw(8) << std::setfill(' ') << std::left << "[No.]"
                << std::setw(8) << std::setfill(' ') << std::left << "NameId"
                << std::setw(10) << std::setfill(' ') << std::left << "Name"
                << std::endl;
    for (auto& stringName : m_stringTable)
    {
        std::cout << std::setw(8) << std::setfill(' ') << std::left << std::dec << index++
                  << std::setw(8) << std::setfill(' ') << std::left << std::hex << stringName.first
                  << std::setw(10) << std::setfill(' ') << std::left << stringName.second
                  << std::endl;
    }
}



SectionHeader SectionHeaderTable::getSymbolTable()
{
    std::string stringTableStr{".symtab"};
    SectionHeader sectionHeaderResult;

    for (auto& sectionHeader : m_sectionHeaderTable)
    {
        auto nameId = sectionHeader.get_sh_name();
        auto name = str_sh_name_in_section_string_table(nameId);
        if (name == stringTableStr)
        {
            std::cout << "Find " <<  name << std::endl;
            sectionHeaderResult = sectionHeader;
            break;
        }
    }
    return sectionHeaderResult;
}
void SectionHeaderTable::loadSymbolTable(std::string file)
{
    SectionHeader symbolTableSectionHeader = getSymbolTable();

    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(symbolTableSectionHeader.get_sh_offset()), std::ios::beg);

    char data{0};

    uint32_t index = 0;
    while(index < symbolTableSectionHeader.get_sh_size())
    {
        Symbol symbol;

        fread.read((char *)&symbol , sizeof(symbol));

        index += sizeof(symbol);

        m_symbols.emplace_back(symbol);
    }

    fread.close();
}
void SectionHeaderTable::dumpSymbolTable()
{
    auto index{0};
    std::cout << std::endl;
    std::cout << "Symbol Table : " << std::endl;
    std::cout << std::setw(15) << std::setfill(' ') << std::left << "[No.]"
              << std::setw(15) << std::setfill(' ') << std::left << "value"
              << std::setw(15) << std::setfill(' ') << std::left << "size"
              << std::setw(15) << std::setfill(' ') << std::left << "info"
              << std::setw(15) << std::setfill(' ') << std::left << "other"
              << std::setw(15) << std::setfill(' ') << std::left << "shndx"
              << "name"
              << std::endl;
    for (auto& symbol : m_symbols)
    {
        std::cout << std::setw(15) << std::setfill(' ') << std::left << std::dec << index++
                  << std::setw(15) << std::setfill(' ') << std::left << std::hex << symbol.st_value
                  << std::setw(15) << std::setfill(' ') << std::left << std::dec << symbol.st_size
                  << std::setw(15) << std::setfill(' ') << std::left << std::hex << symbol.st_info
                  << std::setw(15) << std::setfill(' ') << std::left << std::hex << symbol.st_other
                  << std::setw(15) << std::setfill(' ') << std::left << std::hex << symbol.st_shndx
                  << std::setw(15) << std::setfill(' ') << std::left << std::hex << str_sh_name_in_string_table(symbol.st_name)
                  << std::endl;
    }
}


SectionHeader SectionHeaderTable::getDynamicSymbolTable()
{

}
void SectionHeaderTable::loadDynamicSymbolTable(std::string files)
{

}
void SectionHeaderTable::dumpDynamicSymbolTable()
{

}

