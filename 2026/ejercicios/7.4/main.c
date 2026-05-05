#include <stdio.h>
#include <stdlib.h>
//Confeccionar un programa que permita cargar un número entero positivo de hasta tres cifras y
//muestre un mensaje indicando si tiene 1, 2, o 3 cifras. Mostrar un mensaje de error si el número de cifras es mayor.
int leerEntero();
int main()
{
    int num;
    printf("Ingrese un numero positivo de hasta 3 cifras\n");
    num = leerEntero();
    if(num < 0) {
            do {
                printf("ERROR el numero ingresado es negativo. Intente de nuevo.\n");
                printf("Ingrese un numero positivo de hasta 3 cifras\n");
                num = leerEntero();
            }while(num < 0);
if (num > 999) {
            do {
                printf("ERROR el numero supera las 3 cifras. Intente de nuevo.\n");
                printf("Ingrese un numero positivo de hasta 3 cifras\n");
                num = leerEntero();
            }while(num > 999);

    }
    }
    if(num < 10) {
        printf("El numero %d tiene 1 cifra.\n", num);
    }
    if(num < 100) {
        printf("El numero %d tiene 2 cifras.\n", num);
    } else {
    printf("El numero %d tiene 3 cifras.\n", num);}
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
