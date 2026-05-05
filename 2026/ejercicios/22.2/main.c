#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void cargarMatriz(int mat[4][4]);
void imprimirMatriz(int mat[4][4]);
void imprimirDMatriz(int mat[4][4]);

int main()
{
    srand(time(NULL));
    int matriz[4][4];
    cargarMatriz(matriz);
    imprimirMatriz(matriz);
    printf("Elementos de la diagonal principal: \n");
    imprimirDMatriz(matriz);
    return 0;
}

void cargarMatriz(int mat[4][4]) {
    for (int f = 0; f < 3; f++) {
    for(int c = 0; c < 5; c++) {
        mat[f][c] = 1 + rand() % (100-1+1);
    }
}
}
void imprimirMatriz(int mat[4][4]) {
for(int f = 0; f < 4; f++) {
    for (int c = 0; c <4; c++) {
            printf(" %d ", mat[f][c]);

    }
}

}


void imprimirDMatriz(int mat[4][4]) {
for(int f = 0; f < 4; f++) {
    for (int c = 0; c <4; c++) {
        if(f == c) {
            printf(" %d ", mat[f][c]);
        }
    }
}

}
