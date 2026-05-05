#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz(int mat[3][4]);
void imprimirMatriz(int mat[3][4]);
void imprimirPrimerFila(int mat[3][4]);
void imprimirUltimaFila(int mat[3][4]);
void imprimirPrimerColumna(int mat[3][4]);
int main()
{
    int matriz[3][4];
    cargarMatriz(matriz);
    imprimirMatriz(matriz);
    printf("\n");
    printf("Primera Fila:\n");
    imprimirPrimerFila(matriz);
        printf("\n");
    printf("Ultima Fila:\n");
    imprimirUltimaFila(matriz);
        printf("\n");
    printf("Primera Columna:\n");
    imprimirPrimerColumna(matriz);
    return 0;
}
void cargarMatriz(int mat[3][4]) {
    for (int f = 0; f < 3; f++) {
    for(int c = 0; c < 5; c++) {
        mat[f][c] = 1 + rand() % (100-1+1);
    }
}
}
void imprimirMatriz(int mat[3][4]) {
for(int f = 0; f < 3; f++) {
    for (int c = 0; c <4; c++) {
            printf(" %d ", mat[f][c]);

    }
}

}

void imprimirPrimerFila(int mat[3][4]) {
for(int f = 0; f < 3; f++) {
    for (int c = 0; c <4; c++) {
            if(f == 0) {
                            printf(" %d ", mat[f][c]);
            }


    }
}

}

void imprimirUltimaFila(int mat[3][4]) {
for(int f = 0; f < 3; f++) {
    for (int c = 0; c <4; c++) {
            if(f == 2) {
                            printf(" %d ", mat[f][c]);
            }


    }
}

}

void imprimirPrimerColumna(int mat[3][4]) {
for(int f = 0; f < 3; f++) {
    for (int c = 0; c <4; c++) {
            if(c == 1) {
                            printf(" %d ", mat[f][c]);
            }


    }
}

}
