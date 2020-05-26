#ifndef EST_INTERFACE_H
#define EST_INTERFACE_H

/**
  @file est_interface.h
  @brief TAD para la interfaz grafica de la estacion.
  @authors Alejandro Ugobono, Ezequiel Pirrota, Facundo Palacios, Gonzalo Fernandez, Mauro Pignatta, Mariano Wiñar.
  @date 8/2019, 11/2019.
*/

#include "funcEstaciones.h"
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#define LINE_LENGTH 80
#define VIEW_WIN_WIDTH 0
#define VIEW_WIN_HEIGTH 30
#define MSG_WIN_WIDTH 0
#define MSG_WIN_HEIGTH 50
#define SPACE 1

/**
 * Estructura de Datos para la interfaz grafica 
 */
typedef struct {
    WINDOW *pAppFrame;
    WINDOW *pLogFrame;
    WINDOW *pLogWindow;
    WINDOW *pCmdFrame;
    WINDOW *pCmdWindow;
   	WINDOW *pRegFrame;
    WINDOW *pRegWindow; 
} ST_APP_WINDOW;

/**
 *Variable global para la interfaz grafica 
 */
ST_APP_WINDOW pWin;

/**
 * Enum para los colores a utilizar
 */
typedef enum {RED=1, GREEN, BLUE, WHITE, YELLOW, CYAN,} COLOUR;

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
 * @param * message Titulo a imprimir.
 */
void printWindowTitle(WINDOW *pWin, const char * message);

/**
 * Imprime un mensaje en la ventana de Log
 * @param pWindow Puntero a estructura que contiene la interfaz.
 * @param * message Mensaje a imprimir.
 * @param colour Color a utilizar.
 */
void printLog(ST_APP_WINDOW *pWindow, const char * message, COLOUR colour);

/**
 * Imprime un mensaje en la ventana de Registro
 * @param pWindow Puntero a estructura que contiene la interfaz.
 * @param message Mensaje a imprimir.
 * @param colour Color a utilizar.
 */
void printRegistro(ST_APP_WINDOW *pWindow, const char *message, COLOUR colour);

/**
 * Destruye la interfaz grafica.
 * @param pWindow Puntero a estructura que contiene la interfaz.
 */
void unInitUserInterface(ST_APP_WINDOW *);


/**
 * Imprime el estado de los trenes.
 * @param pWin Puntero a estructura que contiene la interfaz.
 * @param trenes Vector de trenes a imprimir.
 * @return Cantidad de trenes impresos.
 */
int printEstadoTrenes(ST_APP_WINDOW *pWin , TREN trenes[]);

/**
 * Imprime el estado de las estaciones.
 * @param pWin Puntero a estructura que contiene la interfaz.
 * @param est Vector de estaciones a imprimir.
 */
void printEstadoEstaciones(ST_APP_WINDOW *pWin, ESTACION est[]);

/**
 * Imprime la ayuda del programa.
 * @param pAppWin Puntero a estructura que contiene la interfaz.
 */
void printHelp(ST_APP_WINDOW *pAppWin);

/**
 * Limpia una ventana.
 * @param pWin Puntero a la ventana a limpiar.
 */
void clearWindow(WINDOW *pWin);

/**
 * Limpia la ventana de comandos.
 * @param pWin Puntero a la ventana de comandos.
 */
void clearCmdWindow(WINDOW *pWin);

/** 
 * Funcion para el hilo que se encarga de la interfaz grafica
 */
void InterfazGrafica();

#endif /* EST_INTERFACE_H */