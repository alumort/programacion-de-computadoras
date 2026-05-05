#include <stdio.h>
#include <stdlib.h>
//Escribí un programa que le pida al usuario que ingrese notas de alumnos una por una. X
//> Tiene dos reglas: 1. El programa tiene que dejar de pedir notas únicamente cuando el usuario ingrese un número negativo. X
//2. Si el usuario ingresa una nota mayor a 10, el programa le tiene que avisar del error y volver a pedirla obligatoriamente. X
//Al final, el programa debe mostrar por pantalla cuál fue el promedio general de las notas válidas y cuántos alumnos aprobaron
//(con nota 6 o mayor).

float calcularPromedio(float sumaNota, int cantidadNota);

int main()
{
  float nota;
  float promedio;
  float sumaNota;
  int aprobados;
    int cantidadNotas;

    cantidadNotas = 0;
    aprobados = 0;


  do {
       do {
            printf("Por favor ingrese la nota del alumno(0 a 10, se termina el programa con un numero negativo): \n");
            scanf("%f", &nota);
       if (nota > 10){
        printf("Error, la nota no puede ser mayor que 10. Ingrese la nota del alumno: \n");
       }
        }  while (nota > 10);

        if (nota < 0) {
            break;
        }
    cantidadNotas++;
    sumaNota= sumaNota + nota;

    if (nota >= 6) {
     aprobados++;
    }

    } while (1);
    promedio = calcularPromedio(sumaNota, cantidadNotas);

     if(cantidadNotas > 0) {
        printf("Total de notas ingresadas: %d\n", cantidadNotas);
        printf("Alumnos aprobados (nota >= 6): %d\n", aprobados);
        printf("El promedio es: %f\n", promedio);
     }
    else {
    printf("no hay notas validas");
}
    return 0;
}

float calcularPromedio(float sumaNota, int cantidadNota) {
    float promedio;
    promedio = sumaNota / cantidadNota;
    return promedio;
}
