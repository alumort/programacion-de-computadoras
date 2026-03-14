#include <stdio.h>
#include <stdlib.h>
//Pedir por pantalla nombre, apellido, edad, altura y genero de una persona, mostrar los datos por pantalla.
int main()
{
    char nombre[20], apellido[20];
    char genero;
    float edad, altura;
    edad = 0;
    altura = 0;


    printf("cual es tu nombre?\n");
    fgets(nombre, sizeof(nombre), stdin);

    printf("cual es tu apellido?\n");
    fgets(apellido, sizeof(apellido), stdin);

    printf("si sos hombre pone H, si sos mujer pone M, si sos otro pone N\n");
    scanf(" %c", &genero);

while (genero != 'M' && genero  != 'H' && genero != 'N' && genero  != 'm' && genero  != 'h' && genero  != 'n') {
        printf("Ese no es un genero valido. Soy inclusivo pero respeta la consigna la concha de tu madre!!! \n");
        printf("Si sos hombre pone H, si sos mujer pone M, si sos otro pone N\n");
        getchar();
        scanf(" %c", &genero);
    }


    printf("muy interesante. ahora, cuantos anios tenes?\n");
    scanf("%f", &edad);

    printf("wow increible. ok por ultimo y dejo de romperte las bolas, cual es tu altura??\n");
    scanf("%f", &altura);

    printf("PERFECTO ahora lo siguiente es.......... \n");
    printf("tu nombre es %s, apellido %s, y tu genero es %c\n", nombre, apellido, genero);

    printf("POR ULTIMO Y NO MENOS IMPORTANTE, tu edad es de %f con altura %f\n", edad, altura);
    printf("pero obvio ya lo sabias. solo es un ejercicio de practica para programar en c. adios :3\n");

    return 0;
}
