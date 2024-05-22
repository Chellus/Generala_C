#include "generala.h"

//Funcion Principal
int main()
{
    int dado[5];
    printf("¡Bienvenido al Juego de Generala!\n");
    printf("Diseñado por Oliver Kochmann y Gustavo Aquino\n");
    int prueba[5] = {1,1,1,1,1};
    int posicacambiar[5] = {1,1,1,1,1};
    int jugadasDispo[11] = {0};
    tirarDados(dado);
    for (int cuentajugadas = 0; cuentajugadas<3;cuentajugadas++)
    {
        chequeoJugadas(dado,jugadasDispo);
        consultaCambio(posicacambiar);
        cambioDados(dado, posicacambiar);
    }
    
    return 0;
}

