#ifndef CARTA_H_INCLUDED
#define CARTA_H_INCLUDED

typedef struct
{
    char Nombre [20];
    char Expansion [20];
    char Color [20]; // 0 blanco, rojo, azul, verde, negro
    char Tipo [20]; // 0 criatura, hechizo, encantamiento, tierra, artefacto, instantaneo 5
    int Rareza; // 0 Comun, 1 Poco Común, 2 Rara, 3 Mítica
    float Valor;

} cartaMTG;
typedef struct{
    struct coleccion * sig;
    struct coleccion * ante;
    cartaMTG dato;
} coleccion;

cartaMTG cargarCarta();
void mostrarCarta(cartaMTG);
void mostrarMazo(coleccion*,int);
void preguntaCartaBuscar(char *);
void generarEstadisticas(coleccion*);
void verEstadisticas(int,int,int,float);
float cuentaCartasEnMazo(coleccion*);
#endif // CARTA_H_INCLUDED
