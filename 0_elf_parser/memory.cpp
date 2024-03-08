#include "memory.hpp"
#include "address.hpp"
#include <cstdint>
#include <iomanip>
#include <iostream>

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

uint8_t Memory::read8(uint32_t addr)
{
    auto address = Address{addr};

    if(!existPage(address))
    {
        allocPage(address);
    }

    return m_mem[address.m_Dir][address.m_page][address.m_offset].data;
}

void Memory::write8(uint32_t addr, uint8_t data)
{
    auto address = Address{addr};

    if(!existPage(address))
    {
        allocPage(address);
    }

    m_mem[address.m_Dir][address.m_page][address.m_offset].data = data;
    m_mem[address.m_Dir][address.m_page][address.m_offset].status = MemType::Allocated;
}
uint16_t Memory::read16(uint32_t addr)
{
    uint32_t localData{0};
    uint32_t data{0};

    for(uint32_t index=0; index<2; index++)
    {
        localData = read8(addr + index);
        data = data | (localData << (index * 8));
    }

    return data;
}

uint32_t Memory::read32(uint32_t addr)
{
    uint32_t localData{0};
    uint32_t data{0};

    for(uint32_t index=0; index<4; index++)
    {
        localData = read8(addr + index);
        data = data | (localData << (index * 8));
    }

    return data;
}
uint64_t Memory::read64(uint32_t addr)
{
    uint64_t localData{0};
    uint64_t data{0};

    for(uint32_t index=0; index<8; index++)
    {
        localData = read8(addr + index);

        data = data | (localData << (index * 8));
    }

    return data;
}
void Memory::write16(uint32_t addr, uint16_t data)
{
    uint8_t localData{0};

    for(int index=0; index<sizeof(uint16_t); index++)
    {
        localData = static_cast<uint8_t>(data>>(index * 8));
        write8(addr+index , localData);
    }
}
void Memory::write32(uint32_t addr, uint32_t data)
{
    uint8_t localData{0};

    for(int index=0; index<sizeof(uint32_t); index++)
    {
        localData = static_cast<uint8_t>(data>>(index * 8));
        write8(addr+index , localData);
    }
}

void Memory::write64(uint32_t addr, uint64_t data)
{
    uint8_t localData{0};

    for(int index=0; index<sizeof(uint64_t); index++)
    {
        localData = static_cast<uint8_t>(data>>(index * 8));
        write8(addr+index , localData);
    }
}


#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"   /* Yellow */
#define BLUE "\033[34m"   /* Blue */
#define MAGENTA "\033[35m"   /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"   /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"  /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"   /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"   /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"  /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */


void Memory::dump()
{
#define LINE_ITEMS_NUM 0x20

    uint32_t lineItemNum{LINE_ITEMS_NUM};
    std::array<MemCell, LINE_ITEMS_NUM> line;

    uint32_t sum{0};

    std::cout << std::endl;
    std::cout << "Memory Dump: " << std::endl;

    std::cout << std::hex << std::setw(8) << std::setfill('0') << std::right
                 << "########   ";
    for (uint32_t title=0; title<LINE_ITEMS_NUM; title++)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << std::right << title << " ";
    }
    std::cout << std::endl;

    for(auto& dir : m_mem){
        for(auto& page : dir.second){
            for (uint32_t index=0; index <= 0x1000; index++){
                if(((index%lineItemNum) == 0) && (index != 0) ){
                    sum = 0;
                    for (auto & item: line){
                        sum += item.data;
                    }
                    if (sum == 0){
                        line[index%lineItemNum] = page.second[index];
                        continue;
                    }
                    std::cout << std::hex << std::setw(8) << std::setfill('0') << std::right
                                << Address(dir.first, page.first, index-(lineItemNum)).value() << " : ";
                    for (auto & item: line){
                        if (item.status == MemType::Allocated){
                            std::cout << GREEN  << std::hex << std::setw(2) << std::setfill('0') << std::right
                                    << +item.data << RESET << " ";
                        }
                        else{
                            std::cout << std::hex << std::setw(2) << std::setfill('0') << std::right
                                    << +item.data << " ";
                        }
                    }
                    for (auto& item: line)
                    {
                        item.data = 0;
                        item.status = MemType::UnAlloc;
                    }
                    std::cout << std::endl;
                }
                line[index%lineItemNum] = page.second[index];
            }
            {
                sum = 0;
                for (auto & item: line){
                    sum += item.data;
                }
                if (sum != 0){
                    std::cout << std::hex << std::setw(8) << std::setfill('0') << std::right
                            << Address(dir.first, page.first, 0x1000-(0x1000%lineItemNum)).value() << " : ";

                    for (auto & item: line){
                        if (item.status == MemType::Allocated){
                            std::cout << GREEN << std::hex << std::setw(2) << std::setfill('0') << std::right
                                    << +item.data << RESET << " ";
                        }
                        else{
                            std::cout << std::hex << std::setw(2) << std::setfill('0') << std::right
                                    << +item.data << " ";
                        }
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}

// int main(int argc, char const *argv[])
// {
//     auto m = Memory();

//     m.write64(Address(0x2,0x3,0x00).value(), uint64_t{0x0123456789abcdef});
//     m.write64(Address(0x2,0x3,0x10).value(), uint64_t{0x0123456789abcdef});
//     m.write8(Address(0x3FF, 0x3FF, 0xFF0).value(), uint8_t(0x5));

//     m.read64(Address(0x2,0x3,0x00).value());
//     m.read64(Address(0x2,0x3,0x10).value());
//     m.read64(Address(0x3FF, 0x3FF, 0xFF0).value());

//     m.dump();

//     return 0;
// }
