#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void simuladorCarga(const char* mensaje);
void cargarMulta(char patente[], float monto);
void archivoHistorial();
void exportarExcel();

int main()
{

    int opcion;
    char patente[10];
    float deuda;
    float acumDeuda = 0;
    float totalRecaudado;
    system("color 0B");
    do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c   SISTEMA DE MULTAS   %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Cargar nueva multa.\n");
            printf("2. Ver historial completo.\n");
            printf("3. Buscar por patente.\n");
            printf("4. Ver total recaudado.\n");
            printf("5. Exportar Deudores.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;
        }
            switch(opcion) {
            case 1: {
                system("cls");
                printf("Ingrese la patente del deudor\n");
                scanf("%s", patente);
                printf("Ingrese el monto de la multa.\n");
            if (scanf("%f", &deuda) < 1) {
            while (getchar() != '\n');
            deuda = -1;}
            cargarMulta(patente, deuda);
            break;}

            case 2: {
                system("cls");
                simuladorCarga("Abriendo historial");
                archivoHistorial();
                system("pause");

            break;}

            case 3: {
                 system("cls");
                 FILE *multas;
                multas = fopen("multas.txt", "r");

    if (multas == NULL) {
        printf("No se pudo abrir el archivo.\n");
        break;
    }

    char patenteBuscada[10];
    char patenteArchivo[10];
    float deudaArchivo;
    int encontrado = 0;

    printf("Ingrese la patente a buscar: ");
    scanf("%s", patenteBuscada);
while (fscanf(multas, "%s %f", patenteArchivo, &deudaArchivo) != EOF) {
        if (strcmp(patenteBuscada, patenteArchivo) == 0) {
            printf("\nPatente: %s\n", patenteArchivo);
            printf("Deuda: %.2f\n", deudaArchivo);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo se encontro la patente.\n");
    }
fclose(multas);
system("pause");
            break;}

            case 4: {
    system("cls");
    simuladorCarga("Revisando todo lo recaudado");

    FILE *multas = fopen("multas.txt", "r");

    if (multas == NULL) {
        printf("No se pudo abrir el archivo.\n");
        break;
    }

    char patenteArchivo[10];
    float deudaArchivo;
    float total = 0;

    while (fscanf(multas, "%s %f", patenteArchivo, &deudaArchivo) != EOF) {
        total += deudaArchivo;
    }

    fclose(multas);

    printf("\nTotal recaudado: %.2f\n", total);
    system("pause");
    break;}

            case 5: {
                system("cls");
                simuladorCarga("Exportando Base de Datos");
                exportarExcel();
                printf("Base de datos exportada con exito.\n");
                break;
            }

            case 0: {
                 system("cls");
                 simuladorCarga("Saliendo");
            break;}

            default: {
            printf("ERROR: Opcion invalida. Intente de nuevo.\n");
            break;}
            }

    } while(opcion !=0);
    return 0;
}

void simuladorCarga(const char* mensaje) {
    printf("\n  %s", mensaje);
    for (int i = 0; i < 3; i++) {
        printf(".");
        Sleep(400);
    }
    printf(" [OK]\n");
    Sleep(400);
}

void cargarMulta(char patente[], float monto) {
    FILE *multas = fopen("multas.txt", "a");

    if (multas != NULL) {
        fprintf(multas, "%s %.2f\n", patente, monto);
        fclose(multas);
    } else {
        printf("Error al abrir archivo.\n");
    }
}

void archivoHistorial() {
    FILE *multas = fopen("multas.txt", "r");

    if (multas == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    char patente[10];
    float deuda;
    int hayDatos = 0;

    printf("\n--- HISTORIAL DE MULTAS ---\n\n");

    while (fscanf(multas, "%s %f", patente, &deuda) == 2) {
        printf("Patente: %s | Deuda: %.2f\n", patente, deuda);
        hayDatos = 1;
    }

    if (!hayDatos) {
        printf("No hay multas cargadas.\n");
    }

    fclose(multas);
}

void exportarExcel() {
    FILE *multas;
    FILE *deudores;

    char patente[10];
    float deuda;

    multas = fopen("multas.txt", "r");
    deudores = fopen("deudores.csv", "w");

    if (multas != NULL && deudores != NULL) {

        fprintf(deudores, "Patente,Deuda_Pendiente\n");

        while (fscanf(multas, "%s %f", patente, &deuda) != EOF) {
            fprintf(deudores, "%s,%.2f\n", patente, deuda);
        }

        fclose(multas);
        fclose(deudores);

        printf("\n-> Exportado correctamente a 'deudores.csv'\n");

    } else {
        printf("ERROR: No se pudo abrir archivo\n");

        if (multas != NULL) fclose(multas);
        if (deudores != NULL) fclose(deudores);
    }

    system("pause");
}


