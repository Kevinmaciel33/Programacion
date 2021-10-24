#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

typedef struct
{
    int dia,
        mes,
        anio;
}t_Fecha;

void hola();
int factorial(int n);
int combinatoria(int n, int m);
float naturalElevado(int tol, int x); //Ejercicio 3
int fibonacci (int n); //Ejercicio 5
int sumaPrimerosNumerosPrimos(int n);//Ejercicio 11
int esBiciesto(int a);
int validarDia(int d,int m,int a);
int validarMes(int m);
int validarAnio(int a);
int validarFecha(int d, int m, int a);

void mostrarVec(int vec[], int tam);
void insertarElementoArray(int vec[], int n, int pos, int cantElem);
void insertarElementoArrayOrdenado(int* vec, int n, int cantElem);
int eliminarElementoArray(int* vec, int pos, int cantElem);
int eliminarPrimeraAparicionElementoArray(int* vec, int n, int cantElem);
int eliminarTodasAparicionElementoArray(int* vec, int n, int cantElem);
int palindromo(char* v, int tam);
int valorNumericoCadena(char* v, int tam);

#endif // HEADER_H
