#include <stdio.h>
#include <stdlib.h>
//Confeccionar un programa que defina en la main un vector de 5 elementos de tipo entero.
//Cargar e imprimir el mayor elemento y su posción.

void cargarVector (int vec);
void buscarMayor (int vec);

int main()
{
    int vec[5];
    cargarVector(vec);
    buscarMayor(vec);
    return 0;
}

cargarVector(int vec) {
    for (int i = 0; i < 5; i++) {
        printf("Ingrese un número: ");
        scanf("%d", &vec[i]);
    }
}

buscarMayor(vec){
    int i=0;
    int mayor = vec[i];
    int posicion = i;
    int repeticiones = 1;
 for (int i = 1; i < 5; i++) {
        if (vec[i] > mayor) {
            mayor = vec[i];
            posicion = i;
            repeticiones = 1;
        } else if (vec[i] == mayor) {
            repeticiones++;
        }
    }
