#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED
#include "TDA.h"
#include "carta.h"

//FUNCIONES PARA ARMAR EL MAZO RANDOM


void liberarMemoria(coleccion*);
coleccion * cargarListaDesdeArchivo();

int contarCartas(coleccion*);
coleccion * armarMazoAleatorio(coleccion*);
void inicPila (coleccion*);
coleccion * agregarPpio(coleccion*, coleccion*);
cartaMTG verPrimero(coleccion*);
cartaMTG tope (coleccion*);
cartaMTG desapilar (coleccion*);
void apilar (coleccion*, cartaMTG);
void recorrerYmostrar(coleccion*);


#endif // PILAS_H_INCLUDED
