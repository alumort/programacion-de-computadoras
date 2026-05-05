#include <stdio.h>
#include <stdlib.h>


int main()
{
    char palabra[30];
    int contadorVocales = 0;

    printf("Ingrese una palabra:\n");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = 0;
    for(int i = 0; palabra[i] != '\0'; i++) {
        if(palabra[i] == 'a' || palabra[i] == 'e' || palabra[i] == 'i' ||
           palabra[i] == 'o' || palabra[i] == 'u' ||
           palabra[i] == 'A' || palabra[i] == 'E' || palabra[i] == 'I' ||
           palabra[i] == 'O' || palabra[i] == 'U') {
            contadorVocales++;
        }
    }

    printf("La cantidad de vocales de la palabra '%s'a es de %d\n", palabra, contadorVocales);
    return 0;
}
