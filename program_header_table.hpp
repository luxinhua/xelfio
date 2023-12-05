#ifndef __PROGROM_HEADER_TABLE_H__
#define __PROGROM_HEADER_TABLE_H__

#include "common.hpp"
#include <vector>

class ProgramHeader{
public:
  ProgramHeader() = default;
  ~ProgramHeader() = default;

  void load(std::string, Elf64_Off offset, Elf64_Half size);
  void dump();

  void setType(Elf64_Word type);
  void setOffset(Elf64_Off offset);
  void setVAddr(Elf64_Addr vaddr);
  void setPAddr(Elf64_Addr paddr);
  void setFilesz(Elf64_Word filesz);
  void setMemsz(Elf64_Word memsz);
  void setFlags(Elf64_Word flags);
  void setAlign(Elf64_Word align);


  Elf64_Word getType();
  Elf64_Off  getOffset();
  Elf64_Addr getVAddr();
  Elf64_Addr getPAddr();
  Elf64_Word getFilesz();
  Elf64_Word getMemsz();
  Elf64_Word getFlags();
  Elf64_Word getAlign();

private:
  Elf64_Word m_p_type;   
  Elf64_Off  m_p_offset;   
  Elf64_Addr m_p_vaddr;   
  Elf64_Addr m_p_paddr;   
  Elf64_Word m_p_filesz;   
  Elf64_Word m_p_memsz;   
  Elf64_Word m_p_flags;   
  Elf64_Word m_p_align;
};

class ProgramHeaderTable{
public:
  ProgramHeaderTable() = default;
  ~ProgramHeaderTable() = default;

  void load(std::string, Elf64_Off offset, Elf64_Half size);
  void dump();

private:

  std::vector<ProgramHeader> m_programHeaderTable;
};

#endif