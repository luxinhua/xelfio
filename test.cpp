#include <fstream>
#include <iostream>

using namespace std;

int afwefa(int argc, char const *argv[])
{
    std::string file{argv[1]};

    uint32_t data;

    std::ifstream fread(file,std::ios::in|std::ios::binary);

    fread.seekg(10, std::ios::beg);

    fread.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;
    fread.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;

    fread.clear();
    fread.close();
    std::cout << "============================" << std::endl;

    std::ifstream fread2(file,std::ios::in|std::ios::binary);

    fread2.seekg(20, std::ios::beg);

    fread2.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;
    fread2.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;
fread2.clear();
    fread2.close();
    std::cout << "============================" << std::endl;

    std::ifstream fread3(file,std::ios::in|std::ios::binary);
    fread3.seekg(10, std::ios::beg);

    fread3.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;
    fread3.read((char *)&data   , sizeof(data));
    std::cout << std::hex << data << std::endl;

fread3.clear();
    fread3.close();
    std::cout << "============================" << std::endl;

    return 0;
}
