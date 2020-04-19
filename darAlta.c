#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "secretario.h"
#include "darAlta.h"
#include "comprobar.h"

#define MAX_LINE 30

char mostrarMenuAlta()
{
	printf("1. Introducir estudiante\n");
	printf("2. Introducir secretario\n");
	printf("Pulsar 'n' para salir\n");
	printf("\n");
	printf("Opcion: ");
	fflush(stdout);
	char linea[MAX_LINE];
	fgets(linea, MAX_LINE, stdin);
	return *linea;
}



void introducirSecretario (Secretario * s, Secretario *p, int * sizeSecre, Usuario* p2, int * sizeUsu){ //COMPROBAR LETRA

	char str [MAX_LINE];
	int result;

	//NOMBRE
	printf("Introduce nombre: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char *nombre;
	int longitudNombre=0;
	longitudNombre=strlen(str);
	nombre= (char*)malloc ((longitudNombre+1)*sizeof(char));
	sscanf(str, "%s", nombre);

	result=comprobarLetra(nombre);

	while (result==1){

		printf("Introduzca otra vez el nombre\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *nombre;
		int longitudNombre2=0;
		longitudNombre2=strlen(str);
		nombre= (char*)malloc ((longitudNombre2+1)*sizeof(char));
		sscanf(str, "%s", nombre);

		result=comprobarLetra(nombre);
	}

	sscanf (str, "%s", (s)->nombre);

	//PRIMER APELLIDO
	printf("Introduce el primer apellido: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char *apellido;
	int longitudapellido=0;
	longitudapellido=strlen(str);
	apellido= (char*)malloc ((longitudapellido+1)*sizeof(char));
	sscanf(str, "%s", apellido);

	result=comprobarLetra(apellido);

	while (result==1){

		printf("Introduzca otra vez el primer apellido\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *apellido;
		int longitudapellido2=0;
		longitudapellido2=strlen(str);
		apellido= (char*) malloc ((longitudapellido2+1)*sizeof(char));
		sscanf(str, "%s", apellido);

		result=comprobarLetra(apellido);
	}

	sscanf (str, "%s", (s)->apellido1);

	//SEGUNDO APELLIDO
	printf("Introduce el segundo apellido: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char * apellido4;
	int longitudapellido4=0;
	longitudapellido4=strlen(str);
	apellido4=malloc ((longitudapellido4+1)*sizeof(char));
	sscanf(str, "%s", apellido4);

	result=comprobarLetra(apellido4);

	while (result==1){

		printf("Introduzca otra vez el segundo apellido\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *apellido4;
		int longitudapellido4=0;
		longitudapellido4=strlen(str);
		apellido4=malloc ((longitudapellido4+1)*sizeof(char));
		sscanf(str, "%s", apellido4);

		result=comprobarLetra(apellido4);
	}

	sscanf (str, "%s", (s)->apellido2);
	printf("%s \n",(s)->apellido2 );

	//CONTRASEÑA
	printf("Introduce la contrasena \n");
	printf ("No os preocupeis que no hay ninguna restriccion\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	sscanf (str, "%s", (s)->contrasena);

	//SUELDO
	printf ("Introduce el sueldo:\n");
	fflush (stdout);

	int comprobarSueldo=1;
	int salario;

	do{

		comprobarSueldo=0;
		fgets (str, MAX_LINE, stdin);

		char * sueldo;
		int longitudsueldo=0;
		longitudsueldo=strlen(str);
		sueldo=malloc ((longitudsueldo+1)*sizeof(char));
		sscanf(str, "%s", sueldo);

		result=comprobarNumero(sueldo);

		while (result==1){

			printf("Introduzca otra vez el sueldo\n");
			fflush (stdout);
			fgets(str, MAX_LINE, stdin);

			char *sueldo;
			int longitudsueldo=0;
			longitudsueldo=strlen(str);
			sueldo=malloc ((longitudsueldo+1)*sizeof(char));
			sscanf(str, "%s", sueldo);

			result=comprobarNumero(sueldo);
		}//hasta aqui comprobacion

		salario=atoi(str);

		if (salario<950){

			printf("El saldo tiene que ser mayor que el salario minimo interprofesional de 950€\n");
			comprobarSueldo=1;

			printf ("Introduzca un salario valido\n");
			fflush(stdout);

		}

	}while (comprobarSueldo==1);

	sscanf (str, "%i", &(s)->sueldo );

	//EDAD
	printf("Introduce la edad:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char * edad;
	int longitudedad=0;
	longitudedad=strlen(str);
	edad=malloc ((longitudedad+1)*sizeof(char));
	sscanf(str, "%s", edad);

	result=comprobarNumero(edad);

	while (result==1){

		printf("Introduzca otra vez la edad\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *edad;
		int longitudedad=0;
		longitudedad=strlen(str);
		edad=malloc ((longitudedad+1)*sizeof(char));
		sscanf(str, "%s", edad);

		result=comprobarNumero(edad);
	}

	sscanf (str, "%i", &(s)->edad);

	//DNI
	printf ("Introduce tu DNI con letra y sin espacios:\n");
	fflush (stdout);

	int comprobar=1;
	int comprobar2=1;
	char * dnic;
	int resultado;
	int resultado2;

	do{

		comprobar=0;
		comprobar2=0;
		fgets (str, MAX_LINE, stdin);

		int longitud=0;
		longitud=strlen(str);

		dnic=malloc ((longitud+1)*sizeof(char));
		sscanf(str, "%s", dnic);

		for (int i=0; i<*sizeSecre; i++){

				resultado=strcmp(dnic, (p+i)->dni);

				if (resultado==0){

					printf("Te has equivocado. Ya existe otro secretario que tenga ese DNI. Ingrese otro DNI\n");
					comprobar=1;

					printf ("Introduzca un DNI valido\n");
					fflush(stdout);

					break;

				}

		}
		for (int j=0; j<*sizeUsu; j++){

				resultado2=strcmp(dnic, (p2+j)->dni);

				if (resultado2==0){

					printf("Te has equivocado. Ya existe otro usuario que tenga ese DNI. Ingrese otro DNI\n");
					comprobar2=1;

					printf ("Introduzca un DNI valido\n");
					fflush(stdout);

					break;

				}

		}

		}while (comprobar==1||comprobar2==1);

	sscanf (str, "%s", (s)->dni);

	if (verificaDNI((s)->dni)){

	  printf ("El DNI es correcto\n");
	  printf("Ya se ha introducido el usuario\n");

	}
	else{

		printf ("El DNI no es correcto. Vuelve a introducir todos los datos desde el principio por favor.\n");
		fflush (stdout);
		introducirUsuario (s, p, sizeSecre, p2, sizeUsu);
	}

}

void introducirUsuario (Usuario * u, Usuario *p, int * sizeUsuarios, Secretario * p2, int * sizeSecretarios){

	char str [MAX_LINE];
	int result;

	//NOMBRE
	printf("Introduce nombre: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char *nombre;
	int longitudNombre=0;
	longitudNombre=strlen(str);
	nombre=malloc ((longitudNombre+1)*sizeof(char));
	sscanf(str, "%s", nombre);

	result=comprobarLetra(nombre);

	while (result==1){

		printf("Introduzca otra vez el nombre\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *nombre;
		int longitudNombre2=0;
		longitudNombre2=strlen(str);
		nombre=malloc ((longitudNombre2+1)*sizeof(char));
		sscanf(str, "%s", nombre);

		result=comprobarLetra(nombre);
	}

	sscanf (str, "%s", (u)->nombre);

	//PRIMER APELLIDO
	printf("Introduce el primer apellido: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char *apellido;
	int longitudapellido=0;
	longitudapellido=strlen(str);
	apellido=malloc ((longitudapellido+1)*sizeof(char));
	sscanf(str, "%s", apellido);

	result=comprobarLetra(apellido);

	while (result==1){

		printf("Introduzca otra vez el primer apellido\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *apellido;
		int longitudapellido2=0;
		longitudapellido2=strlen(str);
		apellido=malloc ((longitudapellido2+1)*sizeof(char));
		sscanf(str, "%s", apellido);

		result=comprobarLetra(apellido);
	}

	sscanf (str, "%s", (u)->apellido1);

	//SEGUNDO APELLIDO
	printf("Introduce el segundo apellido: \n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char * apellido2;
	int longitudapellido2=0;
	longitudapellido2=strlen(str);
	apellido2=malloc ((longitudapellido2+1)*sizeof(char));
	sscanf(str, "%s", apellido2);

	result=comprobarLetra(apellido2);

	while (result==1){

		printf("Introduzca otra vez el segundo apellido\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *apellido2;
		int longitudapellido2=0;
		longitudapellido2=strlen(str);
		apellido2=malloc ((longitudapellido2+1)*sizeof(char));
		sscanf(str, "%s", apellido2);

		result=comprobarLetra(apellido2);
	}

	sscanf (str, "%s", (u)->apellido2);

	//CONTRASEÑA
	printf("Introduce la contrasena \n");
	printf ("No os preocupeis que no hay ninguna restriccion\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	sscanf (str, "%s", (u)->contrasena);

	//EDAD
	printf("Introduce la edad:\n");
	fflush(stdout);
	fgets(str, MAX_LINE, stdin);

	char * edad;
	int longitudedad=0;
	longitudedad=strlen(str);
	edad=malloc ((longitudedad+1)*sizeof(char));
	sscanf(str, "%s", edad);

	result=comprobarNumero(edad);

	while (result==1){

		printf("Introduzca otra vez la edad\n");
		fflush (stdout);
		fgets(str, MAX_LINE, stdin);

		char *edad;
		int longitudedad=0;
		longitudedad=strlen(str);
		edad=malloc ((longitudedad+1)*sizeof(char));
		sscanf(str, "%s", edad);

		result=comprobarNumero(edad);
	}

	sscanf (str, "%i", &(u)->edad);

	//DNI
	printf ("Introduce tu DNI con letra y sin espacios:\n");
	fflush (stdout);

	int comprobar=1;
	int comprobar2=1;
	char * dnic;
	int resultado;
	int resultado2;

	do{

		comprobar=0;
		comprobar2=0;
		fgets (str, MAX_LINE, stdin);

		int longitud=0;
		longitud=strlen(str);

		dnic=malloc ((longitud+1)*sizeof(char));
		sscanf(str, "%s", dnic);

		for (int i=0; i<*sizeUsuarios; i++){

				resultado=strcmp(dnic, (p+i)->dni);

				if (resultado==0){

					printf("Te has equivocado. Ya existe otro usuario que tenga ese DNI. Ingrese otro DNI\n");
					comprobar=1;

					printf ("Introduzca un DNI valido\n");
					fflush(stdout);

					break;

				}

		}
		for (int j=0; j<*sizeSecretarios; j++){

		resultado2=strcmp(dnic, (p2+j)->dni);
		if (resultado2==0){

			printf("Te has equivocado. Ya existe otro secretario que tenga ese DNI. Ingrese otro DNI\n");
			comprobar2=1;

			printf ("Introduzca un DNI valido\n");
			fflush(stdout);

			break;

			}
		}

	}while (comprobar==1||comprobar2==1);


	sscanf (str, "%s", (u)->dni);

	if (verificaDNI((u)->dni)){

	  printf ("El DNI es correcto\n");
	  printf("Ya se ha introducido el usuario\n");

	}
	else{

		printf ("El DNI no es correcto. Vuelve a introducir todos los datos desde el principio por favor.\n");
		fflush (stdout);
		introducirUsuario (u, p, sizeUsuarios, p2, sizeSecretarios);
	}

}

void darAlta (Usuario * usuario,  int * numUsu, Secretario * secretario, int * numSecre){

	char opcion;

		do{

			opcion=mostrarMenuAlta();
			switch (opcion){

				case '1':
					introducirUsuario (&usuario[*numUsu], usuario, numUsu, secretario, numSecre);
					*numUsu=*numUsu+1;
					escribirFicheroUsuario(usuario, numUsu);
					break;

				case '2':
					introducirSecretario (&secretario [*numSecre], secretario, numSecre, usuario, numUsu);
					*numSecre=*numSecre+1;
					escribirFicheroSecretario(secretario, numSecre);
					break;

			}

		}while (opcion!='n');
}
