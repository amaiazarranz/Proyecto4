
#include <stdio.h>
#include "operaciones.h"

void quicksort (int lista[],int limite_izq,int limite_der)
{

    int izq,der,temporal,pivote;

    izq=limite_izq;

    der = limite_der;

    pivote = lista[(izq+der)/2];


    do{

        while(lista[izq]<pivote && izq<limite_der)izq++;

        while(pivote<lista[der] && der > limite_izq)der--;

        if(izq <=der)

        {

            temporal= lista[izq];

            lista[izq]=lista[der];

            lista[der]=temporal;

            izq++;

            der--;

        }



    }while(izq<=der);

    if(limite_izq<der){
    	quicksort(lista,limite_izq,der);
    }

    if(limite_der>izq){
    	quicksort(lista,izq,limite_der);
    }

}
