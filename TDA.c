#include "TDA.h"
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int buscarCarta(coleccion * mazo,char palabra[20])
{
    int r=0;
    if(mazo)
    {
        if(strcmp(mazo->dato.Nombre,palabra) == 0)
            r = 1;
        else
            r = buscarCarta(mazo->sig,palabra);
    }
    return r;
}
coleccion * borrarCarta(coleccion * mazo, char palabra[20])
{
    if(mazo != NULL) // SI NO ESTA VACIA
    {
        if(strcmp(mazo->dato.Nombre,palabra) == 0) // SI ES EL PRIMER ELEMENTO
        {
            coleccion * aux = mazo; /// recuerda coleccion a borrar
            mazo = mazo->sig; /// lo quita de la mazo (lo skipea)
            free(aux); /// borra el coleccion de la memoria
        }
        else // SI ESTA EN EL RESTO DE LA mazo
        {
            coleccion * seguidora = mazo;
            coleccion * anterior = seguidora;
            while ((seguidora != NULL) && strcmp(seguidora->dato.Nombre,palabra) != 0)
            {
                anterior = seguidora;
                seguidora = seguidora->sig;
            }

            if (seguidora!=NULL) /// si encuentra el dato
            {
                anterior ->sig = seguidora ->sig;
                free(seguidora);
            }


        }
    }
    return mazo;

}
coleccion * cargarVariasCartas(coleccion* listaMazo)
{
    char continuar;
    cartaMTG carta;
    int repetido;

    do
    {
        printf("Cantidad de datos en el mazo = %f, maximo: %i\n\n",cuentaCartasEnMazo(listaMazo),TOPE_DE_MAZO);
        carta = cargarCarta();
        repetido = verificaDatosRepetidos(listaMazo,carta); /// Si el nombre o el valor ya esta en la lista no lo agrega
        if(repetido == 0)
        {
            coleccion * nuevaCarta = crearNodoColeccion(carta);
            listaMazo = agregarAlFinal(listaMazo,nuevaCarta);
        }
        else
            printf("El dato no fue ingresado ya que estaba repetido en la lista...\n Carga de cartas..");
        continuar = preguntaContinuar();


    }
    while(continuar == 's' && cuentaCartasEnMazo(listaMazo) < TOPE_DE_MAZO);

    if(cuentaCartasEnMazo(listaMazo) == TOPE_DE_MAZO)
        printf("El mazo esta lleno.\n");

    return listaMazo;
}
coleccion * inicColeccion ()
{
    return NULL;
}

coleccion * crearNodoColeccion(cartaMTG aux)
{
    coleccion * nuevaCarta = (coleccion*)malloc(sizeof(coleccion));

    strcpy (nuevaCarta->dato.Color, aux.Color);
    strcpy (nuevaCarta->dato.Expansion, aux.Expansion);
    strcpy (nuevaCarta->dato.Nombre, aux.Nombre);
    strcpy (nuevaCarta->dato.Tipo, aux.Tipo);
    nuevaCarta->dato.Rareza = aux.Rareza;
    nuevaCarta->dato.Valor = aux.Valor;

    nuevaCarta->sig = NULL;
    nuevaCarta->ante = NULL;

    return nuevaCarta;
}
coleccion * agregarAlFinal(coleccion * listaMazo, coleccion * nuevaCarta)
{
    if(listaMazo == NULL && cuentaCartasEnMazo(listaMazo) < TOPE_DE_MAZO)
    {
        listaMazo = nuevaCarta;
    }
    else if (cuentaCartasEnMazo(listaMazo) < TOPE_DE_MAZO)
    {
        coleccion * ultimo = buscarUltimo(listaMazo);
        ultimo->sig = nuevaCarta;
    }
    return listaMazo;
}
coleccion * buscarUltimo(coleccion * listaMazo)
{
    coleccion * seg = listaMazo;
    while(seg->sig)
    {
        seg=seg->sig;
    }
    return seg;
}

coleccion * agregarEnOrden(coleccion * listaMazo,coleccion* nuevaCarta)
{
    if(listaMazo == NULL)
    {
        listaMazo = nuevaCarta;
    }
    else
    {
        if(nuevaCarta->dato.Valor <= listaMazo->dato.Valor)
        {
            nuevaCarta->sig = listaMazo;
            listaMazo->ante = nuevaCarta;
            listaMazo = nuevaCarta;
        }
        else
        {
            coleccion* seguidora = listaMazo;
            coleccion* anterior = NULL;
            while((seguidora!=NULL) && (nuevaCarta->dato.Valor >= seguidora->dato.Valor))
            {
                anterior = seguidora;
                seguidora = seguidora->sig;
            }
            nuevaCarta->sig = seguidora;

            if(seguidora != NULL)
            {
                nuevaCarta->ante = anterior;
                anterior->sig = nuevaCarta;
                seguidora->ante = nuevaCarta;
            }
            else
            {
                nuevaCarta->ante = anterior;
                anterior->sig = nuevaCarta;
            }
        }
    }
    return listaMazo;
}
coleccion * ordenarMazo (coleccion * listaMazo)
{
    coleccion * listaOrdenada;
    listaOrdenada = inicColeccion();

    coleccion * seg = listaMazo;
    while(seg)
    {
        coleccion * nuevaCarta = crearNodoColeccion(seg->dato);
        listaOrdenada = agregarEnOrden(listaOrdenada,nuevaCarta);
        seg = seg->sig;
    }

    return listaOrdenada;
}
