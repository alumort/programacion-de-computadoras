#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED


    struct Animal {
    int edad;
    float peso;
    char especie[20];
    char genero;

};

struct Animal cargarAnimal(struct Animal animal);
void mostrarAnimal(struct Animal animal);
void ordenarAnimal (int num, struct Animal animales[]);


#endif // LIBRERIA_H_INCLUDED
