#include <stdio.h>
#include <stdlib.h>


void intercambiar(int* punteroX, int* punteroY);

int main()
{
    int x = 1;
    int y = 99;
    printf("Valores iniciales: %d, %d\n", x, y);
    intercambiar(&x, &y);
    printf("Luego del intercambio: %d, %d\n", x, y);
    return 0;
}

void intercambiar(int* punteroX, int* punteroY) {
    int auxiliar;
    auxiliar = *punteroX;
    *punteroX = *punteroY;
    *punteroY = auxiliar;
}
