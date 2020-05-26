#ifndef FUNCTRENES_H
#define FUNCTRENES_H

/**
  @file funcTrenes.h
  @brief TAD para manejo de los trenes.
  @authors Alejandro Ugobono, Ezequiel Pirrota, Facundo Palacios, Gonzalo Fernandez, Mauro Pignatta, Mariano Wiñar.
  @date 8/2019, 11/2019.
*/

#define max_nombre_est 30
#define restarCombustible(x) 4 * x
#define esTren(x) x == '1'
#define noHayEstacionesDisponible(x) x == '0'

/**
 * Estructura de datos para Trenes 
 */
typedef struct{
    int ID;
    int combustible;
    char modelo[10];
    char estOrigen[max_nombre_est];
    char estDestino[max_nombre_est];
    int tiempoRestante;
    int migrado;
    int nCliente;
}TREN;

/**
 * Inicializa un tren con los datos del archivo de configuracion.
 * @param arch Ruta al archivo de configuracion.
 * @return Tren inicializado.
 */
TREN inicializarTren(char *arch);

/**
 * Arma un mensaje de registro.
 * @param tren Tren a registrar.
 * @param mensaje Puntero al vector donde se va a copiar el mensaje del registro.
 */
void armarMensajeRegistrarse(TREN tren,char * mensaje);

/**
 * Arma el mensaje con el estado del tren.
 * @param tren Tren del cual se arma el estado.
 * @param mensaje Puntero al vector donde se va a copiar el mensaje del estado.
 */
void armarMensajeEstadoDelTren(TREN tren, char * mensaje);

/**
 * Arma el mensaje para avisar a la estacion que va a salir del programa.
 * @param tren Tren que va a salir del programa.
 * @param mensaje Puntero al vector donde se va a copiar el mensaje del salida.
 */
void armarMensajeExit(TREN tren, char * mensaje);

/**
 * Arma el mensaje para indicarle a la estacion que el tren quiere partir.
 * @param tren Tren que quiere partir.
 * @param mensaje Puntero al vector donde se va a copiar el mensaje del partir.
 */
void armarMensajePartir(TREN tren ,char * mensaje);

#endif	// FUNCTRENES_H