#ifndef SECRETARIO_H_
#define SECRETARIO_H_

typedef struct {

	char nombre [10];
	char apellido1 [25];
	char apellido2 [25];
	char contrasena [50];
	char dni [25];
	int edad;
	int sueldo;

} Secretario;

Secretario * leerSecretarios(int * size);
void mostrarSecretarios(Secretario * s, int * size);
void salariosOrdenados(Secretario * s, int * size);
void escribirFicheroSecretario(Secretario * s, int * size);
void borrarSecretario (Secretario * s, int * size);

#endif 
