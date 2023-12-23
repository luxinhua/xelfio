#ifndef __SECTION_STRING_TABLE__
#define __SECTION_STRING_TABLE__

#include "common.hpp"

class SectionStringTable{
public:
    void load(std::string file,
                Elf64_Off sectionStringTableOffset,
                Elf64_Xword size);
    void dump();
    std::map<uint32_t, std::string> get();

private:
    std::map<uint32_t, std::string> m_sectionStringTable;

};

#endif