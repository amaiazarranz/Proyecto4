#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct {

	char nombre [10];
	char apellido1 [25];
	char apellido2 [25];
	char contrasena [40];
	char dni [9];
	int edad;

} Usuario;

Usuario * leerUsuarios (int * size);
void mostrarUsuarios (Usuario * u, int * size);
void mostrarUsuariosOrdenado (Usuario * u, int * size);
void escribirFicheroUsuario (Usuario *u, int * size);
void borrarUsuario (Usuario * u, int * size);

#endif
