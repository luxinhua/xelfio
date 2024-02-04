#ifndef __PROGROM_HEADER_TABLE_H__
#define __PROGROM_HEADER_TABLE_H__

#include "common.hpp"
#include <vector>
#include "section_header_table.hpp"

class ProgramHeader{
public:
  ProgramHeader() = default;
  ~ProgramHeader() = default;

  void load(std::string file, Elf64_Off offset, Elf64_Half size);
  void dump();

  void setType  (uint32_t      type);
  void setOffset(uint64_t      offset);
  void setVAddr (uint64_t      vaddr);
  void setPAddr (uint64_t      paddr);
  void setFilesz(uint64_t      filesz);
  void setMemsz (uint64_t      memsz);
  void setFlags (uint32_t      flags);
  void setAlign (uint64_t      align);


  uint32_t      getType();
  uint64_t      getOffset();
  uint64_t      getVAddr();
  uint64_t      getPAddr();
  uint64_t      getFilesz();
  uint64_t      getMemsz();
  uint32_t      getFlags();
  uint64_t      getAlign();

  std::string str_p_type();

private:
  // Elf64_Word m_p_type;
  // Elf64_Off  m_p_offset;
  // Elf64_Addr m_p_vaddr;
  // Elf64_Addr m_p_paddr;
  // Elf64_Word m_p_filesz;
  // Elf64_Word m_p_memsz;
  // Elf64_Word m_p_flags;
  // Elf64_Word m_p_align;

  uint32_t      m_p_type;
  uint64_t      m_p_offset;
  uint64_t      m_p_vaddr;
  uint64_t      m_p_paddr;
  uint64_t      m_p_filesz;
  uint64_t      m_p_memsz;
  uint32_t      m_p_flags;
  uint64_t      m_p_align;

  std::vector<SectionHeader> m_sections;

};





class ProgramHeaderTable{
public:
  ProgramHeaderTable() = default;
  ~ProgramHeaderTable() = default;

  void load(std::string file, Elf64_Off ProgramHeaderTableOffset, Elf64_Half ProgramHeaderTableItemSize, Elf64_Half ProgramHeaderItemNum);
  void dump();
  std::vector<ProgramHeader> get();

private:

  std::vector<ProgramHeader> m_programHeaderTable;
};

#endif