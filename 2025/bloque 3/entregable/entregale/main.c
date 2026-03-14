#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int cargarMatriz(int m[4][12]);
int calcularTotalGeneral(int m [4] [12]);
int calcularTotalEmpresa (int m [4][12]);
int calcularTotalMes (int m [4] [12]);
void mostrarMatriz(int m[4][12]);
int mayorGanancia (int m[4] [12]);
int menorGanancia (int m[4][12]);
int promedioBimestre (int m[4] [12]);


int main()
{
    srand(time(0));
    int mat [4][12];
    int mes;
    cargarMatriz(mat);
    mostrarMatriz(mat);
    mayorGanancia(mat);
    menorGanancia(mat);
    calcularTotalGeneral(mat);
    calcularTotalMes(mat);
    calcularTotalEmpresa(mat);
    promedioBimestre(mat);
    return 0;
}

int cargarMatriz(int mat[4][12]){
    for (int iF = 0 ; iF< 4; iF++ ){
            for (int iC = 0; iC < 12;iC++){
               mat [iF] [iC] = rand() % 100;
            }

    }
};

void mostrarMatriz(int mat[4] [12]){
    for ( int iF = 0 ;iF < 4; iF++ ){
            for (int iC = 0; iC < 12; iC++){
               printf("  %d ", mat [iF] [iC]);
            }
            printf("\n");
    }
};

int calcularTotalGeneral(int m[4] [12]) {
    int totalGeneral = 0;
    for (int iF = 0; iF < 4; iF++) {
        for (int iC = 0; iC < 12; iC++) {
            totalGeneral += m[iF][iC];
        }
    }
    return totalGeneral;
}

int calcularTotalMes (int m [4] [12]){
    int mes = 0;
    for (int iC = 0; iC < 12; iC++){
            for ( int iF = 0 ;iF < 4; iF++ ){
               mes += m[iF][iC];
            }
            printf("\n total del mes %d es : %d \n", iC, mes);
            mes = 0;
    }


}


int calcularTotalEmpresa(int m[4][12]) {
    int totalEmpresa = 0;
    for (int iF = 0; iF < 4; iF++) {
        for (int iC = 0; iC < 12; iC++) {
            totalEmpresa += m[iF][iC];
        }
        printf("\n total de la empresa %d es : %d \n", iF, totalEmpresa);
            totalEmpresa = 0;
    }
}


int mayorGanancia(int m [4] [12]) {
    int empresa = 0;
    int mes = 0;
    int maxGanancia = 0;
    for (int iF = 0; iF < 4; iF++) {
        for (int iC = 0; iC < 12; iC++) {
            if (m[iF][iC] > maxGanancia) {
                maxGanancia = m[iF][iC];
                empresa = iF;
                mes = iC;
            }
        }
    }
    printf("\n Empresa con mayor ganancia: %d\n", empresa);
    printf("\n Mes de mayor ganancia: %d\n", mes);
}

int menorGanancia(int m [4] [12]) {
    int empresa = 0;
    int mes = 0;
    int minGanancia = 500;
    for (int iF = 0; iF < 4; iF++) {
        for (int iC = 0; iC < 12; iC++) {
            if (m[iF][iC] < minGanancia) {
                minGanancia = m[iF][iC];
                empresa = iF;
                mes = iC;
            }
        }
    }
    printf("\n Empresa con menor ganancia: %d\n", empresa);
    printf("\n Mes de menor ganancia: %d\n", mes);
}

int promedioBimestre(int m[4][12]) {
    for (int iC = 0; iC < 12; iC += 2) {
        double maxPromedio = 0;
        int maxEmpresa = 0;

        printf("\nBimestre %d:\n", iC / 2 + 1);

        for (int iF = 0; iF < 4; iF++) {
            int suma = 0;
            for (int j = 0; j < 2; j++) {
                suma += m[iF][iC + j];
            }
            double promedio = (double)suma / 2;
            printf("Empresa %d: %.2f\n", iF, promedio);

            if (promedio > maxPromedio) {
                maxPromedio = promedio;
                maxEmpresa = iF;
            }
        }

        printf("La empresa %d tuvo el mayor promedio de %.2f en el bimestre %d.\n", maxEmpresa, maxPromedio, iC / 2 + 1);
    }
}
