#ifndef EC_H_INCLUDED
#define EC_H_INCLUDED
#include "carta.h"

typedef struct
{
    char nombreStack[20];
    coleccion * mazoActual;
} variosMazos;

void cargarVariosMazos(variosMazos[],int); /// Coleccion / Validos
void mostrarVariosMazos(variosMazos[],int); /// Coleccion / Validos
void intercambiarCartasEntreMazos(variosMazos[], int);
coleccion * retornaCarta(coleccion *, char[]);

#endif // EC_H_INCLUDED
