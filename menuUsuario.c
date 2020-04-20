#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "secretario.h"
#include "DVD.h"
#include "Cd.h"
#include "Libro.h"
#include "menuUsuario.h"


#define MAX_LINE 4

char mostrarMenuUsuario()
{
	printf("\n");
	printf("Bienvenido eres un usuario\n");
	printf("1. Mostrar libros\n");
	printf("2. Mostrar DVDs\n");
	printf("3. Mostrar CDs\n");
	printf("4. Mostrar  novedades libros\n");
	printf("5. Mostrar novedades DVDs\n");
	printf("6. Mostrar novedades CDs\n");
	printf("Pulsar 'n' para salir\n");
	printf("\n");
	printf("Opcion: ");
	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	return *linea;
}

void altaUsuario (Usuario * usuario, int * numUsu){

	int numL=0;
	Libro* listaL=leerFicheroLibro(&numL);

	int numD=0;
	Dvd * listaD=leerFicheroDVD(&numD);

	int numC=0;
	Cd* listaC=leerFicheroCd(&numC);

	char opcion;

	do{

		opcion=mostrarMenuUsuario();
		switch (opcion){

			case '1':
				mostrarLibro(listaL,&numL);
				break;

			case '2':
				mostrarDVD(listaD,&numD);
				break;

			case '3':
				mostrarCd(listaC,&numC);
				break;

			case '4':
				mostrarNovedadesLibro(listaL,&numL);
				break;

			case '5':
				mostrarNovedadesDVD(listaD,&numD);
				break;
			case '6':
				mostrarNovedadesCd(listaC,&numC);
				break;

		}

	}while (opcion!='n');


}



