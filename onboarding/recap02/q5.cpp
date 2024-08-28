#include <cstdio>
#include <cstdint>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    uint32_t i = 0x41424344;
    uint32_t outval = htonl(i);
    printf("%x\n", i);
    printf("%x\n", outval);
    char *p = (char*) &outval;
    printf("%x\n", p[0]);
    printf("%x\n", p[1]);
    printf("%x\n", p[2]);
    printf("%x\n", p[3]);
    return 0;
}
