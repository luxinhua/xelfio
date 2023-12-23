#include "section_string_table.hpp"
#include <cstdint>
#include <string>
#include "elf.h"


void SectionStringTable::load(std::string file,
                    Elf64_Off sectionStringTableOffset,
                    Elf64_Xword size)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(sectionStringTableOffset), std::ios::beg);

    char data{0};

    for (uint32_t index = 0; index < size; index++)
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

void SectionStringTable::dump(){
    for(auto& stringName: m_sectionStringTable)
    {
        auto nameId = stringName.first;
        auto nameString = stringName.second;
        std::cout << std::hex << nameId << " " << nameString << " " << std::endl;
    }
}

std::map<uint32_t, std::string> SectionStringTable::get()
{
    return m_sectionStringTable;
}