#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "windows.h"
#include "carta.h"
#include "TDA.h"
#include "Pilas.h"
#include "EC.h"
#include "listas.h"
#include "arboles.h"
// Finished ////////////////////////////////////
/// Crear coleccion
/// Agregar a la coleccion
/// Mostrar coleccion
/// Buscar Carta
/// Ordenar la coleccion por valor
/// Generar estadisticas de la coleccion
/// Establecer limite de cartas
/// Eliminar carta de la coleccion
/// Operaciones con listas dobles
/// Mostrar carta
/// Guardar y cargar coleccion
// //////////////////////////////////////////////////
// Andres
/// Intercambiar cartas
/// Operaciones con estructuras compuestas

/// Ivan
// Operaciones con pilas
// Operaciones con arboles
// Filtrar cartas por tipo
// Buscar cartas por rareza
// Mostrar cartas de mayor valor
// Mostrar cartas por expansion
// Generar mazo aleatorio

int main()
{
    /// Listas dobles y EC
    coleccion * mazo;
    mazo = inicColeccion();
    variosMazos mazos[3];
    strcpy(mazos[0].nombreStack,"Principal");
    strcpy(mazos[1].nombreStack,"Secundario");
    strcpy(mazos[2].nombreStack,"Reserva");

    char continuar = 's';
    int input;
    char * nombreArchivo = "colecciones.dat";

    while(continuar == 's')
    {
        Sleep(1500);
        system("cls");

        printf("Que accion desea realizar?\n");
        printf("1- Cargar mazo de cartas\n");
        printf("2- Crear nuevo mazo\n --> ");
        scanf("%i",&input);

        switch(input)
        {
        case 1:
            leerArchivo(&mazo,nombreArchivo);
            continuar = 'n';
            break;
        case 2:
            /// Simplemente se utilizara el mazo inicializado previamente
            continuar = 'n';
            break;
        }
        if(continuar == 's')
            printf("\nEl numero ingresado no corresponde a una accion disponible...\n");
    }


    /// En este punto ya sabemos la intencion principal del usuario


    system("cls");
    int inputSubMenu=0;
    int flagMazosCargados=0;
    continuar = 's';
    /// Arboles
    nodoArbol * arbol;
    arbol = inicArbol();
    /// Pilas
    coleccion * Pila;
    while(continuar == 's')
    {
        opcionesMenu();
        scanf("%i",&input);
        char palabra[20];

        switch(input)
        {
        case 1:
            mazo = cargarVariasCartas(mazo);
            break;
        case 2:
            mostrarMazo(mazo,1);
            break;
        case 3:
            printf("Que carta desea borrar del mazo? -> ");
            scanf("%s",palabra);
            mazo = borrarCarta(mazo,palabra);
            break;
        case 4:
            mazo = ordenarMazo(mazo);
            break;
        case 5:
            generarEstadisticas(mazo);
            break;
        case 6:
            sobreescribirArchivo(mazo);
            break;
        case 7:
            printf("   1- Cargar varios mazos\n");
            printf("   2- Mostrar varios mazos\n");
            printf("   3- Ver estadisticas de cada mazo\n");
            printf("   --> ");
            scanf("%i",&inputSubMenu);
            system("cls");
            switch(inputSubMenu)
            {
            case 1:
                cargarVariosMazos(mazos,3);
                flagMazosCargados = 1;
                break;
            case 2:
                if(flagMazosCargados)
                    mostrarVariosMazos(mazos,3);
                else
                    printf("Los mazos no fueron cargados...\n");
                break;
            case 3:
                if(flagMazosCargados)
                {
                    for(int i = 0; i< 3; i++)
                    {
                        printf(" -  Mazo: %s\n",mazos[i].nombreStack);
                        fflush(stdin);
                        generarEstadisticas(mazos[i].mazoActual);
                        printf("\n");
                    }
                }
                else
                    printf("Los mazos no fueron cargados...\n");
                break;
            }
            break;
        case 8:
            printf("   1- Generar mazo aleatorio a partir de mazo cargado\n");
            printf("   2- Mostrar pila\n");
            printf("   --> ");
            scanf("%i",&inputSubMenu);
            system("cls");
            switch(inputSubMenu)
            {
            case 1:
                mazo = armarMazoAleatorio(mazo);
                break;
            case 2:
                recorrerYmostrar(mazo);
                break;

            }
            break;
        case 9:
            printf("   1- Cargar arbol con datos del mazo\n");
            printf("   2- Mostrar arbol\n");
            printf("   --> ");
            scanf("%i",&inputSubMenu);
            system("cls");
            switch(inputSubMenu)
            {
            case 1:
                arbol = ingresarNodosEnOrden(arbol);
                break;
            case 2:
                system("cls");
                treeprint(arbol,0);
                printf("\n");
                break;
            }
            break;
        case 10:
            preguntaCartaBuscar(palabra);
            coleccion * aux = retornaCarta(mazo,palabra);
            if(aux!=NULL)
                mostrarCarta(aux->dato);
            else
                printf("La carta no se encuentra en el mazo.\n");
            break;
        case 0:
            informacionAlUsuario();
            break;
        }
        if(mazo == NULL)
            printf("El mazo simple esta vacio.\n");
        printf("Menu.. ");
        continuar = preguntaContinuar();
        system("cls");
    }

    return 0;
}
