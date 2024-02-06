#ifndef __SECTION_H__
#define __SECTION_H__

#include "common.hpp"

class Section{
public:
    Section() = default;
    ~Section() = default;

private:

};

class Sections{
public:
    Sections() = default;
    ~Sections() = default;

private:
    std::vector<Section> m_sections;

};



#endif