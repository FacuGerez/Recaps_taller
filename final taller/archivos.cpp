
// Mas apuntes ademas del pdf aca:
// https://jordafiuba.notion.site/a0ac853716dc4be4b25a810ca899a71f?v=e83daba8dafa4c5ab65587607ae9bfb5

#include <cstdio>
#include <cstdint>
#include <unistd.h>

// Escribir un programa ISO C que procese el archivo “nros2bytes.dat” sobre sí mismo,
// duplicando los enteros de 2 bytes múltiplos de 3.

int main(){
    FILE *archivo = fopen("nros2bytes.dat", "r+b");
    if(archivo == NULL) return -1;

    uint16_t number;
    while (fread(&number, sizeof(uint16_t), 1, archivo) == 1){
        if (number % 3 == 0){
            fseek(archivo, -sizeof(uint16_t), SEEK_CUR);
            number *= 2;
            fwrite(&number, sizeof(uint16_t), 1, archivo);
        }
    }

    if (ftruncate(fileno(archivo), ftell(archivo)) == -1) {
        std::printf("Error truncando el archivo\n");
    }
    fclose(archivo);
    return 0;
}


/*
Modos de apertura de archivos (fopen)
Modo	Descripción
"r"     Abre el archivo para lectura. Debe existir.
"w"     Abre el archivo para escritura. Si existe, lo sobrescribe; si no, lo crea.
"a"     Abre el archivo para añadir datos al final. Si no existe, lo crea.
"r+"	Abre el archivo para lectura y escritura sin sobrescribirlo. Debe existir.
"w+"	Abre el archivo para lectura y escritura, pero borra su contenido si existe. Si no existe, lo crea.
"a+"	Abre el archivo para lectura y escritura, pero solo permite escribir al final. Si no existe, lo crea.

"rb", "wb",
"ab", "rb+",    Igual que los anteriores, pero para archivos binarios.
"wb+", "ab+"


Constantes de fseek
Constante	Descripción
SEEK_SET	Posiciona el puntero al inicio del archivo + el offset dado.
SEEK_CUR	Posiciona el puntero en la posición actual + el offset.
SEEK_END	Posiciona el puntero al final del archivo + el offset (normalmente negativo para retroceder).
*/


/*
| Función   | Descripción                                           | Sintaxis                                                   | Parámetros                                              | Utilidad / Uso                                           |
|-----------|------------------------------------------------------|------------------------------------------------------------|----------------------------------------------------------|----------------------------------------------------------|
| fopen     | Abre un archivo en un modo específico.               | FILE* fopen(const char* filename, const char* mode);       | - filename: Nombre del archivo.                         | Abre archivos para lectura, escritura o actualización.  |
|           |                                                      |                                                            | - mode: Modo de apertura ("r", "w", "a", "rb", etc.).   |                                                          |
| fclose    | Cierra un archivo previamente abierto.               | int fclose(FILE* stream);                                  | - stream: Puntero al archivo.                           | Libera recursos y guarda cambios en el archivo.         |
| fread     | Lee datos binarios desde un archivo.                 | size_t fread(void* ptr, size_t size, size_t count, FILE* stream); | - ptr: Dirección donde se almacenarán los datos.        | Lee datos de un archivo binario en bloques de un tamaño fijo. |
|           |                                                      |                                                            | - size: Tamaño de cada elemento.                        |                                                          |
|           |                                                      |                                                            | - count: Cantidad de elementos a leer.                  |                                                          |
|           |                                                      |                                                            | - stream: Archivo.                                       |                                                          |
| fwrite    | Escribe datos binarios en un archivo.                | size_t fwrite(const void* ptr, size_t size, size_t count, FILE* stream); | - ptr: Dirección de los datos a escribir.              | Guarda datos binarios en un archivo.                    |
|           |                                                      |                                                            | - size: Tamaño de cada elemento.                        |                                                          |
|           |                                                      |                                                            | - count: Cantidad de elementos a escribir.              |                                                          |
|           |                                                      |                                                            | - stream: Archivo.                                       |                                                          |
| fseek     | Mueve el puntero del archivo a una posición específica. | int fseek(FILE* stream, long offset, int origin);         | - stream: Archivo.                                       | Controla la posición de lectura/escritura dentro del archivo. |
|           |                                                      |                                                            | - offset: Cantidad de bytes a mover.                    |                                                          |
|           |                                                      |                                                            | - origin: Posición de referencia (SEEK_SET, SEEK_CUR, SEEK_END). |                                                          |
| ftell     | Retorna la posición actual del puntero del archivo.  | long ftell(FILE* stream);                                  | - stream: Archivo.                                       | Útil para saber en qué posición del archivo está el puntero. |
| rewind    | Reinicia el puntero del archivo al inicio.           | void rewind(FILE* stream);                                | - stream: Archivo.                                       | Devuelve el puntero al inicio del archivo sin necesidad de fseek. |
| fflush    | Fuerza la escritura de datos en el archivo.         | int fflush(FILE* stream);                                 | - stream: Archivo. (Si es NULL, vacía todos los buffers de salida). | Útil para asegurar que los datos se escriban inmediatamente en disco. |
| ftruncate | Corta o extiende el tamaño de un archivo.           | int ftruncate(int fd, off_t length);                      | - fd: Descriptor de archivo.                            | Elimina bytes sobrantes o expande un archivo a un tamaño específico. |
|           |                                                      |                                                            | - length: Nuevo tamaño del archivo.                      |                                                          |
| fileno    | Obtiene el descriptor de archivo de un FILE*.       | int fileno(FILE* stream);                                 | - stream: Archivo.                                       | Necesario para funciones como ftruncate.                |
| fprintf   | Escribe texto formateado en un archivo.             | int fprintf(FILE* stream, const char* format, ...);       | - stream: Archivo.                                       | Similar a printf, pero escribe en un archivo en lugar de la consola. |
|           |                                                      |                                                            | - format: Cadena con formato ("%d %s").                 |                                                          |
|           |                                                      |                                                            | - Otros valores según el formato.                       |                                                          |
| fscanf    | Lee texto formateado desde un archivo.              | int fscanf(FILE* stream, const char* format, ...);        | - stream: Archivo.                                       | Similar a scanf, pero lee desde un archivo.             |
|           |                                                      |                                                            | - format: Cadena con formato ("%d %s").                 |                                                          |
|           |                                                      |                                                            | - Punteros a variables donde almacenar los valores leídos. |                                                          |
| feof      | Verifica si se alcanzó el final de un archivo.      | int feof(FILE* stream);                                   | - stream: Archivo.                                       | Útil para saber si se llegó al final de un archivo durante la lectura. |
| ferror    | Verifica si hubo un error en operaciones de archivo. | int ferror(FILE* stream);                                 | - stream: Archivo.                                       | Ayuda a detectar errores en la manipulación de archivos. |

*/
