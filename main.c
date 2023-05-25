#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int** generar_poblacion(int filas, int columnas);

int main() {
    int filas = 8;
    int columnas = 8;
    // GENERAR MATRIZ DE POBLACION
    int** poblacion = generar_poblacion(filas, columnas);

    // MUESTRA MATRIZ
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", poblacion[i][j]);
        }
        printf("\n");
    }

        renglones_aleatorios(poblacion, filas, columnas);

    return 0;
}

int** generar_poblacion(int filas, int columnas) {
    // CREAR MATRIZ
    int** matriz = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int*)malloc(columnas * sizeof(int));
    }

    // GENERAR MATRIZ CON VALORES ALEATORIOS ENTRE O Y 1
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 2;
        }
    }
    return matriz;
}



void renglones_aleatorios(int** matriz, int filas, int columnas) {

    // SELECCIONA INDICES AL AZR
    srand(time(NULL));
    int indice1 = rand() % filas;
    int indice2 = rand() % filas;

    // MOSTRAR RENGLON SELECCIONADO
    printf("Renglones seleccionados:\n");
    printf("Renglon %d: ", indice1+1);
    for (int j = 0; j < columnas; j++) {
        printf("%d ", matriz[indice1][j]);
    }
    printf("\n");
    printf("Renglon %d: ", indice2+1);
    for (int j = 0; j < columnas; j++) {
        printf("%d ", matriz[indice2][j]);
    }
    printf("\n");
}
