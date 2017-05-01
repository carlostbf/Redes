/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ssl.h
 * Author: carlos
 *
 * Created on 11 de abril de 2017, 17:27
 */

#ifndef SSL_H
#define SSL_H

#include <openssl/ssl.h>
#include <openssl/err.h>
#include "G-2301-05-P2-userCommands.h"
/**
 * Esta función se encargará de realizar todas las llamadas necesarias para que la apli-
cación pueda usar la capa segura SSL.
 */
void inicializar_nivel_SSL();

/**
 * Esta función se encargará de inicializar correctamente el contexto que será utilizado para
la creación de canales seguros mediante SSL. Deberá recibir información sobre las rutas a los certificados y
claves con los que vaya a trabajar la aplicación.
 * @param  CAfile certificado de la CA
 * @param  SCfile certificado del servidor/cliente
 * @param  Pfile  clave privada del servidor/cliente
 * @param  CApath ruta del certificado de la CA
 * @return        contexto de la conexión segura
 */
SSL_CTX* fijar_contexto_SSL(char* CAfile,char* SCfile, char* Pfile, char*CApath);

/**
 * Dado un contexto SSL y un descriptor de socket esta función se encargará de
obtener un canal seguro SSL iniciando el proceso de handshake con el otro extremo.
 * @param  ctx    contexto de la conexión segura
 * @param  sockfd socket de la conexión segura
 * @return        estructura SSL de la conexión segura
 */
SSL* conectar_canal_seguro_SSL(SSL_CTX* ctx, int sockfd);

/**
 * Dado un contexto SSL y un descriptor de socket esta función se encargará de
bloquear la aplicación, que se quedará esperando hasta recibir un handshake por parte del cliente.
 * @param  ctx    contexto de la conexión segura
 * @param  sockfd socket de la conexión segura
 * @return        estructura SSL de la conexión segura
 */
SSL* aceptar_canal_seguro_SSL(SSL_CTX* ctx, int sockfd);

/**
 * Esta función comprobará una vez realizado el handshake que el canal de co-
municación se puede considerar seguro.
 * @param  ssl estructura SSL de la conexión segura
 * @return     true si es seguro, false si no
 */
boolean evaluar_post_connectar_SSL(SSL*ssl);

/**
 * Esta función será el equivalente a la función de envío de mensajes que se realizó en la
práctica 1, pero será utilizada para enviar datos a través del canal seguro. Es importante que sea genérica y
pueda ser utilizada independientemente de los datos que se vayan a enviar.
 * @param  ssl estructura SSL de la conexión segura
 * @param  buf datos a enviar
 * @param  num tamaño de los datos
 * @return     numero >0 si ha ido bien <=0 si no
 */
int enviar_datos_SSL(SSL* ssl, void* buf, int num);

/**
 * Esta función será el equivalente a la función de lectura de mensajes que se realizó en la
práctica 1, pero será utilizada para enviar datos a través del canal seguro. Es importante que sea genérica y
pueda ser utilizada independientemente de los datos que se vayan a recibir.
 * @param  ssl estructura SSL de la conexión segura
 * @param  buf datos a recibir
 * @param  num tamaño de los datos
 * @return     numero >0 si ha ido bien <=0 si no
 */
int recibir_datos_SSL(SSL* ssl, void* buf, int num);

/**
 * Esta función liberará todos los recursos y cerrará el canal de comunicación seguro creado
previamente.
 * @param  ssl    estructura SSL de la conexión segura
 * @param  ctx    contexto de la conexión segura
 * @param  sockfd socket de la conexión segura
 * @return        1 si ha ido bien, -1 si ha habido un fallo 
 */
int cerrar_canal_SSL(SSL* ssl, SSL_CTX* ctx, int sockfd);

#endif /* SSL_H */

