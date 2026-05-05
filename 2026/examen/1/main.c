#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define maxCamion 5
#define maxZona 4

struct Gastos {
int Id_Camion;
int Zona_Ruta;
float Gasto_Peaje;
};

void registrarViajes(int *primerViaje, float *primerGasto);
void matrizGastos(int *camionBarato, float *gastoBarato, int *primerViaje, float *primerGasto);
void camionEconomico(int *camionBarato, float *gastoBarato);
void rankingZonas();
void exportarCSV();
void vaciarArchivo();


int main()
{
    int opcion;
    int camionBarato = 0;
    float gastoBarato = 0;
    int primerViaje = 0;
    float primerGasto =0;
    do {
        system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Viajes   %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Registrar Viajes.\n");
            printf("2. Matriz de Gastos.\n");
            printf("3. Camion Mas Economico.\n");
            printf("4. Ranking de Zonas\n");
            printf("5. Exportar CSV.\n");
            printf("6. Vaciar Sistema.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;}
            switch(opcion) {
            case 1: {
            system("cls");
            registrarViajes(&primerViaje, &primerGasto);
            system("pause");
            break;
            }

            case 2:{
            system("cls");
            matrizGastos(&camionBarato, &gastoBarato, &primerViaje, &primerGasto);
            system("pause");
            break;
            }

            case 3: {
            system("cls");
            camionEconomico(&camionBarato, &gastoBarato);
            system("pause");
            break;
            }

            case 4: {
            system("cls");
            rankingZonas();
            system("pause");
            break;
            }

            case 5: {
            system("cls");
            exportarCSV();
            system("pause");
            break;
            }

            case 6: {
            system("cls");
            vaciarArchivo();
            printf("Archivo vaciado con exito.\n");
            system("pause");
            break;
            }

            case 0: {
            system("cls");
            printf("Saliendo...\n");
            system("pause");
            break;
            }
            default: {
            printf("ERROR opcion invalida, intente de nuevo.\n");
            system("pause");
            break;
            }
            }
    }while(opcion!=0);

    return 0;
}

void registrarViajes(int *primerViaje, float *primerGasto) {
struct Gastos g;
FILE *viajes = fopen("peajes.dat", "ab");
if(viajes == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}

while(1) {
        printf("\nIngrese el numero de camion del 1 al %d (o '0' para salir): ", maxCamion);
        if (scanf("%d", &g.Id_Camion) != 1) {
            while (getchar() != '\n');
            g.Id_Camion = -1;
        }
        if(*primerViaje == 0) {
            *primerViaje = g.Id_Camion;
        }

        if (g.Id_Camion == 0) {
            break;
        }

        printf("Ingrese el numero de zona del 1 al %d: ", maxZona);
        if (scanf("%d", &g.Zona_Ruta) != 1) {
            while (getchar() != '\n');
            g.Zona_Ruta = -1;
        }

        printf("Ingrese precio de peaje: ");
        if (scanf("%f", &g.Gasto_Peaje) != 1) {
            while (getchar() != '\n');
            g.Gasto_Peaje= -1;
        }
          if(*primerGasto == 0) {
            *primerGasto = g.Gasto_Peaje;
        }



        fwrite(&g, sizeof(struct Gastos), 1, viajes);
        printf(" -> Viaje guardado.\n");
    }
    fclose(viajes);
    printf("Volviendo al menu...\n");
    system("pause");
}
void matrizGastos(int *camionBarato, float *gastoBarato, int *primerViaje, float *primerGasto) {
struct Gastos g;
FILE *viajes = fopen("peajes.dat", "rb");
if(viajes == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
float matriz[maxCamion][maxZona] = {0};
   while(fread(&g, sizeof(struct Gastos), 1, viajes)) {
      int fila = g.Id_Camion - 1;
      int col = g.Zona_Ruta -1;
      if(fila >= 0 && fila < maxCamion && col >= 0 && col < maxZona){
            matriz[fila][col] = matriz[fila][col] + g.Gasto_Peaje;
      }
    }
    fclose(viajes);

    printf("--------------------------------------\n");
    printf("-------------- GASTOS ----------------\n");
    printf("--------------------------------------\n");
    printf("%-5s", " ");
    for(int c = 0; c < maxZona; c++) {
        printf("Z%d ", c + 1);
    }
    printf("\n");

    for(int f = 0; f < maxCamion; f++) {
        printf("C%d ", f + 1);
        for(int c=0; c < maxZona;c++) {
            printf("%.2f ",matriz[f][c]);
        }
        printf("\n");
    }
*gastoBarato = *primerGasto;
*camionBarato = *primerViaje;

    for(int f = 0; f < maxCamion; f++) {
        for(int c=0; c < maxZona;c++) {
                if(*gastoBarato > matriz[f][c] && matriz[f][c] > 0){
                    *gastoBarato = matriz[f][c];
                    *camionBarato = f + 1;
                }
        }
    }
}

void camionEconomico(int *camionBarato, float *gastoBarato){
printf("Camion con menos gastos: %d\n", *camionBarato);
printf("Gastos del camion: %.2f\n", *gastoBarato);
}

void rankingZonas(){
struct Gastos g;
int ordenado;
float gastos[maxZona] = {0};
float matriz[maxCamion][maxZona] = {0};
float auxZona=0;
char *zonas[] = {
   "CABA", "Sur",
   "Norte", "Oeste"
   };
   char aux[10];
FILE *viajes = fopen("peajes.dat", "rb");
if(viajes == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
while(fread(&g, sizeof(struct Gastos), 1, viajes)) {
      int fila = g.Id_Camion - 1;
      int col = g.Zona_Ruta -1;
      if(fila >= 0 && fila < maxCamion && col >= 0 && col < maxZona){
            matriz[fila][col] = matriz[fila][col] + g.Gasto_Peaje;
      }
    }
    fclose(viajes);
   for(int f=0; f<maxCamion;f++) {
    for(int c=0;c<maxZona;c++) {
        gastos[c] = gastos[c] + matriz[f][c];
    }
   }

   do {
        ordenado = 1;
   for(int c = 0; c<maxZona-1;c++) {
    if(gastos[c] > gastos[c+1]) {
        auxZona = gastos[c];
        gastos[c] = gastos[c+1];
        gastos[c+1] = auxZona;
        strcpy(aux, zonas[c]);
        strcpy(zonas[c],zonas[c+1]);
        strcpy(zonas[c+1],aux);
        ordenado = 0;
    }
   }
   }while(ordenado == 0);

   for(int c = 0; c<maxZona;c++)  {
    printf("Zona: %s", zonas[c]);
    printf("Ganancias Totales: %.2f", gastos[c]);
   }
}

void exportarCSV(){
FILE *viajes = fopen("peajes.dat", "rb");
if(viajes == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
FILE *archivo = fopen(" reporte_logistica.csv", "w");
float matriz[maxCamion][maxZona] = {0};
if (viajes != NULL && archivo != NULL) {

        for(int c = 0; c< maxZona; c++) {
            fprintf(archivo, "Zona%d",c);
        }
        for(int f = 0; f < maxCamion; f++) {
        fprintf(archivo, "Camion%d", f);
        for(int c=0; c < maxZona;c++) {
            fprintf(archivo, "%.2f",matriz[f][c]);
        }
        printf("\n");
    }

        fclose(viajes);
        fclose(archivo);

        printf("\n-> Exportado correctamente a ' reporte_logistica.csv'\n");

    } else {
        printf("ERROR: No se pudo abrir archivo\n");

        if (viajes != NULL) fclose(viajes);
        if (archivo != NULL) fclose(archivo);
    }
}

void vaciarArchivo() {
FILE *viajes;
viajes = fopen("peajes.dat", "wb");
fclose(viajes);
}
