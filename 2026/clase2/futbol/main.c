#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Equipo {
    int id;
    char nombre[20];
    int puntos;
    int partidasJugadas;
};

void ordenarPosiciones (struct Equipo vector[], int tamanio);
void registrarResultado (struct Equipo vector[]);
void registrarVictoria(struct Equipo* punteroVictoria);
void registrarDerrota(struct Equipo* punteroDerrota);
void verEstadisticas (struct Equipo vector[]);
float calcularEfectividad(struct Equipo* n);

int main()
{

struct Equipo grupos[5] = {

    {1, "Evanescencia", 0, 0},
    {2, "Los Colmenas", 0, 0},
    {3, "Una Direccion", 0, 0 },
    {4, "Mi Romance Quimico", 0, 0},
    {5, "Panico! En el disco", 0, 0}
};

int opcion;
int tamanio = 5;

do {
    printf("-----------------------------------------\n");
    printf("----SISTEMA DE SEGUIMIENTO DE ESPORTS----\n");
    printf("Seleccione una opcion:\n");
    printf("1. Ver Tabla de Posiciones. \n");
    printf("2. Registrar Resultado de Partida.\n");
    printf("3. Ver Estadisticas de un Equipo.\n");
    printf("-----------------------------------------\n");
    scanf("%d", &opcion);

        switch(opcion) {

            case 1: {
        ordenarPosiciones(grupos, tamanio);
        printf("----TABLA DE POSICIONES----");
        printf("%-5s %-20s %-5s %-5s\n", "ID", "Equipo", "Pts", "Pj");
        printf("----------------------------------------\n");
        for (int i = 0; i < 5; i++) {
                printf("%-5d %-20s %-5d %-5d\n", grupos[i].id, grupos[i].nombre, grupos[i].puntos, grupos[i].partidasJugadas);
    }
            break;}

            case 2: {
            registrarResultado(grupos);
            registrarVictoria(&grupos[ganadorEncontrado]);
            registrarDerrota(&grupos[perdedorEncontrado]);
            break;}

            case 3: {
                int idEncontrado = -1;
                int idPedido = 0;
    do {
         printf("Ingrese el ID del equipo cuyas estadisticas quiere ver:\n");
    scanf("%d", idPedido);
        for (int i = 0; i <4; i++) {
        if(vector[i].id == idPedido) {
            idEncontrado = i;
            break;
        }}
        if (indiceEncontrado != -1) {
                printf("\n--- ESTADISTICAS DE %s ---\n", grupos[indiceEncontrado].nombre);
                printf("Puntos Totales: %d | Partidas Jugadas: %d\n", grupos[indiceEncontrado].puntos, grupos[indiceEncontrado].partidasJugadas);
                float efectividad = calcularEfectividad(&liga[indiceEncontrado]);
                printf("Efectividad (Pts por partido): %.2f\n", efectividad);}
        if (idEncontrado == -1) {
            printf("No se ha encontrado el equipo. Intente de nuevo.");
        }
} while (idEncontrado == -1);
    float efectividad = calcularEfectividad(&grupos[idEncontrado]);
    printf("La efectividad del equipo %s es de %f",)
            break;}

            case 0: {
            printf("Cerrando programa...");
            break;}

            default: {
            printf("ERROR: Opcion no valida. Intente otra vez.");
            break;}
    }

} while(opcion != 0);
    return 0;
}

void ordenarPosiciones(struct Equipo vector[], int tamanio) {
    struct Equipo aux;
    int ordenado;
        do {
        ordenado = 1;
        for (int j = 0; j < tamanio - 1; j++) {
            if (vector[j].puntos < vector[j + 1].puntos) {
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
                ordenado = 0;
            }
        }
    } while (ordenado == 0);
}

void registrarVictoria(struct Equipo* punteroVictoria) {
punteroVictoria -> puntos = punteroVictoria -> puntos + 3;
punteroVictoria -> partidasJugadas = punteroVictoria -> partidasJugadas + 1;
}

void registrarDerrota(struct Equipo* punteroDerrota) {
punteroDerrota -> puntos = punteroDerrota -> puntos + 0;
punteroDerrota -> partidasJugadas = punteroDerrota -> partidasJugadas + 1;
}

void registrarResultado(struct Equipo vector[]) {
    int ganador, perdedor, ganadorEncontrado, perdedorEncontrado;
    ganador = 0;
    perdedor = 0;
    ganadorEncontrado = -1;
    perdedorEncontrado = -1;

    do {
        printf("Ingrese el ID del equipo ganador\n");
        scanf("%d", ganador);
        for (int i = 0; i <4; i++) {
        if(vector[i].id == ganador) {
            ganadorEncontrado = i;

            break;
        }}
        if (ganadorEncontrado == -1) {
            printf("No se ha encontrado el equipo. Intente de nuevo.");
        }
            printf("Ingrese el ID del equipo perdedor\n");
        scanf("%d", perdedor);
        for (int i = 0; i <4; i++) {
        if(vector[i].id == perdedor) {
            perdedorEncontrado = i;
            break;
        }}
        if (perdedorEncontrado == -1) {
            printf("No se ha encontrado el equipo. Intente de nuevo.");
        }
        if (perdedor == ganador) {
            printf("ERROR un equipo no puede competir con si mismo. Intente de nuevo.");
            perdedorEncontrado = -1;
        }

} while (ganadorEncontrado == -1 || perdedorEncontrado == -1 || perdedorEncontrado == ganadorEncontrado);

}

float calcularEfectividad(struct Equipo* n) {
 if (n->partidasJugadas == 0) {
        return 0.0;
    }
    return (float)n->puntos / n->partidasJugadas;
}
}


