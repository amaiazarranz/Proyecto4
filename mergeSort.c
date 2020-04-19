#include <stdio.h>
#include "operaciones.h"
#include <string.h>
#include "usuario.h"

void merge(Usuario u [], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    Usuario L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = u[l + i];
    for (j = 0; j < n2; j++)
        R[j] = u[m + 1+ j];


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i].edad <= R[j].edad)
        {
            u[k] = L[i];
            i++;
        }
        else
        {
            u[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        u[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        u[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Usuario u[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeSort(u, l, m);
        mergeSort(u, m+1, r);

        merge(u, l, m, r);
    }
}


