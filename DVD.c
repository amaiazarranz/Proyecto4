
#include <stdlib.h>
#include "Libro.h"
#include "DVD.h"
#include "Cd.h"
#include <stdio.h>
#include <string.h>
#include "comprobar.h"
#include "usuario.h"
#include "secretario.h"
#include "comprobar.h"
#include "operaciones.h"
#define MAX_LINE 30

void nuevoDVD(Dvd* listaD, Dvd * d , int* sizeD){

	char str[MAX_LINE];
	int result;

	//TITULO
	printf("Introduce el titulo: \n");
	printf("Permitimos titulos de varias palabras\n");
	fflush(stdout);
	fflush (stdin);
	fgets(str,MAX_LINE,stdin);
	fflush (stdin);

	char * titulo;
	int longitudTitulo=0;
	longitudTitulo=strlen(str);
	titulo=  (char*) malloc ((longitudTitulo+1)*sizeof(char));
	titulo [strlen(titulo)-1]='\0';
	strcpy(titulo, str);

	str[strlen(str)-1]='\0';
	strcpy((listaD)->titulo, str);

	//AUTOR
	printf("Introduce el autor: \n");
	fflush(stdout);
	fflush (stdin);
	fgets(str,MAX_LINE,stdin);
	fflush (stdin);

	char* autor;
	int longitudAutor=0;
	longitudAutor=strlen(str);
	autor= (char*) malloc((longitudAutor+1)*sizeof(char));
	sscanf(str, "%s", autor);

	result=comprobarLetra(autor);

	while(result==1){

		printf("Introduzca otra vez el autor: \n");
		fflush(stdout);
		fflush (stdin);
		fgets(str,MAX_LINE,stdin);
		fflush (stdin);

		free(autor);

		longitudAutor=strlen(str);
		autor= (char*)malloc ((longitudAutor+1)*sizeof(char));

		sscanf(str, "%s", autor);

		result=comprobarLetra(autor);

	}

	sscanf(str, "%s", (listaD)->autor);

	//ANYO PUBLICACION
	printf("Introduce el anyo de publicacion: \n");
	fflush(stdout);
	fflush (stdin);
	fgets(str,MAX_LINE,stdin);
	fflush (stdin);

	char* anyo;
	anyo= (char*)malloc((strlen(str)+1)*sizeof(char));
	sscanf(str,"%s",anyo);

	result=comprobarAnyo(anyo);

	while(result==1){

		printf("Introduce otra vez el anyo de publicacion: \n");
		fflush(stdout);
		fflush (stdin);
		fgets(str,MAX_LINE,stdin);
		fflush (stdin);

		free(anyo);
		anyo= (char*)malloc((strlen(str)+1)*sizeof(char));
		sscanf(str,"%s",anyo);

		result=comprobarAnyo(anyo);


	}

	sscanf(str, "%i", &(listaD)->anyo);

	//CATEGORIA
	printf("Introduce la categoria: \n");
	fflush(stdout);
	fflush (stdin);
	fgets(str,MAX_LINE,stdin);
	fflush (stdin);

	char* categoria;
	int longitudCategoria=0;
	longitudCategoria=strlen(str);
	categoria= (char*) malloc((longitudCategoria+1)*sizeof(char));
	sscanf(str, "%s", categoria);

	result=comprobarLetra(categoria);

	while(result==1){

		printf("Introduzca otra vez la categoria: \n");
		fflush(stdout);
		fflush (stdin);
		fgets(str,MAX_LINE,stdin);
		fflush (stdin);

		free(categoria);

		longitudCategoria=strlen(str);
		categoria= (char*)malloc ((longitudCategoria+1)*sizeof(char));

		sscanf(str, "%s", categoria);

		result=comprobarLetra(categoria);

	}

	sscanf(str, "%s", (listaD)->categoria);

}
void mostrarDVD(Dvd* listaL, int * size){


	printf("Todos los DVD que tenemos por el momento son: \n");

	for(int i=0;i<*size;i++){

		printf("%i- Titulo: %s, Autor: %s, Anyo: %i, Categoria: %s\n", (i+1), (listaL+i)->titulo,(listaL+i)->autor, (listaL+i)->anyo, (listaL+i)->categoria);
	}

	printf("\n");

}
void mostrarNovedadesDVD(Dvd* listaL, int * size){


	printf("Estas son las ultimas novedades de DVD: \n");

	for(int i=0; i<*size; i++){

		if((listaL+i)->anyo>2017){
			printf("- Titulo: %s, Autor: %s, Anyo: %i, Categoria: %s\n", (listaL+i)->titulo,(listaL+i)->autor,
					(listaL+i)->anyo, (listaL+i)->categoria);
		}
	}

	printf("\n");

}
void escribirFicheroDVD(Dvd* listaL, int * size){

	FILE* f;
	f=fopen("Dvd.txt","w");

	fprintf(f, "%i\n",*size);

	for(int i=0; i<*size; i++){

		fprintf(f, "%s;%s;%i;%s\n", (listaL+i)->titulo,(listaL+i)->autor,(listaL+i)->anyo, (listaL+i)->categoria);
	}

	fclose(f);

}
void borrarDVD( Dvd* listaL,int* size){

	int num;
	char string [10];

	printf ("Los DVD que tenemos ahora son:\n");

	for (int i=0; i<*size; i++){

		printf ("%i) Titulo: %s, Autor %s, "
				"Anyo: %i, Categoria: %s\n", (i+1), (listaL+i)->titulo, (listaL+i)->autor,
				(listaL+i)-> anyo, (listaL+i) ->categoria);
	}

	printf ("Inserte el numero del DVD que quieras eliminar\n");
	fflush (stdout);

	fgets(string, 10, stdin);
	sscanf (string, "%i", &num);

	printf("El DVD que quieres borrar es el siguiente %s\n", (listaL+num-1)->titulo); //-1 PORQUE METES EL QUE LE APARECE AL USUARIO

	for(int i= num-1; i<*size-1; i+=1){
			listaL[i]= listaL[i+1];
		}
	*size-=1;

	if(*size>0){
	printf ("Los DVD que tenemos despues del borrado son:\n");

		for (int i=0; i<*size; i++){

				printf ("%i) Titulo: %s, Autor %s, "
						"Anyo: %i, Categoria: %s\n", (i+1), (listaL+i)->titulo, (listaL+i)->autor,
						(listaL+i)-> anyo, (listaL+i) ->categoria);
		}
	}
	else{
		printf("No hay ningun DVD\n");
	}
	
}

