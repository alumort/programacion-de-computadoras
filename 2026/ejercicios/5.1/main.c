#include <stdio.h>
#include <stdlib.h>
//Realizar la carga de dos números enteros por teclado e imprimir su suma y su producto.

int leerEntero();
int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int producto;
    printf("Ingrese el primer numero, por favor.\n");
    numeroUno = leerEntero();
    printf("Ahora ingrese el segundo numero.\n");
    numeroDos = leerEntero();
    suma = numeroUno + numeroDos;
    producto = numeroUno * numeroDos;
    printf("La suma de %d y %d es de %d\n", numeroUno, numeroDos, suma);
    printf("La multiplicacion de %d y %d es de %d", numeroUno, numeroDos, producto);
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
    }
}
