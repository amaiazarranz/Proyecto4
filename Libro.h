#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct {
	
	char titulo[30];
	char autor[30];
	char editorial[30];
	int anyo;
	char categoria[30];

} Libro;

void nuevoLibro( Libro* listaL, Libro * lista, int* size);
void mostrarLibro(Libro* listaL, int * size);
void mostrarNovedadesLibro(Libro* listaL, int * size);
void escribirFicheroLibro(Libro* listaL, int * size);
void borrarLibro( Libro* listaL, int* size);
Libro* leerFicheroLibro(int* size);



#endif