Dvd* leerFicheroDVD(int* size){

	char str [MAX_LINE];

	FILE * f;
	f=fopen ("Dvd.txt", "r");

	fgets(str, MAX_LINE, f);
	sscanf(str, "%i", size);

	Dvd * dvd= (Dvd *) malloc (*size * sizeof (Dvd));

	char c;
	char titulo [MAX_LINE];
	vaciar (titulo);
	char autor [MAX_LINE];
	vaciar (autor);
	char anyo [MAX_LINE];
	vaciar (anyo);
	char categoria [MAX_LINE];
	vaciar (categoria);

	for (int i=0; i<*size; i++){

		for (int i=0; c!=';'; i++){

				c=fgetc(f);

				if (c!=';'){

					titulo[i]=malloc ((MAX_LINE)*sizeof (char));
					titulo[i]=c;

				}
		}

		titulo[strlen(titulo)]='\0';
		strcpy(dvd[i].titulo, titulo);
		vaciar (titulo);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				autor[i]=malloc ((MAX_LINE)*sizeof (char));
				autor[i]=c;
			}
		}

		sscanf(autor, "%s", dvd[i].autor);
		vaciar (autor);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				anyo[i]=malloc ((MAX_LINE)*sizeof (char));
				anyo[i]=c;
			}
		}

		sscanf(anyo, "%i", &dvd[i].anyo);
		vaciar (anyo);

		c='a';

		for (int i=0; ((c!=';') && (c!='\n') &&(c!=EOF)); i++){

			c=fgetc(f);

			if (c!=';'){

				categoria[i]=malloc ((MAX_LINE)*sizeof (char));
				categoria[i]=c;
			}
		}

		sscanf(categoria, "%s", dvd[i].categoria);
		vaciar (categoria);

	}

	fclose (f);
	return dvd;

}
