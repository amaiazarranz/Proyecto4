#include <stdio.h>
#include "secretario.h"
#include "comprobar.h"
#include "operaciones.h"
#include "usuario.h"
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 30
#define MAX_NUM 50


void mostrarSecretarios (Secretario * s, int * size){

	printf ("Estos son todos los secretarios\n");

	for (int i=0; i<*size; i++){

		printf ("Secretario %i) Sueldo: %i, Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
				"DNI: %s, Edad: %i\n", (i+1), (s+i)->sueldo, (s+i)->nombre, (s+i)->apellido1,
				(s+i)->apellido2, (s+i)-> dni, (s+i)->edad);

	}
}

void salariosOrdenados (Secretario * s, int * size){

	printf ("Estos son los salarios ordenados de menor a mayor.\n");
	printf ("Por razones de privacidad no se mostraran los datos personales de los secretarios\n");
	fflush (stdout);

	int salario [*size];

	for (int i=0; i<*size; i++){

		salario[i]=(s+i)->sueldo;
	}

	quicksort(salario, 0, *(size)-1);

		for (int i=0; i<*size; i++){

			printf("%i€\n", salario[i]);
		}
}

void escribirFicheroSecretario (Secretario * s, int * size){

	FILE* f;

	f=fopen ("secretarios.txt", "w");

	fprintf(f, "%i\n", *size);

	for (int i=0; i<*size; i++){

		fprintf (f, "%s;%s;%s;%s;%s;%i;%i\n", (s+i)->nombre, (s+i)->apellido1,
				(s+i)->apellido2, (s+i)-> dni, (s+i)->contrasena, (s+i)->edad, (s+i)->sueldo);
	}

	fclose (f);
}

void borrarSecretario (Secretario * s, int *size){

	int num;
	char string [5];

	printf ("Los secretarios que tenemos ahora son:\n");

	for (int i=0; i<*size; i++){

		printf ("%i) Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
						"DNI: %s, Edad: %i, Sueldo: %i\n", (i+1), (s+i)->nombre, (s+i)->apellido1,
						(s+i)->apellido2, (s+i)-> dni, (s+i)->edad, (s+i)->sueldo);

	}

	printf ("Inserte el numero del secretario que quieras eliminar\n");
	fflush (stdout);

	fgets(string, 5, stdin);
	sscanf (string, "%i", &num);

	printf("El secretario que quieres borrar es el siguiente %s\n", (s+num-1)->nombre); //-1 PORQUE METES EL QUE LE APARECE AL USUARIO

	for(int i= num-1; i<*size-1; i+=1){
			s[i]= s[i+1];
		}
	*size-=1;

	printf ("Los secretarios que tenemos despues del borrado son:\n");

	for (int i=0; i<*size; i++){

			printf ("%i) Nombre: %s, Primero Apellido: %s, Segundo Apellido %s, "
							"DNI: %s, Edad: %i, Sueldo: %i\n", (i+1), (s+i)->nombre, (s+i)->apellido1,
							(s+i)->apellido2, (s+i)-> dni, (s+i)->edad, (s+i)->sueldo);

		}

}

Secretario * leerSecretarios(int * size){

	char str [MAX_NUM];

	FILE * f;
	f=fopen ("secretarios.txt", "r");

	fgets(str, MAX_NUM, f);
	sscanf(str, "%i", size);

	Secretario * secretario= (Secretario *) malloc (*size * sizeof (Secretario));

	char c;
	char nombre [MAX_NUM];
	vaciar (nombre);
	char apellido1 [MAX_NUM];
	vaciar (apellido1);
	char apellido2 [MAX_NUM];
	vaciar (apellido2);
	char dni [MAX_NUM];
	vaciar (dni);
	char contrasena [MAX_NUM];
	vaciar (contrasena);
	char edad [MAX_NUM];
	vaciar (edad);
	char salario [MAX_NUM];
	vaciar (salario);

	for (int i=0; i<*size; i++){

		for (int i=0; c!=';'; i++){

				c=fgetc(f);

				if (c!=';'){

					nombre[i]=malloc ((MAX_NUM)*sizeof (char));
					nombre[i]=c;

				}
		}

		sscanf(nombre, "%s", secretario[i].nombre);
		vaciar (nombre);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				apellido1[i]=malloc ((MAX_NUM)*sizeof (char));
				apellido1[i]=c;
			}
		}

		sscanf(apellido1, "%s", secretario[i].apellido1);
		vaciar (apellido1);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				apellido2[i]=malloc ((MAX_NUM)*sizeof (char));
				apellido2[i]=c;
			}
		}

		sscanf(apellido2, "%s", secretario[i].apellido2);
		vaciar (apellido2);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				dni[i]=malloc ((MAX_NUM)*sizeof (char));
				dni[i]=c;
			}
		}

		sscanf(dni, "%s", secretario[i].dni);
		vaciar (dni);

		c='a';

		for (int i=0; c!=';'; i++){

			c=fgetc(f);

			if (c!=';'){

				contrasena[i]=malloc ((MAX_NUM)*sizeof (char));
				contrasena[i]=c;
			}
		}

		sscanf(contrasena, "%s", secretario[i].contrasena);
		vaciar (contrasena);

		c='a';

		for (int i=0; (c!=';'); i++){

			c=fgetc(f);

			if (c!=';'){

				edad[i]=malloc ((MAX_NUM)*sizeof (char));
				edad[i]=c;
			}
		}

		sscanf(edad, "%i", &secretario[i].edad);
		vaciar (edad);

		c='a';

		for (int i=0; ((c!=';')&& (c!='\n')&& (c!=EOF)); i++){

			c=fgetc(f);

			if (c!=';'){

				salario[i]=malloc ((MAX_NUM)*sizeof (char));
				salario[i]=c;
			}
		}

		sscanf(salario, "%i", &secretario[i].sueldo);
		vaciar (salario);


	}

	return secretario;
	fclose (f);

}
