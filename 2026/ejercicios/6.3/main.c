#include <stdio.h>
#include <stdlib.h>
//Realizar un programa que solicite la carga por teclado de dos números, si el primero es mayor al segundo informar su suma
//y diferencia, en caso contrario informar el producto y la división del primero respecto al segundo.
int leerInt();

int main()
{
    int numUno, numDos, suma, diferencia;
    float producto, division;
    producto = 0;
    division = 0;
    suma = 0;
    diferencia = 0;

    printf("Ingrese primer numero.\n");
    numUno = leerInt();
    printf("Ingrese segundo numero.\n");
    numDos = leerInt();

    if(numUno > numDos) {
        suma = numUno + numDos;
        diferencia = numUno - numDos;
        printf("La suma de %d y %d es de %d\n", numUno, numDos, suma);
        printf("La resta de %d y %d es de %d\n", numUno, numDos, suma);
    } else {
        producto = numUno * numDos;
        division = numDos / numUno;
        printf("El producto de %d y %d es de %.2f\n", numUno, numDos, producto);
        printf("La division de %d y %d es de %.2f\n", numDos, numUno, division);
    }
    return 0;
}

int leerInt() {
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
