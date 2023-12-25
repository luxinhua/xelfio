#ifndef __SYMBOL_H__
#define __SYMBOL_H__

#include "common.hpp"


struct Symbol
{
	Elf64_Word	    st_name; // 4 B (B for bytes)
	unsigned char	st_info; // 1 B
	unsigned char	st_other; // 1 B
	Elf64_Half	    st_shndx; // 2 B
	Elf64_Addr	    st_value; // 8 B
	Elf64_Xword	    st_size; // 8 B
};

#endif