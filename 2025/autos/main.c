#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main() {
    int num = 3;
    struct Vehiculo vehiculo[num];

    cargarVehiculos(num, vehiculo);
    mostrarVehiculos(num, vehiculo);
    ordenarVehiculosPorPatente(num, vehiculo);
    mostrarVehiculos(num, vehiculo);

    getchar();
    return 0;
}
