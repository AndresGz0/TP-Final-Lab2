#ifndef FUNCIONESAUX_H_INCLUDED
#define FUNCIONESAUX_H_INCLUDED
#include "carta.h"

void sobreescribirArchivo(coleccion*);
void leerArchivo(coleccion**,char*);
char preguntaContinuar();
int verificaDatosRepetidos(coleccion*,cartaMTG);
int encontrarMasRepetido(int[],int);
void opcionesMenu();
void informacionAlUsuario(); ///
#endif // FUNCIONESAUX_H_INCLUDED
