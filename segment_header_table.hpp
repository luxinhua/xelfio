#ifndef __SEGMENT_HEADER_TABLE_H__
#define __SEGMENT_HEADER_TABLE_H__

#include "common.hpp"

class SegmentHeader{
public:
    SegmentHeader() = default;
    ~SegmentHeader() = default;

private:
    

};

class SegmentHeaderTable{
public:
    SegmentHeaderTable() = default;
    ~SegmentHeaderTable() = default;

private:
    std::vector<SegmentHeader> m_segmentHeaderTable;

};

#endif