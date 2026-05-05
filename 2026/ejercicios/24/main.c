#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cargar(char nombres[4][20], int notas[4]);
void ordenar(char nombres[4][20], int notas[4]);
void imprimir(char nombres[4][20], int notas[4]);
int main()
{
    char nombres[4][20];
    int notas[4] = {0};
    cargar(nombres, notas);
    ordenar(nombres, notas);
    imprimir(nombres, notas);
    return 0;
}

void cargar(char nombres[4][20], int notas[4]) {
for(int i = 0; i<4; i++) {
    printf("Ingrese nombre del alumno.\n");
    fgets(nombres[i], sizeof(nombres[i]), stdin);
    nombres[i][strcspn(nombres[i], "\n")] = '\0';
    printf("Ingrese nota.\n");
    if( scanf("%d", &notas[i]) != 1) {
        while(getchar()!= '\n');
        notas[i] = -1;
    }
    getchar();
}
}
void ordenar(char nombres[4][20], int notas[4]) {
int auxNotas;
char auxNombre[20];
int ordenado;
do {
    ordenado = 1;
for(int i = 0; i<3;i++) {
        if(notas[i] < notas[i+1]) {
            auxNotas = notas[i];
            notas[i] = notas[i+1];
            notas[i+1] = auxNotas;
            strcpy(auxNombre, nombres[i]);
            strcpy(nombres[i], nombres[i+1]);
            strcpy(nombres[i+1], auxNombre);
            ordenado = 0;
        }

}
} while(ordenado = 0);
}
void imprimir(char nombres[4][20], int notas[4]) {
    int contadorMB = 0;
for(int i = 0; i<4;i++) {
               printf("Nombre del alumno: %s\n", nombres[i]);
        printf("Nota del alumno: %d\n", notas[i]);
    if(notas[i] >=8) {
        printf("Estado: Muy Bueno.\n");
        printf("\n");
        contadorMB++;
    } if (notas[i] <= 7 && notas[i] >= 4) {
        printf("Estado: Bueno.\n");
                printf("\n");
    } if(notas[i] < 4) {
        printf("Estado: Insuficiente.\n");
                printf("\n");
    }


}
  printf("Cantidad de alumnos con estado 'Muy Bueno': %d", contadorMB);

}
