#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <forward_list>

int main(){
    std::forward_list foo = {1, 2, 3, 4, 5,16, 6, 7, 8, 9, 10};
    auto it = std::find(foo.begin(), foo.end(), 16);

    if (it != foo.end()) {
        std::cout << "Encontrado!\n";
    }

    return 0;
}
