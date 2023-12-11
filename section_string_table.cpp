#include "section_string_table.hpp"
#include <cstdint>
#include <string>


void SectionStringTable::load(std::string file, Elf64_Off sectionStringTableOffset, uint32_t number){


    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(sectionStringTableOffset), std::ios::beg);

    std::cout << "xhlu: sectionStringTableOffset " << sectionStringTableOffset << std::endl;
    std::cout << "xhlu: number " << number << std::endl;

    char data;
    fread.read((char *)&data, sizeof(data));

    for (uint32_t index = 0; index < number; index++)
    {
        char data;
        std::string sectionName;

        while (data != '\0') {
            fread.read((char *)&data, sizeof(data));
            sectionName += data;
            std::cout << "xhlu: data  " << static_cast<unsigned int>(data) << std::endl;
        }
        std::cout << "xhlu: index " << index << " sectionName  " << sectionName << std::endl;

        m_sectionStringTable.emplace_back(sectionName);
    }

    fread.close();
}

void SectionStringTable::dump(){
    for(auto& stringName: m_sectionStringTable)
    {
        std::cout << stringName << " " << std::endl;
    }
}