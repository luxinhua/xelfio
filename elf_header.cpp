#include "elf_header.hpp"
#include "elf.h"
#include <algorithm>
#include <codecvt>
#include <cstdint>
#include <ios>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <map>

void ElfHeader::load(std::string file)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    // e_ident
    for (uint32_t ident_id = 0; ident_id < EI_NIDENT; ident_id++)
    {
        fread.read((char *)&(m_e_ident[ident_id]), sizeof(m_e_ident[ident_id]));
    }
    // e_type
    fread.read((char *)&m_e_type, sizeof(m_e_type));
    // e_machine
    fread.read((char *)&m_e_machine, sizeof(m_e_machine));
    // e_version
    fread.read((char *)&m_e_version, sizeof(m_e_version));
    // e_entry
    fread.read((char *)&m_e_entry, sizeof(m_e_entry));
    // e_phoff
    fread.read((char *)&m_e_phoff, sizeof(m_e_phoff));
    // e_shoff
    fread.read((char *)&m_e_shoff, sizeof(m_e_shoff));
    // e_flags
    fread.read((char *)&m_e_flags, sizeof(m_e_flags));
    // e_ehsize
    fread.read((char *)&m_e_ehsize, sizeof(m_e_ehsize));
    // e_phentsize
    fread.read((char *)&m_e_phentsize, sizeof(m_e_phentsize));
    // e_phnum
    fread.read((char *)&m_e_phnum, sizeof(m_e_phnum));
    // e_shentsize
    fread.read((char *)&m_e_shentsize, sizeof(m_e_shentsize));
    // e_shnum
    fread.read((char *)&m_e_shnum, sizeof(m_e_shnum));
    // e_shstrndx
    fread.read((char *)&m_e_shstrndx, sizeof(m_e_shstrndx));

    fread.close();
}

void ElfHeader::dump()
{
    // e_ident
    std::cout << " " << "EI_MAG0     : " << static_cast<unsigned int>(m_e_ident[0]) << std::endl; 
    std::cout << " " << "EI_MAG1     : " << m_e_ident[1] << std::endl; 
    std::cout << " " << "EI_MAG2     : " << m_e_ident[2] << std::endl; 
    std::cout << " " << "EI_MAG3     : " << m_e_ident[3] << std::endl; 
    std::cout << " " << "EI_CLASS    : " << static_cast<unsigned int>(m_e_ident[4]) << std::endl; 
    std::cout << " " << "EI_DATA     : " << static_cast<unsigned int>(m_e_ident[5]) << std::endl; 
    std::cout << " " << "EI_VERSION  : " << static_cast<unsigned int>(m_e_ident[6]) << std::endl; 
    std::cout << " " << "EI_PAD      : " << static_cast<unsigned int>(m_e_ident[7]) << std::endl; 
    std::cout << " " << "e_type      : " << std::hex << str_e_type()      << std::endl;
    std::cout << " " << "e_machine   : " << std::hex << str_e_machine()   << std::endl;
    std::cout << " " << "e_version   : " << std::hex << m_e_version   << std::endl;
    std::cout << " " << "e_entry     : " << std::hex << m_e_entry     << std::endl;
    std::cout << " " << "e_phoff     : " << std::hex << m_e_phoff     << std::endl;
    std::cout << " " << "e_shoff     : " << std::hex << m_e_shoff     << std::endl;
    std::cout << " " << "e_flags     : " << std::hex << m_e_flags     << std::endl;
    std::cout << " " << "e_ehsize    : " << std::hex << m_e_ehsize    << std::endl;
    std::cout << " " << "e_phentsize : " << std::hex << m_e_phentsize << std::endl;
    std::cout << " " << "e_phnum     : " << std::hex << m_e_phnum     << std::endl;
    std::cout << " " << "e_shentsize : " << std::hex << m_e_shentsize << std::endl;
    std::cout << " " << "e_shnum     : " << std::hex << m_e_shnum     << std::endl;
    std::cout << " " << "e_shstrndx  : " << std::hex << m_e_shstrndx  << std::endl;
}

std::string ElfHeader::str_e_type(){
    std::vector<std::pair<uint32_t, std::string>> e_type_string{
        std::make_pair(ET_NONE	 , "No file type "),
        std::make_pair(ET_REL	 , "Relocatable file "),
        std::make_pair(ET_EXEC	 , "Executable file "),
        std::make_pair(ET_DYN	 , "Shared object file "),
        std::make_pair(ET_CORE	 , "Core file "),
        std::make_pair(ET_NUM	 , "Number of defined types "),
        std::make_pair(ET_LOOS	 , "OS-specific range start "),
        std::make_pair(ET_HIOS	 , "OS-specific range end "),
        std::make_pair(ET_LOPROC	 , "Processor-specific range start "),
        std::make_pair(ET_HIPROC	 , "Processor-specific range end"),
    };

    for(auto & item : e_type_string)
    {
        if (item.first == m_e_type)
            return item.second;
    }

    return std::string("unknow e_type type");

}

std::string ElfHeader::str_e_machine(){
    std::vector<std::pair<uint32_t, std::string>> e_machine_string{
        std::make_pair(EM_NONE		  , "No machine"),
        std::make_pair(EM_M32		  , "AT&T WE 32100"),
        std::make_pair(EM_SPARC	      , "SUN SPARC"),
        std::make_pair(EM_386		  , "Intel 80386"),
        std::make_pair(EM_68K		  , "Motorola m68k family"),
        std::make_pair(EM_88K		  , "Motorola m88k family"),
        std::make_pair(EM_IAMCU	      , "Intel MCU"),
        std::make_pair(EM_860		  , "Intel 80860"),
        std::make_pair(EM_MIPS		  , "MIPS R3000 big-endian"),
        std::make_pair(EM_S370		  , "IBM System/370"),
        std::make_pair(EM_MIPS_RS3_LE , "MIPS R3000 little-endia"),
    };

    for(auto & item : e_machine_string)
    {
        if (item.first == m_e_machine)
            return item.second;
    }

    return std::string("unknow e_machine type");
}

std::string ElfHeader::str_e_version(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_entry(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_phoff(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_shoff(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_flags(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_ehsize(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_phentsize(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_phnum(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_shentsize(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_shnum(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}
std::string ElfHeader::str_e_shstrndx(){
    std::string result;
    if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    else if(m_e_machine == ET_NONE)
    {
        return result = "未知文件类型";
    }
    return result;
}