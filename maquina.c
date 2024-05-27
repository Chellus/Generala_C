#include "maquina.h"

int numCambiosEscalera(Jugador* jugador)
{
    if (checkEscalera(jugador) == 1)
        return 0;

    int contador[6] = {0}; // Contador para los números del 1 al 6

    // Contar las ocurrencias de cada número en los dados
    for (int i = 0; i < 5; i++) {
        contador[jugador->dados[i] - 1]++;
    }

    // Definir las dos posibles escaleras
    int escalera1[] = {1, 1, 1, 1, 1, 0}; // Para la escalera 1-5
    int escalera2[] = {0, 1, 1, 1, 1, 1}; // Para la escalera 2-6

    // Contar cuántos números de la escalera 1-5 están presentes
    int presentes1 = 0;
    for (int i = 0; i < 5; i++) {
        if (contador[i] > 0) {
            presentes1++;
        }
    }

    // Contar cuántos números de la escalera 2-6 están presentes
    int presentes2 = 0;
    for (int i = 1; i < 6; i++) {
        if (contador[i] > 0) {
            presentes2++;
        }
    }

    // Calcular cuántos números faltan para completar cada escalera
    int faltan1 = 5 - presentes1;
    int faltan2 = 5 - presentes2;

    // Devolver el menor número de dados que faltan para formar una escalera
    return faltan1 < faltan2 ? faltan1 : faltan2;
}

int numCambiosFull(Jugador* jugador)
{
    if (checkFull(jugador) == 1)
        return 0;

    int contador[6] = {0}; // Contador para los números del 1 al 6

    // Contar las ocurrencias de cada número en los dados
    for (int i = 0; i < 5; i++) {
        contador[jugador->dados[i] - 1]++;
    }

    /* guardamos el dado con mayor ocurrencias y el segundo con mayor ocurrencias
        *si ya hay al menos 3 dados del mismo numero, solo necesitamos dos 
        dados de otro numero
        *si no hay al menos 3 del mismo numero, necesitamos ajustar ambos grupos
        de dados
    
    */
    int maxTres = 0, maxDos = 0;
    for (int i = 0; i < 6; i++) {
        if (contador[i] > maxTres) {
            maxDos = maxTres;
            maxTres = contador[i];
        } else if (contador[i] > maxDos) {
            maxDos = contador[i];
        }
    }

    if (maxTres >= 3) {
        return 2 - maxDos;
    } else {
        return 5 - (maxTres + maxDos);
    }
}

int numCambiosPoker(Jugador* jugador) {
    int contador[6] = {0}; // Contador para los números del 1 al 6

    // Contar las ocurrencias de cada número en los dados
    for (int i = 0; i < 5; i++)
        contador[jugador->dados[i] - 1]++;
    
    int max = 0;

    for (int i = 0; i < 6; i++) {
        if (contador[i] > max) {
            max = contador[i];
        }
    }

    return abs(4 - max);
}

int numCambiosGenerala(Jugador* jugador) {
    int contador[6] = {0}; // Contador para los números del 1 al 6

    // Contar las ocurrencias de cada número en los dados
    for (int i = 0; i < 5; i++)
        contador[jugador->dados[i] - 1]++;
    
    int max = 0;

    for (int i = 0; i < 6; i++) {
        if (contador[i] > max) {
            max = contador[i];
        }
    }

    return abs(5 - max);
}