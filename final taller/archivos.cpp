
#include <cstdio>

int prueba1(char *nombre){
    FILE *archivo = fopen(nombre, "r+b");
    if(archivo == NULL) return -1;


    uint16_t number;
    while (fread(&number, sizeof(uint16_t), 1, archivo) == 1){
        if (number % 3 == 0){
            fseek(archivo, -sizeof(uint16_t), SEEK_CUR);
            number = number * 2;
            fwrite(&number, sizeof(uint16_t), 1, archivo);
        }
    }

    if (ftruncate(fileno(archivo), ftell(archivo)) == -1) {
        std::printf("Error truncando el archivo\n");
    }
    fclose(archivo);
    return 0;

}
