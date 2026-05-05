#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char nombre1[20];
    char nombre2[20];
    int edad1;
    int edad2;

    printf("Ingrese primer nombre:\n");
    fgets(nombre1, sizeof(nombre1), stdin);
    nombre1[strcspn(nombre1, "\n")] = 0;

    printf("Ingrese primer edad:\n");
    scanf("%d", &edad1);

    getchar();

    printf("Ingrese segundo nombre:\n");
    fgets(nombre2, sizeof(nombre2), stdin);
    nombre2[strcspn(nombre2, "\n")] = 0;

    printf("Ingrese segunda edad:\n");
    scanf("%d", &edad2);

    if (edad1 > edad2) {
        printf("La persona mas vieja es %s\n", nombre1);
    } else {
        printf("La persona mas vieja es %s\n", nombre2);
    }

    return 0;
}
