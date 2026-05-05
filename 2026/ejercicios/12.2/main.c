#include <stdio.h>
#include <stdlib.h>

int main()
{
    float promedio;
    float acum = 0;
    int contadorAltas = 0;
    int contadorBajas = 0;
    float vector[5];
    for (int i = 0; i <5; i++) {
        printf("Ingrese la altura de la persona %d:\n", i);
         if (scanf("%f", &vector[i]) != 1) {
            while (getchar() != '\n');
            vector[i] = -1;
    } acum = acum+ vector[i];
    }
    promedio = acum / 5;
    for (int i = 0; i < 5; i++) {
        if(vector[i] < promedio) {
            contadorBajas++;
        }
        if(vector[i]> promedio) {
            contadorAltas++;
        }
    }
    printf("El promedio de alturas es de %.2f\n", promedio);
    printf("La cantidad de personas mas bajas que el promedio es %d\n", contadorBajas);
    printf("La cantidad de personas mas altas que el promedio es %d\n", contadorAltas);
    return 0;
}
