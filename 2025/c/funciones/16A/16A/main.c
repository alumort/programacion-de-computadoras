#include <stdio.h>
#include <stdlib.h>

int valorUno();
int valorDos();
int suma(int a,int b);

int main()
{
    int a = valorUno();
    int b = valorDos();
    suma(a,b);
    return 0;
}

int valorUno() {
    int a;
    printf("ingrese primer valor:");
    scanf("%i", &a);
    return a;
}
int valorDos() {
    int b;
    printf("ingrese segundo valor:");
    scanf("%i", &b);
    return b;
}
int suma(int a, int b) {
    int resultado = a + b;
    printf("La suma de %i y de %i es: &", a, b, resultado);
    return resultado;
}
