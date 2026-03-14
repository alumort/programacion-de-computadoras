#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"


struct Animal cargarAnimal(struct Animal animal) {
    printf("Ingrese la edad del animal: ");
    scanf("%i",&animal.edad);
    printf("Ingrese el peso del animal:  ");
    scanf("%f",&animal.peso);
    getchar();
    printf("Ingrese la especie del animal: ");
    gets(animal.especie);
    animal.especie[strcspn(animal.especie, "\n")] = '\0';
   do {
        printf("Ingrese genero (M / F) del animal: ");
        scanf(" %c", &animal.genero);

        switch (animal.genero) {
            case 'm':
            case 'M':
                animal.genero = 'm';
                break;
            case 'f':
            case 'F':
                animal.genero = 'f';
                break;
            default:
                printf("No es un genero valido...\n");
                animal.genero = '?';
        }
    } while (animal.genero != 'm' && animal.genero != 'f');

    return animal;
}

void mostrarAnimal(struct Animal animal) {
    printf("La edad del animal es: %i\n", animal.edad);
    printf("El peso del animal es: %0.2f\n", animal.peso);
    printf("La especie del animal es: %s\n", animal.especie);
    printf("Genero del animal: %c\n", animal.genero);
    printf("\n");
}
void ordenarAnimal(int num, struct Animal animales[]) {
    struct Animal aux;

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (animales[j].peso < animales[j + 1].peso) {
                aux = animales[j];
                animales[j] = animales[j + 1];
                animales[j + 1] = aux;
            }
        }
    }
}
