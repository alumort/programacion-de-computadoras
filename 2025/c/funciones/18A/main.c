#include <stdio.h>
#include <stdlib.h>
//Confeccionar una función que le enviemos como parámetro el valor del lado de un cuadrado y nos retorne su superficie.

float superficie (float lado);
int main()
{
    float lado, sup;
    printf("ingrese lado del  cuadrado: \n");
    scanf("%f", &lado);
    sup = superficie(lado);
    printf("la superficie es %f", sup);
    return 0;
}
float superficie (float lado){
    float superficie = lado * lado;
    return superficie;
}
