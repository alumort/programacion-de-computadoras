#include <stdio.h>
#include <stdlib.h>
//Confeccionar un programa que pida por teclado tres notas de un alumno, calcule el promedio e imprima alguno de estos mensajes:
//Si el promedio es >=7 mostrar "Promocionado".
//Si el promedio es >=4 y <7 mostrar "Regular".
//Si el promedio es <4 mostrar "Reprobado".
int leerEntero();

int main()
{
    int notaUno, notaDos, notaTres, promedio = 0;
    printf("Ingrese la primer nota.\n");
    notaUno = leerEntero();
    printf("Ingrese la segunda nota.\n");
    notaDos = leerEntero();
    printf("Ingrese la tercer nota.\n");
    notaTres = leerEntero();
    promedio = (notaUno + notaDos + notaTres) / 3;
    if(promedio >= 7) {
        printf("Promocionado!\n");
    } else if (promedio >= 4 && promedio <7) {
    printf("Regular...\n");}
    else {
        printf("Reprobado :C\n");
    }
    return 0;
}
int leerEntero() {
    int x;
    int resultado;

    while (1) {
        resultado = scanf("%d", &x);

        if (resultado == 1) {
            while (getchar() != '\n');
            return x;

        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }
}
