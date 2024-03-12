#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED
#include "carta.h"

typedef struct
{
    struct nodoArbol * izq;
    struct nodoArbol * der;
    cartaMTG dato;
} nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(cartaMTG);
nodoArbol * insertar(nodoArbol*,nodoArbol*);
void preorder(nodoArbol*);
void inorder(nodoArbol*);
void postorder(nodoArbol*);
void mostrarDeTodasManeras(nodoArbol*);
void treeprint(nodoArbol*,int);
//
int contarHojas(nodoArbol*,int);
int contarNodos1Grado(nodoArbol*);
nodoArbol * ingresarNodosEnOrden(nodoArbol*);
void recorrerYMostrarEnOrden(nodoArbol*);


#endif // ARBOLES_H_INCLUDED
