#ifndef COMPROBAR_H_
#define COMPROBAR_H_
#include "DVD.h"
#include "Libro.h"
#include "Cd.h"

short verificaDNI(char * dni);
char letraDNI(int dni);
int comprobarLetra(char * nombre);
int comprobarNumero (char * nombre);
int comprobarAnyo (char* anyo);
void vaciar (char vaciar []);
int comprobarTituloCd (char* titulo, Cd* listaCD, int * size);
int comprobarTituloDvd (char* titulo, Dvd* listaD, int * size);
int comprobarTituloLibro (char* titulo, Libro* listaL, int * size);




#endif
