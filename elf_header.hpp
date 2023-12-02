#ifndef __ELF_HEADER_H__
#define __ELF_HEADER_H__

#include "common.hpp"
#include <array>
#include <cstdint>

class ElfHeader{
public:
    ElfHeader() = default;
    ~ElfHeader() = default;

    void setEIdent();
    void setType();
    void setMachine();
    void setVersion();
    void setEntry();
    void setProgramHeaderOffset();
    void setSectionHeaderOffset();
    void setFlags();
    void setElfHeaderSize();
    void setProgramHeaderItemSize();
    void setProgramHeaderItemNum();
    void setSectionHeaderItemSize();
    void setSectionHeaderItemNum();
    void setStringTableIndexInSectionHeader();
    
    void getEIdent();
    void getType();
    void getMachine();
    void getVersion();
    void getEntry();
    void getProgramHeaderOffset();
    void getSectionHeaderOffset();
    void getFlags();
    void getElfHeaderSize();
    void getProgramHeaderItemSize();
    void getProgramHeaderItemNum();
    void getSectionHeaderItemSize();
    void getSectionHeaderItemNum();
    void getStringTableIndexInSectionHeader();

private:
    std::array<uint8_t,EI_NIDENT> m_e_ident;
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
};

#endif