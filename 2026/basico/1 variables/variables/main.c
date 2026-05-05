#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Variables y como definirlas:\n");

    printf("Interger:\n");
    int a, b, c;

    printf("Ingrese primer numero entero\n");
    scanf(" %i", &a);
    printf("Ingrese segundo numero entero\n");
    scanf(" %i", &b);
    printf("Ingrese tercer numero entero\n");
    scanf(" %i", &c);

    int result = a + b + c;
    printf("%d\n", result);

    printf("Float:\n");
    float d, e, f;

    printf("Ingrese primer numero flotante\n");
    scanf(" %f", &d);
    printf("Ingrese segundo numero flotante\n");
    scanf(" %f", &e);
    printf("Ingrese tercer numero flotante\n");
    scanf(" %f", &f);
    float sumFloat = d + e + f;
    printf(" %f\n", sumFloat);

    printf("Caracter:\n");
    char nombre[30];

    char apodo[] = "Alunois";
    printf("Escriba el nombre completo del apodo %s\n", apodo);
    getchar();
    fgets(nombre, sizeof(nombre), stdin);
    printf("El nombre completo del apodo %s, es %s\n", apodo, nombre);

    printf("Constantes:\n");
    const float pi = 3.14;
    printf("El valor de pi es %f\n", pi);
    return 0;
}
