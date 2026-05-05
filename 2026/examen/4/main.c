#include <stdio.h>
#include <stdlib.h>
#define maxMate 5
#define maxTurno 3
#define maxNota 10

struct Examen {
int ID_Materia;
int Turno;
int Nota;
};

void cargarExamen();
void imprimir();
void bochados(int *totalDesaprobados, int *alumnos);
void mortalidad();
void vaciarArchivo();

int main()
{
    int opcion;
    int totalDesaprobados = 0;
    int alumnos = 0;

    do {printf("------------------------\n");
    printf("Notas\n");
    printf("1. cargar acta\n");
    printf("2. Notas maximas\n");
    printf("3. Analisis de bochados\n");
    printf("4. Ranking de mortalidad\n");
    printf("5. Vaciar archivo\n");
    printf("0.Salir\n");
    printf("Ingrese una opcion\n");
    if(scanf("%d", &opcion) != 1) {
        while(getchar()!= '\n');
        opcion = -1;
    }
    switch(opcion){
    case 1:
        {
            cargarExamen();
            break;
        }
        case 2: {
        imprimir();
        break;}
        case 3: {
        bochados(&totalDesaprobados, &alumnos);
        printf("Total desaprobados: %d\n", totalDesaprobados);
        printf("Alumnos totales: %d\n", alumnos);
        break;}
        case 4: {
        mortalidad();
        break;
        }
    case 5: {
    vaciarArchivo();
    printf("Archivo vaciado con exito");
    break;}
case 0:{
printf("Saliendo...\n");
break;}

default: {
printf("Error: opcion invalida\n");
break;}
    }

    }while(opcion !=0);
    return 0;
}

void cargarExamen(){
struct Examen e;
FILE *actas = fopen("finales.dat", "ab");
if(actas == NULL) {
    printf("Error al abrir el archivo\n");
    return;
}
while(1) {
    printf("Ingrese numero de materia del 1 al %d\n", maxMate);
    if(scanf("%d", &e.ID_Materia) != 1){
        while(getchar()!= '\n');
        e.ID_Materia = -1;
    }
       if(e.ID_Materia == 0) {
        break;
    }
    if(e.ID_Materia >maxMate || e.ID_Materia < 1) {
        printf("Error: la materia debe estar entre 1 y %d\n", maxMate);
        continue;
    }


    printf("Ingrese numero de turno del 1 al %d\n", maxTurno);
        if(scanf("%d", &e.Turno) != 1){
        while(getchar()!= '\n');
        e.Turno = -1;
    }
    if(e.Turno > maxTurno || e.Turno < 1 ) {
        printf("Error: los turnos van del 1 al %d\n", maxTurno);
        continue;
    }

    printf("Ingrese nota del 1 al %d\n", maxNota);
    if(scanf("%d", &e.Nota) != 1){
        while(getchar()!= '\n');
        e.Nota = -1;
    }
        if(e.Nota > maxNota || e.Nota < 1 ) {
        printf("Error: los turnos van del 1 al %d\n", maxNota);
        continue;
    }
        printf("->acta cargada con exito\n");
fwrite(&e, sizeof(struct Examen), 1, actas);
}
    fclose(actas);
}
void imprimir() {
    struct Examen e;
    FILE *actas = fopen("finales.dat", "rb");

    if(actas == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    int matriz[maxMate][maxTurno] = {0};
    int mayorMate[maxMate] = {0};
    int mayorTurno[maxTurno] = {0};

    while(fread(&e, sizeof(struct Examen), 1, actas) == 1) {
        int fila = e.ID_Materia - 1;
        int col = e.Turno - 1;

        if(e.Nota > matriz[fila][col]) {
            matriz[fila][col] = e.Nota;
        }

        if(e.Nota > mayorMate[fila]) {
            mayorMate[fila] = e.Nota;
        }

        if(e.Nota > mayorTurno[col]) {
            mayorTurno[col] = e.Nota;
        }
    }

    fclose(actas);

    printf("\nMATRIZ DE NOTAS MAXIMAS\n");
    printf("         ");
    for(int m = 0; m < maxMate; m++) {
        printf("Mat%d ", m+1);
    }
    printf("\n");

    for(int t = 0; t < maxTurno; t++) {
        printf("Turno%d  ", t+1);
        for(int m = 0; m < maxMate; m++) {
            printf("%4d", matriz[m][t]);
        }
        printf("\n");
    }

    printf("MaxMat   ");
    for(int m = 0; m < maxMate; m++) {
        printf("%4d", mayorMate[m]);
    }

    printf("\n");
}
void bochados(int *totalDesaprobados, int *alumnos) {
    struct Examen e;

    FILE *actas = fopen("finales.dat", "rb");

    if(actas == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    /* Reiniciar contadores */
    *totalDesaprobados = 0;
    *alumnos = 0;

    while(fread(&e, sizeof(struct Examen), 1, actas) == 1) {

        /* Cada registro representa un alumno */
        (*alumnos)++;

        /* Nota menor o igual a 6 = desaprobado */
        if(e.Nota <= 6) {
            (*totalDesaprobados)++;
        }
    }

    fclose(actas);
}

void mortalidad() {
    struct Examen e;
    int aplazosMateria[maxMate] = {0};

    char *materias[maxMate] = {
        "Matematica",
        "Programacion",
        "Sistemas",
        "Ingles",
        "Arquitectura"
    };

    FILE *actas = fopen("finales.dat", "rb");

    if(actas == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }

    /* Contar aplazos por materia (nota <= 3) */
    while(fread(&e, sizeof(struct Examen), 1, actas) == 1) {
        if(e.Nota <= 3) {
            int materia = e.ID_Materia - 1;

            if(materia >= 0 && materia < maxMate) {
                aplazosMateria[materia]++;
            }
        }
    }

    fclose(actas);

    /* Ordenar de mayor a menor junto con nombres */
    for(int i = 0; i < maxMate - 1; i++) {
        for(int j = 0; j < maxMate - 1 - i; j++) {
            if(aplazosMateria[j] < aplazosMateria[j + 1]) {

                int aux = aplazosMateria[j];
                aplazosMateria[j] = aplazosMateria[j + 1];
                aplazosMateria[j + 1] = aux;

                char *auxNom = materias[j];
                materias[j] = materias[j + 1];
                materias[j + 1] = auxNom;
            }
        }
    }

    /* Mostrar ranking */
    printf("\nRANKING DE MORTALIDAD ACADEMICA\n");

    for(int i = 0; i < maxMate; i++) {
        printf("%d. %s -> %d aplazos\n",
               i + 1,
               materias[i],
               aplazosMateria[i]);
    }

    /* Mostrar mayor mortalidad */
    printf("\nLa materia con mas aplazos es %s\n", materias[0]);
    printf("Cantidad de aplazos: %d\n", aplazosMateria[0]);
}

void vaciarArchivo() {
FILE *actas = fopen("finales.dat", "wb");
fclose(actas);
}
