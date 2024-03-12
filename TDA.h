#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED
#define TOPE_DE_MAZO 70
#include "carta.h"

coleccion * inicColeccion ();
coleccion * crearNodoColeccion(cartaMTG);
coleccion * agregarCarta (coleccion*);
coleccion * agregarAlFinal(coleccion*,coleccion*);
coleccion * buscarUltimo(coleccion*);
coleccion * cargarVariasCartas(coleccion*);
coleccion * borrarCarta();
coleccion * ordenarMazo(coleccion*);
coleccion * agregarEnOrden(coleccion *,coleccion *);

#endif // TDA_H_INCLUDED
