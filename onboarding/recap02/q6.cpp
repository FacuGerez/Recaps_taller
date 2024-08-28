#include <cstdio>
#include <cstdint>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    printf("big endian\n");
    uint32_t i = 0x41424344;
    uint8_t  b = (uint8_t) i;  // vemos un int como otro
    char     c = (char) i;     // vemos un int como un char de 1 byte
    uint32_t q = i >> 8;       // operacion entre ints
    uint32_t a = i &  1;       // operacion entre ints
    uint32_t z = i %  2;       // operacion entre ints
    printf("i= 0x%X\n", i);
    // Imprimir el número en formato decimal
    printf("i en dec= %u\n", i);
    printf("b= %x\n", b);
    printf("c= %x\n", c);
    printf("q= 0x%X\n", q);
    // Imprimir el número en formato decimal
    printf("q en dec= %u\n", q);
    printf("a= %x\n", a);
    printf("z= %x\n", z);

    printf("little endian\n");
    i = 0x41424344;
    i = ntohl(i);
    b = (uint8_t) i;  // vemos un int como otro
    c = (char) i;     // vemos un int como un char de 1 byte
    q = i >> 8;       // operacion entre ints
    a = i &  1;       // operacion entre ints
    z = i %  2;       // operacion entre ints
    printf("i= 0x%X\n", i);
    // Imprimir el número en formato decimal
    printf("i en dec= %u\n", i);
    printf("b= %x\n", b);
    printf("c= %x\n", c);
    printf("q= 0x%X\n", q);
    // Imprimir el número en formato decimal
    printf("q en dec= %u\n", q);
    printf("a= %x\n", a);
    printf("z= %x\n", z);
    return 0;
}
