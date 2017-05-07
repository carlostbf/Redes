#ifndef _SOCKET_H
#define _SOCKET_H

#include "G-2301-05-P1-tools.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define SERVERINFO "servidor de Mambru, DoReMi DoReFa"
#define SERVERNAME "Mambru@war"

/**
 * @brief abre un socket TCP
 *
 * @return el socket o -1 en caso de que hubiera un fallo
 */
int openSocket_TCP();

/**
 * @brief enlaza un socket TCP con un puerto a la vez que rellena los campos de la estructura sockaddr_in de serv_addr
 *
 * @param sockfd el socket a enlazar
 * @param portno el puerto al que enlazar el socket
 * @param serv_addr la dirección de una estructura sockaddr_in en donde se guardarán los valores relativos a esta conexión
 *
 * @return -1 en caso de error, un numero positivo en otro caso
 */
int bindSocket_TCP(int sockfd, int portno, struct sockaddr_in* serv_addr);

/**
 * @brief prepara un socket para aceptar una conexión entrante
 *
 * @param sockfd el socket que está escuchando conexiones entrantes
 * @param cli_addr la dirección de una estructura sockaddr_in donde se rellenaran los valores relativos al otro extremo de la conexión
 *
 * @return -1 en caso de error y un nuevo socket (valor mayor que 0) en el que se mantendrá la comunicación con el otro extremo
 */
int acceptConnection(int sockfd, struct sockaddr_in* client_addr);

/**
 * @brief trata de conectarse a un puerto de un host
 *
 * @param sockfd el socket que intentará realizar la conexión
 * @param hostname el nombre de la maquina a la que se desea conectarse
 * @param portno el puerto al que se desea conectar
 *
 * @return en caso de error, un valor negativo. De lo contrario, un nuevo socket en el que se mantendrá la comunicación con el otro extremo
 */
int connectTo(int sockfd, char* hostname, int portno);

/**
 * @brief trata de conectarse a un puerto de una IP
 *
 * @param sockfd el socket que intentará realizar la conexión
 * @param IP la dirección IP en notación estándar a la que conectarse
 * @param portno el puerto al que se desea conectar
 *
 * @return en caso de error, un valor negativo. De lo contrario, un nuevo socket en el que se mantendrá la comunicación con el otro extremo
 */
int connectToIP(int sockfd, char* IP, int portno);

/**
 * @brief abre un socket UDP
 *
 * @return el socket o -1 en caso de que hubiera un fallo
 */
int openSocket_UDP();

/**
 * @brief enlaza un socket UDP con un puerto a la vez que rellena los campos de la estructura sockaddr_in de serv_addr
 *
 * @param sockfd el socket a enlazar
 * @param portno el puerto al que enlazar el socket
 * @param serv_addr la dirección de una estructura sockaddr_in en donde se guardarán los valores relativos a esta conexión
 *
 * @return -1 en caso de error, un numero positivo en otro caso
 */
int bindSocket_UDP(int sockfd, int portno, struct sockaddr_in* serv_addr);

/**
 * @brief obtiene el puerto al que ha sido enlazado el socket sockfd y tambien rellena los campos de serv
 *
 * @param sockfd el socket (enlazado) del que queremos sacar su puerto
 * @param serv la estructura sockaddr_in en la que se guardan los datos referentes a nuestro extremo de la conexion
 *
 * @return el puerto del socket. Si hubo un error, -1
 */
int getSocketPort(int sockfd, struct sockaddr_in* serv_addr);

/**
 * @brief inicializa correctamente la estructura con datos para una conexion UDP
 *
 * @param si_other la estructura que se inicializara
 * @param port el puerto del otro sistema con el que se desea comunicar
 * @param hostname el hostname del otro sistema con el que se desea comunicar
 *
 * @return -1 si hubo un error, IRC_OK si todo fue bien
 */
int iniAddrUDP(struct sockaddr_in *si_other, int port, char* hostname);
#endif