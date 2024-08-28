#include <cstdio>
#include <cstdint>

int main(int argc, char* argv[]) {
    uint32_t i = 0x41424344;
    printf("%x\n", i);
    char *p = (char*) &i;
    printf("%x\n", p[0]);
    return 0;
}
