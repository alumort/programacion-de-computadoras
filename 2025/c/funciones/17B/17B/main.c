#include <stdio.h>
#include <stdlib.h>

//Confeccionar un programa que solicite el pago por hora de un empleado y la cantidad de horas trabajadas dentro de una estructura repetitiva en la función main.
//Elaborar una función que reciba como parámetro el valor de la hora y la cantidad de horas trabajadas y nos muestre el total a pagar.

void calcularSueldo(float pagoHora, int horas);

int main()
{
    float pagoHora;
    int horas;
    printf("ingrese su sueldo por hora: ");
    scanf("%f", &pagoHora);
    printf("ingrese cuantas horas trabajo: ");
    scanf("%i", &horas);
    calcularSueldo(pagoHora, horas);
    return 0;
}

void calcularSueldo(float pagoHora, int horas) {
    float sueldo = pagoHora * horas;
    printf("su sueldo trabajando %i horas y ganando %f por hora es igual a %.f", horas, pagoHora, sueldo);
}
