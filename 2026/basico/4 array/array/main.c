#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Arrays\n");

    printf("Numeros:");
    int enteros[] = {1,2,3};
    printf("el primer numero entero es: %i", enteros[0]);

    printf("Caracteres:\n");
    char *animales[] = {"gato", "perro", "rinoceronte"};
    printf("El animal que maulla es el... %s\n", animales[0]);
    return 0;
}
