#ifndef PILA_DINAMICA_H_INCLUDED
#define PILA_DINAMICA_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct sNodo
{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
} tNodo;

typedef tNodo *tPila;

void crearPila(tPila * p);
int pilaVacia(const tPila * p);
int ponerEnPila(tPila * pp, const void *pd, unsigned tam);
int sacarDePila(tPila * pp, void * pd, unsigned tam);
int pilaLlena(const tPila *p, unsigned cantBytes);
int verTope(const tPila *p, void *d, unsigned cantBytes);
void vaciarPila(tPila *p);


#endif // PILA_DINAMICA_H_INCLUDED
