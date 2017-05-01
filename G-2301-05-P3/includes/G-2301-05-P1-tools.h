#ifndef _TOOLS_H
#define _TOOLS_H

#include "G-2301-05-P1-types.h"

/**
 * @brief daemoniza el proceso
 * el proceso queda en segundo plano como proceso de init 
 *
 */
void daemonizar();

/**
 * @brief identifica y registra un error a la vez que devuelve ese mismo error
 * esta función es específica para errores de tipo long int
 *
 * @param returnValue el error a registrar y devolver
 * @param msg el mensaje de error previo al nombre del error
 *
 * @return el error registrado en returnValue
 */
long int logIntError(long int returnValue, char * msg);

/**
 * @brief identifica y registra un error a la vez que devuelve ese mismo error
 * esta funcion es especifica para los errores de tipo puntero
 *
 * @param returnValue el error a devolver
 * @param msg el mensaje de error
 *
 * @return el error registrado en returnValue
 */
void* logPointerError(void* returnValue , char * msg);

/**
 * @brief registra un mensaje de error
 * 
 * @param msg el mensaje de error a registrar
 */
void logVoidError(char * msg);

/**
 * @brief reserva memoria para una String que contiene le dirección IP de un cliente en formato estandar: xxx.xxx.xxx.xxx
 *
 * @param client la estructura que contiene la IP a encontrar
 * @param ip la dirección de una String donde guardaremos el resultado
 *
 * @return el puntero a la String resultado
 */
char* getIP(struct sockaddr_in* client, char** ip);

/**
 * @brief guarda en hostname el nombre del dispositivo dev
 *
 * @param dev el dispositivo cuyo nombre deseamos encontrar
 * @param hostname la dirección de la String donde escribir el nombre del dispositivo
 *
 * @return IRC_OK si todo va bien
 */
int getHostName(struct sockaddr_in *dev, char** hostname);

/**
 * @brief guarda en nick el nickname del usuario asociado con el socket
 *
 * @param socket el socket que identifica la conexión con el usuario
 * @param nick la dirección de la String donde guardar
 *
 * @return IRC_OK si todo fue bien. El error si no
 */
int getNickFromSocket(int socket, char** nick);

/**
 * @brief obtiene el socket del nick
 *
 * @param socket el socket a obtener
 * @param nick nick a comprobar
 *
 * @return IRC_OK si fue bien, otra cosa si no
 */
int getSocketFromNick(int* socket, char* nick);

/**
 * @brief obtiene el away del socket
 *
 * @param socket el socket a obtener
 * @param away cadena away
 *
 * @return IRC_OK si fue bien, otra cosa si no
 */
int getAwayFromSocket(int socket, char** away);

#endif