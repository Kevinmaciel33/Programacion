#ifndef PILACIRCULAR_H_INCLUDED
#define PILACIRCULAR_H_INCLUDED

//PilaCircular.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMOBYTES(x,y) (((x) < (y)) ? (x) : (y))

typedef struct s_nodo
{
    void *info;
    unsigned tam;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo* t_pila;

void crearPila (t_pila *p);
int pilaVacia (const t_pila *p);
int pilaLlena (const t_pila *p, unsigned cantBytes);
void vaciarPila (t_pila *p);
int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes);
int sacarDePila (t_pila *p, void *dato, unsigned cantBytes);
int verTope (const t_pila *p, void *dato, unsigned cantBytes);


#endif // PILACIRCULAR_H_INCLUDED
