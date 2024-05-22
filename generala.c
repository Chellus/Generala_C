#include "generala.h"

void imprimirArreglo(int* arr)
{
    for (int i = 0; i<6; i++){
        printf("a[%d]: %d\n",i, arr[i]);
    }
}

void tirarDados(int *arr)
{
    int i;
    printf("Presione Enter para tirar los dados ");
    getchar();
    srand(time(0));
    
    for (i = 0; i<5; i++) {
        arr[i] = rand() % 6 + 1;;
        printf (" Dado %d : %d\n ", i+1, arr[i]);
    }
}

void consultaCambio(int* posiciones)
{
    int camb;
    printf("¿Desea cambiar algún dado? (0 para sí, 1 para no): ");
    scanf("%d", &camb);
    
    if (camb == 0) {
        int consult;
        for (int i = 0; i<5; i++) {
            printf("Desea cambiar el dado %d? (0 para sí, 1 para no): ", i+1);
            scanf("%d",&consult);
            printf("%d",consult);
            switch(consult) {
                case 0:
                    posiciones[i] = 0;
                    break;
                case 1:
                    posiciones[i] = 1;
                    break;
                default:
                printf("Número inválido. Ingrese un 0 para sí o un 1 para no.\n");
                i = i-1;
            }
            printf("\nPosicion %d : %d\n", i, posiciones[i]);
        }
    }
    else {
        for (int i = 0; i < 5; i++) {
            posiciones[i] = 1;
        }
    }
}

void cambioDados(int *dados, int *posiciones)
{
    for (int i = 0; i < 5; i++) {
        if (posiciones[i] == 0) {
            dados[i] = rand() % 6 + 1;
        }
        printf (" Dado %d : %d\n ", i+1, dados[i]);
    }
    
}
// Funciones referentes a la verificacion de las jugadas
int checkNum(int *arr,int x,int y)
{
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0) {
        int suma = 0;
        for (int i = 0; i<5; i++) {
            if (arr[i] == y) {
                suma+=1;
            }
        
        }
        return suma*y;
    }
}
    
int checkEsca(int *arr,int x)
{
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0){
	    int contador[6] = {0};
	    for (int i = 0; i < 5; i++) {
	    	contador[arr[i] - 1] = contador[arr[i] - 1] + 1;
	    }
	    if ((contador[0] >= 1 && contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1) ||
	    	(contador[1] >= 1 && contador[2] >= 1 && contador[3] >= 1 && contador[4] >= 1 && contador[5] >= 1)) {
	    	return true;
	    }
	    	return false;
    }
}

int checkFull(int *arr,int x) {
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0){
	int contador[6] = {0};
	for (int i = 0; i < 5; i++) {
		contador[arr[i] - 1]++;
	}
	bool tresIguales = false;
	bool dosIguales = false;
	for (int i = 0; i < 6; i++) {
		if (contador[i] == 3) {
			tresIguales = true;
		} else if (contador[i] == 2) {
			dosIguales = true;
		}
	}
	return tresIguales && dosIguales;
}
}

int checkPoker(int *arr,int x) {
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0){
	int contador[6] = {0};
	for (int i = 0; i < 5; i++) {
		contador[arr[i] - 1]++;
	}
	for (int i = 0; i < 6; i++) {
		if (contador[i] == 4 || contador[i] ==5) {
			return true;
		}
	}
	return false;
}
}
int checkGenerala(int *arr,int x)
{
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0){
        if (arr[0] == arr[1] == arr[2] == arr[3] == arr[4]){
            return true;
        }
        else{
            return false;
        }
    }
}

int checkGeneralaDoble(int *arr,int x, int y)
{
    int a = 2;
    if (x==1) {
        return a;
    }
    else if(x==0){
        if (arr[0] == arr[1] == arr[2] == arr[3] == arr[4] && y==2) {
            return true;
        }
        else{
            return false;
        }
    }
}

void tablaPuntajes(int *arr, int *jugadasDispo)
{
    int sumauno = checkNum(arr,jugadasDispo[0],1);
    int sumados = checkNum(arr,jugadasDispo[1],2);
    int sumatres = checkNum(arr,jugadasDispo[2],3);
    int sumacuatro= checkNum(arr,jugadasDispo[3],4);
    int sumacinco= checkNum(arr,jugadasDispo[4],5);
    int sumaseis= checkNum(arr,jugadasDispo[5],6);
    int escalera= checkEscalera(arr,jugadasDispo[6]);
    int full= checkFull(arr,jugadasDispo[7]);
    int poker= checkPoker(arr,jugadasDispo[8]);
    int generala= checkGenerala(arr,jugadasDispo[9]);
    int generaladoble= checkGeneralaDoble(arr,jugadasDispo[10],generala);
    printf("_Tabla de Puntajes_\n");
    printf("| Categorías |\t Jugador 1 |\t Jugador 2 |\n");
    printf("|     Uno    |\t %d |\t %d |\n", sumauno, 0);
    printf("|     Dos    |\t %d |\t %d |\n", sumados, 0);
    printf("|    Tres    |\t %d |\t %d |\n", sumatres, 0);
    printf("|    Cuatro  |\t %d |\t %d |\n", sumacuatro, 0);
    printf("|    Cinco   |\t %d |\t %d |\n", sumacinco, 0);
    printf("|    Seis    |\t %d |\t %d |\n", sumaseis, 0);
    printf("|   Escalera |\t %d |\t %d |\n", escalera, 0);
    printf("|    Full    |\t %d |\t %d |\n", full, 0);
    printf("|    Poker   |\t %d |\t %d |\n", poker, 0);
    printf("|   Generala |\t %d |\t %d |\n", generala, 0);
    printf("| GeneralaDob|\t %d |\t %d |\n", generaladoble, 0);
    
}