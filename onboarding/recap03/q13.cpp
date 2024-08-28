#include <fstream>
#include <iostream>
#include <string>

int main()
{
    //doc oficial https://en.cppreference.com/w/cpp/io/basic_fstream
    //no anda porque lo copie tal cual y no cambie casi nada xd
    std::string filename{"q13.txt"};
    std::fstream s{filename, s.binary | s.trunc | s.in | s.out};

    if (!s.is_open())
        std::cout << "failed to open " << filename << '\n';
    else
    {
        // write
        double d{3.14};
        s.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
        s << 123 << "abc";                              // text output

        // for fstream, this moves the file position pointer (both put and get)
        s.seekp(0);

        // read
        d = 2.71828;
        s.read(reinterpret_cast<char*>(&d), sizeof d); // binary input
        int n;
        std::string str;
        if (s >> n >> str)                             // text input <----- la respuesta es esta linea
            std::cout << "read back from file: " << d << ' ' << n << ' ' << str << '\n';
    }
}
