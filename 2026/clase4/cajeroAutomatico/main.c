#include <stdio.h>
#include <stdlib.h>



float archivoPlata();
void guardarPlata(float dinero);
void depositar(float deposito, float *dinero);
void extraer(float extraccion, float *dinero);
float leerFloat();
int leerInt();

int main()
{

    float dinero = archivoPlata();
    float extraccionPedida;
    float extraccion = -1;
    float depositoPedido;
    float deposito = -1;
    int opcion;
do {
    printf("----Seguimiento de Plata----\n");
    printf("1. Ver Saldo.\n");
    printf("2. Depositar.\n");
    printf("3. Extraer.\n");
    printf("0. Salir.\n");
        printf("Ingrese una opcion.\n");
        opcion = leerInt();
        switch(opcion) {
        case 1: {
            dinero = archivoPlata();
            printf("Su saldo actual es de: %.2f\n", dinero);

        break;}
        case 2: {
        do {
            printf("Cuanto desea depositar?\n");
            depositoPedido = leerFloat();
            if( depositoPedido <= 0) {
                printf("ERROR no se puede hacer un deposito menor a 1. Intente de nuevo.\n");
            } else {
            deposito = depositoPedido;
            depositar(depositoPedido, &dinero);
            guardarPlata(dinero);
            }
        }while(deposito == -1);
        deposito = -1;
        break;}

        case 3: {
        do {
                printf("Cuanto desea extraer?\n");
                extraccionPedida = leerFloat();
                if( extraccionPedida <= 0) {
                printf("ERROR no se puede hacer una extraccion menor a 1. Intente de nuevo.\n");
            } else if (extraccionPedida > dinero) {
                printf("ERROR saldo insuficiente.\n");
            } else {
            extraccion = extraccionPedida;
            extraer(extraccionPedida, &dinero);
            guardarPlata(dinero);
            }

        }while (extraccion == -1);
        extraccion = -1;
        break;}

        case 0: {
            guardarPlata(dinero);
        printf("Cerrando programa...\n");
        break;
        }
        default: {
        printf("ERROR opcion invalida. Intente de nuevo.\n");
        break;}
        }
    } while (opcion != 0);


    return 0;
}

float archivoPlata() {
FILE *plata;
float miPlata = 0;
plata = fopen("saldo.txt", "r");

if (plata != NULL ) {
    fscanf(plata, "%f", &miPlata);
    fclose(plata);
    return miPlata;
} else {
    printf("No se pudo abrir el archivo.\n");
return 0;}
}

void guardarPlata(float dinero) {
FILE *plata;
plata = fopen("saldo.txt", "w");

if (plata != NULL) {
    fprintf(plata, "%f", dinero);
    fclose(plata);
}
}

void depositar(float deposito, float *dinero) {
*dinero = *dinero + deposito;
}

void extraer(float extraccion, float *dinero) {
*dinero = *dinero - extraccion;
}

float leerFloat() {
    float x;
    int resultado;

    while (1) {
        resultado = scanf("%f", &x);

        if (resultado == 1) {
            while (getchar() != '\n');
            return x;

        } else {
            while (getchar() != '\n');
            printf("Error: debe ingresar un numero.\n");

        }
    }
}
int leerInt() {
    int x;
    int resultado;

    while (1) {
        resultado = scanf("%i", &x);

        if (resultado == 1) {
            while (getchar() != '\n');
            return x;

        } else {
            while (getchar() != '\n');
            printf("Error: debe ingresar un numero.\n");

        }
    }
}
