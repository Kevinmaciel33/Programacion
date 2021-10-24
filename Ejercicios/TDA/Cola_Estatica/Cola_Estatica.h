#ifndef COLA_ESTATICA_H_INCLUDED
#define COLA_ESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COLA 300

typedef struct
{
    char        cola[TAM_COLA];
    unsigned    pri,
                ult,
                tamDisp;
}tCola;

void crearCola(tCola *p);
int colaLlena(const tCola *p, unsigned cantBytes);
int ponerEnCola(tCola *p, const void *d, unsigned cantBytes);
int verPrimeroCola(tCola *p, void *d, unsigned cantBytes);
int colaVacia(const tCola *p);
int sacarDeCola(tCola *p, void *d, unsigned cantBytes);
void vaciarCola(tCola *p);
#endif // COLA_ESTATICA_H_INCLUDED
