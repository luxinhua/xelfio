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
    std::string str_e_type();
    std::string str_e_machine();
    std::string str_e_version();
    std::string str_e_entry();
    std::string str_e_phoff();
    std::string str_e_shoff();
    std::string str_e_flags();
    std::string str_e_ehsize();
    std::string str_e_phentsize();
    std::string str_e_phnum();
    std::string str_e_shentsize();
    std::string str_e_shnum();
    std::string str_e_shstrndx();

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