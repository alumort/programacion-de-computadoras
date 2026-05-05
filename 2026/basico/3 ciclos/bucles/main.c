#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ciclo For\n");

    char *animales[]= {"perro", "gato", "hamster"};

    for (int i = 0; i < 3; i++) {
        printf("%s\n", animales [i]);
    }

    printf("Ciclo While\n");

    int entero = 900;
    int emergencia = 911;

    while (entero <= emergencia) {
        printf("%d\n", entero);
        entero = entero + 1;
    }

    return 0;
}
