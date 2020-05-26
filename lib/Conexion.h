#ifndef CONEXION_H
#define CONEXION_H

/**
  @file Conexion.h
  @brief Contiene funciones para la conexion entre servidor y cliente.
  @authors Alejandro Ugobono, Ezequiel Pirrota, Facundo Palacios, Gonzalo Fernandez, Mauro Pignatta, Mariano Wiñar.
  @date 8/2019, 11/2019.
*/

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <ctype.h>
#include <string.h>

#define sizeIP sizeof(char) * 16
#define sizePORT sizeof(char) * 6
#define sizeMsj 512
#define MaxClientes 25

/**
 * Formatea una palabra poniendo la primer letra en mayuscula y el resto en minuscula.
 * @param Palabra Palabra a formatear.
 * @return Palabra ya formateada. 
 */
char * FormatearNombre( char * Palabra);

/**
 * Obtiene la direccion IP y el puerto de un archivo de configuracion de red.
 * @param IP Puntero a char donde guardar la IP.
 * @param Puerto Puntero a int donde guardar el puerto.
 * @param confRed Ruta al archivo de configuracion de red.
 */
void obtenerDatosRed(char * IP, int * Puerto, char * confRed);

/**
 * Crea el Socket de comunicacion tipo Servidor
 * @param confRed Ruta al archivo de configuracion de red.
 * @return Socket ya configurado.
 */
int CrearSocketServer(char * confRed);

/**
 * Crea el Socket de comunicacion tipo Cliente
 * @param confRed Ruta al archivo de configuracion de red.
 * @return Socket ya configurado.
 */
int CrearSocketCliente(char * confRed);

/**
 * Conecta a una estacion con otra.
 * @param confRed ruta al archivo de configuracion de red de la estacion a conectarse.
 * @return Socket ya configurado.
 */
int conectarEstacion(char * confRed);

/**
 * Obtiene el nombre del archivo de configuracion de Red segun el nombre de la estacion a conectarse.
 * @param nombreEstacion Nombre de la estacion a conectarse.
 * @param archConfigRed Puntero al vector donde se va a guardar la ruta al archivo de configuracion.
 */
void obtenerConfRed(char * nombreEstacion , char * archConfigRed);

#endif	// CONEXION_H
