#include "generala.h"

void imprimirArreglo(int* arr, int size)
{
    for (int i = 0; i < size; i++){
        printf("a[%d]: %d\n",i, arr[i]);
    }
}

void tirarDados(Jugador* jugador)
{
    int i;
    printf("Presione Enter para tirar los dados ");
    getchar();
    srand(time(0));
    
    jugador->servida = true;

    for (i = 0; i < 5; i++) {
        jugador->dados[i] = rand() % 6 + 1;
        printf (" Dado %d : %d\n ", i+1, jugador->dados[i]);
    }
}

void imprimirDados(Jugador* jugador)
{
    printf("Dados: ");
    
    for (int i = 0; i < 4; i++) {
        printf("%d - ", jugador->dados[i]);
    }
    printf("%d\n", jugador->dados[4]);

}

void imprimirPuntajeDados(Jugador* jugador)
{
    if (jugador == NULL) {
        printf("Error: jugador es nulo\n");
        return;
    }

    int* puntos = chequeoJugadas(jugador);

    if (puntos == NULL) {
        printf("Error: puntos es nulo\n");
        return;
    }

    printf("Puntajes de %s con dados actuales\n", jugador->nombre);

    const char* estados[] = { "ABIERTA", "CERRADA" };
    const char* categorias[] = { "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Escalera", "Full", "Poker", "Generala", "Generala Doble" };

    for (int i = 0; i < 11; i++) {
        printf("%s(%s): %d\n", categorias[i], estados[jugador->categorias[i][1]], puntos[i]);
    }
}

bool consultaCambio(Jugador* jugador)
{
    int cambiar;
    printf("¿Desea cambiar algún dado? (1 para sí, 0 para no): ");
    scanf("%d", &cambiar);
    
    if (cambiar) {
        jugador->servida = false;
        int contador_cambios = 0;
        int consult;
        for (int i = 0; i < 5; i++) {
            printf("Desea cambiar el dado %d? (1 para sí, 0 para no): ", i+1);
            scanf("%d",&consult);
            
            switch(consult) {
                case 0:
                    break;
                case 1:
                    jugador->dados[i] = rand() % 6 + 1;
                    contador_cambios++;
                    break;
                default:
                    printf("Número inválido. Ingrese un 1 para sí o un 0 para no.\n");
                    i = i-1;
                    break;
            }
        }

        // si se cambiaron todos los dados, puede ser una jugada servida
        if (contador_cambios == 5)
            jugador->servida = true;

        return true;
    }

    return false;
}

Jugador crearJugador(const char* nombre, bool maquina) {
    Jugador jugador;
    
    // Copiar el nombre al campo nombre de la estructura
    strncpy(jugador.nombre, nombre, sizeof(jugador.nombre) - 1);
    jugador.nombre[sizeof(jugador.nombre) - 1] = '\0';  // Asegurar la terminación nula

    jugador.maquina = maquina;
    jugador.servida = false;
    jugador.ganador = false;

    // Inicializar los dados a 0
    for (int i = 0; i < 5; i++) {
        jugador.dados[i] = 0;
    }

    // Inicializar las categorías a 0
    for (int i = 0; i < 11; i++) {
        jugador.categorias[i][0] = 0;
        jugador.categorias[i][1] = 0;
    }

    jugador.puntaje = 0;

    return jugador;
}

void elegirCategoria(Jugador* jugador)
{
    int opcion;
    int* puntos = chequeoJugadas(jugador);

    printf("\tELIJA UNA CATEGORIA ABIERTA\n");
    printf("1. Uno: %s\n", jugador->categorias[0][1] ? "CERRADA" : "ABIERTA");
    printf("2. Dos: %s\n", jugador->categorias[1][1] ? "CERRADA" : "ABIERTA");
    printf("3. Tres: %s\n", jugador->categorias[2][1] ? "CERRADA" : "ABIERTA");
    printf("4. Cuatro: %s\n", jugador->categorias[3][1] ? "CERRADA" : "ABIERTA");
    printf("5. Cinco: %s\n", jugador->categorias[4][1] ? "CERRADA" : "ABIERTA");
    printf("6. Seis(: %s\n", jugador->categorias[5][1] ? "CERRADA" : "ABIERTA");
    printf("7. Escalera: %s\n", jugador->categorias[6][1] ? "CERRADA" : "ABIERTA");
    printf("8. Full: %s\n", jugador->categorias[7][1] ? "CERRADA" : "ABIERTA");
    printf("9. Poker: %s\n", jugador->categorias[8][1] ? "CERRADA" : "ABIERTA");
    printf("10. Generala: %s\n", jugador->categorias[9][1] ? "CERRADA" : "ABIERTA");
    printf("11. Generala Doble: %s\n", jugador->categorias[10][1] ? "CERRADA" : "ABIERTA");

    printf("Elija su opcion: ");
    scanf("%d", &opcion);

    while (opcion < 1 || opcion > 11 || jugador->categorias[opcion - 1][1]) {
        printf("Opcion invalida. Elija otra: ");
        scanf("%d", &opcion);
    }
    printf("\nPuntaje en la categoria elegida: %d\n", puntos[opcion - 1]);
    jugador->categorias[opcion - 1][0] = puntos[opcion - 1];
    jugador->categorias[opcion - 1][1] = 1;

}

// Funciones referentes a la verificacion de las jugadas
int checkNum(Jugador* jugador, int dado)
{
    int cont = 0;
    for (int i = 0; i<5; i++) {
        if (jugador->dados[i] == dado) {
            cont++;
        }
        
    }
    return cont * dado;
}

