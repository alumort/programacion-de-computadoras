#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void mostrarMenu();
void consultarSaldo(float saldo);
float depositar(float saldo);
float extraer(float saldo);
int seleccionarOpcion();
void ordenarHistorial(float vector[], int cantidad_movimientos);
void mostrarHistorial(float vector[], int cantidad_movimientos);

int main()
{
    int opcion;
    float saldo = 10000.0;
    float historial[100];
    int i = 0;

    do {
        mostrarMenu();
        opcion = seleccionarOpcion();

        switch (opcion) {
        case 1: {
            consultarSaldo(saldo);
            break;
        }


        case 2: {
            float saldo_viejo = saldo;
            saldo = depositar(saldo);

            if (saldo > saldo_viejo) {
                historial[i] = saldo - saldo_viejo;
                i++;
                printf("-> Movimiento guardado en el historial.\n");
            }
            break;
        }

        case 3: {
            float saldo_viejo = saldo;
            saldo = extraer(saldo);

            if (saldo < saldo_viejo) {
                historial[i] = saldo_viejo - saldo;
                i++;
                printf("-> Movimiento guardado en el historial.\n");
            }
            break;
        }

        case 4:
            ordenarHistorial(historial, i);
            break;

        case 5:
            mostrarHistorial(historial, i);
            break;

        case 0:
            printf("Saliendo del cajero...\n");
            break;

        default:
            printf("ERROR\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}

void mostrarMenu() {
    printf("\n*************\n");
    printf("Bienvenido al cajero automatico! Por favor, seleccione una opcion (0 para salir):\n");
    printf("*************\n");
    printf("1. Consultar saldo\n");
    printf("2. Depositar\n");
    printf("3. Extraer\n");
    printf("4. Ordenar historial\n");
    printf("5. Mostrar historial\n");
    printf("0. Salir\n");
    printf("*************\n");
}

int seleccionarOpcion() {
    int opcion;
    int resultado;
    do {
        resultado = scanf("%d", &opcion);
        if (resultado == 0 || opcion < 0 || opcion > 5) {
            printf("Opcion invalida. Intente de nuevo ingresando un numero del 0 al 5:\n");
            while (getchar() != '\n');
        }
        else {
        }
            break;
        }
    } while (1);

    return opcion;
}

void consultarSaldo(float saldo) {
    printf("El saldo actual es de: $ %.2f\n", saldo);
}

float depositar(float saldo) {
    float deposito = 0;
    do {
        printf("Cuanto desea depositar?\n");
        if (scanf("%f", &deposito) == 0) {
            printf("ERROR ingrese un numero valido\n");
            while (getchar() != '\n');
            deposito = -1;
            continue;
        }
        if (deposito <= 0) {
            printf("ERROR: no puede depositar cantidades negativas ni iguales a 0\n");
        }
    } while (deposito <= 0);

    saldo = saldo + deposito;
    printf("Deposito exitoso.\n");
    return saldo;
}

float extraer(float saldo) {
    float extraccion = 0;
    do {
        printf("Cuanto desea extraer?:\n");
        if (scanf("%f", &extraccion) == 0) {
            printf("ERROR: ingrese un numero valido\n");
            while (getchar() != '\n');
            extraccion = saldo + 1;
            continue;
        }
        if (extraccion <= 0) {
            printf("ERROR: ingrese un monto mayor a 0.\n");
        }
        else if (extraccion > saldo) {
            printf("FONDOS INSUFICIENTES. El saldo es de: $ %.2f\n", saldo);
        }
    } while (extraccion > saldo || extraccion <= 0);

    saldo = saldo - extraccion;
    printf("Extraccion exitosa.\n");
    return saldo;
}

void ordenarHistorial(float vector[], int cantidad_movimientos) {
    float aux;
    int ordenado;

    if (cantidad_movimientos == 0) {
        printf("Todavia no hay movimientos en el historial para ordenar.\n");
        return;
    }

    do {
        ordenado = 1;
        for (int j = 0; j < cantidad_movimientos - 1; j++) {
            if (vector[j] < vector[j + 1]) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
                ordenado = 0;
            }
        }
    } while (ordenado == 0);

    printf("Historial ordenado correctamente de mayor a menor.\n");
}

void mostrarHistorial(float vector[], int cantidad_movimientos) {
    if (cantidad_movimientos == 0) {
        printf("El historial esta vacio. No hay movimientos para mostrar.\n");
        return;
    }

    printf("\n--- HISTORIAL DE MOVIMIENTOS ---\n");
    for (int j = 0; j < cantidad_movimientos; j++) {
        printf("Movimiento %d: $ %.2f\n", j + 1, vector[j]);
    }
    printf("--------------------------------\n");
}
