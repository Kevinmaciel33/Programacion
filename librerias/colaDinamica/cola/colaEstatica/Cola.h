#ifndef COLA_H
#define COLA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_COLA 40

typedef struct{
    char cola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisponible;
}t_cola;

void crearCola(t_cola* p);
int colaVacia(const t_cola* p);
int colaLlena(const t_cola* p, unsigned cantBytes);
int ponerEnCola(t_cola* p,const void *dato,unsigned cantBytes);
int sacarDeCola(t_cola* p,void *dato,unsigned cantBytes);
void vaciarCola(t_cola* p);
int verPrimero(const t_cola* p, void *dato, unsigned cantBytes);

#endif // COLA_H