int checkEscalera(Jugador* jugador)
{
	int contador[6] = {0};
    int* dados = jugador->dados;

	for (int i = 0; i < 5; i++) {
		contador[dados[i] - 1]++;
	}

	if ((contador[0] >= 1 && contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1) ||
		(contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1 && contador[5] >= 1)) {
		return 1;
	}
		return 0;
    
}

int checkFull(Jugador* jugador)
{
	int contador[6] = {0};
	bool tresIguales = false;
	bool dosIguales = false;

	for (int i = 0; i < 5; i++) {
		contador[jugador->dados[i] - 1]++;
	}


	for (int i = 0; i < 6; i++) {
		if (contador[i] == 3)
			tresIguales = true;
		else if (contador[i] == 2)
			dosIguales = true;
		
	}

	if (tresIguales && dosIguales)
        return 1;
    return 0;
}


int checkPoker(Jugador* jugador)
{
	int contador[6] = {0};

	for (int i = 0; i < 5; i++) {
		contador[jugador->dados[i] - 1]++;
	}

	for (int i = 0; i < 6; i++) {
		if (contador[i] == 4 || contador[i] ==5)
			return 1;
	}
	return 0;
}

int checkGenerala(Jugador* jugador)
{
    int* dados = jugador->dados;

    if (dados[0] == dados[1] == dados[2] == dados[3] == dados[4])
        return 1;
    else
        return 0;
}

int checkGeneralaDoble(Jugador* jugador)
{
    bool segunda_generala = jugador->categorias[9][1];
    
    if (checkGenerala(jugador) && segunda_generala)
        return 1;
    return 0;
    
}

int* chequeoJugadas(Jugador* jugador)
{
    int suma_uno = checkNum(jugador, 1);
    int suma_dos = checkNum(jugador, 2);
    int suma_tres = checkNum(jugador, 3);
    int suma_cuatro = checkNum(jugador, 4);
    int suma_cinco = checkNum(jugador, 5);
    int suma_seis = checkNum(jugador, 6);

    /* estas variables solo pueden ser 1 o 0 */
    int escalera = checkEscalera(jugador);
    int full = checkFull(jugador);
    int poker = checkPoker(jugador);
    int generala = checkGenerala(jugador);
    int generala_doble = checkGeneralaDoble(jugador);

    /* calculamos la tabla de puntajes del jugador con estos dados */
    int categorias[] = {suma_uno, suma_dos, suma_tres, suma_cuatro, suma_cinco, suma_seis, escalera * 20, full * 30,
                        poker * 40, generala * 50, generala_doble * 100};

    int* p_categorias = (int*)malloc(11 * sizeof(int));

    for (int i = 0; i < 11; i++) {
        p_categorias[i] = categorias[i];
    }

    if (jugador->servida) {
        p_categorias[6] = escalera * 25;
        p_categorias[7] = escalera * 35;
        p_categorias[8] = escalera * 45;
    }

    /* verificamos si hay un generala servida */
    if (generala == 1 && jugador->servida) {
        printf("\n\tGENERALA SERVIDA DEL JUGADOR %s\n", jugador->nombre);
        jugador->ganador = true;
    }

    return p_categorias;
}

void imprimirCategorias(Jugador* jugador)
{
    printf("Tabla de Puntajes de %s\n", jugador->nombre);
    printf("| Categorías |\t Puntos |\n");
    printf("|     Uno    |\t %d |\n", jugador->categorias[0][0]);
    printf("|     Dos    |\t %d |\n", jugador->categorias[1][0]);
    printf("|    Tres    |\t %d |\n", jugador->categorias[2][0]);
    printf("|    Cuatro  |\t %d |\n", jugador->categorias[3][0]);
    printf("|    Cinco   |\t %d |\n", jugador->categorias[4][0]);
    printf("|    Seis    |\t %d |\n", jugador->categorias[5][0]);
    printf("|   Escalera |\t %d |\n", jugador->categorias[6][0]);
    printf("|    Full    |\t %d |\n", jugador->categorias[7][0]);
    printf("|    Poker   |\t %d |\n", jugador->categorias[8][0]);
    printf("|   Generala |\t %d |\n", jugador->categorias[9][0]);
    printf("| GeneralaDob|\t %d |\n", jugador->categorias[10][0]);

}

void gameLoop(Jugador jugadores[], int num_jugadores)
{
    bool ganador = false;
    int indice_ganador;
    bool fin_turno;

    /* cada jugador tiene un maximo de 11 tiradas en el juego */
    for (int i = 0; i < 11; i++) {
        /* cada jugador realiza su turno */
        for (int j = 0; j < num_jugadores; j++) {
            /* si el jugador es humano, juega su turno */
            if (!jugadores[i].maquina) {
                /* tiene 3 tiradas posibles */
                printf("\n\tTurno de %s\n", jugadores[j].nombre);
                tirarDados(&jugadores[j]);
                fin_turno = false;
                for (int k = 0; k < 3; k++) {
                    imprimirDados(&jugadores[j]);
                    imprimirPuntajeDados(&jugadores[j]);

                    /* si no quiere realizar ningun cambio, se quiere quedar con esta jugada */
                    if (!consultaCambio(&jugadores[j])) {
                        elegirCategoria(&jugadores[j]);
                        fin_turno = true;
                        break;
                    }
                }

                if (!fin_turno) {
                    imprimirDados(&jugadores[j]);
                    imprimirPuntajeDados(&jugadores[j]);
                    elegirCategoria(&jugadores[j]);
                }
                imprimirCategorias(&jugadores[j]);
            }

            if (jugadores[j].ganador) {
                ganador = true;
                indice_ganador = j;
                break;
            }
        }
        if (ganador)
            break;
    }
}