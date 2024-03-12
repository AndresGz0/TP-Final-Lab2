#include "EC.h"
#include <stdio.h>
void cargarVariosMazos(variosMazos mazo[],int cantMazos)
{
    for(int i = 0; i < cantMazos; i++)
    {
        printf("----- CARGA DEL %i MAZO -----(%i/%i)\n",i+1,i+1,cantMazos);
        mazo[i].mazoActual = inicColeccion();
        mazo[i].mazoActual = cargarVariasCartas(mazo[i].mazoActual);
        system("cls");
    }
}
void mostrarVariosMazos(variosMazos mazo[],int val)
{
    for(int i = 0; i<val ; i++)
    {
        printf("----- MAZO: %s -----\n",mazo[i].nombreStack);
        while(mazo[i].mazoActual != NULL)
        {
            mostrarCarta(mazo[i].mazoActual->dato);
            mazo[i].mazoActual = mazo[i].mazoActual->sig;
        }
        if(i<val-1)
        {
            printf("\n\nIngrese cualquier tecla para ver siguiente mazo ->");
            fflush(stdin);
            scanf("%i");
            system("cls");
        }
    }
}
void intercambiarCartasEntreMazos(variosMazos mazo[], int numMazos)
{
    char nombreCartaAIntercambiar[20];
    char nombreCartaBIntercambiar[20];
    char respuesta;

    do
    {
        printf("Ingrese el nombre de la carta a intercambiar: ");
        fflush(stdin);
        scanf("%s", nombreCartaAIntercambiar);
        printf("\nIngrese el nombre de la carta por la cual desea intercambiar: ");
        fflush(stdin);
        scanf("%s", nombreCartaBIntercambiar);

        // Búsqueda de las cartas en cada mazo
        coleccion *cartaA = inicColeccion();
        coleccion *cartaB = inicColeccion();

        for (int i = 0; i < numMazos; i++)
        {
            cartaA = retornaCarta(mazo[i].mazoActual, nombreCartaAIntercambiar);
            cartaB = retornaCarta(mazo[i].mazoActual, nombreCartaBIntercambiar);

            if (cartaA != NULL && cartaB != NULL)
            {
                // Intercambio de las cartas entre mazos
                if (cartaA->ante != NULL)
                {
                    coleccion * aux = cartaA->ante;
                    aux->sig = cartaB;
                    cartaB->ante = cartaA->ante;
                }
                else
                {
                    mazo[i].mazoActual = cartaB; // Actualizar el inicio del mazo si la carta intercambiada era la primera
                }

                cartaA->sig = cartaB->sig;
                if (cartaB->sig != NULL)
                {
                    coleccion * aux2 = cartaB->sig;
                    aux2->ante = cartaA;
                }

                cartaB->sig = cartaA;
                cartaA->ante = cartaB;

                // Puedes agregar aquí la lógica necesaria con la variable auxiliar

                free(cartaA); // Liberar memoria de la carta intercambiada
            }
        }

        printf("¿Desea realizar otro intercambio? (s/n): ");
        scanf(" %c", &respuesta); // Espacio antes del %c para consumir el salto de línea anterior
    }
    while (respuesta == 's');
    /// ver el retorno o mostrar en la funcion esta
}

coleccion * retornaCarta(coleccion * mazo, char carta[])
{
    coleccion * seg = mazo;
    while(seg!= NULL && strcmpi(seg->dato.Nombre,carta)!=0)
    {
        seg = seg->sig;
    }
    return seg;
}

