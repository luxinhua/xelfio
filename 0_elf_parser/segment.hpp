#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "common.hpp"

class Segment{
public:
    Segment() = default;
    ~Segment() = default;

private:

};

class Segments{
public:
    Segments() = default;
    ~Segments() = default;

private:
    std::vector<Segment> m_segments;
};

#endif