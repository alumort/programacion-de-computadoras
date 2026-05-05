#include <stdio.h>
#include <stdlib.h>

float leerFloat();

int main()
{
    float notaUno, notaDos, notaTres, promedio;

    printf("Ingrese la primera nota del alumno.\n");
    notaUno = leerFloat();
    printf("Ingrese la segunda nota del alumno.\n");
    notaDos = leerFloat();
    printf("Ingrese la tercera nota del alumno.\n");
    notaTres = leerFloat();

    promedio = (notaUno + notaDos + notaTres) / 3;
    printf("Con las notas %.2f, %.2f y %.2f el promedio es %.2f\n", notaUno, notaDos, notaTres, promedio);
    if (promedio >= 7) {
        printf("Alumno promocionado!");
    } else {
    printf("No promociona...\n");
    }
    return 0;
}
float leerFloat() {
float x;
float resultado;

    while (1) {
        resultado = scanf("%f", &x);

        if (resultado == 1) {
            return x;
            while (getchar() != '\n');
        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }}
