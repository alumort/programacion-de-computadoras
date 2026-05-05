#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

void cargar(int vec[CANTIDAD])
{
    int f;
    for (f = 0; f < 5; f++)
    {
        printf("Ingrese elemento:");
        scanf("%i",&vec[f]);
    }
}

void ordenar(int vec[CANTIDAD],int cant)
{
    if (cant > 1)
    {
        int f;
        for (f = 0; f < cant - 1; f++)
        {
            if (vec[f] > vec[f + 1])
            {
                int aux = vec[f];
                vec[f] = vec[f + 1];
                vec[f + 1] = aux;
            }
        }
        ordenar(vec, cant - 1);
    }
}

void imprimir(int vec[CANTIDAD])
{
    int f;
    for (f = 0; f < 5; f++)
    {
        printf("%i ", vec[f]);
    }
}


int main()
{
    int vec[CANTIDAD];
    cargar(vec);
    ordenar(vec, CANTIDAD);
    imprimir(vec);
    getch();
    return 0;
}
