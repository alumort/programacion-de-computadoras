#include <stdio.h>
#include <stdlib.h>
#define maxDoctor 6
#define maxCober 4

struct Clinica {
int Numero_Medico;
int Cobertura;
int Edad_Paciente;};


void cargarTurno(int *edadesParticulares, int *contadorParticulares);
void matrizFrecuencia();
float promedioEdades(int *edadesParticulares, int *contadorParticulares);
void rankingMedicos();
void exportarCSV();
void vaciarArchivo();

int main()
{
    int opcion;
    int edadesParticulares = 0;
    int contadorParticulares = 0;
    int pacientes[maxDoctor][maxCober] = {0};

    do {
    printf("============\n");
    printf("Clinica\n");
    printf("============\n");
    printf("1. Cargar Turnos\n");
    printf("2. Matriz de Frecuencia\n");
    printf("3. Promedio de Edad\n");
    printf("4. Ranking de Medicos\n");
    printf("5. Exportar CSV\n");
    printf("6. Vaciar Sistema\n");
    printf("0. Guardar y Salir\n");
    printf("elija su opcion:\n");
    if(scanf("%d", &
             opcion) != 1) {
        while(getchar() != '\n');
        opcion = -1;
    }
    switch(opcion) {

    case 1: {
    cargarTurno(&edadesParticulares, &contadorParticulares);
    break;
    }

    case 2: {
    matrizFrecuencia();
    break;
    break;}

    case 3: {
    float promedioParticulares = promedioEdades(&edadesParticulares, &contadorParticulares);

    printf("Hasta ahora el promedio de edad de los pacientes particulares es de: %.2f\n", promedioParticulares);
    break;
    }
    case 4: {
    rankingMedicos();
    break;
    }

    case 5: {
    exportarCSV();
    printf("sistema exportado con exito\n");
    break;}

    case 6: {
    vaciarArchivo();
    printf("Sistema vaciado con exito\n");
    break;
    }

    case 0: {
        printf("guardando...\n");
exportarCSV(pacientes);
printf("guardado\n");
printf("saliendo...\n");
    break;}

    default: {
    printf("ERROR: opcion invalida, intente de nuevo.\n");
    break;}
    }
    }while(opcion!= 0);
    return 0;
}


