#include <stdio.h>
#include "usuario.h"
#include "secretario.h"
#include "comprobar.h"
#include "operaciones.h"
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 30


void mostrarUsuarios (Usuario * u, int * size){

	printf ("Todos los usuarios que tenemos por el momento son:\n");

	for (int i=0; i<*size; i++){

				printf ("Usuario %i) Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
						"DNI: %s, Edad: %i\n", (i+1), (u+i)->nombre, (u+i)->apellido1, (u+i)->apellido2, (u+i)-> dni, (u+i) ->edad);
		}
}

void mostrarUsuariosOrdenado (Usuario * u, int * size){

	printf ("Procederemos a ordenar los usuarios del mas joven al menos joven. Espere unos segundos\n");

	mergeSort(u, 0, *(size)-1);

	printf ("Este es el resultado ordenado\n");

	for (int i=0; i<*size; i++){

		printf ("Usuario %i) Edad: %i, Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
				"DNI: %s\n", (i+1), (u+i)->edad, (u+i)->nombre, (u+i)->apellido1, (u+i)->apellido2, (u+i)-> dni);
	}
}

void escribirFicheroUsuario (Usuario * u, int * size){

	FILE* f;

	f=fopen ("usuarios.txt", "w");

	fprintf(f, "%i\n", *size);

	for (int i=0; i<*size; i++){

		fprintf (f, "%s;%s;%s;%s;%s;%i\n",
				(u+i)->nombre, (u+i)->apellido1, (u+i)->apellido2, (u+i)->dni, (u+i)->contrasena, (u+i)->edad);
	}

	fclose (f);
}

void borrarUsuario (Usuario * u, int * size){

	int num;
	char string [10];

	if (*size==0){

		printf("No hay usuarios por lo que no podemos borrar\n");

	}

	else{
		printf ("Los estudiantes que tenemos ahora son:\n");

		for (int i=0; i<*size; i++){

			printf ("%i) Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
					"DNI: %s, Edad: %i\n", (i+1), (u+i)->nombre, (u+i)->apellido1, (u+i)->apellido2, (u+i)-> dni, (u+i) ->edad);
		}

		printf ("Inserte el numero del usuario que quieras eliminar\n");
		fflush (stdout);

		fgets(string, 10, stdin);
		sscanf (string, "%i", &num);

		printf("El usuario que quieres borrar es el siguiente %s\n", (u+num-1)->nombre); //-1 PORQUE METES EL QUE LE APARECE AL USUARIO

		for(int i= num-1; i<*size-1; i+=1){
				u[i]= u[i+1];
			}
		*size-=1;

		printf ("Los estudiantes que tenemos despues del borrado son:\n");

		for (int i=0; i<*size; i++){

			printf ("%i) Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
					"DNI: %s, Edad: %i\n", (i+1), (u+i)->nombre, (u+i)->apellido1, (u+i)->apellido2, (u+i)-> dni, (u+i) ->edad);
		}
	}

}


Usuario * leerUsuarios (int * size){

	char str [MAX_LINE];

	FILE * f;
	f=fopen ("usuarios.txt", "r");

	fgets(str, MAX_LINE, f);
	sscanf(str, "%i", size);

	Usuario * usuario= (Usuario *) malloc (*size * sizeof (Usuario));

	char c;
	char nombre [MAX_LINE];
	vaciar (nombre);
	char apellido1 [MAX_LINE];
	vaciar (apellido1);
	char apellido2 [MAX_LINE];
	vaciar (apellido2);
	char dni [MAX_LINE];
	vaciar (dni);
	char contrasena [MAX_LINE];
	vaciar (contrasena);
	char edad [MAX_LINE];
	vaciar (edad);

	for (int i=0; i<*size; i++){

		for (int i=0; c!=';'; i++){

				c=fgetc(f);

				if (c!=';'){

					nombre[i]=malloc ((MAX_LINE)*sizeof (char));
					nombre[i]=c;

				}
		}

		sscanf(nombre, "%s", usuario[i].nombre);
		vaciar (nombre);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				apellido1[i]=malloc ((MAX_LINE)*sizeof (char));
				apellido1[i]=c;
			}
		}

		sscanf(apellido1, "%s", usuario[i].apellido1);
		vaciar (apellido1);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				apellido2[i]=malloc ((MAX_LINE)*sizeof (char));
				apellido2[i]=c;
			}
		}

		sscanf(apellido2, "%s", usuario[i].apellido2);
		vaciar (apellido2);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				dni[i]=malloc ((MAX_LINE)*sizeof (char));
				dni[i]=c;
			}
		}

		sscanf(dni, "%s", usuario[i].dni);
		vaciar (dni);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				contrasena[i]=malloc ((MAX_LINE)*sizeof (char));
				contrasena[i]=c;
			}
		}

		sscanf(contrasena, "%s", usuario[i].contrasena);
		vaciar (contrasena);

		c='a';

		for (int i=0; ((c!=';')&& (c!='\n')&& (c!=EOF)); i++){

			c=fgetc(f);

			if (c!=';'){

				edad[i]=malloc ((MAX_LINE)*sizeof (char));
				edad[i]=c;
			}
		}

		sscanf(edad, "%i", &usuario[i].edad);
		vaciar (edad);


	}

	fclose (f);
	return usuario;

}
