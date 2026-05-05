#include <stdio.h>
#include <stdlib.h>
#define maxEmple 4
#define maxAsegu 5


struct Agentes {
int ID_Empleado;
int Aseguradora;
float Monto_Liquidado;
};

void guardarArchivo(int *primerEmpleado, int *primerSeguro, float *primerRegistro);
void imprimir();
void mejorAcuerdo(int *primerEmpleado, int *primerSeguro, float *primerRegistro);
void ordenar();
void exportar(int *primerEmpleado, int *primerSeguro, float *primerRegistro);
void vaciarArchivo();

int main()
{
    int opcion;
    int primerEmpleado = 0;
    int primerSeguro = 0;
    float primerRegistro = 0;
    do {
    printf("=====================\n");
    printf("----Liquidaciones----\n");
    printf("=====================\n");
    printf("1 - Cargar Oficios\n");
    printf("2 - Matriz Liquidaciones\n");
    printf("3 - Mejor Acuerdo\n");
    printf("4 - Ranking de Empleados\n");
    printf("5 - Exportacion dual\n");
    printf("6 - Vaciar Sistema\n");
    printf("0 - Guardar y salir\n");
    printf("=====================\n");
    printf("Seleccione una opcion\n");
    if(scanf("%d",&opcion) != 1) {
        while(getchar()!= '\n');
        opcion = -1;
    }
    switch(opcion) {
    case 1: {
guardarArchivo(&primerEmpleado, &primerSeguro, &primerRegistro);
    break;}

    case 2: {
imprimir();
    break;}

    case 3: {
        printf("Analizando estadisticas para ver cual fue el mejor acuerdo...\n");
mejorAcuerdo(&primerEmpleado, &primerSeguro, &primerRegistro);
    break;}

    case 4: {
ordenar();
    break;}

    case 5: {
exportar(&primerEmpleado, &primerSeguro, &primerRegistro);
    break;}

    case 6: {
    vaciarArchivo();
    printf("Archivo vaciado con exito.\n");
    break;}

    case 0: {
printf("Guardando antes de salir...\n");
exportar(&primerEmpleado, &primerSeguro, &primerRegistro);
printf("Archivo guardado con exito. Saliendo...\n");
    break;}

    default: {
    printf("ERROR: opcion invalida!\n");
    break;}
    }

    }while(opcion!= 0);

    return 0;
}

