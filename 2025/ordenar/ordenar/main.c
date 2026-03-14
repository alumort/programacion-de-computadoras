#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarVector(int t, int v[]);
void mostrarVector(int t, int v[]);
//pos
int buscarEnVector(int t, int v[], int datoQueBusco);
void ordenarVector(int t, int v[]);
int buscarEnVectorB(int t, int v[], int datoQueBusco);

///Matrices
void cargarMatriz(int c,int f,  int m[c][f]);
void mostrarMatriz(int c,int f, int m[c][f]);

int main()
{//Estoy en el main
    srand(time(0));
    printf("-------- CLASE 4 --------\n");

    //Arreglos!!! --- Funciones y Procedimientos!!!
    //Definimos
    int col = 10;
    int ren = 5;

    int matriz[col][ren]; //Tamaño es fijo durante todo el
    //ejercicio
    //Cargamos con valores - aleatorios
    cargarMatriz(col, ren, matriz);
    //Mostramos
    mostrarMatriz(col, ren, matriz);

   //0 --> TT 5   6   3   6   10  2
   //1---> TN 7   8   3   9   10  2
   //2---> TM 1   2   3   9   10  2
   ///arrays de arrays -- Arrays BIdimensionales!!


    return 0;
} //Cierro el main

///Implementación!!!
void cargarVector(int t, int v[]){
    //Pensarlo con while
    ///V = _  _  _  _  _
    ///    0  1  2           ---------> t-1
    for ( int i = 0 ;i<t; i++ ){
        v[i]  = rand()%100;
        ///Print - Scanf
    }
};

void mostrarVector(int t, int v[]){
    printf("\n[ ");
    ///i++ ----> i = i + 1;
    ///i+=3 ----> i = i + 3;
    for ( int i = 0 ;i<t; i++){
        printf(" %d, ", v[i]);
    }
    printf("]\n\n");

};

int buscarEnVector(int t, int v[], int datoQueBusco){
     int posBusqueda = -1;
     for ( int i = 0 ;i<t; i++){

            if ( v[i] == datoQueBusco){
                posBusqueda = i;
            }
    }
    /*
    if(posBusqueda != -1){
        printf("\nLo encontre: %d ", posBusqueda);
    }else{
         printf("\nNO Lo encontre!!!");
    }
    */
    return posBusqueda;  ///0---> t-1
};

///Burbuja!!! for - for  while - for
void ordenarVector(int t, int v[]){
    //{ Repetir!!!! t veces
    /// 4    13    5    12  1
    /// i  <  i+1
    ///permutaba
    /// 13   4     5     12  1
    ///      i+1   i+2
    /// 13   5      12    4  1
    int aux;
    for ( int j = 0 ; j<t; j++){ //While
        for ( int i = 0 ; i< t-1; i++){
            if ( v[i] < v[i+1]){ //permuto
               aux = v[i] ;
               v[i]  = v[i+1] ;
               v[i+1] = aux;
            }
        }
    }

};


int buscarEnVectorB(int t, int v[], int datoQueBusco){

    int pos = -1;

    int medio = t/2; /// 7/2 ----> 3
    //0  1   2  3   4
    //M2; i0  --- f4
    //m3;i2 f4

   if ( v[medio]==datoQueBusco){
        pos = medio;
   }else{ //No lo encontre....

    if(datoQueBusco > v[medio]){
        medio = medio +1; //Mal-- derecha
    }
    if(datoQueBusco < v[medio]){
        medio = medio -1; //Mal-- izq
    }

   }



    return pos;
};


///Matrices
void cargarMatriz(int c,int f,  int m[c][f]){
    ///renglones!!!
    for ( int iF = 0; iF<f; iF++ ){
        ///Columnas!!!!
        for ( int iC = 0; iC<c; iC++){
            m[iC][iF]   = 10 + rand()%90;
        }
    }
};

void mostrarMatriz(int c,int f, int m[c][f]){
    ///renglones!!!
    for ( int iF = 0; iF<f; iF++ ){
        ///Columnas!!!!
        for ( int iC = 0; iC<c; iC++){
           printf("  %d  ", m[iC][iF]);
        }
        printf("\n");
    }
};

