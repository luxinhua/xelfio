#include "section_string_table.hpp"
#include <cstdint>
#include <string>


void SectionStringTable::load(std::string file, Elf64_Off SectionStringTableOffset, uint32_t number){


    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(SectionStringTableOffset), std::ios::beg);

    char data;
    fread.read((char *)&data, sizeof(data));

    for (uint32_t index = 0; index < number; index++)
    {
        char data{'a'};
        std::string sectionName;

        while (data != '\0') {
            fread.read((char *)&data, sizeof(data));
            sectionName += data;
        }
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