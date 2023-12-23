#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "common.hpp"

class Symbol{
public:
    void set_st_name(Elf32_Word     name);
    void set_st_value(Elf32_Addr    value);
    void set_st_size(Elf32_Word     size);
    void set_st_info(unsigned char  info);
    void set_st_other(unsigned char other);
    void set_st_shndx(Elf32_Half    shndx);

    Elf32_Word    get_st_name();
    Elf32_Addr    get_st_value();
    Elf32_Word    get_st_size();
    unsigned char get_st_info();
    unsigned char get_st_other();
    Elf32_Half    get_st_shndx();

private:
    Elf32_Word    st_name;
    Elf32_Addr    st_value;
    Elf32_Word    st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf32_Half    st_shndx;
};

#endif