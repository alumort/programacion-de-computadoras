#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char palabra[20];
    char palabraminu[20];
    printf("ingrese su palabra magica\n");
    fgets(palabra, sizeof(palabra), stdin);
    for(int i = 0; i < palabra[i] != '\0'; i++) {
       palabraminu[i] = tolower(palabra[i]);
    }

    palabraminu[strcspn(palabraminu, "\n")] = 0;
    for(int i = 0; palabraminu[i] != '\0'; i++) {
        if(palabraminu[i] == 'a' || palabraminu[i] == 'e' || palabraminu[i] == 'i' ||
           palabraminu[i] == 'o' || palabraminu[i] == 'u') {
            palabraminu[i] = '-';
        }
    }
printf("Palabra original: %s\n", palabra);
printf("Palabra nueva: %s\n", palabraminu);
    return 0;
}
