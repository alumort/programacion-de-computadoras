#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Condicionales y Operadores:\n");
    printf("Operadores matematicas:\n");

    float a = 1;
    float b = 2;
    float c = 3;

    printf("Operaciones matematicas con los numeros %f, %f, y %f\n", a, b, c);

    float suma = a + b;
    float resta = c - b;
    float multi = b * c;
    float divi = c / a;

    printf("la suma de %f + %f es igual a %f ", a, b, suma);
    printf("la resta de %f - %f es igual a %f ", c, b, resta);
    printf("la multiplicacion de %f * %f es igual a %f ", c, b, multi);
    printf("la division de %f / %f es igual a %f\n", c, a, divi);

    printf("Operaciones de comparacion:\n");

    //printf(suma == c);
    //printf("1" != "1");
    //printf(multi != suma);
    //printf(resta >= 0);
    //printf(resta < 50);

    printf("Operaciones logicas:\n");

    printf("%d\n", 1 && 1); // and
    printf("%d\n", 1 && 0);
    printf("%d\n", 0 && 0);
    printf("%d\n", 0 && 1);

    printf("%d\n", 1 || 1); // or
    printf("%d\n", 1 || 0);
    printf("%d\n", 0 || 0);
    printf("%d\n", 0 || 1);

    printf("Condicional If:\n");

    int contrasena= 3241;

    if (contrasena == 123) {
        printf("autorizo");
    } else if (contrasena == 321) {
        printf("no autorizo");
    } else {
        printf("Watafa esto no estaba en lo planeado o.O");
    }

    printf("Condicional Switch:\n"); // solo INT y CHAR
        char color = 'A';

        switch (color) {

        case 'V':
            printf("Aceptado!");
            break;

        case 'A':
            printf("Cuidadooo");
            break;

        default:
            printf("errorcito, que paso?");
            break;
        }

    return 0;
}
