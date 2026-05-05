#include <stdio.h>
#include <stdlib.h>

int leerEntero();

int main()
{
    int lado;
    int perimetro;
    printf("Ingrese el tamaño del lado del cuadrado. \n");
    lado = leerEntero();
    perimetro = lado * 4;
    pritntf("Tamanio de los lados: %d\n perimetro: %d\n", lado, perimetro);
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
