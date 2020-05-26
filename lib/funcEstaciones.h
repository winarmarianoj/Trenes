#ifndef FUNCESTACIONES_H
#define FUNCESTACIONES_H

/**
  @file funcEstaciones.h
  @brief TAD para manejo de las estaciones.
  @authors Alejandro Ugobono, Ezequiel Pirrota, Facundo Palacios, Gonzalo Fernandez, Mauro Pignatta, Mariano Wiñar.
  @date 8/2019, 11/2019.
*/

#define MAX_TREN 20
#define MAX_ESTACION 5

#define esEstacion(x) x == '2'
#define estacionConectada(y) y == 1
#define andenLibre(x) x == NULL

#include "funcTrenes.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

/** 
 * Estructura de datos para Estaciones 
 */
typedef struct 
{
	int ID;
	char nombre[max_nombre_est];
	int distancia;
	int online;
	int nCliente;
	TREN * tren;
}ESTACION;

/** 
 * Estructura de datos de Nodo Trenes
 */
typedef struct nodo
{
	struct nodo * sig;
	TREN * tren;
	int prioridad;
}ST_NODO_TRENES;

/** 
 * Variables globales Tipo Nodos a Tren, anden, tipo file txt a estacion
 */
pthread_mutex_t lock;
TREN * anden ;
ST_NODO_TRENES * ColaPrioridadMenor ;
ST_NODO_TRENES * ColaPrioridadMayor ;

pthread_mutex_t log_lock;
FILE * logEstacion;

int serverEst[MAX_ESTACION];
ESTACION estaciones[MAX_ESTACION];
int miPos;
int trenEnViaje;

/**
 * Obtiene los datos de mi estacion.
 * @param nomArchivo ruta al archivo de configuracion de la estacion.
 * @param est Vector de estaciones.
 * @return Posicion de la estacion en el vector.
 */
int ObtenerDatosMiEstacion(char * nomArchivo, ESTACION est[]);

/**
 * Obtiene los datos del resto de las estaciones.
 * @param est Vector de estaciones.
 * @param miPos Posicion a mi estacion.
 */
void ObtenerOtrasEstaciones(ESTACION est[],int miPos);

/**
 * Registra a un tren en el vector de trenes de la estacion.
 * @param estacion Puntero a mi estacion.
 * @param mensaje Contiene los datos para registrar el tren.
 * @return 1 si el tren se registro correctamente o 0 en caso de que no se haya registrado.
 */
int registrarTren(ESTACION *estacion, char * mensaje);

/**
 * Busca en el vector de trenes de la estacion las posiciones donde hay trenes registrados.
 * @param trenes Vector de trenes de mi estacion.
 * @param posTrenes Vector donde se van a guardar las pocisiones donde se encuentran los trenes.
 * @return Cantidad de trenes en el vector.
 */
int buscarTrenes( TREN trenes[] ,int posTrenes[]);

/**
 * Busca un Tren en el vector de trenes.
 * @param estacion Estacion donde buscar.
 * @param idTren ID del tren a buscar.
 * @return La posicion en la que se encuentra el tren en el vector de trenes de la estacion o -1 si no se encuentra.
 */
int BuscarTrenPorID(ESTACION estacion, int idTren);

/**
 * Copia un mensaje con los trenes migrados que pueden viajar.
 * @param mensaje puntero al vector donde se va a copiar el mensaje.
 * @return Cantidad de trenes migrados.
 */
int mostrarTrenesMigrados(char * mensaje);

/**
 * Pide al usuario que ingrese el tren migrado que quiere que viaje.
 * @return Posicion del tren elegido en el vector de trenes o -1 en caso de que el tren elegido no sea valido. 
 */
int elegirTren();

/**
 * Copia un mensaje con las estaciones disponible donde viajar.
 * @param mensaje puntero al vector donde se va a copiar el mensaje.
 * @return Cantidad de estaciones que estan disponibles para viajar.
 */
int mensajeListadoEstDisp(char * mensaje);

/**
 * Pide al usuario que ingrese el nombre de la estacion donde quiere viajar.
 * @return Posicion la estacion elegida o -1 en caso de que no sea valida.
 */
int elegirEstDestino();

/**
 * Busca a la estacion por el nombre.
 * @param char * mensaje Nombre de la estacion a buscar.
 * @return Posicion de la estacion en el vector de estaciones o -1 si no la encuentra.
 */
