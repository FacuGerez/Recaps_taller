// Segmentos de memoria

/*
    * Code segment: Contiene el código del programa.
    * Data segment: Contiene las variables globales y locales (estaticas) creadas al inicio del programa.
    * Stack segment: Contiene las variables locales y los parámetros de las funciones creadas apenas
    *                empieza una funcion o bloque de codigo y eliminadas apenas termina este.
    * Heap segment: Contiene la memoria dinámica controlada por el programador en run-time.
*/

// Proceso de codigo fuente a ejecutable

/*
    * Preprocesador: Elimina comentarios, incluye archivos .h, reemplaza macros, reemplaza los defines, etc.
    * Compilador: Traduce el código fuente a código objeto (ensamblador).
    * Enlazador (linkeo): Combina los códigos objetos y las librerías para generar un archivo ejecutable.
*/

// Variables globales

/*
    * Las variables globales son aquellas que se declaran fuera de los bloques de codigo.
    * Estas variables se almacenan en el data segment.
    * Las variables globales tienen un tiempo de vida igual al tiempo de ejecución del programa.
    * Las variables globales tienen un alcance global, es decir, pueden ser accedidas desde cualquier parte del programa.
    * Si no se les pone static, las variables globales son visibles en otros archivos.
*/

// Variables locales

/*
    * Las variables locales son aquellas que se declaran dentro de un bloque de codigo.
    * Las variables locales tienen un tiempo de vida igual al tiempo de ejecución del bloque de codigo en el que fueron declaradas.
    * Las variables locales tienen un alcance local, es decir, solo pueden ser accedidas desde el bloque de codigo en el que fueron declaradas.
*/

// Static

/*
    * La palabra clave static se puede usar para declarar variables globales y locales.
    * El tiempo de vida de una variable declarada con static es igual al tiempo de ejecución del programa.
    * Si se usa static en una variable global, esta variable SOLO SERA VISIBLE en el archivo en el que fue declarada.
    * Si se usa static en una variable local, esta variable MANTENDRA su valor entre llamadas a la función en la que fue declarada.
    * Si se usa static en un atributo de una clase, este atributo sera compartido por todas las instancias de la clase.
    * Si se usa static en un método de una clase, este método podra ser llamado sin necesidad de instanciar la clase.
    * Si se usa static, la variable o método pertenecera al segmento de memoria = data segment.
*/

// extern

/*
    * La palabra clave extern se utiliza para declarar variables globales o funciones que se encuentran en otros archivos.
*/

// Espacio de cada tipo de dato en arquitectura de 64 bits

/*   NO OLVIDAR JAMAS EL PADDING QUE SE AGREGA PARA QUE LOS DATOS ESTEN ALINEADOS EN MEMORIA
    (por ejemplo, un int de 4 bytes se almacena en una dirección de memoria que es múltiplo de 4).
    (por ejemplo, un char de 1 byte se almacena y se le agrega 3 bytes de padding para que el siguiente dato este alineado).
    * char: 1 byte
    * short: 2 bytes
    * int: 4 bytes
    * long: 8 bytes
    * long long: 8 bytes
    * float: 4 bytes
    * double: 8 bytes
    * long double: 16 bytes
    * pointer: 8 bytes
*/

// Archivos .h

/*
    * Los archivos .h se utilizan para declarar clases, funciones, variables globales, constantes, macros y templates.
    * Los archivos .h no se compilan, solo se incluyen en otros archivos.
    * Los archivos .h se utilizan para compartir una interfaz entre diferentes archivos.
    * Los archivos .h se utilizan para separar la interfaz de la implementación.
*/

// Archivos .cpp

/*
    * Los archivos .cpp se utilizan para implementar las clases, funciones, variables globales, constantes, macros y templates declarados en los archivos .h.
    * Los archivos .cpp se compilan.
    * Los archivos .cpp se utilizan para separar la implementación de la interfaz.
*/

// Ventajas de separacion de .h y .cpp

/*
    * Facilita la lectura del código.
    * Facilita la reutilización del código ya que los .h actuan como una biblioteca sin necesidad de ver el código fuente.
    * Facilita la modificación del código ya que se pueden modificar los .cpp sin necesidad de modificar los .h y solo recompilar los .cpp.
    * Facilita la encapsulación del código ya que se pueden ocultar los detalles de implementación en los .cpp.
*/

// struct y class

/*
    * struct y class son dos palabras clave que se utilizan para definir clases en C++.
    * La única diferencia entre struct y class es que los miembros de una struct son públicos por defecto y los de una class son privados por defecto.
    * En C++ se recomienda usar class en lugar de struct para definir clases.
*/

// Constructores y destructores

