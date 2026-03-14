#include <stdio.h>
#include <stdlib.h>


int definirValor ();
int mayor(int valorA, int valorB);

int main()
{
    int valorA, valorB;
    valorA = definirValor();
    valorB = definirValor();
    mayor(valorA, valorB);
    return 0;
}

int definirValor () {
    int valor;
    printf("ingrese el valor: ");
    scanf("%i", &valor);
    return valor;
}

int mayor(int valorA, int valorB) {

    if (valorA > valorB) {
        printf("el mayor es %i", valorA);
    }
    else {
        printf("el mayor es %i", valorB);
    }
}
