#ifndef __SECTION_HEADER_TABLE_H__
#define __SECTION_HEADER_TABLE_H__

#include <cstdint>
#include "common.hpp"

class SectionHeader{
public:
    SectionHeader() = default;
    ~SectionHeader() = default;

    void load(std::string file, Elf64_Off offset, Elf64_Half size);
    void dump(uint32_t index);

    Elf64_Word get_sh_name();
    Elf64_Word get_sh_type();
    Elf64_Word get_sh_flags();
    Elf64_Addr get_sh_addr();
    Elf64_Off  get_sh_offset();
    Elf64_Word get_sh_size();
    Elf64_Word get_sh_link();
    Elf64_Word get_sh_info();
    Elf64_Word get_sh_addralign();
    Elf64_Word get_sh_entsize();

    void set_sh_name(Elf64_Word);
    void set_sh_type(Elf64_Word);
    void set_sh_flags(Elf64_Word);
    void set_sh_addr(Elf64_Addr);
    void set_sh_offset(Elf64_Off );
    void set_sh_size(Elf64_Word);
    void set_sh_link(Elf64_Word);
    void set_sh_info(Elf64_Word);
    void set_sh_addralign(Elf64_Word);
    void set_sh_entsize(Elf64_Word);

private:
    Elf64_Word sh_name;
    Elf64_Word sh_type;
    Elf64_Word sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off  sh_offset;
    Elf64_Word sh_size;
    Elf64_Word sh_link;
    Elf64_Word sh_info;
    Elf64_Word sh_addralign;
    Elf64_Word sh_entsize;

};

class SectionHeaderTable{
public:
    SectionHeaderTable() = default;
    ~SectionHeaderTable() = default;

  void load(std::string file, Elf64_Off SectionHeaderTableOffset, Elf64_Half SectionHeaderTableItemSize, Elf64_Half SectionHeaderTableItemNum);
  void dump();

private:
    std::vector<SectionHeader> m_sectionHeaderTable;

};

#endif