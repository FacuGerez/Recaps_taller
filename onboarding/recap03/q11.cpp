#include <iostream>
#include <list>

int main() {
    std::list<int> lista = {1984, 2022, 101, 33};
    for (auto it = lista.cbegin(); it != lista.cend(); ++it)
        if (*it % 2 == 0) // remover si es par
            lista.erase(it);

    for (int i : lista)
        std::cout << i << "\n";
    return 0;
}
