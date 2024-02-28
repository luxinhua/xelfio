#ifndef __CPU_H__
#define __CPU_H__

#include "common.hpp"

// struct core_registers{
//     "zero", // x0
//     "ra",   // x1
//     "sp",   // x2
//     "gp",   // x3
//     "tp",   // x4
//     "t0",   // x5
//     "t1",   // x6
//     "t2",   // x7
//     "s0",   // x8
//     "s1",   // x9
//     "a0",   // x10
//     "a1",   // x11
//     "a2",   // x12
//     "a3",   // x13
//     "a4",   // x14
//     "a5",   // x15
//     "a6",   // x16
//     "a7",   // x17
//     "s2",   // x18
//     "s3",   // x19
//     "s4",   // x20
//     "s5",   // x21
//     "s6",   // x22
//     "s7",   // x23
//     "s8",   // x24
//     "s9",   // x25
//     "s10",  // x26
//     "s11",  // x27
//     "t3",   // x28
//     "t4",   // x29
//     "t5",   // x30
//     "t6",   // x31
// }

class Core{
public:
    Core() = default;
    ~Core() = default;

    void fetch();
    void decode();
    void execute();
    void writeBackMem();

private:

};






#endif