#ifndef DVD_H_
#define DVD_H_

typedef struct {
	
	char titulo[30];
	char autor[30];
	int anyo;
	char categoria[30];

}Dvd;

void nuevoDVD( Dvd* listaD, Dvd * lista, int* size);
void mostrarDVD(Dvd* listaD, int * size);
void mostrarNovedadesDVD(Dvd* listaD, int * size);
void escribirFicheroDVD(Dvd* listaD, int * size);
void borrarDVD(Dvd* listaD,int* size);
Dvd* leerFicheroDVD(int* size);

#endif
