#include "arboles.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

nodoArbol * inicArbol()
{
    return NULL;
}
nodoArbol * crearNodoArbol(cartaMTG datoNC)
{
    nodoArbol * nuevoNodo = (nodoArbol*)malloc(sizeof(nodoArbol));


    strcpy(nuevoNodo->dato.Color,datoNC.Color);
    strcpy(nuevoNodo->dato.Expansion,datoNC.Expansion);
    strcpy(nuevoNodo->dato.Nombre,datoNC.Nombre);
    nuevoNodo->dato.Rareza = datoNC.Rareza;
    strcpy(nuevoNodo->dato.Tipo,datoNC.Tipo);
    nuevoNodo->dato.Valor = datoNC.Valor;


    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

nodoArbol * insertar(nodoArbol * raiz, nodoArbol * nuevoNodo)
{
    if(raiz == NULL)
        raiz = nuevoNodo;
    else
    {
        if(nuevoNodo->dato.Valor > raiz->dato.Valor) /// Inserta por rareza, si es el mismo, se rompe, deberia ser por valor de mercado
        {
            raiz->der = insertar(raiz->der,nuevoNodo);
        }
        else
        {
            raiz->izq = insertar(raiz->izq,nuevoNodo);
        }
    }

    return raiz;
}

nodoArbol * ingresarNodosEnOrden(nodoArbol * raiz)
{
    char cont;
    cartaMTG p;

    do
    {
        p = cargarCarta();
        nodoArbol * nuevoNodo = crearNodoArbol(p);

        raiz = insertar(raiz,nuevoNodo);

        system("cls");
        cont = preguntaContinuar();
    }
    while(cont == 's');

    return raiz;
}
int contarHojas(nodoArbol* raiz,int cantidad)
{
    if(raiz != NULL)
    {
        printf("cantidad %i\n",cantidad);
        cantidad = cantidad + contarHojas(raiz->izq,cantidad);
        cantidad = cantidad + contarHojas(raiz->der,cantidad);
    }
    else
        cantidad = cantidad + 1;

    return cantidad;
}
void preorder(nodoArbol * raiz)
{
    if(raiz != NULL)
    {
        mostrarCarta(raiz->dato);
        preorder(raiz->izq);
        preorder(raiz->der);
    }
}
void inorder(nodoArbol * raiz)
{
    if(raiz != NULL)
    {
        inorder(raiz->izq);
        mostrarCarta(raiz->dato);
        inorder(raiz->der);
    }
}
void postorder(nodoArbol * raiz)
{
    if(raiz != NULL)
    {
        postorder(raiz->izq);
        postorder(raiz->der);
        mostrarCarta(raiz->dato);
    }
}
void mostrarDeTodasManeras(nodoArbol * raiz)
{
    printf("PREORDER:\n");
    preorder(raiz);
    printf("INORDER:\n");
    inorder(raiz);
    printf("POSTORDER:\n");
    postorder(raiz);
}

void treeprint(nodoArbol *root, int level)
{
    if (root == NULL)
        return;
    for (int i = 0; i < level; i++)
        printf(i == level - 1 ? "|-" : "  ");
    printf("%s\n", root->dato.Nombre);
    treeprint(root->izq, level + 1);
    treeprint(root->der, level + 1);
}



