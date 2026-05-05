#include <stdio.h>
#include <stdlib.h>

typedef struct Lenguaje {
    char* nombre;
    int anio;
} Lenguaje;

void descripcion(Lenguaje lenguaje){
    printf("%s fue creado en %d", lenguaje.nombre, lenguaje.anio);
}


int main()
{
    Lenguaje html;
    html.nombre = "HTML";
    html.anio = 1993;
    descripcion(html);
    return 0;
}
