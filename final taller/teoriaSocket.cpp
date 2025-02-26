// Que es un socket

/*
    * Un socket es un punto de comunicación entre dos programas que permite el intercambio de datos en una red
    * La IP identifica un dispositivo y el puerto, una aplicación en ese dispositivo.

*/

// TCP (Transmission Control Protocol)

/*
    * TCP es un protocolo de comunicación que permite la comunicación entre procesos en la misma máquina o en máquinas diferentes.
    * TCP es un protocolo de comunicación bidireccional.
    * TCP es un protocolo de comunicación que garantiza la entrega de los datos en orden y sin errores.
    * TCP esta orientado a la conexión.
*/

// UDP (User Datagram Protocol)

/*
    * UDP es un protocolo de comunicación que permite la comunicación entre procesos en la misma máquina o en máquinas diferentes.
    * UDP es un protocolo de comunicación bidireccional.
    * UDP no esta orientado a la conexión sino orientado a los datagramas.
    * UDP no garantiza la entrega de los datos en orden y sin errores o duplicados pero si llegan llegan completos.
*/


// ntohs y htons

/*
    * ntohs: network to host short (sirve para convertir un short de la red a un short del host) (16 bits)
    * ntohl: network to host long (sirve para convertir un long de la red a un long del host) (32 bits)
    * htons: host to network short (sirve para convertir un short del host a un short de la red) (16 bits)
    * htonl: host to network long (sirve para convertir un long del host a un long de la red) (32 bits)
*/


// Ejemplo socket server

/*
int main(int argc, char const *argv[]){
    if (argc != 3) return -1;

    // argumentos para una socket de servidor
    const char *ip = argv[1];
    const char *port = argv[2];

    // crear socket de servidor
    struct addrinfo hints;
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    hints.ai_flags = AI_PASSIVE; // para server (bind)
    struct addrinfo *addr;

    if (getaddrinfo(ip, port, &hints, &addr) != 0) return -1;

    int skt_s = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    if (skt_s == -1){
        freeaddrinfo(addr);
        return -1;
    }

    // bind
    if (bind(skt_s, addr->ai_addr, addr->ai_addrlen) == -1){
        freeaddrinfo(addr);
        close(skt_s);
        return -1;
    }

    freeaddrinfo(addr);

    // listen
    if (listen(skt_s, 1) == -1){
        close(skt_s);
        return -1;
    }

    // accept
    int skt_c = accept(skt_s, NULL, NULL);
    if (skt_c == -1){
        close(skt_s);
        return -1;
    }

    // recibir mensaje
    char byteorcaracter;
    int recibido = recv(skt_c, &byteorcaracter, sizeof(char), 0);

    // enviar mensaje
    //...

    // cerrar sockets
    shutdown(skt_c, SHUT_RDWR);
    close(skt_c);
    shutdown(skt_s, SHUT_RDWR);
    close(skt_s);

    return 0;
}
*/

// Ejemplo socket client

/*
int main(int argc, char const *argv[]){
    if (argc != 3) return -1;

    // argumentos para una socket de servidor
    const char *ip = argv[1];
    const char *port = argv[2];

    // crear socket de servidor
    struct addrinfo hints;
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    hints.ai_flags = 0; // para cliente (connect)
    struct addrinfo *addr;

    if (getaddrinfo(ip, port, &hints, &addr) != 0) return -1;

    int skt_c = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
    if (skt_c == -1){
        freeaddrinfo(addr);
        return -1;
    }

    // conectar con el servidor
    if (connect(skt_c, addr->ai_addr, addr->ai_addrlen) == -1){
        freeaddrinfo(addr);
        close(skt_c);
        return -1;
    }

    freeaddrinfo(addr);

    // enviar y recibir datos
    char byteorcaracter;
    int recibido = recv(skt_c, &byteorcaracter, sizeof(char), 0);

    // cerrar socket
    shoutdown(skt_c, SHUT_RDWR);
    close(skt_c);
    return 0;
}
*/
