#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <string.h>
#define MINIMO( X , Y ) ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )

typedef struct s_nodoPila
{
    void * info;
    unsigned tam;
    struct s_nodoPila * sig;
} t_nodoPila;

typedef t_nodoPila* t_pila;

void crearPila (t_pila *p);
int pilaVacia (const t_pila *p);
int pilaLlena (const t_pila *p, unsigned cantBytes);
void vaciarPila (t_pila *p);
int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes);
int sacarDePila (t_pila *p, void *dato, unsigned cantBytes);
int verTope (const t_pila *p, void *dato, unsigned cantBytes);

#endif // PILA_H
