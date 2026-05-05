#include <stdio.h>
#include <stdlib.h>

int leerEntero();
float leerFloat();
int main()
{
    int cantidadLlevada;
    float precioArticulo;
    float precioTotal;

    printf("Ingrese el precio de los frijoles magicos\n");
    precioArticulo = leerFloat();
    printf("Cuantos fijoles magicos va a llevar?(no me robes ninguno porfis)\n");
    cantidadLlevada = leerEntero();
    precioTotal = precioArticulo * cantidadLlevada;
    printf("Se lleva %d de frijoles con precio de %.2f cada uno, en total son %.2f. Disfrute socializar con gigantes!\n", cantidadLlevada, precioArticulo, precioTotal);
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
float leerFloat() {
float x;
float resultado;

    while (1) {
        resultado = scanf("%f", &x);

        if (resultado == 1) {
            return x;
            while (getchar() != '\n');
        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }}
