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
    bool servida;
    bool ganador;
    int dados[5];
    int categorias[11][2];
    int puntaje;
} Jugador;

/* util */
void imprimirArreglo(int* arr, int size);
void ordenarArreglo(int arr[], int size);

/* funciones referentes a los dados */
void tirarDados(Jugador* jugador);
bool consultaCambio(Jugador* jugador);
void imprimirDados(Jugador* jugador);
void imprimirPuntajeDados(Jugador* jugador);

/* Funciones del jugador */
Jugador crearJugador(const char* nombre, bool maquina);
void imprimirCategorias(Jugador* jugador);
void elegirCategoria(Jugador* jugador);
void calcularPuntaje(Jugador* jugador);
bool consultaCambioMaquina(Jugador* jugador);

/* funciones para verificar jugadas */
int checkNum(Jugador* jugador, int dado);
int checkEscalera(Jugador* jugador);
int checkFull(Jugador* jugador);
int checkPoker(Jugador* jugador);
int checkGenerala(Jugador* jugador);
int checkGeneralaDoble(Jugador* jugador);
int* chequeoJugadas(Jugador* jugador);

/* funcion del juego principal*/
void gameLoop(Jugador jugadores[], int num_jugadores);

/*
def juegoMaquina():
    tirarDados()
    checkGenerala()
    consultarCambio()
    analizar cuantos dados tienen que cambiar para un juego mayor
    revisar si el juego mayor con menor cantidad de cambios necesarios sigue abierto
    si:
        tirar los dados necesarios para ese juego
    no:
        analizar el siguiente

*/