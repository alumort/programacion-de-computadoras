#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch = fopen("archivo.dat", "rb");
    if(arch == NULL)
        exit(1);
    char c;
    fread(&c, sizeof(char),1, arch);
    int i;
    fread(&i, sizeof(int), 1, arch);
    float f;
    fread(&f, sizeof(float), 1, arch);
    fclose(arch);
    printf("archivo leido con exito.\n");
    printf("caracter: %s\n", c);
    printf("int: %d\n", i);
    printf("float: %.2f\n", f);
    return 0;
}
