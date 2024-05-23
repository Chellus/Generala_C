#include "generala.h"

void imprimirArreglo(int* arr)
{
    for (int i = 0; i<6; i++){
        printf("a[%d]: %d\n",i, arr[i]);
    }
}

void tirarDados(Jugador* jugador)
{
    int i;
    printf("Presione Enter para tirar los dados ");
    getchar();
    srand(time(0));
    
    for (i = 0; i < 5; i++) {
        jugador->dados[i] = rand() % 6 + 1;
        printf (" Dado %d : %d\n ", i+1, jugador->dados[i]);
    }
}

void consultaCambio(Jugador* jugador)
{
    int cambiar;
    printf("¿Desea cambiar algún dado? (1 para sí, 0 para no): ");
    scanf("%d", &cambiar);
    
    if (cambiar) {
        int consult;
        for (int i = 0; i < 5; i++) {
            printf("Desea cambiar el dado %d? (0 para sí, 1 para no): ", i+1);
            scanf("%d",&consult);
            
            switch(consult) {
                case 0:
                    jugador->dados[i] = rand() % 6 + 1;
                    break;
                case 1:
                    break;
                default:
                    printf("Número inválido. Ingrese un 0 para sí o un 1 para no.\n");
                    i = i-1;
                    break;
            }
        }
    }
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

int checkEsca(Jugador* jugador)
{
	int contador[6] = {0};
    int dados[5] = jugador->dados;

	for (int i = 0; i < 5; i++) {
		contador[dados[i] - 1] = contador[dados[i] - 1] + 1;
	}
	if ((contador[0] >= 1 && contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1) ||
		(contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1 && contador[5] >= 1)) {
		return true;
	}
		return false;
    
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

	return tresIguales && dosIguales;
}


bool checkPoker(Jugador* jugador)
{
	int contador[6] = {0};

	for (int i = 0; i < 5; i++) {
		contador[jugador->dados[i] - 1]++;
	}

	for (int i = 0; i < 6; i++) {
		if (contador[i] == 4 || contador[i] ==5)
			return true;
	}
	return false;
}

bool checkGenerala(Jugador* jugador)
{
    int dados[5] = jugador->dados;

    if (dados[0] == dados[1] == dados[2] == dados[3] == dados[4])
        return true;
    else
        return false;
}

bool checkGeneralaDoble(Jugador* jugador)
{
    bool segunda_generala = jugador->categorias[9][1];
    
    return checkGenerala(jugador) && segunda_generala;
    
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

    return categorias;
}