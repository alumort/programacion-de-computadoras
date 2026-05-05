#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Perfil {
    int id;
    char empresa[50];
    int seguidoresTotales;
    int historial[3];
};


void actualizarSeguidores (struct Perfil* n, int variacion);


int main()
{
    struct Perfil usuarios[5] = {
    {1, "_alumort", 704, {0,0,0}},
    {2, "lucma", 607, {0, 0,0}},
    {3, "jugex", 500, {0, 0, 0}},
    {4, "manuelita04", 200000, {0, 0, 0}},
    {5, "josefina89", 10, {0, 0, 0}}
    };

int variacion, opcion, n;

do {
    printf("--------------------\n");
    printf("COMMUNITY MANAGER APP\n");
    printf("--------------------\n");
    printf("Seleccione una opcion:\n");
    printf("1.Recuento Diario.\n");
    printf("2.Estadisticas.\n");
    printf("3.Estado Actual\n");
    printf("0.Salir.\n");
    scanf("%d", &opcion);

    switch(opcion){
    case 1: {
    for(int i = 0; i < 5; i++){
        printf("Ingrese la variacion de seguidores: \n");
        scanf("%d", &variacion);
        actualizarSeguidores(&usuarios[i], variacion);
    }
    break;}

    case 2: {
    for(int i = 0; i < 5; i++){
        printf("Las estadisticas de la cuenta %s es de %d, %d, %d \n",
               usuarios[i].empresa,
               usuarios[i].historial[0],
               usuarios[i].historial[1],
               usuarios[i].historial[2]);
    }
    break;}

    case 3: {
    for(int i = 0; i < 5; i++){
        printf("Los seguidores totales de la cuenta %s son de %d\n",
               usuarios[i].empresa,
               usuarios[i].seguidoresTotales);
    }
    break;}

    case 0: {
    printf("Cerrando...\n");
    break;}

    }

} while (opcion != 0);

    return 0;
}

void actualizarSeguidores(struct Perfil* n, int variacion) {
    n->historial[2] = n->historial[1];
    n->historial[1] = n->historial[0];

    n->historial[0] = variacion;

n -> seguidoresTotales = n -> seguidoresTotales + variacion;
    if (n -> seguidoresTotales < 0) {
        n -> seguidoresTotales = 0;
    }

}
