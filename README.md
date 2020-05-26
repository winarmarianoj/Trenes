# Programa Trenes y Estaciones

## Instalación y Ejecución del Programa Para Plataformas Linux:

1-	Abrir una Terminal 

2-	Crear el directorio “Trenes y Estaciones”

3-	Ingresar al directorio creado

4-	Clonar el repositorio con el siguiente comando: 
-	git clone https://github.com/MauroPignatta/TP-Trenes-y-estaciones

5-	Instalar Make y GCC con los siguientes comandos:
- 	sudo apt-get install make
- 	sudo apt-get install gcc

6-	Instalar NCurses con el siguiente comando:
-	sudo apt-get install libncurses5-dev
-	sudo apt-get install libncursesw5-dev

7-  Crear el directorio "bin".

8-  En una Terminal ingresar el comando make

9-	Ingresar al directorio "bin".

10-	Ya puede ejecutar el Programa de Estaciones con el siguiente comando:
```
./estación <Archivo de configuracion de estacion>.conf
```

11-	Abrir otra Terminal para ejecutar el Programa de Tren con el siguiente comando:
```
./tren <Archivo de configuracion de tren>.conf <Estacion donde conectarse>
```

12-	Por cada Tren que desee agregar, deberá repetir el punto 11

## Generando la documentacion:

1-	Instalar Doxygen con el siguiente comando:
-	sudo apt-get install doxygen

2-	Abrir una terminal en el directorio principal del programa.

3-	Ejecutar el siguiente comando en la terminal:
-	doxygen Doxyfile