int buscarEstacionPorNombre(char * mensaje);

/**
 * Calcula el tiempo basandose en la distancia entre una estacion y otra.
 * @param  posEstacionDestino La posicion en el vector de estacion destino.
 * @return Tiempo de viaje.
 */
int calcularTiempoDeViaje(int posEstacionDestino);

/**
 * Prepara el mensaje para enviar un tren de una estacion a otra.
 * @param mensaje puntero al vector donde copia el mensaje a enviar.
 * @param tren Puntero al tren a enviar.
 */
void prepararEnvioTren(char *mensaje , TREN * tren);

/**
 * Crea nodo de tren
 * @param  tren Puntero al tren a agregar en el nodo.
 * @return Nodo creado.
 */
ST_NODO_TRENES * crearNuevoNodo(TREN * tren);

/**
 * Agrega un tren a la cola de trenes.
 * @param tren Puntero al tren a agregar en la cola.
 * @param cola Puntero a la cabecera de la cola.
 */
void encolarTren(TREN * tren, ST_NODO_TRENES ** cola);

/**
 * Asigna el anden al primer tren de una cola.
 * @param cola Puntero a la cabecera de la cola.
 * @return Puntero al tren al que se le debe asignar anden o NULL si no hay trenes en la cola.
 */
TREN * asignarAnden(ST_NODO_TRENES ** cola);

/**
 * Elimina nodo que hayaa alcanzado la prioridad maxima de la cola.
 * @param cola Puntero a la cabecera de la cola.
 * @return Puntero al tren del nodo eliminado.
 */
TREN * eliminarNodoPrioridad(ST_NODO_TRENES ** cola);

/**
 * Elimina Nodo del tren segun su ID.
 * @param IDTren ID del tren a eliminar de la cola.
 * @param cola Puntero a la cabecera de la cola.
 */
void eliminarNodoTrenSegunID(int IDTren, ST_NODO_TRENES ** cola);

/**
 * Sube la prioridad a los trenes en la cola.
 * @param * cola Cabecera de la cola.
 * @return Cantidad de nodos que alcanzaron la prioridad necesaria para ser movidos de cola de mayor prioridad.
 */
int subirPrioridadTrenes(ST_NODO_TRENES * cola);

/**
 * Cambia de cola a los nodos que hayan alcanzado la prioridad necesaria 
 * para ser transferidos de la cola menor prioridad a la cola de mayor prioridad.
 * @param cola_Menor Puntero a la cabecera de la cola de menor prioridad.
 * @param cola_Mayor Puntero a la cabecera de la cola de mayor prioridad.
 * @param cantNodos Cantidad de nodos que tiene que cambiar de colas.
 */
void CambiarDeColaTrenes(ST_NODO_TRENES ** cola_Menor, ST_NODO_TRENES ** cola_Mayor, int cantNodos);

/**
 * Selecciona al siguiente tren que va a ocupar el anden.
 * @param anden Puntero al anden.
 * @param cola_Menor Puntero a la cabecera de la cola de menor prioridad.
 * @param cola_Mayor Puntero a la cabecera de la cola de mayor prioridad.
 */
void NuevoTrenAnden(TREN ** anden, ST_NODO_TRENES ** cola_Menor, ST_NODO_TRENES ** cola_Mayor);

/**
 * Crea un archivo de texto segun nombre de la estacion donde se guardan los registros de los trenes.
 * @param nombreEstacion Nombre de la estacion.
 * @return Puntero al archivo creado.
 */
FILE * crearLogEstacion(char * nombreEstacion);

/**
 * Guarda los datos del tren en el archivo de texto.
 * @param tren Puntero al tren que tiene los datos a guardar.
 * @param logEstacion Puntero al archivo de texto donde guardar los datos.
 */
void * llenarLog(TREN * tren , FILE * logEstacion);

/**
 * Avisa a las estaciones que hay un tren en viaje o que llego al destino.
 * @param posEstacionDestino Posicion de la estacion a la que viaja el tren.
 * @param tipoAviso 1 para avisar un tren empezo a viajar, 2 para avisar que el tren llego.
 */
void avisarEstaciones(int posEstacionDestino, int tipoAviso);

/**
 * Funcion para el hilo que se encarga de la conexion servidor-cliente
 */
void ConexionServer();

#endif	// FUNCESTACIONES_H