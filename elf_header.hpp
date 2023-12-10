#ifndef __ELF_HEADER_H__
#define __ELF_HEADER_H__

#include "common.hpp"

class ElfHeader{
public:
    ElfHeader() = default;
    ~ElfHeader() = default;

    void load(std::string file);
    void dump();

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

    std::array<uint8_t,EI_NIDENT> getEIdent();
    Elf64_Half getType();
    Elf64_Half getMachine();
    Elf64_Word getVersion();
    Elf64_Addr getEntry();
    Elf64_Off  getProgramHeaderOffset();
    Elf64_Off  getSectionHeaderOffset();
    Elf64_Word getFlags();
    Elf64_Half getElfHeaderSize();
    Elf64_Half getProgramHeaderItemSize();
    Elf64_Half getProgramHeaderItemNum();
    Elf64_Half getSectionHeaderItemSize();
    Elf64_Half getSectionHeaderItemNum();
    Elf64_Half getStringTableIndexInSectionHeader();

private:
    std::string str_e_type();
    std::string str_e_machine();
    std::string str_e_version();

private:
    std::array<uint8_t,EI_NIDENT> m_e_ident;
    Elf64_Half m_e_type;
    Elf64_Half m_e_machine;
    Elf64_Word m_e_version;
    Elf64_Addr m_e_entry;
    Elf64_Off  m_e_phoff;
    Elf64_Off  m_e_shoff;
    Elf64_Word m_e_flags;
    Elf64_Half m_e_ehsize;
    Elf64_Half m_e_phentsize;
    Elf64_Half m_e_phnum;
    Elf64_Half m_e_shentsize;
    Elf64_Half m_e_shnum;
    Elf64_Half m_e_shstrndx;
};

#endif