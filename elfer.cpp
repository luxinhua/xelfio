#include "elfer.hpp"
#include "section_header_table.hpp"

 bool Elfer::isSectionInSegment(ProgramHeader segment, SectionHeader sections)
 {
    bool result{false};

    /// Only PT_LOAD, PT_GNU_RELRO and PT_TLS segments can contain SHF_TLS sections.
    if (  ( segment.getType() == PT_TLS       ||
            segment.getType() == PT_GNU_RELRO ||
            segment.getType() == PT_LOAD )    &&
          ((sections.get_sh_flags() & SHF_TLS) != 0)  )
    {
        result = true;
    }

    /// PT_TLS segment contains only SHF_TLS sections, PT_PHDR no sections at all.
    if (  ( segment.getType() != PT_TLS       &&
            segment.getType() != PT_PHDR )    &&
          ((sections.get_sh_flags() & SHF_TLS) != 0)  )
    {
        result = true;
    }


    return result;
//==================================================================================================
//   ((/* Only PT_LOAD, PT_GNU_RELRO and PT_TLS segments can contain	\
//        SHF_TLS sections.  */						\
//     ((((sec_hdr)->sh_flags & SHF_TLS) != 0)				\
//      && ((segment)->p_type == PT_TLS					\
// 	 || (segment)->p_type == PT_GNU_RELRO				\
// 	 || (segment)->p_type == PT_LOAD))				\
//==================================================================================================
//     /* PT_TLS segment contains only SHF_TLS sections, PT_PHDR no	\
//        sections at all.  */						\
//     || (((sec_hdr)->sh_flags & SHF_TLS) == 0				\
// 	&& (segment)->p_type != PT_TLS					\
// 	&& (segment)->p_type != PT_PHDR))				\
//==================================================================================================
//    /* PT_LOAD and similar segments only have SHF_ALLOC sections.  */	\
//    && !(((sec_hdr)->sh_flags & SHF_ALLOC) == 0				\
// 	&& ((segment)->p_type == PT_LOAD				\
// 	    || (segment)->p_type == PT_DYNAMIC				\
// 	    || (segment)->p_type == PT_GNU_EH_FRAME			\
// 	    || (segment)->p_type == PT_GNU_STACK			\
// 	    || (segment)->p_type == PT_GNU_RELRO			\
// 	    || (segment)->p_type == PT_GNU_SFRAME			\
// 	    || ((segment)->p_type >= PT_GNU_MBIND_LO			\
// 		&& (segment)->p_type <= PT_GNU_MBIND_HI)))		\
//==================================================================================================
//    /* Any section besides one of type SHT_NOBITS must have file		\
//       offsets within the segment.  */					\
//    && ((sec_hdr)->sh_type == SHT_NOBITS					\
//        || ((bfd_vma) (sec_hdr)->sh_offset >= (segment)->p_offset	\
// 	   && (!(strict)						\
// 	       || ((sec_hdr)->sh_offset - (segment)->p_offset		\
// 		   <= (segment)->p_filesz - 1))				\
// 	   && (((sec_hdr)->sh_offset - (segment)->p_offset		\
// 		+ ELF_SECTION_SIZE(sec_hdr, segment))			\
// 	       <= (segment)->p_filesz)))				\
//==================================================================================================
//    /* SHF_ALLOC sections must have VMAs within the segment.  */		\
//    && (!(check_vma)							\
//        || ((sec_hdr)->sh_flags & SHF_ALLOC) == 0			\
//        || ((sec_hdr)->sh_addr >= (segment)->p_vaddr			\
// 	   && (!(strict)						\
// 	       || ((sec_hdr)->sh_addr - (segment)->p_vaddr		\
// 		   <= (segment)->p_memsz - 1))				\
// 	   && (((sec_hdr)->sh_addr - (segment)->p_vaddr			\
// 		+ ELF_SECTION_SIZE(sec_hdr, segment))			\
// 	       <= (segment)->p_memsz)))					\
//==================================================================================================
//    /* No zero size sections at start or end of PT_DYNAMIC nor		\
//       PT_NOTE.  */							\
//    && (((segment)->p_type != PT_DYNAMIC					\
// 	&& (segment)->p_type != PT_NOTE)				\
//        || (sec_hdr)->sh_size != 0					\
//        || (segment)->p_memsz == 0					\
//        || (((sec_hdr)->sh_type == SHT_NOBITS				\
// 	    || ((bfd_vma) (sec_hdr)->sh_offset > (segment)->p_offset	\
// 	        && ((sec_hdr)->sh_offset - (segment)->p_offset		\
// 		    < (segment)->p_filesz)))				\
// 	   && (((sec_hdr)->sh_flags & SHF_ALLOC) == 0			\
// 	       || ((sec_hdr)->sh_addr > (segment)->p_vaddr		\
// 		   && ((sec_hdr)->sh_addr - (segment)->p_vaddr		\
// 		       < (segment)->p_memsz))))))
//==================================================================================================
 }

void Elfer::mapSegmentsAndSections()
{
    for(auto& segment : m_programHeaderTable.get())
    {
        std::cout << "Mapping " << segment.getType();
        for(auto& section : m_sectionHeaderTable.get())
        {
            auto sectionName = m_sectionHeaderTable.str_sh_name_in_section_string_table(section.get_sh_name());
            if(isSectionInSegment( segment, section ))
            {
                std::cout  << " " << sectionName;
            }
        }
        std::cout << std::endl;
    }
}

void Elfer::load(std::string file)
{
    m_elfHeader.load(file);
    m_programHeaderTable.load(file,
                                m_elfHeader.getProgramHeaderOffset(),
                                m_elfHeader.getProgramHeaderItemSize(),
                                m_elfHeader.getProgramHeaderItemNum());
    m_sectionHeaderTable.load(file,
                                m_elfHeader.getSectionHeaderOffset(),
                                m_elfHeader.getSectionHeaderItemSize(),
                                m_elfHeader.getSectionHeaderItemNum());


    m_sectionHeaderTable.loadSectionStringTable(file,
                                        m_elfHeader.getSectionStringTableIndex());

    m_sectionHeaderTable.loadStringTable(file);
    m_sectionHeaderTable.loadSymbolTable(file);

    m_sectionHeaderTable.loadDynamicStringTable(file);
    m_sectionHeaderTable.loadDynamicSymbolTable(file);

    mapSegmentsAndSections();
}

void Elfer::dump()
{
    // m_elfHeader.dump();
    // m_programHeaderTable.dump();
    // m_sectionHeaderTable.dump();
    // m_sectionHeaderTable.dumpSectionStringTable();
    // m_sectionHeaderTable.dumpStringTable();
    // m_sectionHeaderTable.dumpSymbolTable();
    // m_sectionHeaderTable.dumpDynamicStringTable();
    // m_sectionHeaderTable.dumpDynamicSymbolTable();
}