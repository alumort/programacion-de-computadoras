#include <stdio.h>
#include <stdlib.h>

void guardarFichada(int dni, int hora);

int main()
{
    int dni;
    int hora;
    int opcion;

    do {
    printf("----Sistema de Fichado de Personal----\n");
    printf("1. Fichar.\n");
    printf("0.Salir.\n");
        printf("Ingrese una opcion.\n");
        scanf("%d", &opcion);
        switch(opcion) {
        case 1: {
            printf("Ingrese su dni.\n");
            scanf("%d", &dni);
            printf("Ingrese la hora de ficheo (0 a 23)\n");
            scanf("%d", &hora);
            guardarFichada(dni, hora);
        break;}

        case 0: {
        printf("Cerrando programa...\n");
        break;
        }
        }
    } while (opcion != 0);
    return 0;
}

void guardarFichada(int dni, int hora) {
FILE *registro;
registro = fopen("asistencia.txt", "a");

if (registro == NULL) {
    printf("No se pudo crear el archivo. Intente de nuevo.\n");
    return 1;
}
fprintf(registro, "Dni: %d\n", dni);
fprintf(registro, "Hora: %d\n", hora);

fclose(registro);
printf("Fichada aniadida con exito.\n");
}
