#ifndef __SECTION_HEADER_TABLE_H__
#define __SECTION_HEADER_TABLE_H__

#include <vector>
#include "common.hpp"
#include "symbol.hpp"

class SectionHeader{
public:
    SectionHeader() = default;
    ~SectionHeader() = default;

    void load(std::string file, Elf64_Off offset, Elf64_Xword size);
    void dump(uint32_t index, std::string name);

    Elf64_Word get_sh_name();
    Elf64_Word get_sh_type();
    Elf64_Xword get_sh_flags();
    Elf64_Addr get_sh_addr();
    Elf64_Off  get_sh_offset();
    Elf64_Xword get_sh_size();
    Elf64_Word get_sh_link();
    Elf64_Word get_sh_info();
    Elf64_Xword get_sh_addralign();
    Elf64_Xword get_sh_entsize();

    void set_sh_name(Elf64_Word);
    void set_sh_type(Elf64_Word);
    void set_sh_flags(Elf64_Xword);
    void set_sh_addr(Elf64_Addr);
    void set_sh_offset(Elf64_Off );
    void set_sh_size(Elf64_Xword);
    void set_sh_link(Elf64_Word);
    void set_sh_info(Elf64_Word);
    void set_sh_addralign(Elf64_Xword);
    void set_sh_entsize(Elf64_Xword);

private:
    Elf64_Word sh_name;
    Elf64_Word sh_type;
    Elf64_Xword sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off  sh_offset;
    Elf64_Xword sh_size;
    Elf64_Word sh_link;
    Elf64_Word sh_info;
    Elf64_Xword sh_addralign;
    Elf64_Xword sh_entsize;
};

class SectionHeaderTable{
public:
    SectionHeaderTable() = default;
    ~SectionHeaderTable() = default;

    void load(std::string file, Elf64_Off SectionHeaderTableOffset, Elf64_Half SectionHeaderTableItemSize, Elf64_Half SectionHeaderTableItemNum);
    void dump();

    SectionHeader getSectionHeaderByIndex(uint32_t index);
    void loadSectionStringTable(std::string file, Elf64_Half sectionStringTableIndex);
    void dumpSectionStringTable();

    std::string str_sh_name_in_section_string_table(Elf64_Word nameId);
    SectionHeader getStringTable();
    void loadStringTable(std::string files);
    void dumpStringTable();

    std::string str_sh_name_in_string_table(Elf64_Word nameId);
    SectionHeader getSymbolTable();
    void loadSymbolTable(std::string files);
    void dumpSymbolTable();

    std::string str_sh_name_in_dynamic_string_table(Elf64_Word nameId);
    SectionHeader getDynamicSymbolTable();
    void loadDynamicSymbolTable(std::string files);
    void dumpDynamicSymbolTable();

private:
    std::vector<SectionHeader> m_sectionHeaderTable;

    std::map<uint32_t, std::string> m_sectionStringTable;

    std::map<uint32_t, std::string> m_stringTable;
    std::vector<Symbol>             m_symbols;

    std::map<uint32_t, std::string> m_dynamicStringTable;
    std::vector<Symbol>             m_dynamicSymbols;
};

#endif
