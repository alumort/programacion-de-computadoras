#include <stdio.h>
#include <stdlib.h>


// Procedimiento para cargar la matriz
void cargarMatrizPorTeclado(int filas, int columnas, int matriz[filas][columnas]);

void cargarMatrizAleatoria(int filas, int columnas, int matriz[filas][columnas]);

// Procedimiento para mostrar la matriz
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) ;

int main()
{
    printf("------------------- Clase Procedimientos sobre arrays 2 ----------------\n");

    int numero;
    char nombre[20];

    printf("Por favor ingrese un numero:\n");
    scanf("%d", &numero);


    printf("Por favor ingrese su nombre:\n");
    //fflush(stdin);//para vaciar el búfer ---- SOLO PARA WINDOWS
    getchar(); //Multiplataforma, consume un solo caracter, en este caso el \n
    fgets(nombre, sizeof(nombre), stdin);


    printf("\nEl numero ingresado es: %d\n", numero);

    int f = 4, c = 6;

    int matriz[f][c];

    cargarMatrizAleatoria(f,c,matriz);

    mostrarMatriz(f,c,matriz);



    return 0;
}



// Procedimiento para cargar la matriz
void cargarMatrizPorTeclado(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Procedimiento para cargar la matriz aleatoria
void cargarMatrizAleatoria(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

           matriz[i][j] = 10 + rand()%90;
        }
    }
}


// Procedimiento para mostrar la matriz
void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz:\n\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
