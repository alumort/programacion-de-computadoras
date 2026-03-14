#include <stdio.h>
#include <stdlib.h>
//Crear un vector de 20 números enteros, los 20 números son ingresados por el usuario.
//Mostrar por pantalla el máximo de esos 20 números.

int main()
{
    int max, posicion, i;
    max = 0;
    posicion = 0;
    int enteros[20];
    for (i = 0; i < 20; i++) {
        printf("ingrese un numero\n");
        scanf("%d", &enteros[i]);
        if (max = 0) {
            max = enteros[i];
            posicion = i;
        }
        if (max < enteros [i]) {
            max = enteros[i];
            posicion = i;
        }
    }
    for (i = 0; i < 20; i++) {
        printf(" %d \n", enteros[i]);
    }
    printf("el mayor es: %d, posicion %d \n", max, posicion);
    return 0;
}
