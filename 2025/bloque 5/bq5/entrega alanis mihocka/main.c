#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"


//Luego, hacer un array de Animales reutilizando lo anterior, y ordenarlos por el dato float.



int main() {
    int num;
    printf("cuantos animales quieres?: ");
    scanf("%i", &num);

    struct Animal animales[num];
    for (int i = 0; i < num; i++) {
        animales[i] = cargarAnimal(animales[i]);
        printf("\n");
    }

    printf("animales cargados sin orden: \n\n");
    for (int i = 0; i < num; i++) {
         mostrarAnimal(animales[i]);
    }

    printf("Ordenando mediante burbuja...\n\n");
    ordenarAnimal(num, animales);


    printf("animales cargados y ordenados por peso: \n\n");
        for (int i = 0; i < num; i++) {
         mostrarAnimal(animales[i]);
    }
    getchar();
    return 0;
}
