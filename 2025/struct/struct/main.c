#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiante{
    int legajo;
    float promedioGeneral;
    char nombre[25];
};

///Declaraciones de las funciones o procedimientos!!!
struct Estudiante cargarEstudiante(int l, float p, char n[25]); //:)
///void cargarEstudiante2(int l, float p, char n[25], struct Estudiante e); //:)
struct Estudiante cargarEstudiantePorTeclado();
///void cargarEstudiantePorTeclado2 (struct Estudiante e);

void mostrarEstudiante(struct Estudiante e);

///--- Funciones y procedimientos que trabajan con arreglo de structs

///Cargar el arreglo!!!
void cargarEstudiantesPorTeclado(struct Estudiante a[], int t);

void mostrarEstudiantes(struct Estudiante a[], int t);

void ordenarEstudiantes(struct Estudiante a[], int t);




int main()
{
    printf("----------- Clase -------------\n");

    ///Arrays ----> Guargar MUCHOS datos DE UN MISMO TIPO
    ///En una unica variable!!!!

    ///Struct ----> Guardar MUCHOS datos de Distintito tipo
    ///En una misma variable

    //int               variable = 1;
    ///Asignación estatica con todos los datos juntos :(
    //struct Estudiante   estudiante1 = {11, 5.6, "Nico"};

    ///Asignación estatica pero con datos de uno en uno
    ///Estudiante con basura en los datos
    //struct Estudiante   estudiante2;

//estudiante2.legajo
 = 22;

//estudiante2.promedioGeneral
 = 8.9;
    ///Asignación estatica de arreglo de caracteres
    //strcpy(estudiante2.nombre, "NICO");

    ///Asignación dinamica
    //printf("Por favor ingresar el nombre!!!!\n");
    //fflush(stdin);
    //gets(estudiante2.nombre);

    //printf("\n---> Estudiante 1: \nLEGAJO: %d", estudiante1.legajo);

    //Cargar con funciones!!!!
    ///For de 3 (Muchos) Estudiantes ---
    //struct Estudiante estudiante3 = cargarEstudiante(123,9.3,"Brenda");
    //struct Estudiante estudiante4 = cargarEstudiante(123,9.3,"Flor");
    //struct Estudiante estudiante5 = cargarEstudiante(123,9.3,"Luis");

    //Funcion que muestra
    // mostrarEstudiante(estudiante3);


    ///Arreglos de Estructuras!!!!
    int tamanio = 3;  //3 estudiantes
    struct Estudiante arregloDeEstudiantes[tamanio];

    ///Cargarlo.... Mostrar
    cargarEstudiantesPorTeclado(arregloDeEstudiantes,tamanio);

    mostrarEstudiantes(arregloDeEstudiantes,tamanio);

    ordenarEstudiantes(arregloDeEstudiantes,tamanio);

    mostrarEstudiantes(arregloDeEstudiantes,tamanio);

    return 0;
}



///Declaraciones de las funciones o procedimientos!!!
struct Estudiante cargarEstudiante(int l, float p, char n[25]){

    struct Estudiante e;

    e.legajo = l;
    e.promedioGeneral = p;

    strcpy(e.nombre, n);

    return e;
}; //:);


///void cargarEstudiante2(int l, float p, char n[25], struct Estudiante e); //:)
struct Estudiante cargarEstudiantePorTeclado(){

    //struct Estudiante e;
    int l;
    float p;
    char n[25];

    printf("Ingresar legajo\n");
    scanf("%d", &l);

    printf("Ingresar promedio\n");
    scanf("%f", &p);

    printf("Ingresar nombre\n");
    scanf("%s", n);

    struct Estudiante e = cargarEstudiante(l,p,n);

    return e;
};
///void cargarEstudiantePorTeclado2 (struct Estudiante e);

void mostrarEstudiante(struct Estudiante e){


    printf("\n\n------ESTUDIANTE------\n");
    printf("\tLEGAJO: %d\n",e.legajo );
    printf("\tPROMEDIO: %.2f\n",e.promedioGeneral );
    printf("\tNOMBRE: %s\n",e.nombre );

};


///--- Funciones y procedimientos que trabajan con arreglo de structs

///Cargar el arreglo!!!
void cargarEstudiantesPorTeclado(struct Estudiante a[], int t){

    ///fgets(variable, sizeof(variable), stdin)
    for ( int i = 0; i< t; i++){

        a[i] = cargarEstudiantePorTeclado();

    }

};

void mostrarEstudiantes(struct Estudiante a[], int t){

    for ( int i = 0; i< t; i++){

        mostrarEstudiante(a[i]);

    }

};



void ordenarEstudiantes(struct Estudiante a[], int t){

    struct Estudiante aux;

    for ( int i = 0; i<t; i++){

        for ( int j = 0; j<t-1; j++){

            if (a[j].legajo > a[j+1].legajo ){

                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }





};
