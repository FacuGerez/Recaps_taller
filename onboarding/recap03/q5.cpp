#include <vector>
#include <list>

int main(){
    std::vector<int> container;

    for (int i = 0; i < 1000; ++i) {
        container.push_back(i);
    }

    std::list<int> container2;
    for (int i = 0; i < 1000; ++i) {
        container2.push_back(i);
    }
    return 0;
}
