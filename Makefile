all: estacion tren
	
SRCTREN = src/tren_interface.c src/Conexion.c src/funcTrenes.c

SRCEST = src/est_interface.c src/Conexion.c src/funcEstaciones.c

HEADERS = $(wildcard lib/*.h)

LIB = -Ilib

CFLAG = -lncurses -lpthread

CC = gcc

estacion: estacion.c $(SRCFILES) $(HEADERS)
	$(CC) $(LIB) estacion.c $(SRCEST) -o bin/estacion $(CFLAG) 

tren: tren.c $(SRCFILES) $(HEADERS)
	$(CC) $(LIB) tren.c $(SRCTREN) -o bin/tren $(CFLAG)

debug: tren.c estacion.c $(SRCFILES) $(HEADERS)
	$(CC) -g $(LIB) estacion.c $(SRCEST) -o bin/DEBUGestacion $(CFLAG)
	$(CC) -g $(LIB) tren.c $(SRCTREN) -o bin/DEBUGtren $(CFLAG)

clean: 
	rm -f bin/*
