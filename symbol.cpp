#include "symbol.hpp"

void Symbol::set_st_name(Elf32_Word name)
{
    st_name = name;
}
void Symbol::set_st_value(Elf32_Addr value)
{
    st_value = value;
}
void Symbol::set_st_size(Elf32_Word size)
{
    st_size = size;
}
void Symbol::set_st_info(unsigned char info)
{
    st_info = info;
}
void Symbol::set_st_other(unsigned char other)
{
    st_other = other;
}
void Symbol::set_st_shndx(Elf32_Half shndx)
{
    st_shndx = shndx;
}

Elf32_Word    Symbol::get_st_name()
{
    return st_name;
}
Elf32_Addr    Symbol::get_st_value()
{
    return st_value;
}
Elf32_Word    Symbol::get_st_size()
{
    return st_size;
}
unsigned char Symbol::get_st_info()
{
    return st_info;
}
unsigned char Symbol::get_st_other()
{
    return st_other;
}
Elf32_Half    Symbol::get_st_shndx()
{
    return st_shndx;
}