#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    int vector[20];
    for (int i = 0; i<20; i++){
        vector[i] = 1 + rand() % (100-1+1);
        printf("%d\n", vector[i]);
        // variable = minimo + rand()% (maximo - minimo + 1);
    }
    int min = -50, max = -1;
    int i;

    printf("Numeros aleatorios negativos entre %d y %d:\n", min, max);
    for(i = 0; i < 5; i++) {
        // Fórmula: rand() % (rango) + desplazamiento
        int numero = rand() % (max - min + 1) + min;
        printf("%d\n", numero);
    }
    return 0;
}
