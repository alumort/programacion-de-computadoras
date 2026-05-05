#include <stdio.h>
#include <stdlib.h>

int leerInt();

int main()
{
    int numUno, numDos;
    printf("Ingrese el primer numero.\n");
    numUno = leerInt();
    printf("Ingrese el segundo numero.\n");
    numDos = leerInt();
    if ( numUno > numDos){
        printf("%d es mayor que %d", numUno, numDos);
    } else {
     printf("%d es mayor que %d", numDos, numUno);
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
