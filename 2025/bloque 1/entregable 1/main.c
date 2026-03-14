#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//- Calcular el promedio de las notas x
//- Contar la cantidad de aprobados x
//- Cantidad de desaprobados X
//- Cantidad de ausentes X
//- El usuario ingresa notas hasta que ingresa -1 X
//- Cantidad de notas impares x
//- Promedio de notas pares y aprobadas x
//- La menor nota y la mayor nota x
//- Las notas son de 0 a 10. Con el -1 termina el ingreso de notas, si se carga 11 la nota pasa a ser aleatoria en vez de por teclado. X


int main()
{
    srand(time(0));
    float promedio;
    float promedioParAp;
    int cantNota;
    int acumNotaParAp;
    int acumNota;
    int nota;
    int cantNotaPar;
    int cantNotaAprobada;
    int cantNotaParAp;
    int notaMayor;
    int notaMenor;
    int auxMayor;
    int auxMenor;
    int aprobados;
    int desaprobados;
    char presente;
    int cantAusentes;
    int notasImpares;

    aprobados = 0;
    desaprobados = 0;
    acumNota = 0;
    acumNotaPar = 0;
    notaMayor = 0;
    notaMenor = 0;
    desaprobados = 0;
    presente = 0;
    cantAusentes = 0;
    notasImpares = 0;
    auxMenor = 0;
    auxMayor = 0;
    cantNotaPar = 0;


    printf("Este es un programa para calcular promedios, aprobados y desaprobados de alumnos.\n");

    printf("Por favor escriba la nota \n");

    scanf("%i", &nota);

    while (nota != -1) {
            cantNota ++;
    printf("El alumno quedo ausente? S= si / N = no");
    scanf(" %c", &presente);

        if (presente != 'S' && presente != 's' && presente != 'N' && presente != 'n') {
            printf("No es una opcion valida. El alumno quedo ausente? S= si / N = no");

            scanf("% c", &presente);
        }

        if (presente == 'S' || presente == 's') {
            cantAusentes ++;
        }

        if (nota = 11){
            nota = rand() % 10 + 1;
            acumNota = acumNota + nota;
        }

        if (notaMayor == 0 || notaMayor < nota ){
            notaMayor = nota;
        }

        if (notaMenor == 0 || notaMenor > nota) {
            notaMenor = nota;
        }



        if (nota < 4) {
                desaprobados ++;
                acumNota = acumNota + nota;
        }

        else {
                aprobados ++;
                acumNota = acumNota + nota;
        }

        if (nota % 2 == 0 && nota >= 4) {
                acumNotaParAp = acumNotaParAp + nota;
                cantNotaParAp++;

        }

        else {
            notasImpares++;
        }

    printf("Por favor escriba la nota \n");

    scanf("%i", &nota);
    }

    promedio = ((float) acumNota) / ((float) cantNota);

    printf("Promedio de notas: %f", promedio);

    promedioParAp = ((float)acumNotaParAp) / ((float) cantNotaParAp);

    printf("Promedio de notas pares y aprobadas: %f", promedioParAp);

    printf("La nota menor es: %i", notaMenor);

    printf("La nota mayor es: %i", notaMayor);

    printf("Cantidad de ausentes: %i", cantAusentes );

    printf("Cantidad de aprobados: %i", aprobados);

    printf ("Cantidad de desaprobados: %i", desaprobados);

    return 0;
}
