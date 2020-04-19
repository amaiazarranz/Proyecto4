#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "secretario.h"
#include "DVD.h"
#include "Cd.h"
#include "Libro.h"
#include "usuario.h"
#include "menuSecretario.h"

#define MAX_LINE 4

char mostrarMenuSecretario()
{
	printf("0. Nuevo secretario\n");
	printf("1. Mostrar seceretarios ordenados por salarios\n");
	printf("2. Borrar un secretario\n");
	printf("3. Mostrar usuarios ordenados por edad\n");
	printf("4. Nuevo libro\n");
	printf("5. Nuevo DVD\n");
	printf("6. Nuevo CD\n");
	printf("7. Borrar libro\n");
	printf("8. Borrar DVD\n");
	printf("9. Borrar CD\n");
	printf("a. Borrar usuario\n");
	printf("Pulsar 'n' para salir\n");
	printf("\n");
	printf("Opcion: ");
	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	return *linea;
}

void altaSecretario (Secretario * secretario, int * numSecre, Usuario * usuario, int * numUsu,
		Libro * l, Dvd * d, Cd * c, int *numL, int * numC, int  * numD){

	printf("Bienvenido eres un secretario\n");
	fflush (stdout);

	char opcion;

	do{

		opcion=mostrarMenuSecretario();
		switch (opcion){

			case '0':
				introducirSecretario (&secretario[*numSecre], secretario, numSecre,  usuario, numUsu);
				*numSecre=*numSecre+1;
				escribirFicheroSecretario(secretario, numSecre);
				break;

			case '1':
				salariosOrdenados(secretario, numSecre);
				break;

			case '2':
				borrarSecretario(secretario, numSecre);
				escribirFicheroSecretario(secretario, numSecre);
				break;

			case '3':
				mostrarUsuariosOrdenado(usuario, numUsu);
				break;

			case '4':
				nuevoLibro (&l[*numL], l, numL);
				*numL=*numL+1;
				escribirFicheroLibro(l,numL);
				break;

			case '5':
				nuevoDVD(&d[*numD], d, numD);
				*numD=*numD+1;
				escribirFicheroDVD(d,numD);
				break;

			case '6':
				nuevoCd(&c[*numC], c, numC);
				*numC=*numC+1;
				escribirFicheroCd(c,numC);
				break;

			case '7':
				 borrarLibro(l,numL);
				 escribirFicheroLibro(l,numL);
				break;

			case '8':
				borrarDVD(d,numD);
				escribirFicheroDVD(d,numD);
				break;

			case '9':
				borrarCd(c,numC);
				escribirFicheroCd(c,numC);
				break;

			case 'a':
				borrarUsuario(usuario, numUsu);
				escribirFicheroUsuario(usuario, numUsu);
				break;

		}

	}while (opcion!='n');

}
