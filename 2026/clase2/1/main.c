#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Alumno {

    int legajo;
    char nombre[50];
    float promedio;

};

void sumarPromedio (struct Alumno a);

int main()
{
    struct Alumno alumno1;
    alumno1.legajo = 1;
    strcpy(alumno1.nombre, "Jose gimenez");
    alumno1.promedio = 7.5;

    printf("Datos del alumno:\n Legajo: %d\n Nombre: %s\n Promedio: %.2f\n", alumno1.legajo, alumno1.nombre, alumno1.promedio);
    sumarPromedio(alumno1);
    printf("Datos del alumno despues de la funcion:\n Legajo: %d\n Nombre: %s\n Promedio: %.2f\n", alumno1.legajo, alumno1.nombre, alumno1.promedio);
    return 0;
}

void sumarPromedio (struct Alumno a) {
    a.promedio = a.promedio + 1.0;
}
