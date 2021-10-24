#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int dni;
    char apyn[30];
}tAlum;

void mostrarVec(char * c, int ce);
void ordenarSeleccionGen (void * base, int nMemb, int tam, int (*compararDato)(const void * d1,const void * d2));
int compararEnteros(const void * d1,const void * d2);
int compararCaracteres(const void * d1,const void * d2);
void intercambiarEnt(void * n1, void * n2);
 int intercambiarGen(void * n1, void * n2, int tam);
int compararAlum(const void * d1,const void * d2);
void* buscarMinimoGen (void * base, void * fin, int tam, int (*compararDato)(const void * d1,const void * d2));
#endif // HEADER_H_INCLUDED
