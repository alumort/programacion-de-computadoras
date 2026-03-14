#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Crear un vector de 30 números enteros aleatorios.

int main()
{
    srand(time(0));
    int i;
    int random[30];
    for (i = 0; i<30; i++) {
        random[i] = rand();
        printf("  %d  ", random[i]);
    }
    return 0;
}
