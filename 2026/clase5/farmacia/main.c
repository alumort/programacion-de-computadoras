#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct Medicamento{
    int id;
    char nombre[15];
    float precio;
    int stock;

};
void vender(struct Medicamento* m);
void reponer(struct Medicamento* m, int cantidad);

void ordenarCatalogo(struct Medicamento vector[], int tamanio);
void simuladorCarga(const char* mensaje);
int main()
{
    struct Medicamento drogas[4] = {
    {123, "Paracetamol", 5.2, 2},
    {345, "Diclofenac", 7.5, 4},
    {678, "Amoxicilina", 4.1, 5},
    {901, "Ibuprofeno", 5.5, 7}
    };
    system("pause");
    system("color 0A");

    int opcion;
    int tamanio = 4;
    int medicamentoVentaBuscado;
    int medicamentoVentaEncontrado = -1;
    int medicamentoReponerBuscado;
    int medicamentoReponerEncontrado = -1;
    int cantidadReponer;

    do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c   FARMACIA  %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Vender.\n");
            printf("2. Reponer.\n");
            printf("3. Ver Catalogo.\n");
            printf("4. Exportar Inventario.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;
        }
            switch(opcion) {
            case 1: {
            system("cls");

       do {
    printf("Ingrese el ID del medicamento a vender.\n");

    if (scanf("%d", &medicamentoVentaBuscado) != 1) {
        while (getchar() != '\n');
        medicamentoVentaBuscado = -1;
    }

    medicamentoVentaEncontrado = -1;

    for(int i = 0; i < tamanio; i++) {
        if(drogas[i].id == medicamentoVentaBuscado) {
            medicamentoVentaEncontrado = i;
            break;
        }
    }

    if(medicamentoVentaEncontrado == -1) {
        printf("Medicamento no encontrado. Intente de nuevo.\n");
    }

} while(medicamentoVentaEncontrado == -1);
            vender(&drogas[medicamentoVentaEncontrado]);



            FILE* comprobantes;
            comprobantes = fopen("ventas.txt", "a");
if (comprobantes != NULL) {
    fprintf(comprobantes, "Nombre del Producto: %s\n", drogas[medicamentoVentaEncontrado].nombre);
fprintf(comprobantes, "Precio: %.2f\n", drogas[medicamentoVentaEncontrado].precio);
fclose(comprobantes);
} else {
printf("No se pudo crear el archivo. Intente de nuevo.\n");
}

            medicamentoVentaEncontrado = -1;
            system("pause");
            break;}

            case 2: {
            system("cls");

        do {
            printf("Ingrese el ID del medicamento a reponer.\n");
            if (scanf("%d", &medicamentoReponerBuscado) != 1) {
            while (getchar() != '\n');
            medicamentoReponerBuscado = -1;
        }
                for(int i = 0; i < tamanio; i++) {
                    if(drogas[i].id == medicamentoReponerBuscado) {
                        medicamentoReponerEncontrado = i;
                        break;
                    }
                }
                if (medicamentoReponerEncontrado == -1) {
                    printf("Medicamento no encontrado. Intente de nuevo.\n");
                }

        } while(medicamentoReponerEncontrado == -1);
            do {
    printf("Ingrese cantidad de medicamento a reponer.\n");
    if (scanf("%d", &cantidadReponer) != 1 || cantidadReponer < 0) {
        while (getchar() != '\n');
        printf("Cantidad invalida.\n");
    }
} while (cantidadReponer < 0);
        reponer(&drogas[medicamentoReponerEncontrado], cantidadReponer);
        medicamentoReponerEncontrado = -1;
            break;}

            case 3: {
            system("cls");
            ordenarCatalogo(drogas, tamanio);
            printf("------- Medicamentos -------\n");
            printf("%-5s %-20s %-5s %-5s \n", "id", "nombre", "$$$","stock");
            printf("----------------------------\n");
            for(int i = 0; i < tamanio; i++) {
                printf("%-5d %-20s %-5.2f %-5d \n", drogas[i].id,
                                                    drogas[i].nombre,
                                                    drogas[i].precio,
                                                    drogas[i].stock);

            }
            system("pause");
            break;}

            case 4: {
            system("cls");
        simuladorCarga("Exportando inventario");
            FILE *inventario;
inventario = fopen("inventario.csv", "w");
if (inventario != NULL) {
        fprintf(inventario, "ID,Nombre,Precio,Stock\n");

for (int i = 0; i < tamanio; i++) {
    fprintf(inventario, "%d,%s,%.2f,%i\n", drogas[i].id,
            drogas[i].nombre,
            drogas[i].precio,
            drogas[i].stock);
}
} else {
    printf("No se pudo abrir el archivo.\n");
}
fclose(inventario);
printf("Inventario exportado con exito.\n");
system("pause");

            break;}

            case 0: {
            system("cls");
            printf("Saliendo...\n");
            break;}

            default: {
            system("cls");
            printf("Error: Opcion invalida. Intente de nuevo.\n");
            break;}

    }} while (opcion != 0);
    return 0;
}


void vender(struct Medicamento* m) {
if (m -> stock <= 0) {
    printf("Error: El medicamento no tiene stock.\n");
} else {
    m -> stock = m -> stock - 1;
    printf("Venta registrada con exito.\n");
}
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

void ordenarCatalogo(struct Medicamento vector[], int tamanio) {
struct Medicamento aux;
int ordenado;
do {
        ordenado = 1;
    for(int i = 0; i < tamanio - 1; i++){
    if(vector[i].precio > vector[i+1].precio) {
        aux = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = aux;
        ordenado = 0;
    }}
} while(ordenado == 0);
}


void reponer(struct Medicamento* m, int cantidad) {
m -> stock += cantidad;
printf("Producto repuesto con exito.\n");
}
