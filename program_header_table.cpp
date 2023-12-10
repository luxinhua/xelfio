#include "program_header_table.hpp"
#include <iomanip>


void ProgramHeader::load(std::string file, Elf64_Off offset, Elf64_Half size)
{
    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(std::streamoff(offset), std::ios::beg);

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
    std::cout << std::hex << std::setw(16) << std::setfill(' ') << std::left << str_p_type()
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_offset
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_vaddr
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_paddr
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_filesz
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_memsz
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_flags
              << std::hex << std::setw(16) << std::setfill(' ') << std::left << m_p_align << std::endl;;
}


std::string ProgramHeader::str_p_type()
{
    std::vector<std::pair<uint32_t, std::string>> p_type_string{
        std::make_pair(PT_NULL    , "NULL"),
        std::make_pair(PT_LOAD    , "LOAD"),
        std::make_pair(PT_DYNAMIC , "DYN"),
        std::make_pair(PT_INTERP  , "INTERP"),
        std::make_pair(PT_NOTE    , "NOTE"),
        std::make_pair(PT_SHLIB   , "SHLIB"),
        std::make_pair(PT_PHDR    , "PHDR"),
        std::make_pair(PT_LOPROC  , "LOPROC"),
        std::make_pair(PT_HIPROC  , "HIPROC"),

        std::make_pair(PT_GNU_PROPERTY  , "GNU_PROPERTY"),
        std::make_pair(PT_GNU_SFRAME  , "HIPROC"),
        std::make_pair(PT_GNU_RELRO  , "HIPROC"),
        std::make_pair(PT_HIPROC  , "HIPROC"),

        // #define PT_NULL		0		/* Program header table entry unused */
        // #define PT_LOAD		1		/* Loadable program segment */
        // #define PT_DYNAMIC	2		/* Dynamic linking information */
        // #define PT_INTERP	3		/* Program interpreter */
        // #define PT_NOTE		4		/* Auxiliary information */
        // #define PT_SHLIB	5		/* Reserved */
        // #define PT_PHDR		6		/* Entry for header table itself */
        // #define PT_TLS		7		/* Thread-local storage segment */
        // #define PT_NUM		8		/* Number of defined types */
        // #define PT_LOOS		0x60000000	/* Start of OS-specific */
        // #define PT_GNU_EH_FRAME	0x6474e550	/* GCC .eh_frame_hdr segment */
        // #define PT_GNU_STACK	0x6474e551	/* Indicates stack executability */
        // #define PT_GNU_RELRO	0x6474e552	/* Read-only after relocation */
        // #define PT_GNU_PROPERTY	0x6474e553	/* GNU property */
        // #define PT_GNU_SFRAME	0x6474e554	/* SFrame segment.  */
        // #define PT_LOSUNW	0x6ffffffa
        // #define PT_SUNWBSS	0x6ffffffa	/* Sun Specific segment */
        // #define PT_SUNWSTACK	0x6ffffffb	/* Stack segment */
        // #define PT_HISUNW	0x6fffffff
        // #define PT_HIOS		0x6fffffff	/* End of OS-specific */
        // #define PT_LOPROC	0x70000000	/* Start of processor-specific */
        // #define PT_HIPROC	0x7fffffff	/* End of processor-specific */
    };


    for(auto & item : p_type_string)
    {
        if (item.first == m_p_type)
            return item.second;
    }

    return std::string("unknow_e_type");

}

void ProgramHeaderTable::load(std::string file,
                              Elf64_Off  ProgramHeaderTableOffset,
                              Elf64_Half ProgramHeaderTableItemSize,
                              Elf64_Half ProgramHeaderItemNum)
{
    for(uint32_t index = 0; index < ProgramHeaderItemNum; index++)
    {
        ProgramHeader programHeader;
        programHeader.load(file,
                        ProgramHeaderTableOffset + ProgramHeaderTableItemSize * index,
                        ProgramHeaderTableItemSize);
        m_programHeaderTable.emplace_back(programHeader);
    }
}

void ProgramHeaderTable::dump()
{
    std::cout << std::endl;
    std::cout << std::setw(16) << std::setfill(' ') << std::left << "m_p_type"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_offset"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_vaddr"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_paddr"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_filesz"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_memsz"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_flags"
              << std::setw(16) << std::setfill(' ') << std::left << "m_p_align" << std::endl;

    for (auto& programHeader : m_programHeaderTable)
    {
        programHeader.dump();
    }
}


