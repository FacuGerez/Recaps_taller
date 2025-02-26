// Como lanzar un thread

/*
    * Ejemplo:
    *         - std::thread <nombre>(*function*, *args*);
    *         - std::thread <nombre>([](int x, int y) { return x + y; }, 1, 2);
    * Esperar que termine un thread
    *         - <nombre>.join();
*/

// que es un deadlock

/*dos o más hilos (o procesos) se quedan esperando indefinidamente porque
cada uno necesita un recurso que está siendo bloqueado por otro hilo*/
/*
    * Un deadlock es una situación en la que dos o más hilos de ejecución se bloquean mutuamente
    * esperando que el otro libere un recurso.
*/

// que es un mutex
/*
    * Un mutex es un mecanismo de sincronización que permite a los hilos de ejecución
    * acceder a un recurso compartido de forma segura (uno a la vez).
*/

// que es un std::unique_lock<std::mutex>
/*
    * Un lock es un mecanismo que permite a un hilo de ejecución adquirir un mutex
    * y liberarlo automáticamente al salir de su scope evitando errores de olvido de unlock.
*/

// Cuando usamos un mutex y porque
/*
    * Usamos un mutex cuando queremos proteger un recurso compartido (una critical section) entre hilos de ejecución
    * para evitar problemas de concurrencia (race condition) y garantizar la consistencia de los datos.
*/

// Que es un monitor
/*
    * Un monitor es un mecanismo de sincronización que encapsula un recurso compartido que no conoce al mutex y
    * provee métodos para acceder a él de forma segura (con un mutex interno).
*/

// Que es una race condition
/*
    * Una race condition se debe al acceso no-atómico de lecto/escritura de un recurso compartido.
    * Si el recurso compartido es inmutable o solamente se accede a él para operaciones de lectura, no existe la posibilidad de tal error
*/

// Que es un condition variable
/*
    * Una condition variable es un mecanismo de sincronización que permite a un hilo de ejecución esperar a que se cumpla una condición
    * antes de continuar
    * (por ejemplo, esperar a que un recurso compartido esté disponible).
    * Para ello, se llama a .wait(std::unique_lock<std::mutex>&) para hacer que el hilo se detenga y libere el mutex.
    * Luego, otro hilo puede llamar a .notify_all() para despertar al hilo en espera.
    * La condición que se espera se debe verificar dentro de un bucle while para evitar spurious wakeups (falsos despertares).
    * Si la condición no se cumple, el hilo en espera se vuelve a dormir.
    * Si la condición se cumple, el hilo en espera se despierta y adquiere el mutex automáticamente.
*/
