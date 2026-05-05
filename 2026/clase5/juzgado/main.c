#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


struct Expediente {
int numero;
int juzgado;
int estado;
};
void simuladorCarga(const char* mensaje);
void cargarDesdeArchivo(struct Expediente v[], int tam);
void bajaLogica(struct Expediente* c);
void reactivarExpediente(struct Expediente* c);
void guardar(struct Expediente v[], int tam);
int main()
{
    int opcion;
    int tamanio = 5;
    int expedienteBuscadoBaja;
    int expedienteEncontradoBaja = -1;
    int expedienteBuscadoReactivar;
    int expedienteEncontradoReactivar = -1;


    struct Expediente casos[5];
    cargarDesdeArchivo(casos, tamanio);
    system("pause");
    system("color 0B");

 do {
     system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c   JUZGADO   %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Ver Activos.\n");
            printf("2. Archivar.\n");
            printf("3. Nueva Causa.\n");
            printf("4. Reactivar.\n");
            printf("5. Auditoria.\n");
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
                printf("%-5s %-15s %-5s\n", "num", "juzgado", "estado");
                for(int i = 0; i < tamanio; i++){
                    if(casos[i].estado == 1) {
                        printf("%-5d %-15d %-5d\n", casos[i].numero,
                                                  casos[i].juzgado,
                                                  casos[i].estado);
                    }

                }
                system("pause");
            break;}

            case 2: {
                system("cls");
                int encontrado = 0;
            do {
    expedienteEncontradoBaja = -1;

    printf("Ingrese el numero de expediente a archivar:\n");

    if (scanf("%d", &expedienteBuscadoBaja) != 1) {
        while (getchar() != '\n');
        continue;
    }

    for(int i = 0; i < tamanio; i++) {
        if(casos[i].numero == expedienteBuscadoBaja) {
            expedienteEncontradoBaja = i;
            break;
        }
    }

    if (expedienteEncontradoBaja == -1) {
        printf("No encontrado.\n");
    }

} while(expedienteEncontradoBaja == -1);
            bajaLogica(&casos[expedienteEncontradoBaja]);
            expedienteEncontradoBaja = -1;
                system("pause");

            break;
            }

            case 3: {
                 system("cls");
                 int agregado = 0;
                 for(int i = 0; i < tamanio; i++) {
                    if(casos[i].estado == -1) {
                        printf("Ingrese el numero de caso.\n");
                                   if (scanf("%d", &casos[i].numero) != 1) {
            while (getchar() != '\n');
            casos[i].numero = -1;
        }
        printf("Ingrese el juzgado del caso.\n");
                   if (scanf("%d", &casos[i].juzgado) != 1) {
            while (getchar() != '\n');
            casos[i].juzgado = -1;
        }
        casos[i].estado = 1;
        agregado = 1;
                        break;
                    }
                } if(!agregado) {
                printf("No hay espacio disponible.\n");}




            system("pause");

            break;}

            case 4: {
   system("cls");
   int encontrado = 0;
   do{
                  printf("Ingrese el numero de expediente a reactivar.\n");
                if (scanf("%d", &expedienteBuscadoReactivar != 1)) {
                                while (getchar() != '\n');
                                expedienteBuscadoReactivar = -1;
                }
                for(int i = 0; i < tamanio; i++) {
                    if(casos[i].numero == expedienteBuscadoReactivar) {
                        expedienteEncontradoReactivar = i;
                        encontrado = 1;
                        break;
                    }
                } if (encontrado == 0) {
                    printf("Expediente no encontrado. Intentelo de nuevo.\n");
                }
                 encontrado = 0;

            }while(expedienteEncontradoReactivar == -1);
            reactivarExpediente(&casos[expedienteEncontradoReactivar]);
            expedienteEncontradoReactivar = -1;

            system("pause");

            break;}

            case 5: {
            system("cls");

             printf("%-5s %-15s %-5s\n", "num", "juzgado", "estado");
                for(int i = 0; i < tamanio; i++) {
                        printf("%-5d %-15d %-5d\n", casos[i].numero,
                                                  casos[i].juzgado,
                                                  casos[i].estado);
                }
            system("pause");
            break;}

            case 0: {
                system("cls");
            simuladorCarga("Guardando");
            guardar(casos, tamanio);
            printf("Guardado con exito. Saliendo...\n");
            break;}

            default: {
            system("cls");
            printf("ERROR\n");
            break;
            }
            }

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


void inicializar(struct Expediente v[], int tam) {
    for (int i = 0; i < tam; i++) {
        v[i].numero = -1;
        v[i].juzgado = -1;
        v[i].estado = -1;
    }

    v[0].numero = 123;
    v[0].juzgado = 20;
    v[0].estado = 1;

    v[1].numero = 456;
    v[1].juzgado = 21;
    v[1].estado = 1;
}

void guardar(struct Expediente v[], int tam) {
            FILE *f;
            f = fopen("expedientes.dat", "wb");
        if (f != NULL) {
            fwrite(v, sizeof(struct Expediente), tam, f);
            fclose(f);
        }}

void cargarDesdeArchivo(struct Expediente v[], int tam) {
    FILE *f = fopen("expedientes.dat", "rb");

    if (f != NULL) {
        fread(v, sizeof(struct Expediente), tam, f);
        fclose(f);
        printf("Archivo cargado correctamente.\n");
    } else {
        printf("Archivo no existe. Inicializando...\n");
        inicializar(v, tam);

        f = fopen("expedientes.dat", "wb");
        if (f != NULL) {
            fwrite(v, sizeof(struct Expediente), tam, f);
            fclose(f);
        }
    }
}

void bajaLogica(struct Expediente* c) {
if (c -> estado == 0) {
    printf("Error: El expediente ya esta archivado.\n");
} else {
    c -> estado = 0;
}
}

void reactivarExpediente(struct Expediente* c){
if (c -> estado == 1) {
    printf("Error: El expediente ya esta activo.\n");
} else {
c -> estado = 1;
}
}