void cargarTurno(int *edadesParticulares, int *contadorParticulares) {
    struct Clinica c;
    FILE *consultorio = fopen("turnos.dat", "ab");

    if(consultorio == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    while(1) {
        printf("Ingrese numero del doctor del 1 al %d (0 para salir): ", maxDoctor);

        if(scanf("%d", &c.Numero_Medico) != 1) {
            while(getchar() != '\n');
            continue;
        }

        if(c.Numero_Medico == 0) break;

        printf("Ingrese numero de cobertura de 1 a %d: ", maxCober);

        if(scanf("%d", &c.Cobertura) != 1) {
            while(getchar() != '\n');
            continue;
        }

        if(c.Numero_Medico < 1 || c.Numero_Medico > maxDoctor ||
           c.Cobertura < 1 || c.Cobertura > maxCober) {
            printf("Datos invalidos.\n");
            continue;
        }

        printf("Ingrese edad del paciente: ");

        if(scanf("%d", &c.Edad_Paciente) != 1 || c.Edad_Paciente <= 0) {
            while(getchar() != '\n');
            printf("Edad invalida.\n");
            continue;
        }

        int doctor = c.Numero_Medico - 1;
        int cobertura = c.Cobertura - 1;


        if(c.Cobertura == 4) {
            *edadesParticulares += c.Edad_Paciente;
            (*contadorParticulares)++;
        }

        fwrite(&c, sizeof(struct Clinica), 1, consultorio);

        printf("-> turno cargado con exito\n");
    }

    fclose(consultorio);
}


void matrizFrecuencia() {
int totalPacienteDr[maxDoctor] = {0};
int totalPacienteCo[maxCober] = {0};
struct Clinica c;
FILE *consultorio = fopen("turnos.dat", "rb");
if(consultorio == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
int pacientes[maxDoctor][maxCober] = {0};
   while(fread(&c, sizeof(struct Clinica), 1, consultorio)) {
      int fila = c.Numero_Medico - 1;
      int col = c.Cobertura -1;
      if(fila >= 0 && fila < maxDoctor && col >= 0 && col < maxCober){
            pacientes[fila][col]++;
      }
    }
    fclose(consultorio);
printf("REPORTE DE LA CLINICA\n");
printf("=======================\n");
printf("%-2s", " ");
printf("OSDE-IOMA-PAMI-PARTICULAR-TOTAL DOCTOR\n");

for(int f = 0; f<maxDoctor; f++) {
    printf("Dr%d ", f+1);
    for(int c = 0; c<maxCober; c++){
        printf("%-3d ",pacientes[f][c]);
        totalPacienteDr[f] += pacientes[f][c];
        totalPacienteCo[c] += pacientes[f][c];
    }
    printf("%d", totalPacienteDr[f]);
    printf("\n");
}
printf("==========================\n");
printf("TOTAL POR COBERTURA\n");
for(int i = 0; i < maxCober; i++) {
    printf(" %d ", totalPacienteCo[i]);
}
printf("\n");
}

float promedioEdades(int *edadesParticulares, int *contadorParticulares) {
float promedio;
if(*contadorParticulares == 0) {
    printf("No hay pacientes particulares.\n");
    return 0;
} else {promedio = (float)(*edadesParticulares) / (*contadorParticulares);
return promedio;
}

}

void rankingMedicos() {

    struct Clinica c;
FILE *consultorio = fopen("turnos.dat", "rb");
if(consultorio == NULL) {
    printf("No se pudo abrir el archivo.\n");
    return;
}
int pacientes[maxDoctor][maxCober] = {0};
   while(fread(&c, sizeof(struct Clinica), 1, consultorio)) {
      int fila = c.Numero_Medico - 1;
      int col = c.Cobertura -1;
      if(fila >= 0 && fila < maxDoctor && col >= 0 && col < maxCober){
            pacientes[fila][col]++;
      }
    }
    fclose(consultorio);
    int doctores[maxDoctor] = {0};
    int numeroDoc[maxDoctor];

    for(int i = 0; i < maxDoctor; i++) {
        numeroDoc[i] = i + 1;

        for(int j = 0; j < maxCober; j++) {
            doctores[i] += pacientes[i][j];
        }
    }

    for(int i = 0; i < maxDoctor-1; i++) {
        for(int j = 0; j < maxDoctor-1-i; j++) {
            if(doctores[j] < doctores[j+1]) {
                int aux = doctores[j];
                doctores[j] = doctores[j+1];
                doctores[j+1] = aux;

                int auxDoc = numeroDoc[j];
                numeroDoc[j] = numeroDoc[j+1];
                numeroDoc[j+1] = auxDoc;
            }
        }
    }

    printf("RANKING DE MEDICOS:\n");
    for(int i = 0; i < maxDoctor; i++) {
        printf("Doctor %d - Pacientes: %d\n", numeroDoc[i], doctores[i]);
    }
}

void exportarCSV() {
    FILE *consultorio = fopen("turnos.dat", "rb");

    if(consultorio == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    FILE *archivo = fopen("estadisticas.csv", "w");

    if(archivo == NULL) {
        printf("No se pudo crear el archivo CSV.\n");
        fclose(consultorio);
        return;
    }

    struct Clinica c;
    int matriz[maxDoctor][maxCober] = {0};

    while(fread(&c, sizeof(struct Clinica), 1, consultorio)) {
        int fila = c.Numero_Medico - 1;
        int col = c.Cobertura - 1;

        if(fila >= 0 && fila < maxDoctor &&
           col >= 0 && col < maxCober) {
            matriz[fila][col]++;
        }
    }

    fprintf(archivo, "Doctor,OSDE,IOMA,PAMI,PARTICULAR\n");

    for(int f = 0; f < maxDoctor; f++) {
        fprintf(archivo, "Doctor%d", f + 1);

        for(int c = 0; c < maxCober; c++) {
            fprintf(archivo, ",%d", matriz[f][c]);
        }

        fprintf(archivo, "\n");
    }

    fclose(consultorio);
    fclose(archivo);

    printf("Archivo CSV exportado correctamente.\n");
}


void vaciarArchivo() {
FILE *consultorio = fopen("turnos.dat", "wb");
fclose(consultorio);
}
