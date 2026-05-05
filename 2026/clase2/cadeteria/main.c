#include <stdio.h>
#include <stdlib.h>

struct Tramite {
    int numeroExpediente;
    char destino[30];
    int estado;
};

void cambiarEstado (struct Tramite* punteroEnviado);
int main()
{
    struct Tramite envios[4] = {

    {1234, "Temperley", 0},
    {4321, "Lanus", 0},
    {2314, "Banfield", 0},
    {3421, "Quilmes", 0}
    };
    int opcion;
    int expedienteBuscado;
    int expedienteEncontrado = -1;

do {
    printf("------------------------------\n");
    printf("--- SISTEMA DE CADETERIA ---\n");
    printf("Seleccione una opcion:\n");
    printf("1. Ver tramites pendientes.\n");
    printf("2. Marcar como entregado.\n");
    printf("0. Salir\n");
    printf("------------------------------\n");
    scanf("%d", &opcion);
    switch(opcion){
    case 1: {
    for (int i = 0; i < 4; i++) {
        printf("Numero de expediente: %d \n", envios[i].numeroExpediente);
        printf("Destino: %s \n", envios[i].destino);
        printf("Estado (0 no enviado, 1 enviado): %d \n", envios[i].estado);
    }
    break;
    }

    case 2: {
   do { printf("Ingrese el numero del expediente que quiere marcar como enviado:\n");
        scanf("%d", &expedienteBuscado);
        expedienteEncontrado = -1;
        for (int i = 0; i <4; i++) {
        if(envios[i].numeroExpediente == expedienteBuscado) {
            expedienteEncontrado = i;

            break;
        }}
        if (expedienteEncontrado == -1) {
            printf("No se ha encontrado el expediente. Intente de nuevo.");
        }

    } while(expedienteEncontrado == -1);
                cambiarEstado(&envios[expedienteEncontrado]);
    break;
    }
    case 0: {
    printf("Cerrando programa...");
    break;
    }
    default: {
    printf("ERROR! Opcion invalida");
    break;
    }
}} while(opcion != 0);
    return 0;
}

void cambiarEstado(struct Tramite* punteroEnviado) {
    punteroEnviado->estado = punteroEnviado -> estado = 1;
    printf("Estado cambiado con exito.");

}
