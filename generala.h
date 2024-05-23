#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/* estructura de jugador */
/*
    en la matriz categorias, las filas representan cada categoria
    La primera columna representa el puntaje en esa categoria.
    La segunda columna representa si la categoria esta abierta o cerrada.
*/
typedef struct Jugador {
    char nombre[20];
    bool maquina;
    int dados[5];
    int categorias[11][2];
} Jugador;

/* util */
void imprimirArreglo(int* arr);

/* funciones referentes a los dados */
void tirarDados(Jugador* jugador);
void consultaCambio(Jugador* jugador);

/* funciones para verificar jugadas */
int checkNum(Jugador* jugador, int dado);
bool checkEscalera(Jugador* jugador);
bool checkFull(Jugador* jugador);
bool checkPoker(Jugador* jugador);
bool checkGenerala(Jugador* jugador);
bool checkGeneralaDoble(Jugador* jugador);
int* chequeoJugadas(Jugador* jugador);
