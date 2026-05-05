#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define maxZona 4
#define maxTurno 3

struct Servicio {
int zona;
int turno;
float temperatura_registrada;
};
void cargarArchivo();
void imprimir();
void minimo();
void vaciarArchivo();

int main()
{
    int tempMinima = 0;
    int opcion;

     do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Clima    %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Temperatura Minima.\n");
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
            cargarArchivo();
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
            minimo();
            system("pause");
            break;
            }

            case 4: {
            system("cls");
            vaciarArchivo();
            printf("Archivo vaciado con exito.\n");
            break;
            }
            case 0: {
            system("cls");
            printf("Saliendo...\n");
            system("pause");
            break;}

            default: {
            printf("ERROR: opcion invalida, intente de nuevo.\n");
            system("pause");
            break;
            }
            }
            }while(opcion!=0);
    return 0;
}

void cargarArchivo() {
    struct Servicio s;
    FILE *clima = fopen("clima.dat", "ab");
    if(clima == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de zona del 1 al %d (o '0' para salir): ", maxZona);
        if (scanf("%d", &s.zona) != 1) {
            while (getchar() != '\n');
            s.zona = -1;
        }
        if (s.zona == 0) {
            break;
        }

        printf("Ingrese el numero de turno del 1 al %d: ", maxTurno);
        if (scanf("%d", &s.turno) != 1) {
            while (getchar() != '\n');
            s.turno = -1;
        }

        printf("Ingrese la temperatura registrada: ");
        if (scanf("%f", &s.temperatura_registrada) != 1) {
            while (getchar() != '\n');
            s.temperatura_registrada = -1;
        }


        fwrite(&s, sizeof(struct Servicio), 1, clima);
        printf(" -> Temperatura guardada.\n");
    }


  fclose(clima);
  printf("\nVolviendo al menu...\n");
system("pause");
}

void imprimir() {
struct Servicio s;
FILE *clima = fopen("clima.dat", "rb");
float matriz[maxZona][maxTurno] = {0};
if(clima == NULL) {
    printf("No se pudo abrir el archivo, intente de nuevo.\n");
    system("pause");
    return;
}
while(fread(&s, sizeof(struct Servicio), 1, clima)) {
    int fila = s.zona - 1;
    int col = s.turno -1;
    if(fila >= 0 && fila <maxZona && col >= 0 && col <maxTurno) {
       matriz[fila][col] = s.temperatura_registrada;
    }
}
fclose(clima);

printf("---------------------------------------\n");
    printf("-----------INFORME CLIMATICO-----------\n");
    printf("---------------------------------------\n");
     printf("%-5s", " ");
    for(int t = 0; t < maxTurno; t++) {
        printf("|Tur%d ", t + 1);
    }
    printf("\n");

    for(int z = 0; z<maxZona; z++) {
        printf("Zona %d", z+1);
        for(int t=0;t<maxTurno;t++) {
            printf(" %.2f ", matriz[z][t]);
        }
        printf("\n");
    }
}

void minimo() {
struct Servicio s;

FILE *clima = fopen("clima.dat", "rb");
float matriz[maxZona][maxTurno] = {0};
if(clima == NULL) {
    printf("No se pudo abrir el archivo, intente de nuevo.\n");
    system("pause");
    return;
}
while(fread(&s, sizeof(struct Servicio), 1, clima)) {
    int fila = s.zona - 1;
    int col = s.turno -1;
    if(fila >= 0 && fila <maxZona && col >= 0 && col <maxTurno) {
       matriz[fila][col] = s.temperatura_registrada;
    }
}
fclose(clima);
char *zonas[] = {
"Norte", "Sur",
"Este", "Oeste"
};
char *turnos[] = {
"Maniana", "Tarde",
"Noche"
};
float tempMinima = 100;
int turno = 0;
int zona = 0;
for(int f = 0; f<maxZona; f++) {
    for(int c = 0; c<maxTurno;c++) {
        if(matriz[f][c] < tempMinima) {
            tempMinima = matriz[f][c];
            turno = c;
            zona = f;
        }
    }
}
printf("La temperatura minima fue de %.2f, registrada en la zona %s, turno %s\n", tempMinima, zonas[zona], turnos[turno]);
}






void vaciarArchivo() {
FILE *clima = fopen("clima.dat", "wb");
fclose(clima);
}
