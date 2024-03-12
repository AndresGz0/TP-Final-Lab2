#include "FuncionesAux.h"
#include <stdio.h>

void sobreescribirArchivo(coleccion * listaMazo)
{
    coleccion * seg = listaMazo;
    FILE * archivo = fopen("colecciones.dat","wb");
    if(archivo)
    {
        while(seg)
        {
            fwrite(&seg->dato,sizeof(cartaMTG),1,archivo);
            seg = seg->sig;
        }

        fclose(archivo);
    }
    else
        printf("Ocurrio un error en la sobreescritura del archivo.\n");
}
void opcionesMenu()
{
    printf("Que accion desea realizar?\n");
    printf("0- Ver informacion para ingreso de cartas\n");
        printf("1- Cargar cartas en mazo\n");
        printf("2- Mostrar mazo\n");
        printf("3- Borrar una carta del mazo\n");
        printf("4- Ordenar el mazo por valor\n");
        printf("5- Ver estadisticas generales del mazo\n");
        printf("6- Guardar archivo\n");
        printf("7- Operaciones con varios mazos (EC)\n");
        printf("8- Operaciones con pilas\n"); ///
        printf("9- Operaciones con arboles\n"); ///
        printf("10- Buscar una carta en el mazo\n");
        printf(" --> ");
}
void leerArchivo(coleccion ** mazo,char * nombreArchivo)
{
    FILE * archivo = fopen(nombreArchivo,"rb");
    if(archivo)
    {
        cartaMTG aux;

        while(fread(&aux,sizeof(cartaMTG),1,archivo)==1)
        {
            coleccion * nuevaCarta = crearNodoColeccion(aux);
            (*mazo) = agregarAlFinal((*mazo),nuevaCarta);
        }
    }
    else
        printf("El archivo no existe.\n");
}
char preguntaContinuar()
{
    char c;

    printf("Desea continuar? (s/n) -> ");
    fflush(stdin);
    scanf("%c",&c);

    return c;
}
int encontrarMasRepetido(int arreglo[], int val)
{
    int dato = 0;  // Inicializa dato con el primer índice
    for (int i = 1; i < val; i++)
    {
        if (arreglo[dato] < arreglo[i])
            dato = i;
    }
    return dato;
}

int verificaDatosRepetidos(coleccion * listaMazo,cartaMTG carta)
{
    int repetido = 0;

    if(listaMazo)
    {
        if(carta.Valor == listaMazo->dato.Valor)
            repetido = 1;
        else if (strcmpi(carta.Nombre,listaMazo->dato.Nombre) == 0)
            repetido = 1;
        else
            repetido = verificaDatosRepetidos(listaMazo->sig,carta);
    }
    return repetido;
}
void informacionAlUsuario()
{
    printf("\nLos atributos de las cartas estan representados por valores enteros\nque parten desde el 0. Los atributos son:\n");
    printf("Colores:\n- -0: Blanco\n -1: Rojo\n -2: Azul\n -3 Verde\n -4 Negro\n");
    printf("Tipo:\n -0 Critura\n -1 Hechizo\n -2 Encantamiento\n -3 Tierra\n -4 Artefacto\n -5 Instantaneo\n");
    printf("Rareza:\n -0 Comun\n -1 Poco Comun\n -3 Rara\n -4 Mitica\n\n");
}
