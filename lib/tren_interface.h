#ifndef TREN_INTERFACE_H
#define TREN_INTERFACE_H

/**
  @file tren_interface.h
  @brief TAD para la interfaz grafica del tren.
  @authors Alejandro Ugobono, Ezequiel Pirrota, Facundo Palacios, Gonzalo Fernandez, Mauro Pignatta, Mariano Wiñar.
  @date 8/2019, 11/2019.
*/

#include <curses.h>
#include <unistd.h>
#include "funcTrenes.h"
#include "Conexion.h"

#define LINE_LENGTH 80
#define VIEW_WIN_WIDTH 0
#define VIEW_WIN_HEIGTH 30
#define MSG_WIN_WIDTH 0
#define MSG_WIN_HEIGTH 50
#define SPACE 1

/**
 * Estructura de datos para la variable global
 */
typedef struct {
    WINDOW *pAppFrame;
    WINDOW *pLogFrame;
    WINDOW *pLogWindow;
    WINDOW *pCmdFrame;
    WINDOW *pCmdWindow;
} ST_APP_WINDOW;

/**
 *Estructura del tipo enum para los colores a utilizar
 */
typedef enum {RED = 1, GREEN, BLUE, WHITE, YELLOW, CYAN,} COLOUR;

/**
 * Inicializa la interfaz grafica.
 * @param pWindow Puntero a estructura que contiene la interfaz.
 */
void initUserInterface(ST_APP_WINDOW *pWindow);

/**
 * Dibuja la interfaz grafica.
 * @param pWindow Puntero a estructura que contiene la interfaz.
 */
void drawUserInterface(ST_APP_WINDOW *pWindow);

/**
 * Imprime un titulo en el marco de la ventana.
 * @param pWin Puntero a la ventana.
 * @param message Titulo a imprimir.
 */
void printWindowTitle(WINDOW *pWin, const char * message);

/**
 * Imprime un mensaje en la ventana de Log
 * @param pWindow Puntero a estructura que contiene la interfaz.
 * @param message Mensaje a imprimir.
 * @param colour Color a utilizar.
 */
void printMessage(ST_APP_WINDOW *pWindow, const char * message, COLOUR colour);

/**
 * Destruye la interfaz grafica.
 * @param pWindow Puntero a estructura que contiene la interfaz.
 */
void unInitUserInterface(ST_APP_WINDOW *pWindow);

/**
 * Limpia la ventana de comandos.
 * @param pWin Puntero a la ventana de comandos.
 */
void clearCmdWindow(WINDOW *pWin);

/**
 * Limpia la ventana del Log
 * @param pWin Puntero a la ventana de Log.
 */
void clearLogWindow(WINDOW *pWin);

/**
 * Imprime la ayuda del programa.
 * @param pAppWin Puntero a estructura que contiene la interfaz.
 */
void printHelp(ST_APP_WINDOW *pAppWin);

/**
 * Imprime el mensaje de que el anden fue asignado.
 * @param pWin Puntero a estructura que contiene la interfaz.
 */
void imprimirAndenAsignado(ST_APP_WINDOW *pWin);

/**
 * Dibuja un tren viajando.
 * @param pLogWindow Puntero a la ventana de Log.
 * @param tiempoRestante Puntero al tiempo de viaje restante del tren. 
 */
void DibujarTrenViajando(WINDOW *pLogWindow, int * tiempoRestante);

/**
 * Termina la ejecucion del programa.
 * @param tren Tren que va a terminar la ejecucion del programa.
 * @param client socket para enviarle mensaje a la estacion que va a salir del programa.
 * @param pWin Puntero a estructura que contiene la interfaz.
 */
void salirDelPrograma(TREN tren, int client, ST_APP_WINDOW * pWin);

/**
 * Funcion para el hilo que se encarga de la interfaz grafica.
 * @param argumentos Puntero a los argumentos para modificarlos cuando un tren migra.
 */
void InterfazGrafica(void * argumentos);

#endif /* TREN_INTERFACE_H */