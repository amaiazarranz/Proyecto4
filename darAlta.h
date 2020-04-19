#ifndef DARALTA_H_
#define DARALTA_H_

#include "secretario.h"
#include "usuario.h"

char mostrarMenuAlta();
void darAlta (Usuario * usuario,  int * numUsu, Secretario * secretario, int * numSecre);
void introducirUsuario (Usuario * u, Usuario *p, int * sizeUsuarios, Secretario * p2, int * sizeSecretarios);
void introducirSecretario (Secretario * s, Secretario *p, int * sizeSecre, Usuario* p2, int * sizeUsu);

#endif
