#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MaxAlumno 5
#define MaxMateria 4

struct Actas {
int numeroAlumno;
int codigoMateria;
float notaFinal;

};
void guardarArchivo();
void vaciarArchivo();
void imprimir();
int main()
{
    int opcion;
     do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Notas    %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Vaciar Archivo.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;}
            switch(opcion) {
        case 1:{
            system("cls");
            guardarArchivo();
            system("pause");
        break;}

        case 2:{
            system("cls");
            imprimir();
            system("pause");
        break;}


        case 3: {
            system("cls");
            vaciarArchivo();
            printf("Archivo vaciado con exito.\n");
            system("pause");
        break;}

        case 0: {
            system("cls");
            printf("Saliendo...\n");
            system("pause");
        break;}

        default:{
            system("cls");
        printf("ERROR opcion invalida.\n");
        system("pause");}
            }

        } while(opcion != 0);
    return 0;
}

void guardarArchivo() {
struct Actas a;
FILE *notas;
notas = fopen("actas.dat", "wb");

if(notas == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de alumno del 1 al %d (o '0' para salir): ", MaxAlumno);
        if (scanf("%d", &a.numeroAlumno) != 1) {
            while (getchar() != '\n');
            a.numeroAlumno = -1;
        }
        if (a.numeroAlumno == 0) {
            break;
        }

        printf("Ingrese el numero de materia del 1 al %d: ", MaxMateria);
        if (scanf("%d", &a.codigoMateria) != 1) {
            while (getchar() != '\n');
            a.codigoMateria = -1;
        }

        printf("Ingrese la nota");
        if (scanf("%f", &a.notaFinal) != 1) {
            while (getchar() != '\n');
            a.notaFinal = -1;
        }


        fwrite(&a, sizeof(struct Actas), 1, notas);
        printf(" -> Nota guardada.\n");
    }
    fclose(notas);
  printf("\nVolviendo al menu...\n");
system("pause");
}

void imprimir() {
    struct Actas a;
    FILE *notas = fopen("actas.dat", "rb");
    float matriz[MaxAlumno][MaxMateria] = {0};

    if (notas == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

    // Cargar datos en matriz
    while (fread(&a, sizeof(struct Actas), 1, notas) == 1) {
        int fila = a.numeroAlumno - 1;
        int col = a.codigoMateria - 1;

        if (fila >= 0 && fila < MaxAlumno && col >= 0 && col < MaxMateria) {
            matriz[fila][col] = a.notaFinal;
        }
    }

    fclose(notas);

    printf("---------------------------------------------\n");
    printf("------------- INFORME MATRICIAL -------------\n");
    printf("---------------------------------------------\n");

    // Encabezado
    printf("%-10s", " ");
    for (int t = 0; t < MaxMateria; t++) {
        printf("| Mat %-4d", t + 1);
    }
    printf("\n");

    printf("---------------------------------------------\n");

    // Filas
    for (int l = 0; l < MaxAlumno; l++) {
        printf("Alumno %-3d ", l + 1);

        for (int t = 0; t < MaxMateria; t++) {
            printf("| %-7.2f", matriz[l][t]);
        }

        printf("\n"); // IMPORTANTE: salto de línea por cada alumno
    }

    printf("---------------------------------------------\n");
}

void vaciarArchivo() {
FILE *notas;
notas = fopen("actas.dat", "wb");
fclose(notas);
}
