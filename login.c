#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "secretario.h"
#include "login.h"
#include "menuSecretario.h"
#include "menuUsuario.h"

#define MAX_NUM 50


void login (Usuario * u, Secretario * s, int sizeUs, int sizeSe, Libro * l, Dvd * d, Cd * c, int *numL, int * numC, int  * numD){

	char str [MAX_NUM];

	printf ("Introduce tu dni para verificarte\n");
	fflush (stdout);
	fgets (str, MAX_NUM, stdin);

	char *usuario;
	int longituddni=0;
	longituddni=strlen(str);
	usuario=malloc ((longituddni+1)*sizeof(char));
	sscanf(str, "%s", usuario);

	printf ("Introduce tu contraseña para verificarte\n");
	fflush(stdout);
	fgets (str, MAX_NUM, stdin);

	char *contrasena;
	int longitudcontra=0;
	longitudcontra=strlen(str);
	contrasena=malloc ((longitudcontra+1)*sizeof(char));
	sscanf(str, "%s", contrasena);

	int resultadoUsu= comprobarUsuario(usuario, contrasena, u, sizeUs);

	if (resultadoUsu==1){

		altaUsuario(u, &sizeUs);

	}

	int resultadoSecre= comprobarSecretario (usuario, contrasena, s, sizeSe);

	if (resultadoSecre==1){

		altaSecretario(s, &sizeSe,u, &sizeUs, l, d, c, numL, numD, numC);
	
	}
	if (resultadoUsu!=1 && resultadoSecre!=1){

		printf("No hay ningun usuario o secretario con estos datos\n");
	}

}

int comprobarUsuario (char * dni, char * contrasena, Usuario * u, int sizeUs){

	int existe = 0;

	for (int i=0; i<sizeUs; i++) {

		int resultadoNombre=strcmp(u[i].dni, dni);
		int resultadoContra=strcmp(u[i].contrasena, contrasena);

		if (resultadoNombre==0) {

			if (resultadoContra==0) {
				existe = 1;
				break;
			}
		}
	}

	return existe;

}

int comprobarSecretario (char * dni, char * contrasena, Secretario * s, int sizeSe){

	int existe = 0;

	for (int i=0; i<sizeSe; i++) {

		int resultadoNombre=strcmp(s[i].dni, dni);
		int resultadoContra=strcmp(s[i].contrasena, contrasena);

		if (resultadoNombre==0) {

			if (resultadoContra==0) {
				existe = 1;
				break;
			}
		}
	}

	return existe;

}


