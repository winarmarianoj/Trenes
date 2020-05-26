#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "lib/Conexion.h"
#include "lib/funcTrenes.h"
#include "lib/tren_interface.h"

int main(int argc, char** argv) {

	if(argc == 3) /* Para cuando el tren migra a la estacion. */
	{
		if( atoi(argv[1]) )
		{
			pause();
		}
	}

    if(argc != 3){
		printf("\nuso: ./tren <Nombre archivo Conf Tren> <Nombre de Estacion a conectarse>\n");
    	exit(3);
    }

    system("clear");

    pthread_t Interfaz;
    pthread_create(&Interfaz, NULL,(void*) InterfazGrafica , (void*) argv);    

    pthread_join(Interfaz, NULL);

    return (EXIT_SUCCESS);
}