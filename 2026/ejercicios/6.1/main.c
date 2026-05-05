#include <stdio.h>
#include <stdlib.h>

float leerFloat();

int main()
{
    float sueldo;
    printf("Ingrese el sueldo a analizar por razones... secretas.\n");
    sueldo = leerFloat();
    if(sueldo > 3000) {
        printf("Tiene que abonar impuestos. YA!\n");
    } else {

    printf("Tu no has visto nada...");}
    return 0;
}
float leerFloat() {
float x;
float resultado;

    while (1) {
        resultado = scanf("%f", &x);

        if (resultado == 1) {
            return x;
            while (getchar() != '\n');
        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }}