void guardarArchivo(int *primerEmpleado, int *primerSeguro, float *primerRegistro){
struct Agentes a;
FILE *archivo = fopen("acuerdos.dat", "ab");
if(archivo == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}

while(1) {
        printf("\nIngrese el numero de empleado del 1 al %d (o '0' para salir): ", maxEmple);
        if (scanf("%d", &a.ID_Empleado) != 1) {
            while (getchar() != '\n');
            a.ID_Empleado = -1;
        }


        if (a.ID_Empleado == 0) {
            break;
        }

        if(*primerEmpleado == 0) {
            *primerEmpleado = a.ID_Empleado;
        }
        printf("Ingrese el numero de aseguradora del 1 al %d: ", maxAsegu);
        if (scanf("%d", &a.Aseguradora) != 1) {
            while (getchar() != '\n');
            a.Aseguradora = -1;
        }
        if(*primerSeguro == 0) {
            *primerSeguro = a.Aseguradora;
        }

        printf("Ingrese monto liquidado: ");
        if (scanf("%f", &a.Monto_Liquidado) != 1) {
            while (getchar() != '\n');
            a.Monto_Liquidado= -1;
        }
if(a.ID_Empleado < 1 || a.ID_Empleado > maxEmple) {
    printf("Empleado invalido.\n");
    continue;
}

if(a.Aseguradora < 1 || a.Aseguradora > maxAsegu) {
    printf("Aseguradora invalida.\n");
    continue;
}
          if(*primerRegistro == 0) {
            *primerRegistro = a.Monto_Liquidado;
        }
            if(a.Monto_Liquidado > *primerRegistro) {
            *primerEmpleado = a.ID_Empleado;
            *primerSeguro = a.Aseguradora;
            *primerRegistro = a.Monto_Liquidado;
        }



        fwrite(&a, sizeof(struct Agentes), 1, archivo);
        printf(" -> Monto guardado.\n");
    }
    fclose(archivo);
    printf("Volviendo al menu...\n");
}
void imprimir(){
    struct Agentes a;
FILE *archivo = fopen("acuerdos.dat", "rb");
float totalAsegu[maxAsegu] = {0};
float totalEmple[maxEmple] = {0};
float totalGeneral= 0;
if(archivo == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
float matriz[maxEmple][maxAsegu] = {0};
   while(fread(&a, sizeof(struct Agentes), 1, archivo)) {
      int fila = a.ID_Empleado - 1;
      int col = a.Aseguradora -1;
      if(fila >= 0 && fila < maxEmple && col >= 0 && col < maxAsegu){
            matriz[fila][col] = matriz[fila][col] +  a.Monto_Liquidado;
      }
    }
    fclose(archivo);
for(int f=0; f<maxEmple;f++){
    for(int c =0;c<maxAsegu;c++){
        totalGeneral= totalGeneral + matriz[f][c];
        totalAsegu[c] = totalAsegu[c] + matriz[f][c];
        totalEmple[f] =totalEmple[f] + matriz[f][c];
    }
}
    printf("-------------------------------------\n");
    printf("REPORTE DE SEGUROS\n");
    printf("-------------------------------------\n");
    printf("%-5s", " ");
    for(int c = 0; c<maxAsegu;c++) {
        printf("Asegu%d|", c+1);
    }
    printf("TOTAL EMPLE");
    printf("\n");
    for(int f=0;f < maxEmple; f++) {
        printf("Emple%d ",f+1);
        for(int c = 0; c<maxAsegu;c++){
            printf("  %.2f", matriz[f][c]);
        }
        printf("  %.2f", totalEmple[f]);
        printf("\n");
    }
    printf("%-10s", "TOTAL ASE ");
    for(int c = 0; c < maxAsegu;c++) {
        printf("%.2f ", totalAsegu[c]);
    }
    printf("\n");
    printf("Total General: %.2f", totalGeneral);
    printf("\n");
}

void mejorAcuerdo(int *primerEmpleado, int *primerSeguro, float *primerRegistro){
    printf("Monto de mejor acuerdo: %.2f\n", *primerRegistro);
    printf("Empleado que lo logro: %d\n", *primerEmpleado);
    char *seguros[5] = {
    "La Caja", "Sancor",
    "Mapfre", "Provincia",
    "Federacion"
    };
    printf("Seguro: %s\n", seguros[*primerSeguro]);
}

void ordenar(){
struct Agentes a;
float aux = 0;
FILE *archivo = fopen("acuerdos.dat", "rb");
float totalEmple[maxEmple] = {0};
int ordenado;
if(archivo == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
float matriz[maxEmple][maxAsegu] = {0};
   while(fread(&a, sizeof(struct Agentes), 1, archivo)) {
      int fila = a.ID_Empleado - 1;
      int col = a.Aseguradora -1;
      if(fila >= 0 && fila < maxEmple && col >= 0 && col < maxAsegu){
            matriz[fila][col] = matriz[fila][col] +  a.Monto_Liquidado;
      }
    }
    fclose(archivo);
for(int f=0; f<maxEmple;f++){
    for(int c =0;c<maxAsegu;c++){
        totalEmple[f] =totalEmple[f] + matriz[f][c];
    }
}
do {
        ordenado = 1;
  for(int f = 0; f<maxEmple-1;f++) {
        if(totalEmple[f] < totalEmple[f+1]){
            aux = totalEmple[f];
            totalEmple[f] = totalEmple[f+1];
            totalEmple[f+1] = aux;
            ordenado = 0;
        }
}
}while(ordenado == 0);

}


void exportar(int *primerEmpleado, int *primerSeguro, float *primerRegistro) {
    FILE *maximo = fopen("premio.txt", "w");
    if(maximo != NULL) {
        fprintf(maximo, "Monto Liquidado Maximo: %.2f\n", *primerRegistro);
        fprintf(maximo, "Empleado: %d\n", *primerEmpleado);
        fprintf(maximo, "Aseguradora: %d\n", *primerSeguro);
        fclose(maximo);
    }

    FILE *archivo = fopen("acuerdos.dat", "rb");
    if(archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    FILE *exporte = fopen("matriz_acuerdos.csv", "w");
    if(exporte == NULL) {
        fclose(archivo);
        printf("No se pudo crear el CSV.\n");
        return;
    }

    struct Agentes a;
    float matriz[maxEmple][maxAsegu] = {0};

    while(fread(&a, sizeof(struct Agentes), 1, archivo)) {

        int fila = a.ID_Empleado - 1;
        int col = a.Aseguradora - 1;

        if(fila >= 0 && fila < maxEmple && col >= 0 && col < maxAsegu) {
            matriz[fila][col] += a.Monto_Liquidado;
        }
    }


    fprintf(exporte, "Empleado,");
    for(int c = 0; c < maxAsegu; c++) {
        fprintf(exporte, "Aseguradora%d,", c+1);
    }
    fprintf(exporte, "\n");

    for(int f = 0; f < maxEmple; f++) {
        fprintf(exporte, "Empleado%d,", f+1);

        for(int c = 0; c < maxAsegu; c++) {
            fprintf(exporte, "%.2f,", matriz[f][c]);
        }

        fprintf(exporte, "\n");
    }

    fclose(exporte);
    fclose(archivo);

    printf("\n-> Base de datos exportada correctamente a 'matriz_acuerdos.csv'\n");
    printf("-> Premio exportado correctamente a 'premio.txt'\n");
}


void vaciarArchivo(){
FILE *archivo = fopen("acuerdos.dat", "wb");
fclose(archivo);
}
