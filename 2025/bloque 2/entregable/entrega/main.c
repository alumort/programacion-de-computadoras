#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANIO 5

//Crear un programa con funciones y procedimientos para trabajar con arreglos.
//El mismo programa tiene que permitir hacer lo siguiente sobre arreglos:
//Contar pares X
//Promedio de impares X
//Contar cantidad de numeros superiores a un argumento X
//Comparar dos arreglos X
//Buscar repetidos entre dos arreglos X
//Asignar aleatorios al arreglo, los aleatorios deben ser impares  de 3 cifras, o pares de dos. X

int contarPares (int contar[TAMANIO]);
int promedioImpares (int contar[TAMANIO]);
int contarMayores (int contar[TAMANIO], int argumento);
int comparacion (int contar[TAMANIO], int contarDos[TAMANIO]);
void asignarAleatorios (int contar[TAMANIO]);
int main()
{
    srand(time(0));

    int contar[TAMANIO], contarDos[TAMANIO];
    int i, repetidos;
    asignarAleatorios(contar);
    asignarAleatorios(contarDos);
    contarPares(contar);
    promedioImpares(contar);
    contarMayores(contar, 400);
    repetidos = comparacion(contar, contarDos);
    getchar();

    return 0;
}

int contarPares (int contar[TAMANIO]) {
    int pares, i;
    pares = 0;
    for (i = 0; i <TAMANIO; i++) {
        if (contar[i] % 2 == 0) {
            pares++;
        }
    }
    printf("la cantidad de pares es: %i \n", pares);
}

int promedioImpares (int contar[TAMANIO]) {
    float contImpares, acumImpares, promedioImpares;
    int i;
    contImpares = 0;
    acumImpares = 0;
    for (i = 0; i <TAMANIO; i++) {
        if (contar[i] % 2 == 1) {
            contImpares++;
            acumImpares = acumImpares + contar[i];
        }
    }
    promedioImpares = acumImpares/contImpares;
    printf("el promedio de los impares es: %f \n", promedioImpares);

}

int contarMayores (int contar[TAMANIO], int argumento) {
    int i, mayores;
    mayores = 0;
    for (i = 0; i <TAMANIO; i++) {
        if (contar[i] > argumento) {
            mayores++;
        }
    }
    printf("numeros mayores al argumento: %i \n", mayores);
    return mayores;

}

int comparacion(int contar[TAMANIO], int contarDos[TAMANIO]) {
    int i, j, repetidos = 0;
    for (i = 0; i < TAMANIO; i++) {
        for (j = 0; j < TAMANIO; j++) {
            if (contar[i] == contarDos[j]) {
                repetidos++;
            }
        }
    }
    printf("los repetidos son %i", repetidos);
    return repetidos;

}



void asignarAleatorios(int contar[TAMANIO]) {
    srand(time(0));
    for (int i = 0; i < TAMANIO; i++) {
        int aleatorio = rand() % 999 + 100;
        if (aleatorio % 2 == 0) {
            contar[i] = aleatorio;
        }
        if (aleatorio > 99 && aleatorio % 2  != 0) {
            contar[i] = aleatorio;
        }
    }
}


