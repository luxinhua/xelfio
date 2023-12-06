#include "program_header_table.hpp"


void ProgramHeader::load(std::string file, Elf64_Off offset, Elf64_Half size){
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.read((char *)&m_p_type   , sizeof(m_p_type));
    fread.read((char *)&m_p_offset , sizeof(m_p_offset));
    fread.read((char *)&m_p_vaddr  , sizeof(m_p_vaddr));
    fread.read((char *)&m_p_paddr  , sizeof(m_p_paddr));
    fread.read((char *)&m_p_filesz , sizeof(m_p_filesz));
    fread.read((char *)&m_p_memsz  , sizeof(m_p_memsz));
    fread.read((char *)&m_p_flags  , sizeof(m_p_flags));
    fread.read((char *)&m_p_align  , sizeof(m_p_align));

    fread.close();
}

void ProgramHeader::dump(){
    // std::cout << "p_type      : " << "Size of this header                -- " << std::dec << m_e_ehsize    << std::endl;
}

void ProgramHeaderTable::load(std::string file, Elf64_Off offset, Elf64_Half size){

}

void ProgramHeaderTable::dump(){
    // std::cout << "p_type      : " << "Size of this header                -- " << std::dec << m_e_ehsize    << std::endl;
}