/*
    * Un constructor es un método especial que se llama cuando se crea un objeto.
    * Un constructor tiene el mismo nombre que la clase y no tiene tipo de retorno.
    * Un constructor puede tener parámetros.
    * Un constructor puede tener inicializadores de miembros.
    * Un destructor es un método especial que se llama cuando se destruye un objeto.
    * Un destructor tiene el mismo nombre que la clase precedido por el símbolo ~ y no tiene parámetros ni tipo de retorno.
    * Un ejemplo de un constructor y destructor seria:
                Clase() { cout << "Constructor" << endl; }
                ~Clase() { cout << "Destructor" << endl; }
*/

// Constructor move y el Operador= move

/*
    * Un constructor move es un constructor que se llama cuando se crea un objeto a partir de otro objeto.
    * Cuando se llama a un constructor move, el objeto original pierde su estado o queda en un estado indefinido.
    * Es eficiente ya que evita copiar el objeto original.
    * Transfiere la propiedad de los recursos del objeto original al objeto nuevo.
    * Cuando este no es definido, el compilador crea uno por defecto.
    * Para desactivar el constructor move se puede usar la palabra clave delete (=delete).
    * Un ejemplo de este seria:
                Clase(Clase&&) = delete;

    * El operador= move es un operador que se llama cuando se asigna un objeto a otro objeto.
    * Cuando se llama al operador= move, el objeto original pierde su estado o queda en un estado indefinido.
    * Se comporta de manera similar al constructor move.
    * Un ejemplo de este seria:
                Clase& operator=(Clase&&) = delete;
*/

// Constructor copy y el Operador= copy

/*
    * Un constructor copy es un constructor que se llama cuando se crea un objeto a partir de otro objeto.
    * Cuando se llama a un constructor copy, se crea una copia del objeto original.
    * Es ineficiente ya que copia el objeto original.
    * Cuando este no es definido, el compilador crea uno por defecto.
    * Para desactivar el constructor copy se puede usar la palabra clave delete (=delete).
    * Un ejemplo de este seria:
                Clase(const Clase&) = delete;

    * El operador= copy es un operador que se llama cuando se asigna un objeto a otro objeto.
    * Cuando se llama al operador= copy, se crea una copia del objeto original.
    * Se comporta de manera similar al constructor copy.
    * Un ejemplo de este seria:
                Clase& operator=(const Clase&) = delete;
*/

// RAII

//Es una patrón de diseño que nos permite encapsular la adquisición de recursos y su posterior
//liberación en un solo objeto, nos permite tener implementaciones más seguras, ya que al irse de
//scope cada objeto se les invoca su destructor automáticamente y por ende liberan sus recurso sin
//necesidad de hacer explícitamente

/*
    * RAII (Resource Acquisition Is Initialization) es un patrón de diseño que consiste en adquirir un recurso en el constructor de un objeto y liberar el recurso en el destructor del objeto.
    * RAII garantiza que los recursos se liberarán correctamente incluso en caso de excepción.
    * RAII garantiza una gestión segura de los recursos.
    * RAII se utiliza para gestionar recursos como memoria, archivos, sockets, entre otros.
    * Un ejemplo de RAII seria:
                class Archivo {
                    FILE* file;
                public:
                    Archivo(const char* nombre) {
                        file = fopen(nombre, "r");
                    }
                    ~Archivo() {
                        fclose(file);
                    }
                };
*/

// Namespace

/*
    * Un namespace es un espacio de nombres que permite agrupar un conjunto de elementos (variables, funciones, clases, etc) bajo un mismo nombre.
    * Los namespaces permiten evitar conflictos de nombres entre elementos de un programa.
    * Los namespaces se declaran con la palabra clave namespace seguida del nombre del namespace.
    * Se puede usar using namespace para evitar tener que escribir el nombre del namespace antes de cada elemento.
*/

// Iteradores

/*
    * Los iteradores son objetos que permiten recorrer los elementos de un contenedor.
    * Los iteradores se utilizan para los vector, list, map, set, entre otros.
    * Un ejemplo de iterador seria:
                vector<int> v = {1, 2, 3, 4, 5};
                for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
                    cout << *it << endl;
                }
*/

// Functores

/*
    * Un functor es un objeto que se comporta como una función.
    * Un functor es un objeto que sobrecarga el operador ().
    * Un functor puede tener estado.
    * Un ejemplo de functor seria:
                struct Suma {
                    int operator()(int a, int b) {
                        return a + b;
                    }
                };
                Suma suma;
                cout << suma(1, 2) << endl;
*/

// Smart pointers

