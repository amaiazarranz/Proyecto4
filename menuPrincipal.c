#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuario.h"
#include "secretario.h"
#include "login.h"
#include "darAlta.h"
#include "Libro.h"
#include "DVD.h"
#include "Cd.h"

#define MAX_LINE 4

char mostrarMenuAltas()
{
	printf("\n");
	printf("1. Iniciar sesion\n");
	printf("2. Dar alta\n");
	printf("Pulsar 'n' para salir\n");
	printf("\n");
	printf("Opcion: ");
	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	return *linea;
}

int main (void){

	printf("\n");
	printf ("Bienvenido a nuestra biblioteca\n");
	fflush (stdout);

	char opcion;

	int numUsu=0;
	Usuario * usuario =leerUsuarios(&numUsu);

	int numSecre=0;
	Secretario * secretario=leerSecretarios(&numSecre);

	int numL=0;
	Libro* listaL=leerFicheroLibro(&numL);

	int numD=0;
	Dvd* listaD=leerFicheroDVD(&numD);

	int numC=0;
	Cd* listaC=leerFicheroCd(&numC);


	do{

			opcion=mostrarMenuAltas();
			switch (opcion){

				case '1':
					login(usuario, secretario, numUsu, numSecre, listaL, listaD, listaC, &numL, &numD, &numC);

					break;

				case '2':
					darAlta(usuario, &numUsu, secretario, &numSecre);
					break;

			}

		}while (opcion!='n');

	return 0;
}
