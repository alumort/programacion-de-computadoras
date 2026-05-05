#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Alumno {
    int legajo;
    float promedio;
};

void subirNota(struct Alumno* punteroAlumnoA);

int main()
{

    struct Alumno alumnos[3];

    for (int i = 0; i < 3; i++) {
        printf("Ingrese el legajo del alumno:", i + 1);
        scanf("%d", &alumnos[i].legajo);
        printf("Ingrese el promedio del alumno: ", i + 1);
        scanf("%f", &alumnos[i].promedio);
    }


    subirNota(&alumnos[0]);
    float mejorPromedio = 0;
    int mejorLegajo = 0;
    for (int i = 0; i < 3; i++){
        if (alumnos[i].promedio > mejorPromedio) {
            mejorPromedio = alumnos[i].promedio;
            mejorLegajo = alumnos[i].legajo;
        }
    }
    printf("El mejor promedio es de:%.2f , y su legajo es de %d\n", mejorPromedio, mejorLegajo);
    return 0;
}

void subirNota(struct Alumno* punteroAlumnoA) {
    //trabajar con punteros de lista de struct hay que ser especifico donde vamos a trabajar con ->
    punteroAlumnoA -> promedio = punteroAlumnoA -> promedio + 1;
}
