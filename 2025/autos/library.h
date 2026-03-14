#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

struct Vehiculo {
    int anio;
    float precio;
    char color[12];
    char patente[7];

};

void cargarVehiculos(int num, struct Vehiculo vehiculo[]);
void mostrarVehiculos(int num, struct Vehiculo vehiculo[]);
void ordenarVehiculosPorPatente(int num, struct Vehiculo vehiculo[]);

#endif // LIBRERIA_H_INCLUDED
