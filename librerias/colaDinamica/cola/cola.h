#ifndef COLA_H
#define COLA_H
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    void* dato;
    unsigned tamDato;
    struct s_nodo *sig;
}t_nodo;

typedef struct
{
    t_nodo* pri;
    t_nodo* ult;
}t_cola;

void crearCola(t_cola *pc);
int colaVacia(const t_cola *pc);
int colaLlena(const t_cola *pc,unsigned cantBy);
void vaciarCola(t_cola *pc);
int verPrimero(const t_cola *pc, void *dato, unsigned cantBy);
int ponerEnCola(t_cola *pc,const void *dato, unsigned cantBy);
int sacarDeCola(t_cola *pc,void *dato, unsigned cantBy);

#endif // COLA_H
