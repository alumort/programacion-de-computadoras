#include <stdio.h>
#include <stdlib.h>


int main()
{
    char nombre[50];
    int edad;
    FILE *archivo;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);


    archivo = fopen(filename: "perfil.txt", modes: "w");

    if (archivo == NULL) {
        printf("Error: No se pudo crear el archivo.\n");
        return 1;
    }


    fprintf(stream: archivo, format: "Nombre del usuario: %s\n", nombre);
    fprintf(stream: archivo, format: "Edad: %d anios\n", edad);


    fclose(archivo);

    printf("¡Archivo creado! Anda a buscar el .txt a la carpeta de tu proyecto.\n");
    return 0;
}
