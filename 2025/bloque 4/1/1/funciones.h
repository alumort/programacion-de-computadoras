#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Persona {
    int edad;
    float altura;
    char nombre[30];
    float promedio;
};

struct Persona cargarPersona(struct Persona persona);

#endif // FUNCIONES_H_INCLUDED
