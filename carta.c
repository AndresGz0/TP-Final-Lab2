#include "carta.h"
#include <stdio.h>

cartaMTG cargarCarta()
{
    cartaMTG aux;
    printf("Ingrese nombre: ");
    scanf("%s",aux.Nombre);
    printf("\nIngrese expansion: ");
    scanf("%s",aux.Expansion);
    printf("\nIngrese color (0-4): ");
    scanf("%s",aux.Color);
    printf("\nIngrese tipo (0-5): ");
    scanf("%s",aux.Tipo);
    printf("\nIngrese rareza (0-3): ");
    scanf("%i",&aux.Rareza);
    printf("\nIngrese valor: ");
    scanf("%f",&aux.Valor);
    printf("\n");

    return aux;
}
float cuentaCartasEnMazo(coleccion * listaMazo)
{
    float cantidad=0;
    coleccion * seg = listaMazo;
    while(seg)
    {
        cantidad++;
        seg = seg->sig;
    }
    return cantidad;
}
void mostrarCarta(cartaMTG carta)
{
    printf("================================\n");
    printf("|| Nombre ----> %s   \n",carta.Nombre);
    printf("|| Expansion -> %s   \n",carta.Expansion);
    printf("|| Color -----> %s   \n",carta.Color);
    printf("|| Tipo ------> %s   \n",carta.Tipo);
    printf("|| Rareza ----> %i   \n",carta.Rareza);
    printf("|| Valor -----> %.0f     \n",carta.Valor);
    printf("================================\n");

    printf("\n");
}
void mostrarMazo(coleccion * listaMazo,int i)
{
    coleccion * seg = listaMazo;
    if(seg != NULL)
    {
        printf("            %i\n",i);
        mostrarCarta(seg->dato);
        mostrarMazo(seg->sig,i+1);
    }
}
void preguntaCartaBuscar(char * cartaABuscar)
{
    printf("Que carta desea buscar? -> ");
    scanf("%s",cartaABuscar);
}
void generarEstadisticas(coleccion *listaMazo)
{
    int flag = 0;
    float promedioValor = 0;
    int cantRareza[4] = {0, 0, 0, 0};
    int cantColor[5] = {0, 0, 0, 0, 0};
    int cantTipo[6] = {0, 0, 0, 0, 0, 0};
    float cantCartas;
    cantCartas = cuentaCartasEnMazo(listaMazo);
    while (listaMazo)
    {
        flag = 1;
        fflush(stdin); ///
        promedioValor = promedioValor + listaMazo->dato.Valor;
        if (strcmp(listaMazo->dato.Color, "1") == 0)
            cantColor[0]++;
        else if (strcmp(listaMazo->dato.Color, "2") == 0)
            cantColor[1]++;
        else if (strcmp(listaMazo->dato.Color, "3") == 0)
            cantColor[2]++;
        else if (strcmp(listaMazo->dato.Color, "4") == 0)
            cantColor[3]++;
        else if (strcmp(listaMazo->dato.Color, "5") == 0)
            cantColor[4]++;

        if (strcmp(listaMazo->dato.Tipo, "1") == 0)
            cantTipo[0]++;
        else if (strcmp(listaMazo->dato.Tipo, "2") == 0)
            cantTipo[1]++;
        else if (strcmp(listaMazo->dato.Tipo, "3") == 0)
            cantTipo[2]++;
        else if (strcmp(listaMazo->dato.Tipo, "4") == 0)
            cantTipo[3]++;
        else if (strcmp(listaMazo->dato.Tipo, "5") == 0)
            cantTipo[4]++;
        else if (strcmp(listaMazo->dato.Tipo, "6") == 0)
            cantTipo[5]++;

        if (listaMazo->dato.Rareza == 1)
            cantRareza[0]++;
        else if (listaMazo->dato.Rareza == 2)
            cantRareza[1]++;
        else if (listaMazo->dato.Rareza == 3)
            cantRareza[2]++;
        else if (listaMazo->dato.Rareza == 4)
            cantRareza[3]++;

        listaMazo = listaMazo->sig;
    }
    if(flag == 1) /// flag simplificado
    {
        promedioValor = promedioValor / cantCartas;
        int indiceColor = encontrarMasRepetido(cantColor, 5);
        int indiceRareza = encontrarMasRepetido(cantRareza, 4);
        int indiceTipo = encontrarMasRepetido(cantTipo, 6);
        verEstadisticas(indiceColor, indiceTipo, indiceRareza, promedioValor);
    }

}
void verEstadisticas(int cantColor, int cantTipo,int cantRareza, float promedio)
{
    printf("Atributos mas repetidos en la coleccion:\n");
    switch(cantColor)
    {
    case 0:
        printf("Blanco");
        break;
    case 1:
        printf("Rojo");
        break;
    case 2:
        printf("Azul");
        break;
    case 3:
        printf("Verde");
        break;
    case 4:
        printf("Negro");
        break;
    }

    printf("\n");
    switch(cantTipo)
    {
    case 0:
        printf("Criatura");
        break;
    case 1:
        printf("Hechizo");
        break;
    case 2:
        printf("Encantamiento");
        break;
    case 3:
        printf("Tierra");
        break;
    case 4:
        printf("Artefacto");
        break;
    case 5:
        printf("Instantaneo");
        break;
    }

    printf("\n");
    switch(cantRareza)
    {
    case 0:
        printf("Comun");
        break;
    case 1:
        printf("Poco comun");
        break;
    case 2:
        printf("Rara");
        break;
    case 3:
        printf("Mitica");
        break;
    }
    printf("\nPromedio del valor de las cartas: %f\n",promedio);

}
