#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Max_Locales 4
#define Max_Trimestres 3

struct Ventas {
int numeroLocal;
int numeroTrimestre;
float importeVendido;
};

void guardarVentas();
void informeGeneral(float *maximoVendido, int *maximoLocal);
void masVendio(float *maximoVendido, int *maximoLocal);
void vaciarArchivo();
int main()
{
float maximoVendido = 0;
int  maximoLocal = 0;
int opcion;

     do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Tienda   %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Tienda que mas vendio.\n");
            printf("4. Vaciar Archivo.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;}
            switch(opcion) {
        case 1:{
            system("cls");
            guardarVentas();
            system("pause");
        break;}

        case 2:{
            system("cls");
            informeGeneral(&maximoVendido, &maximoLocal);
            system("pause");
        break;}

        case 3: {
            system("cls");
            masVendio(&maximoVendido, &maximoLocal);
            system("pause");
        break;}

        case 4: {
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

void guardarVentas() {
    struct Ventas v;
    FILE *reporte;
    reporte = fopen("reporte.dat", "ab");
    if(reporte == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de local del 1 al %d (o '0' para salir): ", Max_Locales);
        if (scanf("%d", &v.numeroLocal) != 1) {
            while (getchar() != '\n');
            v.numeroLocal = -1;
        }
        if (v.numeroLocal == 0) {
            break;
        }

        printf("Ingrese el numero de trimestre del 1 al %d: ", Max_Trimestres);
        if (scanf("%d", &v.numeroTrimestre) != 1) {
            while (getchar() != '\n');
            v.numeroTrimestre = -1;
        }

        printf("Ingrese el importe vendido total: $");
        if (scanf("%f", &v.importeVendido) != 1) {
            while (getchar() != '\n');
            v.importeVendido = -1;
        }


        fwrite(&v, sizeof(struct Ventas), 1, reporte);
        printf(" -> Venta guardada.\n");
    }


  fclose(reporte);
  printf("\nVolviendo al menu...\n");
system("pause");

}

void informeGeneral(float *maximoVendido, int *maximoLocal) {
    struct Ventas v;
    FILE *reporte = fopen("reporte.dat", "rb");
    float matriz[Max_Locales][Max_Trimestres]= {0};
    float totalTrimestre[Max_Trimestres]= {0};
    float totalLocal[Max_Locales]= {0};
    float totalGeneral= 0;
    if(reporte == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }
    while(fread(&v, sizeof(struct Ventas), 1, reporte)) {
      int fila = v.numeroLocal - 1;
      int col = v.numeroTrimestre -1;
      if(fila >= 0 && fila < Max_Locales && col >= 0 && col < Max_Trimestres){
            matriz[fila][col] = matriz[fila][col] + v.importeVendido;
      }
    }
          fclose(reporte);
          *maximoVendido = 0;
for(int l = 0; l < Max_Locales; l++) {
        for(int t = 0; t < Max_Trimestres; t++) {
            totalTrimestre[t] = totalTrimestre[t] + matriz[l][t];
            totalLocal[l] = totalLocal[l] + matriz[l][t];
            totalGeneral = totalGeneral + matriz[l][t];
            if (matriz[l][t] > *maximoVendido) {
                *maximoVendido = matriz[l][t];
                *maximoLocal = l + 1;
            }
        }
    }
    printf("---------------------------------------\n");
    printf("-----------INFORME MATRICIAL-----------\n");
    printf("---------------------------------------\n");
     printf("%-10s", " ");
    for(int t = 0; t < Max_Trimestres; t++) {
        printf(" | Trim %d  ", t + 1);
    }
    printf(" | TOTAL LOCAL\n");
    printf("--------------------------------------------------\n");

    // Imprimir filas (Nombre del local, los importes de la matriz y el total de la fila)
    for(int l = 0; l < Max_Locales; l++) {
        printf("Local %-4d", l + 1); // Nombre del local

        for(int t = 0; t < Max_Trimestres; t++) {
            printf(" | $%-7.2f", matriz[l][t]); // Imprime el valor de la matriz
        }
        printf(" | $%.2f\n", totalLocal[l]); // Imprime el total del local
    }
    printf("--------------------------------------------------\n");

    // Imprimir fila final (Totales de los trimestres y total general)
    printf("%-10s", "TOTAL TRIM");
    for(int t = 0; t < Max_Trimestres; t++) {
        printf(" | $%-7.2f", totalTrimestre[t]);
    }
    printf(" | $%.2f\n\n", totalGeneral);

}




void masVendio(float *maximoVendido, int *maximoLocal) {
    if (*maximoVendido == 0) {
        printf("Aun no se generaron reportes o no hay ventas.\n");
        printf("(Recuerde pasar por la Opcion 2 primero)\n");
    } else {
        printf("Local que mas vendio: %d\n", *maximoLocal);
        printf("Cantidad Vendida: $%.2f\n", *maximoVendido);
    }

}

void vaciarArchivo() {
FILE *reporte;
reporte = fopen("reporte.dat", "wb");
fclose(reporte);
}
