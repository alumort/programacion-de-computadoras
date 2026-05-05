#include <stdio.h>
#include <stdlib.h>


int leerEntero();


int main()
{
    int numUno, numDos, numTres, numCuatro, suma;
    float promedio;
    printf("Ingrese el primer numero.\n");
    numUno = leerEntero();
    printf("Ingrese el segundo numero.\n");
    numDos = leerEntero();
    printf("Ingrese el tercer numero.\n");
    numTres = leerEntero();
    printf("Ingrese el cuarto numero.\n");
    numCuatro = leerEntero();
    suma = numUno + numDos + numTres + numCuatro;
    promedio= suma / 4;
    printf("La suma de los numeros %d, %d, %d y %d es de %d\n", numUno, numDos, numTres, numCuatro, suma);
    printf("El promedio de los numeros es %.2f", promedio);
    return 0;
}

int leerEntero() {
int x;
int resultado;

    while (1) {
        resultado = scanf("%d", &x);

        if (resultado == 1) {
            return x;
            while (getchar() != '\n');
        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }}
