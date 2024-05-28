#include "maquina1.h"

int evaluarMejorCategoria(Jugador* jugador)
{
    /* arreglo de 11 elementos
    Posiciones de jugadas mayores:
    6 = escalera, 7 = full, 8 = poker, 9 = generala, 10 = generala doble
    */
    int* puntos = chequeoJugadas(jugador);

    /* revisamos si obtuvimos un juego mayor y si se encuentra abierto */
    // escalera
    if (puntos[6] > 0 && jugador->categorias[6][1] == 0)
        return 6;
    // full
    if (puntos[7] > 0 && jugador->categorias[7][1] == 0)
        return 7;
    // poker
    if (puntos[8] > 0 && jugador->categorias[8][1] == 0)
        return 8;
    // generala
    if (puntos[9] > 0 && jugador->categorias[9][1] == 0)
        return 9;
    
    /* si no conseguimos un juego mayor, seguimos */
    return 0;
}

void elegirCategoriaMaquina(Jugador* jugador, int categoria)
{
    int* puntos = chequeoJugadas(jugador);

    // si recibimos un juego mayor
    if (categoria != 0) {
        jugador->categorias[categoria][0] = puntos[categoria];
        jugador->categorias[categoria][1] = 1;
        return;
    }

    /*
        Si recibimos 0, significa que no conseguimos un juego mayor o ya estan todos cerrados.
        Si es este el caso, debemos elegir la categoria normal que mas puntos nos de y que siga
        abierta. Para esto crearemos una matriz de 6 filas y 2 columnas.
        La fila representa el puntaje en esa categoria. La columna representa la posicion original
        de esa fila, ya que ordenaremos las filas de acuerdo al puntaje obtenido
    */
    int puntos_menores[6][2];
    int aux_f;
    int aux_c;
    // cargamos la matriz
    for (int i = 0; i < 6; i++) {
        puntos_menores[i][0] = puntos[i];
        puntos_menores[i][1] = i;
    }

    // ordenamos las filas de acuerdo a la primera columna
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            if (puntos_menores[j][0] < puntos_menores[j + 1][0]) {
                aux_f = puntos_menores[j][0];
                aux_c = puntos_menores[j][1];
                puntos_menores[j][0] = puntos_menores[j + 1][0];
                puntos_menores[j][1] = puntos_menores[j + 1][1];
                puntos_menores[j + 1][0] = aux_f;
                puntos_menores[j + 1][1] = aux_c;
            }
        }
    }

    // recorremos las filas de la matriz
    for (int i = 0; i < 6; i++) {
        // si la categoria esta abierta, almacenamos ahi y retornamos
        int pos = puntos_menores[i][1];
        if (jugador->categorias[pos][1] == 0) {
            jugador->categorias[pos][0] = puntos_menores[i][0];
            jugador->categorias[pos][1] = 1;
            return;
        }
    }

}