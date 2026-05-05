#include <stdio.h>
#include <stdlib.h>
int leerEntero();
//Un postulante a un empleo, realiza un test de capacitación, se obtuvo la siguiente información:
//cantidad total de preguntas que se le realizaron y la cantidad de preguntas que contestó correctamente.
//Se pide confeccionar un programa que ingrese los dos datos por teclado e informe el nivel del mismo
//según el porcentaje de respuestas correctas que ha obtenido, y sabiendo que:
//	Nivel máximo:	Porcentaje>=90%.
//	Nivel medio:	Porcentaje>=75% y <90%.
//	Nivel regular:	Porcentaje>=50% y <75%.
//	Fuera de nivel:	Porcentaje<50%.
int main()
{
    printf("Hello world!\n");
    return 0;
}
int leerEntero() {
    int x;
    int resultado;

    while (1) {
        resultado = scanf("%d", &x);

        if (resultado == 1) {
            while (getchar() != '\n');
            return x;

        } else {
            printf("Error: debe ingresar un numero.\n");
            while (getchar() != '\n');
        }
    }
}
