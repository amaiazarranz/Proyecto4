#ifndef MENUSECRETARIO_H_
#define MENUSECRETARIO_H_


#include "usuario.h"
#include "libro.h"
#include "DVD.h"
#include "Cd.h"

char mostrarMenuUsuario();
void altaUsuario (Usuario * usuario, int * numUsu);
void mostrarLibro (Libro * listaL,int *num);
void mostrarNovedadesLibro(Libro* listaL, int * size);
void mostrarCd(Cd * listaC, int * numC);
void mostrarNovedadesCd(Cd * listaC, int * numC);
void mostrarDVD (Dvd * listaD, int * numD);
void mostrarNovedadesDVD(Dvd * listaD, int * numD);

#endif
