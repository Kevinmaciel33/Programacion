#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#define TAM 7

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int dni;
    char apyn [30];
}t_Alumno;

int* buscarMenorInt(const int * v, const int * fin);

//void ordenarSeleccionInt(int* v, size_t ce);
int cmp_ent(const void * v1, const void * v2);
void mostrarVec(int vector[], int tam);

void mostrarMatriz(int v[][TAM], int ord);

int sumatoriaTrianguloSuperior(int mat2[][TAM], int ord);
int sumatoriaTrianguloSuperiorSecundaria(int v[][TAM], int ord);
int sumatoriaTrianguloInferior(int v[][TAM], int ord);

int sumaTrazaDiagonalPrincipal(int v[][TAM], int ord);
int sumaTrazaDiagonalSecundaria(int v[][TAM], int ord);

int matrizDiagonal(int v[][TAM], int ord);
int matrizIdentidad(int v[][TAM], int ord);

int matrizSimetrica(int v[][TAM], int ord);

void transponerMatriz(int[][TAM], int ord);

void productoMatriz(int v1[][TAM], int v2[][TAM], int v3[][TAM],int ord);

void cuadranteT1(int v[][TAM], int ord);
void cuadranteT2(int v[][TAM], int ord);

#endif // MATRICES_H_INCLUDED
