#include "../lib/funcTrenes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../lib/Conexion.h"

FILE * openFile(char * nombreArchivo)
{
    FILE *ptr = fopen(nombreArchivo,"r");
    if(ptr == NULL){
        printf("No se pudo abrir el archivo de configuracion\n");
        exit(1);
    }
    return ptr;
}

TREN inicializarTren(char *arch)
{
    FILE *tren = openFile(arch);
    TREN aux;
    fscanf(tren, "ID: %d\n", &aux.ID);
    fscanf(tren, "Combustible: %d\n",&aux.combustible);
    fscanf(tren, "Modelo: %s", aux.modelo);
    aux.tiempoRestante = 0;
    strcpy(aux.estDestino,"A asignar");
    strcpy(aux.estOrigen,"A asignar");
    aux.migrado = 0;
    fclose(tren);
    return aux;
}

void armarMensajeRegistrarse(TREN tren,char * mensaje)
{
    sprintf(mensaje , "1;1;%d;%d;%s;%s;%s;",
        tren.ID, tren.combustible, tren.modelo,
            tren.estDestino, tren.estOrigen );
}

void armarMensajeEstadoDelTren(TREN tren, char * mensaje)
{
    sprintf(mensaje,"Estado:\n\n");
    mensaje += strlen(mensaje);
    sprintf(mensaje,"ID: %d\n",tren.ID);
    mensaje += strlen(mensaje);
    sprintf(mensaje,"Combustible restante: %d\n",tren.combustible);
    mensaje += strlen(mensaje);
    sprintf(mensaje,"Modelo: %s\n",tren.modelo); 
    mensaje += strlen(mensaje);
    sprintf(mensaje,"Estacion Actual: %s\n",tren.estOrigen);
    mensaje += strlen(mensaje);
    sprintf(mensaje,"Estacion Destino: %s\n",tren.estDestino);
    mensaje += strlen(mensaje);
    sprintf(mensaje,"Tiempo de viaje restante: %d\n",tren.tiempoRestante);
}

void armarMensajePartir(TREN tren ,char * mensaje)
{
    sprintf(mensaje, "1;3;%d", tren.ID);
}

void armarMensajeExit(TREN tren, char * mensaje)
{
    sprintf(mensaje, "1;5;%d", tren.ID);
}