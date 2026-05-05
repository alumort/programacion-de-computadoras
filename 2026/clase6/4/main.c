#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define maxFila 10
#define maxAsiento 5

struct Sala {
int fila;
int asiento;
int estado;
};
void guardarArchivo();
void imprimir();
void vaciarArchivo();
void asientosLibres(int *totalLibres);
int main()
{
    int opcion;
    int totalLibres = 0;
do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Cine     %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Asientos Vacios.\n");
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
            asientosLibres(&totalLibres);
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
        struct Sala s;
    FILE *asientos;
    asientos = fopen("reservas.dat", "ab");
    if(asientos == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de fila del 1 al %d (o '0' para salir): ", maxFila);
        if (scanf("%d", &s.fila) != 1) {
            while (getchar() != '\n');
            s.fila = -1;
        }
        if (s.fila == 0) {
            break;
        }

        printf("Ingrese el numero de asiento del 1 al %d: ", maxAsiento);
        if (scanf("%d", &s.asiento) != 1) {
            while (getchar() != '\n');
            s.asiento = -1;
        }

        printf("Ingrese el estado: 0 = Vacio, 1 = Ocupado: " );
        if (scanf("%d", &s.estado) != 1) {
            while (getchar() != '\n');
            s.estado = -1;
        }


        fwrite(&s, sizeof(struct Sala), 1, asientos);
        printf(" -> Reserva guardada.\n");
    }
  fclose(asientos);
  printf("\n Volviendo al menu...\n");
system("pause");
}

void imprimir() {
    struct Sala s;
    FILE *asientos;
    int matriz[maxFila][maxAsiento] = {0};
    asientos = fopen("reservas.dat", "rb");
    if(asientos == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

 while(fread(&s, sizeof(struct Sala), 1, asientos)) {
      int fila = s.fila - 1;
      int col = s.asiento -1;
      if(fila >= 0 && fila < maxFila && col >= 0 && col < maxAsiento){
            matriz[fila][col] = s.estado;
      }
    }
          fclose(asientos);
    printf("---------------------------------------\n");
    printf("-----------LAYOUT DE LA SALA-----------\n");
    printf("---------------------------------------\n");
     printf("%-8s", " ");
    for(int t = 0; t < maxAsiento; t++) {
        printf("|A%d ", t + 1);
    }
    printf("\n");
    for(int l = 0; l < maxFila; l++) {
        printf("Fila %-4d", l + 1);

        for(int t = 0; t < maxAsiento; t++) {
                if(matriz[l][t] == 0) {
                    printf("[ ] ");
                } else if(matriz[l][t] == 1) {

                printf("[X] ");}

        } printf("\n");
    }
    printf("--------------------------------------------------\n");


          }

void asientosLibres(int *totalLibres) {
    struct Sala s;
    FILE *asientos;
    *totalLibres = 0;
       int matriz[maxFila][maxAsiento] = {0};
    asientos = fopen("reservas.dat", "rb");
    if(asientos == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }
     while(fread(&s, sizeof(struct Sala), 1, asientos)) {
      int fila = s.fila - 1;
      int col = s.asiento -1;
      if(fila >= 0 && fila < maxFila && col >= 0 && col < maxAsiento){
            matriz[fila][col] = s.estado;
      }
    }
          fclose(asientos);
          for(int f=0; f<maxFila;f++) {
            for(int c=0; c<maxAsiento;c++) {
                if(matriz[f][c] == 0) {
                    (*totalLibres)++;
                }
            }
          }
          printf("La cantidad de asientos libres es de %d\n", *totalLibres);
          printf("Volviendo al menu...\n");
}

void vaciarArchivo() {
FILE *asientos;
asientos = fopen("reservas.dat", "wb");
fclose(asientos);
}

