#include <stdio.h>
#include <stdlib.h>

void imprimir(int x)
{
    if( x > 0) {
            printf("%i ",x);
    imprimir(x - 1);
    }

}
int main()
{
    imprimir(5);
    getch();
    return 0;
}
