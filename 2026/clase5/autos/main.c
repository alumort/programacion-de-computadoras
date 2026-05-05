#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>



struct Vehiculo {
char patente[10];
char marca[20];
int anio;
int dniTitular;
};

void simuladorCarga(const char* mensaje);
void inicializar(struct Vehiculo v[], int tam);
void ordenar(struct Vehiculo vector[], int tamanio);
void cargarDesdeArchivo(struct Vehiculo v[], int tam);
void guardar(struct Vehiculo v[], int tam);
void transferir(struct Vehiculo* v, int dni);
int main()
{
    struct Vehiculo autos[3];
    int tamanio = 3;
    int opcion;
    int dni;
    char patentePedida[10];
    int patenteEncontrada = -1;
cargarDesdeArchivo(autos, tamanio);
    system("pause");
    system("color 0D");
   do {
        system("cls");
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c AUTOMOTORES %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Ver Padron.\n");
            printf("2. Transferencia.\n");
            printf("0. Guardar y Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;
        }
        switch(opcion) {

            case 1: {
                system("cls");
            ordenar(autos, tamanio);
            printf(" -------------------------- Autos --------------------------\n");
            printf("%-20s %-20s %-5s %-10s \n", "patente", "marca", "anio","dniTitu");
            printf("------------------------------------------------------------\n");
            for(int i = 0; i < tamanio; i++) {
                printf("%-20s %-20s %-5d %-10d \n", autos[i].patente,
                                                    autos[i].marca,
                                                    autos[i].anio,
                                                    autos[i].dniTitular);
            }
            system("pause");
            break;
            }

            case 2:
                { system("cls");
                    do {
                    printf("Ingrese la patente del auto a transferir.\n");
                    while(getchar() != '\n');
        fgets(patentePedida, sizeof(patentePedida), stdin);
        patentePedida[strcspn(patentePedida, "\n")] = 0;
                    for (int i = 0; i < tamanio; i++) {
                        if(strcmp(autos[i].patente, patentePedida) == 0) {
                            patenteEncontrada = i;
                            break;
                        }
                    } if (patenteEncontrada == -1) {
                    printf("No se pudo encontrar la patente, intente otra vez.\n");} else {
                    do {
    printf("Ingrese el dni del nuevo titular:\n");
    if (scanf("%d", &dni) != 1) {
        while (getchar() != '\n');
        dni = -1;
        printf("DNI invalido. Intente de nuevo.\n");
    }
} while (dni == -1);}
                } while (patenteEncontrada == -1);
                transferir(&autos[patenteEncontrada], dni);
                printf("Transferencia de titular realizada con exito.\n");
                patenteEncontrada = -1;
                    system("pause");
                    break;
                }
    case 0:{
        system("cls");
        simuladorCarga("Guardando");
        guardar(autos, tamanio);
        printf("Guardado con exito. Saliendo...\n");
        system("pause");
        break;}

    default: {
        system("cls");
    printf("ERROR: opcion invalida, intente de nuevo.\n");
    system("pause");
    break;}}


   } while (opcion != 0);
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



void ordenar(struct Vehiculo vector[], int tamanio) {
struct Vehiculo aux;
int ordenado;
do {
        ordenado = 1;
    for(int i = 0; i < tamanio - 1; i++){
    if(vector[i].anio < vector[i+1].anio) {
        aux = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = aux;
        ordenado = 0;
    }}
} while(ordenado == 0);

}

void inicializar(struct Vehiculo v[], int tam) {
    for (int i = 0; i < tam; i++) {
strcpy(v[i].patente, "");
strcpy(v[i].marca, "");
        v[i].anio = -1;
        v[i].dniTitular = -1;

    }

strcpy(v[0].patente, "123Alu56");
strcpy(v[0].marca, "Ford fiesta");
    v[0].anio = 2004;
    v[0].dniTitular = 45304245;

    strcpy(v[1].patente, "765Pan15");
    strcpy(v[1].marca, "Ecosport");
    v[1].anio = 2005;
    v[1].dniTitular = 44235012;

    strcpy(v[2].patente, "890Pom12");
    strcpy(v[2].marca, "Chevrolet");
    v[2].anio = 2006;
    v[2].dniTitular = 47801840;
}


void cargarDesdeArchivo(struct Vehiculo v[], int tam) {
    FILE *f = fopen("parque_automotor.dat", "rb");

    if (f != NULL) {
        fread(v, sizeof(struct Vehiculo), tam, f);
        fclose(f);
        printf("Archivo cargado correctamente.\n");
    } else {
        printf("Archivo no existe. Inicializando...\n");
        inicializar(v, tam);

        f = fopen("parque_automotor.dat", "wb");
        if (f != NULL) {
            fwrite(v, sizeof(struct Vehiculo), tam, f);
            fclose(f);
        }
    }
}


void guardar(struct Vehiculo v[], int tam) {
            FILE *f;
            f = fopen("parque_automotor.dat", "wb");
        if (f != NULL) {
            fwrite(v, sizeof(struct Vehiculo), tam, f);
            fclose(f);
        }}

void transferir (struct Vehiculo* v, int dni) {
    v->dniTitular = dni;
}
