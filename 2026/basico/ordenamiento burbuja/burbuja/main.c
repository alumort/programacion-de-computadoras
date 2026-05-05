#include <stdio.h>
#include <stdlib.h>

void ordenar(int vector[], int n) {
      int aux, ordenado;
      do {
               ordenado = 1;
    for (int i = 0; i < n - 1; i++) {
        if (vector[i] > vector[i + 1]) {
            aux = vector[i];
            vector[i] = vector[i+1];
            vector[i+1] = aux;
            ordenado = 0;
    }
    } }while(ordenado == 0);
}

void imprimir(int vector[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", vector[i]);
    }

}
int main()
{
    int n = 5;
    int vector[5] = {4, 10, 2, 15, 50};
    printf("Vector sin ordenar:\n");
    imprimir(vector, n);
    ordenar(vector, n);
    printf("Vector ordenado:\n");
    imprimir(vector, n);
    return 0;

    }
