#include <stdio.h>
#include <stdlib.h>


struct Vuelo {
int numeroVuelo;
char destino[25];
int capacidadMax;
int asientosOcupados;
float precio;
float ganancias;
};

int leerEntero();
void ordenarVuelos(struct Vuelo vector[], int tamanio);
void venderPasaje (struct Vuelo* n);
void exportarCsv(struct Vuelo vector[], int tamanio);
int main()
{
    struct Vuelo viajes[5] = {
    {12345, "Brasil", 50, 25, 2000.2, 0},
    {54354, "Noruega", 120, 31, 10000.4, 0},
    {11111, "Canada", 210, 100, 7000.9, 0},
    {22214, "Chile", 72, 40, 1500.1, 0},
    {33331, "Alemania", 120, 80, 9400.5, 0}
    };
    int opcion;
    int tamanio = 5;
    int vueloPedido;
    int vueloEncontrado = -1;

    do {
            printf("-----------------------------------\n");
            printf("-------Sistema de Aeroparque-------\n");
            printf("1. Ver Panel de Vuelos.\n");
            printf("2. Vender Pasaje.\n");
            printf("3. Exportar Cierre del Dia y Salir\n");
            printf("-----------------------------------\n");
            printf("Elija una opcion.\n");
            opcion = leerEntero();
            switch(opcion) {

            case 1: {
                ordenarVuelos(viajes, tamanio);
                printf("---- Vuelos existentes ----\n");
                printf("%-5s %-25s %-5s %-5s %-5s\n", "num", "destino", "a max","a ocu", "$$", "total$");
                printf("-----------------------------------\n");
                for (int i = 0; i < tamanio; i++) {
                    printf("%-5d %-25s %-5d %-5d %-5.2f %-5.2f\n", viajes[i].numeroVuelo,
                                                    viajes[i].destino,
                                                    viajes[i].capacidadMax,
                                                    viajes[i].asientosOcupados,
                                                    viajes[i].precio,
                                                    viajes[i].ganancias);
                }
            break;}

            case 2: {
                do {
                  printf("Ingrese el numero de vuelo cuyo pasaje quiere vender.\n");
                vueloPedido = leerEntero();
                for(int i = 0; i < tamanio; i++) {
                    if(viajes[i].numeroVuelo == vueloPedido) {
                        vueloEncontrado = i;
                        break;
                    }
                } if (vueloEncontrado == -1) {
                printf("Vuelo no encontrado. Intentelo de nuevo.\n");
                }
                } while(vueloEncontrado == -1);
                venderPasaje(&viajes[vueloEncontrado]);
                vueloEncontrado = -1;

            break;}

            case 3: {
                printf("Exportando base de datos, por favor espere...\n");
                exportarCsv(viajes, tamanio);
                printf("Exportado con exito!\n");
                printf("Saliendo...\n");

            break;}
            default: {
            printf("ERROR opcion invalida, intente de nuevo.\n");
            break;
            }
            }

    } while(opcion != 3);

    return 0;
}
int leerEntero() {
    int x;
    int resultado;

    while (1) {
        resultado = scanf("%d", &x);

        if (resultado == 1) {
            while (getchar() != '\n');
            return x;

        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }
}

void ordenarVuelos(struct Vuelo vector[], int tamanio){
struct Vuelo aux;
int ordenado;
do {
        ordenado = 1;
    for(int i = 0; i < tamanio - 1; i++){
    if((vector[i].capacidadMax - vector[i].asientosOcupados) < (vector[i+1].capacidadMax - vector[i+1].asientosOcupados)) {
        aux = vector[i];
        vector[i] = vector[i+1];
        vector[i+1] = aux;
        ordenado = 0;
    }}
} while(ordenado == 0);
}

void venderPasaje(struct Vuelo* n) {
    int cantidadPasajes;
    float gananciasVenta;
    if(n ->capacidadMax == n ->asientosOcupados) {
        printf("Todos los asientos de este vuelo estan ocupados.\n");
        return;
    } else {
        printf("Cuantos pasajes quiere vender?\n");
        cantidadPasajes = leerEntero();
        if (n -> capacidadMax < n -> asientosOcupados + cantidadPasajes) {
            printf("ERROR. Se excede la capacidad maxima con esa cantidad de pasajes.\n");
            n -> asientosOcupados = n->asientosOcupados - cantidadPasajes;
            n -> ganancias += n-> ganancias - (n->precio * cantidadPasajes);
            gananciasVenta = 0;
            return;
        }
        n -> asientosOcupados += cantidadPasajes;
        gananciasVenta = n-> precio * cantidadPasajes;
        n->ganancias+=gananciasVenta;
    }

    FILE *ventas;
    ventas = fopen("ventas_log.txt", "a");
    if (ventas != NULL) {
       fprintf(ventas, "Pasajes vendido - Vuelo %d a %s, ganancias de la venta %.2f, ganancias totales %.2f\n", n -> numeroVuelo, n->destino, gananciasVenta,n->ganancias);
       fclose(ventas);
       printf("Pasaje vendido con exito.\n");
    } else {
         printf("No se pudo crear el archivo, intentelo de nuevo.\n");
    }
        gananciasVenta = 0;


}

void exportarCsv(struct Vuelo vector[], int tamanio) {
FILE *viajes;
viajes = fopen("reporte_diario.csv", "w");
if (viajes != NULL) {
        fprintf(viajes, "NumeroVuelo;Destino;AsientosMaximos;AsientosOcupados;Precio;Ganancias\n");
for (int i = 0; i < tamanio; i++) {
    fprintf(viajes, "%d;%s;%i;%i;%.2f;%.2f\n", vector[i].numeroVuelo,
            vector[i].destino,
            vector[i].capacidadMax,
            vector[i].asientosOcupados,
            vector[i].precio,
            vector[i].ganancias);
}
}
fclose(viajes);
}
