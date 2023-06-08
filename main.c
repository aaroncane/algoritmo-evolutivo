#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 10
#define COLUMNAS 10

void generarPoblacion(int poblacion[FILAS][COLUMNAS]) {
    int i, j;

    srand(time(NULL));

    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            poblacion[i][j] = rand() % 2;
        }
    }
}

void mostrarPoblacion(int poblacion[FILAS][COLUMNAS], int pesos[FILAS]) {
    int i, j;

    printf("Poblacion generada:\t  Pesos \n");
    for (i = 0; i < FILAS; i++) {
        for (j = 0; j < COLUMNAS; j++) {
            printf("%d ", poblacion[i][j]);
        }
        printf("\t  %d\n", pesos[i]);
    }
}

void funcionObjetivo(int poblacion[FILAS][COLUMNAS], int pesos[FILAS]) {
    int i;

    for (i = 0; i < FILAS; i++) {
        int decimal = 0;
        int base = 1;
        int j;

        for (j = COLUMNAS - 1; j >= 0; j--) {
            decimal += poblacion[i][j] * base;
            base *= 2;
        }
        pesos[i] = decimal;
    }
}


void cruza(int poblacion[FILAS][COLUMNAS], int poblacion_hijos[FILAS][COLUMNAS]){
    int i,j;
    int padre1, padre2;
    int puntoCruza;
    srand(time(NULL));
    padre1 = rand() % FILAS;
    padre2 = rand() % FILAS;
    
    puntoCruza = FILAS / 2;
    printf("\n padre1: %d, \n", padre1);
    for (j = 0; j < puntoCruza; j++) {
            poblacion_hijos[padre1][j] = poblacion[padre1][j];
            printf("%d", poblacion_hijos[padre1][j] );
    }
    printf("\n padre2: %d, \n", padre2);
    for (j = puntoCruza; j < FILAS; j++) {
        
            poblacion_hijos[padre2][j] = poblacion[padre2][j];
            printf("%d", poblacion_hijos[padre2][j] );
    }
    printf("\n \n \n");
}

int main() {
    int poblacion[FILAS][COLUMNAS];
    int poblacion_hijos[FILAS][COLUMNAS];
    int pesos[FILAS];
    int i, j;

    generarPoblacion(poblacion);
    funcionObjetivo(poblacion, pesos);
    printf("Poblacion padres\n");
    mostrarPoblacion(poblacion, pesos);
    i = 0;
    while (i < 2) {
        printf("\nGeneracion %d:\n", i + 1);
        cruza(poblacion,poblacion_hijos);
        //funcionObjetivo(poblacion, pesos);
        //printf("Poblacion hijos \n");

        //mostrarPoblacion(poblacion, pesos);
        i++;
    }


    return 0;
}
