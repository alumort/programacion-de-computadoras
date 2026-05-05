#include <stdio.h>
#include <stdlib.h>

int main()
{
    float vector[5];
    for(int i = 0; i < 5; i++) {
        printf("Ingrese el sueldo del operario %d:\n", i);
        if (scanf("%f", &vector[i]) != 1) {
            while (getchar() != '\n');
            vector[i] = -1;
        }
    }
    for (int i = 0; i <5; i++) {
        printf("Operario: %d , sueldo: %.2f\n", i, vector[i]);
    }

    return 0;
}
