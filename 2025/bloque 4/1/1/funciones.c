#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


struct Persona cargarPersona (struct Persona persona) {
    persona.edad = 20;
    persona.altura = 2.20;
    strcpy(persona.nombre, "Patroclo");
    persona.promedio = 5.4;
    return persona;

}

void mostrarPersona (struct Persona persona){
    printf("Nombre: %s\n", persona.nombre);
    printf("Edad: %i\n", persona.edad);
    printf("Altura: %.2f\n", persona.altura);
    printf("Promedio: %.2f\n", persona.promedio);
    getchar();
    }
