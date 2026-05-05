#include <stdio.h>
#include <stdlib.h>
//Se ingresa por teclado un número positivo de uno o dos dígitos (1..99)
//mostrar un mensaje indicando si el número tiene uno o dos dígitos.
//(Tener en cuenta que condición debe cumplirse para tener dos dígitos un número entero)
int leerInt();

int main()
{
    int numero;
    printf("Ingrese un numero positivo de uno o dos digitos.\n");
    numero = leerInt();
    do {
        if (numero < 1 || numero > 100) {
            printf("ERROR solo puede elegir un numero del 1 al 99. Ingrese un numero valido.\n");
            numero = leerInt();
        }
    }while(numero < 1 || numero > 100);

    if (numero >= 10) {
        printf("El numero %d tiene dos digitos.\n", numero);
    } else {
    printf("El numero %d tiene un digito.\n", numero);
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
