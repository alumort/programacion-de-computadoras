#include <stdio.h>
#include <stdlib.h>
//Confeccionar un programa que defina dos funciones, una que permita cargar un vector de 5 elementos enteros y otra que muestre un vector de 5 elementos
//En la función main definir una variable de tipo vector y seguidamente llamar a las dos funciones.

void cargar(int vec[5]);
void mostrar(int vec[5]);
int main()
{
    int vec[5];
    cargar(vec);
    mostrar(vec);
    getch();
    return 0;
}
void cargar(int vec[5]) {
    for (int i = 0; i < 5; i++) {
        printf("ingrese un numero: ");
        scanf("%i", &vec[i]);
    }
}

void mostrar(int vec[5]) {
    for (int i = 0; i < 5; i++) {
        printf("%i \n", vec[i]);
    }
}
