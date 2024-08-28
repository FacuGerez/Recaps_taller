#include <iostream>
#include <algorithm>
#include <list>

template<class T>
void m(const T &z) {
    std::cout << z << " ";
}

int main() {
    std::list<int> l = {1984, 2022, 101};
    std::for_each(l.begin(), l.end(), m<int>);
    return 0;
}
