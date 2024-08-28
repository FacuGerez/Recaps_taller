#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

int main()
{
    std::string bin = {'\x12', '\x12', '\x12', '\x12'};
    std::istringstream f(bin);
    std::vector<char> buf(512, 0);
    f.read(&buf[0], 512);
    std::cout << buf[0] << std::endl;
    return 0;
}

