#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Empleando un vector solo se requiere definir un único nombre y accedemos a cada elemento por medio del subíndice.
int main()
{
    srand(time(0));
    int sueldo[5], aux;
    for (int i = 0; i < 5; i++) {
        sueldo[i] = rand ( ) / (700 - 50 + 1) + 50;
    }
    for (int i = 0; i < 5; i++) {
            for ( int j = 0; j < 5-i-1; j++)  {
            if (sueldo[j] > sueldo[j + 1]){
            aux = sueldo[j];
            sueldo[j] = sueldo[j + 1];
            sueldo[j + 1] = aux;
        }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("sueldo %i es igual a: %i \n", i, sueldo[i]);
    }

    return 0;
}
