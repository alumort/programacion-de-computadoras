#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define maxDia 7
#define maxProd 3

struct Ventas {

int diaSemana;
int categoriaProducto;
int cantidadVendida;

};

void guardarArchivo();

void imprimir(int *diaMaximo, int *cantMax);

void masBebidas(int *diaMaximo, int *cantMax);
void vaciarArchivo();

int main()
{
    int opcion;
    int diaMaximo = 0;
    int cantMax = 0;
     do {
            system("cls");
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,  205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,187);
            printf("%c    Ventas   %c\n", 186, 186);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200, 205,  205,  205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205,188);
            printf("1. Guardar Archivo.\n");
            printf("2. Informe General.\n");
            printf("3. Dia Con Mas Bebidas Vendidas.\n");
            printf("4. Vaciar Archivo.\n");
            printf("0. Salir.\n");
            printf("--------------------------------\n");
            printf("Ingrese una opcion:\n");
            if (scanf("%d", &opcion) != 1) {
            while (getchar() != '\n');
            opcion = -1;}
            switch(opcion) {
        case 1:{
            system("cls");
            guardarArchivo();
            system("pause");
        break;}

        case 2:{
            system("cls");
            imprimir(&diaMaximo, &cantMax);
            system("pause");
        break;}

        case 3: {
        system("cls");
        masBebidas(&diaMaximo, &cantMax);
        system("pause");
        break;}

        case 4: {
            system("cls");
            vaciarArchivo();
            printf("Archivo vaciado con exito.\n");
            system("pause");
        break;}

                case 0: {
            system("cls");
            printf("Saliendo...\n");
            system("pause");
        break;
        }

        default: {
            system("cls");
            printf("ERROR opcion invalida.\n");
            system("pause");
        break;
        }

        }
    } while(opcion != 0);

    return 0;

}

void guardarArchivo() {
 struct Ventas v;
    FILE *reporte;
    reporte = fopen("reporte.dat", "ab");
    if(reporte == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }

while(1) {
        printf("\nIngrese el numero de dia del 1 al %d (o '0' para salir): ", maxDia);
        if (scanf("%d", &v.diaSemana) != 1) {
            while (getchar() != '\n');
            v.diaSemana = -1;
        }
        if (v.diaSemana == 0) {
            break;
        }

        printf("Ingrese el numero de producto del 1 al %d: ", maxProd);
        if (scanf("%d", &v.categoriaProducto) != 1) {
            while (getchar() != '\n');
            v.categoriaProducto = -1;
        }

        printf("Ingrese cantidad vendida total: ");
        if (scanf("%d", &v.cantidadVendida) != 1) {
            while (getchar() != '\n');
            v.cantidadVendida = -1;
        }


        fwrite(&v, sizeof(struct Ventas), 1, reporte);
        printf(" -> Venta guardada.\n");
    }


  fclose(reporte);
  printf("\nVolviendo al menu...\n");
system("pause");
}

void imprimir(int *diaMaximo, int *cantMax) {
    struct Ventas v;
    FILE *reporte = fopen("reporte.dat", "rb");
    float matriz[maxDia][maxProd]= {0};
    if(reporte == NULL) {
        printf("No se pudo abrir el archivo. Intente de nuevo.\n");
        system("pause");
        return;
    }
    while(fread(&v, sizeof(struct Ventas), 1, reporte)) {
      int fila = v.diaSemana - 1;
      int col = v.categoriaProducto -1;
      if(fila >= 0 && fila < maxDia && col >= 0 && col < maxProd){
            matriz[fila][col] = matriz[fila][col] + v.cantidadVendida;
      }
    }
          fclose(reporte);


     printf("---------------------------------------\n");
    printf("-----------INFORME MATRICIAL-----------\n");
    printf("---------------------------------------\n");
     printf("%-10s", " ");
    for(int t = 0; t < maxProd; t++) {
        printf(" | Producto %d  ", t + 1);
    }
    printf("\n");
    printf("--------------------------------------------------\n");

    // Imprimir filas (Nombre del local, los importes de la matriz y el total de la fila)
    for(int l = 0; l < maxDia; l++) {
    printf("Dia %-4d", l + 1);

    for(int t = 0; t < maxProd; t++) {
        printf(" | %-7.0f", matriz[l][t]);
    }

    printf("\n");
    printf("--------------------------------------------------\n");

}


}

void masBebidas(int *diaMaximo, int *cantMax) {
    struct Ventas v;
    char *dias[] = {
    "Lunes", "Martes", "Miercoles",
    "Jueves", "Viernes", "Sabado", "Domingo"
};

int matriz[maxDia][maxProd] = {0};

FILE *reporte = fopen("reporte.dat", "rb");

if (reporte == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}

while (fread(&v, sizeof(struct Ventas), 1, reporte)) {
    int fila = v.diaSemana - 1;
    int col = v.categoriaProducto - 1;

    if (fila >= 0 && fila < maxDia &&
        col >= 0 && col < maxProd) {

        matriz[fila][col] += v.cantidadVendida;
    }
}

fclose(reporte);

*cantMax = matriz[0][1];
*diaMaximo = 0;

for (int l = 1; l < maxDia; l++) {
    if (matriz[l][1] > *cantMax) {
        *cantMax = matriz[l][1];
        *diaMaximo = l;
    }
}

if (*cantMax > 0) {
    printf("El dia que mas bebidas vendio fue el %s con total de %d\n",
           dias[*diaMaximo], *cantMax);
} else {
    printf("No hay ventas de bebidas registradas.\n");
}
}

void vaciarArchivo() {
FILE *reporte;
reporte = fopen("reporte.dat", "wb");
fclose(reporte);
}

