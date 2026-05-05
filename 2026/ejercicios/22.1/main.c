#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargar( int matriz[3][5]);
void imprimir(int matriz[3][5]);
int main()
{
    srand(time(NULL));
    int matriz[3][5];
    cargar(matriz);
    imprimir(matriz);
    return 0;
}
void cargar(int matriz[3][5]) {
for (int f = 0; f < 3; f++) {
    for(int c = 0; c < 5; c++) {
        matriz[f][c] = 1 + rand() % (100-1+1);
    }
}
}

void imprimir(int matriz[3][5]) {
for (int f = 0; f < 3; f++) {
    for(int c = 0; c < 5; c++) {
        printf("%d\n", matriz[f][c]);
    }
}
}

