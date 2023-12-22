#include "section_string_table.hpp"
#include <cstdint>
#include <string>
#include "elf.h"


void SectionStringTable::load(std::string file,
                    Elf64_Off sectionStringTableOffset,
                    Elf64_Xword size,
                    uint32_t count)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(sectionStringTableOffset), std::ios::beg);

    std::cout << "xhlu: sectionStringTableOffset " << sectionStringTableOffset << std::endl;
    std::cout << "xhlu: size " << size << std::endl;
    std::cout << "xhlu: count " << count << std::endl;

    char data{0};

    for (uint32_t index = 0; index < size; index++)
    {
        std::string tmpstr;

        fread.read((char *)&data, sizeof(data));

        while (data != '\0')
        {
            index++;
            tmpstr += data;
            fread.read((char *)&data, sizeof(data));

            std::cout << tmpstr << std::endl;
        }
        // std::cout << std::hex << "xhlu: "<< index << " " << static_cast<char>(data) << std::endl;


    }

    fread.close();
}

void SectionStringTable::dump(){
    for(auto& stringName: m_sectionStringTable)
    {
        std::cout << stringName << " " << std::endl;
    }
}