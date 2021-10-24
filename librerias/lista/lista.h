#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct s_nodo
{
    void* info;
    unsigned cantBy;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista *pl);
int ponerEnListaAlFinal(t_lista *pl, const void * dato, unsigned tamDato);
void recorrer (const t_lista *pl, void (*accion)(const void *d));
int insertarEnListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,
                            int(*comparar)(const void *d1, const void *d2),
                            int duplicado);

int insertarEnListaOrdenadaAgrupar
(t_lista *pl, const void *dato, unsigned tamDato,
 int (*comparar)(const void *d1, const void *d2),
 int (*accion)(const void *d1, const void *d2));

int eliminarDeListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,
                            int(*comparar)(const void *d1, const void *d2));
int eliminarDeLista(t_lista *pl, const void *dato, unsigned tamDato,
                    int(*comparar)(const void *d1, const void *d2));

int eliminarDeListaMuchos(t_lista *pl, const void *dato, unsigned tamDato,
                          int(*comparar)(const void *d1, const void *d2));

int compararEnterosMenorMayor(const void *dato1, const void *dato2);

int compararEnterosMayorMenor(const void *dato1, const void *dato2);

int ordenarLista(t_lista *pl, int(*comparar)(const void *d1, const void *d2));

t_nodo *buscarMinimo(t_lista *pl, int(*comparar)(const void *d1, const void *d2));

int maximosEnLista(t_lista *pl,int tope,const void* dato,unsigned tamDato,
                    int(*comparar)(const void *d1, const void *d2));

int actualizarEnListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,\
                              int(*comparar)(const void *d1, const void *d2),
                              void(*actualizar)(const void *d1, const void *d2));

void imprimirListaEnArchivo (const t_lista *pl,
                             void (*imprimir)(const void* dato, FILE **fp),
                             FILE**fp);
#endif // LISTA_H
