#include <cstdio>
#include <cstdint>

int main(int argc, char* argv[]) {
    int x;
    int y;
    x = sizeof(char);
    y = sizeof(uint16_t);
    printf("%d\n", x);
    printf("%d\n", y);
    return 0;
}
