#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Cargar por teclado dos nombres de personas que tengan distinta cantidad de caracteres.
//Almacenar en un tercer vector de caracteres el nombre que tenga más caracteres. Luego imprimir dicho vector.
int main()
{
    char nombre1[21];
    char nombre2[21];
    char nombre3[21];
    printf("INGRESE PRIMER NOMBRE\n");
    fgets(nombre1, sizeof(nombre1), stdin);
    nombre1[strcspn(nombre1, "\n")] = 0;
    printf("INGRESE SEGUNDO NOMBRE\n");
    fgets(nombre2, sizeof(nombre2), stdin);
    nombre2[strcspn(nombre2, "\n")] = 0;
    if(strlen(nombre1) > strlen(nombre2)) {
        strcpy(nombre3, nombre1);
    } else {
    strcpy(nombre3, nombre2);}
    printf("EL NOMBRE MAS LARGO DEL UNIVERSO ES.... %s\n", nombre3);
    return 0;
}
