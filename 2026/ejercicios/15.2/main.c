#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre1[20];
    char nombre2[20];
    printf("ingrese primer nombre\n");
    fgets(nombre1, sizeof(nombre1), stdin);
    nombre1[strcspn(nombre1, "\n")] = 0;
    printf("ingrese segundo nombre\n");
    fgets(nombre2, sizeof(nombre2), stdin);
    nombre2[strcspn(nombre2, "\n")] = 0;
    if(strcmp(nombre1,nombre2) == 0) {
        printf("Los nombres son iguales.\n");
    } else {    if(strcmp(nombre1,nombre2) > 0) {
        printf("El mayor alfabeticamente es %s", nombre1);
    } else {
    printf("El mayor alfabeticamente es %s", nombre2);}}

    return 0;
}
