#include "generala.h"

//Funcion Principal
int main()
{
    int cantidad_jugadores;
    printf("¡Bienvenido al Juego de Generala!\n");
    printf("Diseñado por Oliver Kochmann y Gustavo Aquino\n");
    
    /* entrada de jugadores */
    printf("Ingrese la cantidad de jugadores para el juego de generala: ");
    scanf("%d", &cantidad_jugadores);

    while (cantidad_jugadores < 1) {
        printf("Debe ser mayor a 1. Ingrese de nuevo: ");
        scanf("%d", &cantidad_jugadores);
    }

    Jugador jugadores[cantidad_jugadores];
    char nombre[20];
    int maquina;
    int contador_maquinas = 0;

    for (int i = 0; i < cantidad_jugadores; i++) {
        printf("\nJugador %d\n", i + 1);
        printf("Ingrese 1 si este jugador es una maquina, sino 0: ");
        scanf("%d", &maquina);

        getchar();

        if (maquina) { // si es una maquina, le asignamos de nombre maquina y un numero
            contador_maquinas++;
            sprintf(nombre, "Maquina %d", contador_maquinas);
        }
        else { // sino, le pedimos al usuario el nombre del jugador
            printf("Ingrese el nombre del jugador: ");
            fgets(nombre, 20, stdin);

            // Eliminar el carácter de nueva línea si está presente
            size_t len = strlen(nombre);
            if (len > 0 && nombre[len - 1] == '\n') {
                nombre[len - 1] = '\0';
            }
        }

        jugadores[i] = crearJugador(nombre, maquina);

    }

    gameLoop(jugadores, cantidad_jugadores);

    return 0;
}

