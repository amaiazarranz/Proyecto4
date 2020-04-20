#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "usuario.h"
#include "secretario.h"
#include "Libro.h"
#include "Cd.h"
#include "DVD.h"

#define MAX_LINE 30

char letraDNI(int dni)
{
  char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";

  return letra[dni%23];
}

short verificaDNI(char *dni)
{

  if (strlen(dni)!=9){

	  return 0;
  }

  else{

	  return (letraDNI(atoi(dni))==dni[8]);
  }

}

int comprobarLetra(char * nombre){

	int comprobacionNombre=1;

	for (int i=0; i<strlen(nombre);i++){

		if ((nombre[i]>=65 && nombre[i]<=90) || (nombre[i]>=97 && nombre[i]<=9122)) //MAYUSCULAS O MINUSCULAS
		{
			comprobacionNombre=0;
		}
		else{

			printf("Has introducido algo que no son letras\n");
			comprobacionNombre=1;
			break;
		}
	}

	return comprobacionNombre;
}



int comprobarNumero(char * numero){

	int comprobacionNumero=1;

	for (int i=0; i<strlen(numero);i++){

		if ((numero[i]>=48 && numero[i]<=57))
		{
			comprobacionNumero=0;
		}
		else{

			printf("Has introducido algo que no son numeros\n");
			comprobacionNumero=1;
			break; //si busca uno ya es malo
		}
	}

	return comprobacionNumero;
}

int comprobarAnyo (char* numero){
	int comprobacionNumero=1;

	for (int i=0; i<strlen(numero);i++){

		if ((numero[i]>=48 && numero[i]<=57))
		{
			int fecha=atoi(numero);
			if (fecha>2020){

				printf("Has introducido una fecha erronea\n");
				comprobacionNumero=1;
				break;

			}else{

				comprobacionNumero=0;
			}
		}
		else{

			printf("Has introducido algo que no son numeros\n");
			comprobacionNumero=1;
			break; //si busca uno ya es malo
		}
	}

	return comprobacionNumero;
	
}

void vaciar (char vaciar [])
{
	for (int i=0; i<MAX_LINE; i++)
	{
		vaciar[i] = '\0';
	}
}

int comprobarTituloCd (char* titulo, Cd* listaCd, int * size){

	int result=0;
	char * aux;

	for(int i=0; i<*size; i++){

		aux=(char*)malloc(strlen(((listaCd+i)->titulo)+1)*sizeof(char));
		strcpy(aux, (listaCd+i)->titulo);

		if((strcmp(titulo,aux))==0){

			result=1;
			break;

		}
	}

	return result;

}
int comprobarTituloDvd (char* titulo, Dvd* listaD, int * size){


	int result=0;
	char * aux;

	for(int i=0; i<*size; i++){

		aux=(char*)malloc(strlen(((listaD+i)->titulo)+1)*sizeof(char));
		strcpy(aux, (listaD+i)->titulo);

		if((strcmp(titulo,aux))==0){

			result=1;
			break;
		}
	}

	return result;
}

int comprobarTituloLibro (char* titulo, Libro* listaL, int * size){


	int result=0;
	char * aux;

	for(int i=0; i<*size; i++){

		aux=(char*)malloc(strlen(((listaL+i)->titulo)+1)*sizeof(char));
		strcpy(aux, (listaL+i)->titulo);

		if((strcmp(titulo,aux))==0){

			result=1;
			break;
		}
	}

	return result;
}

