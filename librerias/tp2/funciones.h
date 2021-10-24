#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
//#include <conio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define FACTORIAL(x) int f=1;\
int i;\
for(i=(x);i>1;i--)\
    f*=i;

int cantCaracteres(char* p);

int esShortInt(char* cad1);

int pow1(int base, int exp);

int esMayorQue(char* cad1, char*cad2);

#include "/home/bruno/Desktop/Unlam/Programacion/ejercicios/TP2/librerias/funciones.c"
//#include "E:\Unlam\Programacion\ejercicios\TP2\librerias\funciones.c"

#endif


