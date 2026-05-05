#include <stdio.h>
#include <stdlib.h>

int leerEntero();

int main()
{
    int num;
    printf("Ingrese un numero.\n");
    num = leerEntero();
    if(num > 0) {
                printf("El numero %d es positivo.\n", num);
        }
     else if (num < 0) {
                printf("El numero %d es negativo.\n", num);
    } else {
     printf("El numero %d es nulo.\n", num);
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
