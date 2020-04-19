#ifndef MENUSECRETARIO_H_
#define MENUSECRETARIO_H_

#include "secretario.h"
#include "usuario.h"
#include "Libro.h"
#include "DVD.h"
#include "Cd.h"

char mostrarMenuSecretario();
void altaSecretario (Secretario * secretario, int * numSecre, Usuario * usuario, int * numUsu,
		Libro * l, Dvd * d, Cd * c, int *numL, int * numC, int  * numD);
void borrarUsuario (Usuario * u, int * size);
void introducirSecretario (Secretario * s, Secretario *p, int * sizeSecre, Usuario* p2, int * sizeUsu);


#endif
