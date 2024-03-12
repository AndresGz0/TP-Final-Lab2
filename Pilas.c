#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Pilas.h"
#include "carta.h"
#include "TDA.h"


coleccion * agregarPpio(coleccion * lista, coleccion * nuevoNodo)
{

    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else

    {
        nuevoNodo->sig = lista;
        lista = nuevoNodo;
    }
    return lista;
}


// Función para obtener la cantidad de cartas en la colección
int contarCartas(coleccion* coleccionActual) {
    int contador = 0;
    coleccion * aux = coleccionActual;
    while (aux != NULL) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}


// Función para armar un mazo aleatorio a partir de una colección
coleccion * armarMazoAleatorio(coleccion* coleccionOriginal) {
    coleccion * mazo = inicColeccion();
    srand(time(0)); // Semilla para números aleatorios
    coleccion * auxi = coleccionOriginal;

    int totalCartas = contarCartas(auxi);
    int cartasMazo = (totalCartas > 25) ? 25 : totalCartas;

    int cartasAgregadas = 0;

    while (cartasAgregadas < cartasMazo && auxi != NULL) {
        // Genera un número aleatorio entre 0 y el total de cartas disponibles
        int indiceCarta = rand() % totalCartas;

        // Recorre la colección hasta el índice seleccionado
        coleccion * temp = auxi;
        coleccion * prevTemp = NULL;
        for (int i = 0; i < indiceCarta && temp != NULL; i++) {
            prevTemp = temp;
            temp = temp->sig;
        }

        if (temp != NULL) {
            // Agregar la carta al mazo
            mazo = agregarPpio(mazo, crearNodoColeccion(temp->dato));
            cartasAgregadas++;

            // Eliminar la carta de la colección original
            if (prevTemp == NULL) {
                auxi = temp->sig;
            } else {
                prevTemp->sig = temp->sig;
            }

            free(temp);
            totalCartas--;
        }
    }

    return mazo;
}

// Funciones con pilas o mazos

cartaMTG verPrimero(coleccion * lista)
{
    cartaMTG rta;
    if(lista)
    {
        rta=lista->dato;
    }
    return rta;

}


cartaMTG tope (coleccion * pila)
{
    cartaMTG rta;
    if(pila !=NULL)
    {
       rta=verPrimero(pila);
    }
    return rta;
}


cartaMTG desapilar (coleccion * pila)
{

    cartaMTG rta;
    if(pila !=NULL)
    {
        rta = verPrimero(pila);

            coleccion * aux = pila; /// recuerda coleccion a borrar
            pila = pila->sig;
            pila->ante = NULL;                     /// lo quita de la mazo (lo skipea)
            free(aux); /// borra el coleccion de la memoria

    }

    return rta;
}


void  apilar (coleccion * pila, cartaMTG dato)
{
    coleccion * aux= crearNodoColeccion(dato);
    pila=agregarPpio(pila,aux);
}


void recorrerYmostrar(coleccion * lista)
{
    coleccion * aux=lista;
    while(aux!=NULL)
    {
        mostrarCarta(aux->dato);
        aux=aux->sig;
        }
}
coleccion * apilarCartas(coleccion * mazo) /// /// ///
{
    char cont;
    cartaMTG carta;
    do{

        carta = cargarCarta();
        apilar(mazo,carta);
        cont = preguntaContinuar();

    }while(cont == 's');

    return mazo;
}
