#include <iostream>
#include <vector>

int main(){
    std::vector<int> first;
    std::vector<int> second (1000,33);
    std::vector<int> third (second.begin(),second.end());
    std::vector<int> fourth (third);

    return 0;
}
