#include <iostream>
#include <map>


int main(){
    std::map<char, int> f;
    for (auto &c : "It's a sad truth that those who shine brightest often burn fastest") {
        f[c] += 1;
    }

    for (auto &kv : f) {
        std::cout << kv.first << ": " << kv.second << "\n";
    }

    return 0;
}
