#include <stdio.h>
#include <stdlib.h>

int leerEntero();

int main()
{
    int numUno, numDos, numTres = 0;
    int mayor = 0;
    printf("Ingrese el primer numero.\n");
    numUno = leerEntero();
    printf("Ingrese el segundo numero.\n");
    numDos = leerEntero();
    printf("Ingrese el tercer numero.\n");
    numTres = leerEntero();
    if (numUno > mayor) {
        mayor = numUno;
         if (numDos > numUno) {
        mayor = numDos;
        if (numTres > numDos) {
        mayor = numTres;
    }
    }
    }


    printf("De los numeros %d, %d y %d el mayor es %d", numUno, numDos, numTres, mayor);
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
