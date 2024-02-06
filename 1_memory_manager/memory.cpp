#include "memory.hpp"
#include "address.hpp"
#include <cstdint>
#include <iomanip>

bool Memory::existPage(Address addr)
{
    if (m_mem.find(addr.m_Dir) != m_mem.end()){
        if (m_mem[addr.m_Dir].find(addr.m_page) == m_mem[addr.m_Dir].end()){
            return false;
        }
    }
    else{
        return false;
    }

    return true;
}

void Memory::allocPage(Address addr)
{
    if (m_mem.find(addr.m_Dir) == m_mem.end()){
        m_mem[addr.m_Dir] = PageDir();
    }

    if (m_mem[addr.m_Dir].find(addr.m_page) == m_mem[addr.m_Dir].end()){
        m_mem[addr.m_Dir][addr.m_page] = Page();
    }
}

uint8_t Memory::readbyte(uint32_t addr)
{
    auto address = Address{addr};

    if(!existPage(address))
    {
        allocPage(address);
    }

    return m_mem[address.m_Dir][address.m_page][address.m_offset];
}

void Memory::writebyte(uint32_t addr, uint8_t data)
{
    auto address = Address{addr};

    if(!existPage(address))
    {
        allocPage(address);
    }

    // std::cout << "m_Dir    " << std::hex << address.m_Dir << std::endl;
    // std::cout << "m_page   " << std::hex << address.m_page << std::endl;
    // std::cout << "m_offset " << std::hex << address.m_offset << std::endl;

    m_mem[address.m_Dir][address.m_page][address.m_offset] = data;
}

void Memory::write64(uint32_t addr, uint64_t data)
{
    uint8_t data8bit{0};

    for(int index=0; index<8; index++)
    {
        data8bit = static_cast<uint8_t>(data>>(index * 8));
        writebyte(addr+index , data8bit);
    }
}

void Memory::dump()
{
#define LINE_ITEMS_NUM 0x20

    uint32_t lineItemNum{LINE_ITEMS_NUM};
    std::array<uint8_t, LINE_ITEMS_NUM> line;

    uint32_t sum{0};

    std::cout << "Memory Dump: " << std::endl;

    for(auto& dir : m_mem)
    {
        for(auto& page : dir.second)
        {
            // std::cout << std::endl;
            // std::cout << "Dir: " << std::hex << dir.first << std::endl;
            // std::cout << "    " ;
            // std::cout << "Page: " << std::hex << page.first << std::endl;

            for (uint32_t index=0; index <= 0x1000; index++)
            {
                if(((index%lineItemNum) == 0) && (index != 0) )
                {
                    sum = 0;
                    for (auto & item: line)
                    {
                        sum += item;
                    }
                    if (sum == 0)
                    {
                        line[index%lineItemNum] = page.second[index];
                        continue;
                    }

                    std::cout << std::hex << std::setw(8) << std::setfill('0') << std::right
                                << Address(dir.first, page.first, index-(lineItemNum)).value() << " : ";

                    for (auto & item: line)
                    {
                        std::cout << std::hex << std::setw(2) << std::setfill('0') << std::right
                                << +item << "  ";
                    }

                    line.fill(0);

                    std::cout << std::endl;
                }

                line[index%lineItemNum] = page.second[index];
            }

            {
                sum = 0;
                for (auto & item: line)
                {
                    sum += item;
                }
                if (sum != 0)
                {
                    std::cout << std::hex << std::setw(8) << std::setfill('0') << std::right
                            << Address(dir.first, page.first, 0x1000-(0x1000%lineItemNum)).value() << " : ";

                    for (auto & item: line)
                    {
                        std::cout << std::hex << std::setw(2) << std::setfill('0') << std::right
                            << +item << "  ";
                    }
                }
            }
        }
    }
    // std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    auto m = Memory();
    m.writebyte(Address(0x0, 0x0, 0x0).value(), uint8_t(0x1));
    m.writebyte(Address(0x0, 0x0, 0x10).value(), uint8_t(0x7));
    m.writebyte(Address(0x0, 0x0, 0xF0).value(), uint8_t(0x7));
    m.writebyte(Address(0x0, 0x0, 0xFF0).value(), uint8_t(0x2));
    m.writebyte(Address(0x0, 0x0, 0xFFF).value(), uint8_t(0x3));

    m.writebyte(Address(0x1, 0x1, 0x1).value(), uint8_t(0x4));

    m.write64(Address(0x2,0x3,0x00).value(), uint64_t{0xAAAAAAAAAAAAAAAA});
    m.write64(Address(0x2,0x3,0x10).value(), uint64_t{0xBBBBBBBBBBBBBBBB});
    m.write64(Address(0x2,0x3,0x20).value(), uint64_t{0xCCCCCCCCCCCCCCCC});
    m.write64(Address(0x2,0x3,0x40).value(), uint64_t{0xCCCCCCCCCCCCCCCC});
    m.write64(Address(0x2,0x3,0x50).value(), uint64_t{0xDDDDDDDDDDDDDDDD});
    m.write64(Address(0x2,0x3,0x60).value(), uint64_t{0xFFFFFFFFFFFFFFFF});

    m.writebyte(Address(0x3FF, 0x3FF, 0xFF0).value(), uint8_t(0x5));
    m.writebyte(Address(0x3FF, 0x3FF, 0xFFF).value(), uint8_t(0x6));
    m.writebyte(Address(0x3FF, 0x3FF, 0xFFe).value(), uint8_t(0xA));

    // std::cout << "adddress " << std::hex << Address(0x3FF, 0x3FF, 0xFFe).value() << "  " << +m.readbyte(Address(0x3FF, 0x3FF, 0xFFe).value()) << std::endl;
    // std::cout << "adddress " << std::hex << Address(1, 1, 1).value() << "  " << +m.readbyte(Address(1, 1, 1).value()) << std::endl;
    // std::cout << "adddress " << std::hex << Address(0, 0, 0).value() << "  " << +m.readbyte(Address(0, 0, 0).value()) << std::endl;

    m.dump();

    return 0;
}
