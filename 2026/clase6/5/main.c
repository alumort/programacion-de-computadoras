#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define maxLinea 3
#define maxEstacion 5

struct Viajes {
int linea;
int estacion;
int pasajeros;
};
void guardarArchivo();
void imprimir();
void pasajerosLinea();
void vaciarArchivo();

int main()
{
    int opcion;

do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c   Subte     %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Total Pasajers por Linea.\n");
            printf("4. Vaciar Archivo.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;}
            switch(opcion) {
            case 1: {
            system("cls");
            guardarArchivo();
            system("pause");
            break;
            }

            case 2: {
            system("cls");
            imprimir();
            system("pause");
            break;
            }

            case 3: {
            system("cls");
            pasajerosLinea();
            system("pause");
            break;
            }
            case 4: {
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
            printf("ERROR: opcion invalida. Intente de nuevo.\n");
            system("pause");
            break;
            }
            }}while(opcion != 0);
    return 0;
}

void guardarArchivo() {
    struct Viajes v;
    FILE *registro;
    registro = fopen("molinetes.dat", "ab");
    if(registro == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de linea de subte del 1 al %d (o '0' para salir): ", maxLinea);
        if (scanf("%d", &v.linea) != 1) {
            while (getchar() != '\n');
            v.linea = -1;
        }
        if (v.linea == 0) {
            break;
        }

        printf("Ingrese el numero de estacion del 1 al %d: ", maxEstacion);
        if (scanf("%d", &v.estacion) != 1) {
            while (getchar() != '\n');
            v.estacion = -1;
        }

        printf("Ingrese cantidad de pasajeros: ");
        if (scanf("%d", &v.pasajeros) != 1) {
            while (getchar() != '\n');
            v.pasajeros = -1;
        }


        fwrite(&v, sizeof(struct Viajes), 1, registro);
        printf(" -> Registro guardado.\n");
    }


  fclose(registro);
  printf("\nVolviendo al menu...\n");
system("pause");

}
void imprimir() {
struct Viajes v;
FILE *registro = fopen("molinetes.dat", "rb");
int matriz[maxLinea][maxEstacion] = {0};
 if(registro == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }
        while(fread(&v, sizeof(struct Viajes), 1, registro)) {
      int fila = v.linea - 1;
      int col = v.estacion -1;
      if(fila >= 0 && fila < maxLinea && col >= 0 && col < maxEstacion){
            matriz[fila][col] = v.pasajeros;
      }
    }
          fclose(registro);

    printf("---------------------------------------\n");
    printf("-----------INFORME DE VIAJES-----------\n");
    printf("---------------------------------------\n");
     printf("%-7s", " ");
    for(int t = 0; t < maxEstacion; t++) {
        printf("|E%d", t + 1);
    }
    printf("\n");

    for(int l = 0; l < maxLinea; l++) {
        printf("Linea %d", l +1);
        for(int t = 0; t<maxEstacion; t++) {
            printf(" %d ", matriz[l][t]);
        }
        printf("\n");
    }
}

void pasajerosLinea() {
struct Viajes v;
FILE *registro = fopen("molinetes.dat", "rb");
int matriz[maxLinea][maxEstacion] = {0};
int totalLinea[maxLinea]={0};
 if(registro == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }
        while(fread(&v, sizeof(struct Viajes), 1, registro)) {
      int fila = v.linea - 1;
      int col = v.estacion -1;
      if(fila >= 0 && fila < maxLinea && col >= 0 && col < maxEstacion){
            matriz[fila][col] = v.pasajeros;
      }
    }
          fclose(registro);
          for(int f = 0; f < maxLinea; f++) {
    for(int c = 0; c < maxEstacion; c++) {
        totalLinea[f] = totalLinea[f] + matriz[f][c];
    }
}
for(int f = 0; f < maxLinea; f++) {
    printf("Cantidad total de pasajeros de la linea %d : %d \n", f + 1, totalLinea[f]);

}

}





void vaciarArchivo() {
FILE *registro;
registro = fopen("molinetes.dat", "wb");
fclose(registro);
}
