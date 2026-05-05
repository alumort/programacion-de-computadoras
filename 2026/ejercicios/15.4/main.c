#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[30];
    char apellido[30];
    char nomape[60];

    printf("Ingrese nombre:\n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;

    printf("Ingrese apellido:\n");
    fgets(apellido, sizeof(apellido), stdin);
    apellido[strcspn(apellido, "\n")] = 0;
    strcpy(nomape, nombre);
    strcat(nomape, " ");
    strcat(nomape, apellido);
    printf("Nombre y Apellido: %s\n", nomape);
    return 0;
}
