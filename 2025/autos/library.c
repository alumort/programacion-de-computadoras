#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int validarPatente(char patente[]) {
    int len = strlen(patente);

    // Caso 1: NNNLLL (6 caracteres)
    if (len == 6) {
        if (isdigit(patente[0]) && isdigit(patente[1]) && isdigit(patente[2]) &&
            isalpha(patente[3]) && isalpha(patente[4]) && isalpha(patente[5])) {
            return 1;
        }
    }

    // Caso 2: LLNNNLL (7 caracteres)
    if (len == 7) {
        if (isalpha(patente[0]) && isalpha(patente[1]) &&
            isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) &&
            isalpha(patente[5]) && isalpha(patente[6])) {
            return 1;
        }
    }

    return 0;
}

void cargarVehiculos(int num, struct Vehiculo vehiculo[num]) {;
    for (int i = 0; i < num; i++) {
        int val = 0;

        printf("Ingrese el anio del vehiculo: ");
        scanf("%i",&vehiculo[i].anio);

        printf("Ingrese el precio del vehiculo:  ");
        scanf("%f",&vehiculo[i].precio);

        getchar();

        printf("Ingrese el color del vehiculo: ");
        gets(vehiculo[i].color);
        vehiculo[i].color[strcspn(vehiculo[i].color, "\n")] = '\0';

        do {
            if (val == 0) {
                printf("Ingrese el patente del vehiculo: ");
                gets(vehiculo[i].patente);
                vehiculo[i].patente[strcspn(vehiculo[i].patente, "\n")] = '\0';
                val = validarPatente(vehiculo[i].patente);
            }
            if (val == 1) {
                break;
            }

            printf("Las patentes deben ser NNNLLL o LLNNNLL donde las L son letras y N números, ej: 458KHE o AL454DO");

        } while (val != 1);
        
        printf("\n");
    }
}

void ordenarVehiculosPorPatente(int num, struct Vehiculo vehiculo[num]) {
    printf("\n Ordenando Vehiculos... \n");
    struct Vehiculo aux;

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (strcmp(vehiculo[j].patente, vehiculo[j + 1].patente) > 0) {
                // Intercambio
                aux = vehiculo[j];
                vehiculo[j] = vehiculo[j + 1];
                vehiculo[j + 1] = aux;
            }
        }
    }
}

void mostrarVehiculos(int num, struct Vehiculo vehiculo[num]) {
    printf("\n Vehiculos: \n");
    for (int i = 0; i < num; i++) {
        printf("El año del vehiculo es: %i\n", vehiculo[i].anio);
        printf("El precio del vehiculo es: %0.2f\n", vehiculo[i].precio);
        printf("El color del vehiculo es: %s\n", vehiculo[i].color);
        printf("La patente del vehiculo es: %s\n", vehiculo[i].patente);
        printf("\n");
    }
}
