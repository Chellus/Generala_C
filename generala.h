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
int checkNum(int* arr, int x, int y);
int checkEscalera(int* arr, int x);
int checkFull(int* arr, int x);
int checkPoker(int* arr, int x);
int checkGenerala(int* arr, int x);
int checkGeneralaDoble(int* arr, int x, int y);
void tablaPuntajes(int* arr, int* jugadas_disponibles);
