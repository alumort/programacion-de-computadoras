#include <stdio.h>
#include <stdlib.h>
//Confeccionar una función que reciba dos enteros e imprima el mayor de ellos.
//Llamar a la función desde la main cargando previamente dos valores por teclado.
int cargarNumeroA();
void mostrarMayor(int a, int b);
int main()
{
    int a = cargarNumeroA();
    int b = cargarNumeroB();
    mostrarMayor(a, b);
    return 0;
}
int cargarNumeroA(){
    int a;
    printf("ingrese primer valor: ");
    scanf("%i", &a);
    return a;

}

int cargarNumeroB(){
    int b;
    printf("ingrese segundo valor: ");
    scanf("%i", &b);
    return b;
}

void mostrarMayor(int a, int b) {
    if (a > b) {
        printf("el mayor es %i", a);
    }
    if (b > a) {
        printf ("el mayor es %i", b);
    }
}
