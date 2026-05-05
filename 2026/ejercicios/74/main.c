#include <stdio.h>
#include <stdlib.h>

int main()
{
 FILE *arch = fopen("archivo.dat", "wb");
 if(arch == NULL)
    exit(1);
    int uno = 1;
    int dos = 2;
    int tres = 3;
 fwrite(&uno, sizeof(int), 1, arch);
 fwrite(&dos, sizeof(int),1,arch);
 fwrite(&tres, sizeof(int),1,arch);
 fclose(arch);
 arch = fopen("archivo.dat", "ab");
 float cuatro = 4.4;
 fwrite(&cuatro, sizeof(int),1,arch);
 fclose(arch);
 arch = fopen("archivo.dat","rb");
 int one;
 int two;
 int three;
 float four;
 fread(&one, sizeof(int),1,arch);
 fread(&two, sizeof(int),1,arch);
 fread(&three, sizeof(int),1,arch);
 fread(&four, sizeof(float),1,arch);
 fclose(arch);
 printf("Variable uno: %d\n", one);
 printf("Variable dos: %d\n", two);
 printf("Variable tres: %d\n", three);
 printf("Variable cuatro: %.2f\n", four);
    return 0;
}
