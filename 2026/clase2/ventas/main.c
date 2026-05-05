#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Vamos a armar un sistema de ventas tech.
//Definí un struct Producto (ID, nombre, stock). X
//En el main, armá un arreglo de 3 productos y hardcodeales los datos (ej: una placa de video, unos auris). X
//Armá una función venderProducto que reciba el puntero a UN producto y le reste 1 al stock usando la flecha ->.
//En el main, armá un menú principal con un do-while. Una opción para ver el inventario y otra para vender.
//Si elige vender, pedile el ID y obligala a poner uno válido con otro do-while. Recién cuando el ID sea correcto, buscalo en el vector y pasale el ampersand & de esa posición a tu función para descontar el stock."


struct Producto{
    int id;
    char nombre[20];
    int stock;
};

void vender(struct Producto* punteroObjeto);

int main()


{
    struct Producto objetos[3] =
    {
        {1, "Mouse", 10},
        {2,"Teclado", 5},
        {3, "Monitor",6}
    };
    int opcion;
    int idBuscado;
    int idEncontrado = -1;

 do {
printf("\n=============================\n");
  printf("   SISTEMA DE VENTAS TECH\n");
  printf("=============================\n");
  printf("1. Ver productos disponibles\n");
  printf("2. Vender un producto\n");
  printf("0. Salir\n");
  printf("Elija una opcion: ");
  scanf("%d", &opcion);

    switch (opcion) {
        case 1: {
for (int i = 0; i < 3; i++) {
        printf("Id: %d \n", objetos[i].id);
        printf("Nombre: %s \n", objetos[i].nombre);
        printf("Cantidad: %d \n", objetos[i].stock);
    }
            break;
        }
        case 2: {
            do {printf("Ingresa el ID del producto que desea vender\n");
            scanf("%d", &idBuscado);
            for (int i = 0; i < 3; i++) {
                if (objetos[i].id == idBuscado) {
                    idEncontrado = i;
                    break;
                }
            }
            if (idEncontrado == -1) {
                printf("ERROR id no encontrado");
            }
            } while (idEncontrado == -1);

            vender(&objetos[idEncontrado]);
            break;
        }
        case 0: {
            printf("Saliendo...");
            break;
        }
        default: {
        printf("Opcion no valida...");
        break;
        }
    }


 } while(opcion != 0);

    return 0;
}



void vender(struct Producto* punteroObjeto) {

    if (punteroObjeto -> stock > 0) {
           punteroObjeto -> stock = punteroObjeto -> stock - 1;
           printf("Venta procesada con exito.");
    } else {
        printf("ERROR no hay suficiente stock.");
    }

}

