#ifndef LISTADOBLEMENTEENLAZADA_H_INCLUDED
#define LISTADOBLEMENTEENLAZADA_H_INCLUDED

///ListaDE.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y) (((x) > (y)) ? (y) : (x))

typedef struct s_nodo{
                    void *dato;
                    unsigned tam;
                    struct s_nodo *sig;
                    struct s_nodo *ant;
                     }t_nodo;

typedef t_nodo* t_listaDE;
void crearListaDE(t_listaDE* p);
int ponerEnListaDEOrdenada (t_listaDE *p, const void *dato, unsigned cantBytes,
                             int (*cmp)(const void*, const void*));
int mostrarDelPrincipio(t_listaDE *p,void (*accion)(const void*));
void mostrarEnt (const void *pnodo);
int cmp_int (const void *d1,const void *d2);


#endif // LISTADOBLEMENTEENLAZADA_H_INCLUDED
