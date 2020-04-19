#ifndef CD_H
#define CD_H

typedef struct {
	char titulo[30];
	char autor[30];
	int anyo;
	char categoria[30];
}Cd;

void nuevoCd (Cd* lista, Cd* c,int* size);
void mostrarCd (Cd* lista, int *size);
void mostrarNovedadesCd (Cd* lista, int *size);
void escribirFicheroCd (Cd* lista, int * size);
Cd* leerFicheroCd (int* size);
void borrarCd (Cd* lista, int* size);

#endif

