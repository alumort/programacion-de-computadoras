#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Envio {
    int codigoTracking;
    char direccion[20];
    float distanciaKm;
    int estado;
};

void ordenarKilometros(struct Envio vector[], int tamanio);
void entregarPaquete(struct Envio* n);


int main()
{
    struct Envio tareas[5] = {
    {123, "Maipu 300", 7.3, 0},
    {345, "Alsina 1200", 6.5, 0},
    {567, "Salta 105", 1.2, 0},
    {789, "Caguazu 10", 3.4, 0},
    {901, "Darrageira 402", 7.6, 0}
    };

    int opcion;
    int envioBuscado;
    int envioEncontrado = -1;
    int tamanio = 5;
    float kmRecorrido = 0;
    do {
    printf("-----------------------------\n");
    printf("-----Rutas de Envios App-----\n");
    printf("Seleccione una opcion:\n");
    printf("1. Hoja de Ruta Optima.\n");
    printf("2. Entregar Paquete.\n");
    printf("3.Resumen.\n");
    printf("0.Salir.\n");
    printf("-----------------------------\n");
    scanf("%d", &opcion);

    switch(opcion) {

    case 1: {
    printf("Ordenando los envios no enviados de menor a mayor distancia...\n");
    ordenarKilometros(tareas, tamanio);
    printf("--- RUTA OPTIMIZADA ---\n");
    printf("%-5s %-20s %-5s\n", "cod", "direccion", "Km");
    printf("-----------------------------\n");
     for (int i = 0; i < tamanio; i++) {
            if(tareas[i].estado == 0) {
                printf("%-5d %-20s %-5.2f\n", tareas[i].codigoTracking, tareas[i].direccion, tareas[i].distanciaKm);
            }

    }
    break;}

    case 2: {
     do { printf("Ingrese el numero del envio que quiere marcar como enviado:\n");
        scanf("%d", &envioBuscado);
        envioEncontrado = -1;
        for (int i = 0; i <tamanio; i++) {
        if(tareas[i].codigoTracking == envioBuscado) {
            envioEncontrado = i;

            break;
        }}
        if (envioEncontrado == -1) {
            printf("No se ha encontrado el envio. Intente de nuevo.");
        }

    } while(envioEncontrado == -1);
                entregarPaquete(&tareas[envioEncontrado]);
    break;}

    case 3: {
    printf("Calculando los kilometros recorridos...\n");
    for (int i = 0; i < tamanio; i++) {
        if(tareas[i].estado == 1) {
            kmRecorrido = kmRecorrido + tareas[i].distanciaKm;
        }
    }
    printf("La distancia recorrida hasta ahora es de: %f", kmRecorrido);
    break;}

    case 0: {

    break;}

    default: {
    printf("ERROR opcion invalida.\n");
    break;
    }

    }

    } while (opcion != 0);
    return 0;
}


void ordenarKilometros(struct Envio vector[], int tamanio) {
    struct Envio aux;
    int ordenado;
 do {
        ordenado = 1;
 for(int i = 0; i < tamanio -1; i++){
    if(vector[i].distanciaKm > vector[i+1].distanciaKm) {
        aux = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = aux;
        ordenado = 0;
    }
 }

 } while(ordenado == 0);



}
void entregarPaquete(struct Envio* n) {
n -> estado = 1;
printf("Estado cambiado con exito.\n");

}