/*
    * Los smart pointers son punteros que se encargan de liberar la memoria automáticamente.
    * Los smart pointers se utilizan para evitar fugas de memoria.
    * Existen tres tipos de smart pointers: unique_ptr, shared_ptr y weak_ptr.
    * El unique_ptr es un puntero que es único y no se puede copiar.
    * El shared_ptr es un puntero que se puede compartir entre varios punteros.
    * El weak_ptr es un puntero que no incrementa el contador de referencias.
    * Un ejemplo de smart pointer seria:
                unique_ptr<int> p(new int(5));
                cout << *p << endl;
*/

// Macros

/*
    * Una macro es una secuencia de instrucciones que se expande en tiempo de compilación.
    * Las macros se definen con la palabra clave #define seguida del nombre de la macro y su valor.
    * Las macros se utilizan para definir constantes, funciones, entre otros.
    * Las macros se utilizan para evitar la repetición de código.
    * Las macros se utilizan para mejorar la legibilidad del código.
    * Las macros no ocupan memoria en tiempo de ejecución.
    * Un ejemplo de macro seria:
                #define PI 3.14159
    * Y un ejemplo de macro para una funcion seria:
                #define SUMA(a, b) ((a) + (b))
    * Y cuando se habla de una compilacion condicional, se habla de macros las cuales bajos ciertas
    * condiciones se compilaran y bajo otras no.
    * Un ejemplo de esto seria:
                int main() {
                    #ifdef _WIN32 // Detecta Windows
                        printf("Ejecutando en Microsoft Windows\n");
                    #elif defined(__linux__) // Detecta Linux
                        printf("Ejecutando en Linux\n");
                    #else
                        printf("Sistema operativo no reconocido\n");
                    #endif
                    return 0;
                }
    * Algunas buenas practicas de estas para su definicion son:
                ➔ Usar nombres descriptivos
                ➔ Escribir los nombres de las macros en mayúsculas
                ➔ Declararlas al principio del archivo.
                ➔ Usar paréntesis en las de parámetros para evitar errores inesperados en las
                operaciones.
                ➔ Considerar alternativas como const para valores constantes y funciones inline para
                operaciones, ya que son más seguras y evitan errores típicos de las macros.
                ➔ Las macros se utilizan para evitar la repetición de código.
                ➔ Las macros se utilizan para mejorar la legibilidad del código.
                ➔ Las macros no ocupan memoria en tiempo de ejecución.

*/

// Templates

/*
    * Un template es una plantilla que permite definir clases y funciones genéricas.
    * Un template se declara con la palabra clave template seguida de los parámetros de la plantilla.
    * Estas se declaran en el .h debido a la forma que el compilador maneja los templates durante la compilacion
    * Esto se debe a que los templates no generan codigo hasta que son instanciados con un tipo especifico,
    * por lo tanto el compilador necesita tener acceso tanto a la declaracion como a la deficion del template al momento de instanciarlo.
    * Un ejemplo de template seria:
                template <typename T>
                T suma(T a, T b) {
                    return a + b;
                }
*/

// Metodo virtual

//Los métodos virtuales son métodos cuyo llamado se resuelve en tiempo de ejecución
//(según el objeto en memoria), esto permite que pueda suceder el polimorfismo (en C++, el
//llamado a la función tiene distintos comportamiento según el tipo de objeto).
//A esto se lo conoce como Dynamic Linkage / Late Binding y es necesario declarar el
//método con el modificador “virtual”, ya que de otra forma el llamado se resolvería en tiempo
//de compilación (según la variable), evitando que suceda el polimorfismo.

/*
    * Un método virtual es un método que se puede sobrescribir en una clase derivada.
    * Un método virtual se declara con la palabra clave virtual.
    * Un override es una palabra clave que se utiliza para indicar que un método sobrescribe un método virtual de la clase base.
    * Un ejemplo donde este es impresindible seria:
                class Base {
                public:
                    virtual void imprimir() {
                        cout << "Base" << endl;
                    }
                };
                class Derivada : public Base {
                public:
                    void imprimir() override {
                        cout << "Derivada" << endl;
                    }
                };
*/

// Compilacion condicional

/*
    * La compilación condicional es un proceso que permite compilar diferentes partes de un programa en función de ciertas condiciones.
    * La compilación condicional se realiza con las directivas de preprocesador #if, #ifdef, #ifndef, #else, #elif y #endif.
    * La compilación condicional se utiliza para compilar diferentes partes de un programa en función de la plataforma, el sistema operativo, la arquitectura, entre otros.
    * Un ejemplo de compilación condicional seria:
                #ifdef _WIN32 // Detecta Windows
                    printf("Ejecutando en Microsoft Windows\n");
                #elif defined(__linux__) // Detecta Linux
                    printf("Ejecutando en Linux\n");
                #else
                    printf("Sistema operativo no reconocido\n");
                #endif
*/
