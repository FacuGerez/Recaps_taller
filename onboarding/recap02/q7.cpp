#include <cstdio>
#include <cstdint>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    printf("little endian\n");
    char buf[4] = {0x41, 0x42, 0x43, 0x44};
    uint32_t ret = *(uint32_t*) buf;  // vemos un buffer de N bytes como un int
    uint16_t r1 = *(uint16_t*) buf;    // vemos los 2 primeros bytes como un int
    uint16_t r2 = *((uint16_t*) buf+1);  // vemos los 2 ultimos bytes como un int
    printf("buf= %s\n", buf);
    printf("ret= 0x%X\n", ret);
    printf("r1= 0x%X\n", r1);
    printf("r2= 0x%X\n", r2);
    return 0;
}
