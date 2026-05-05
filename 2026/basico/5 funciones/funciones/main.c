#include <stdio.h>
#include <stdlib.h>

void sumar(int sumA, int sumB) {
    printf("%d\n", sumA + sumB);
}

int multiplicar(int mulA, int mulB){
    return mulA * mulB;
}

int main()
{
    sumar(2,2);
    sumar(3,5);
    int multiplicado = multiplicar(3, 50);
    printf("%d\n", multiplicado);
    return 0;
}
