#ifndef LOGIN_H_
#define LOGIN_H_

#include "secretario.h"
#include "usuario.h"
#include "Libro.h"
#include "DVD.h"
#include "Cd.h"

void login (Usuario * u, Secretario * s, int sizeUs, int sizeSe, Libro * l, Dvd * d, Cd * c, int *numL, int * numC, int  * numD);
int comprobarUsuario (char * dni, char * contrasena, Usuario * u, int sizeUs);
int comprobarSecretario (char * dni, char * contrasena, Secretario * s, int sizeSe);

#endif
