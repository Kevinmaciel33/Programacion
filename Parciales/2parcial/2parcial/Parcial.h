#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Arbol.h"

typedef struct
{
    char   herramienta[15] ;
    int    stock;
    int    precio;
}tHerramienta;

void recorrerLista(tLista *pl, void (*accion)(void *), void *param);

int obtenerNodo(const tLista *p, void *d, unsigned cantBytes, int pos);

void imprimirConFormaHerramienta(void * info, unsigned tam, unsigned n, void * params);

int cmp(const tHerramienta * a, const tHerramienta * b);

int cmp_ent_herramienta(const void * a, const void * b);

int cmp_herramienta(const void * a, const void * b);

int cmp_ent(const void * v1, const void * v2);

int cmp_precio_precio(const void * a, const void * b);

void acumularStock(void* a, const void* b);

int insertarArbolBinBusqDirecto(tArbolBinBusq *p, void * d, unsigned tam, int(*cmp)(const void*, const void*));

void eliminarElementosArbolNoClave(tArbolBinBusq *p, int(*verificacion)(const void*));

int leerArchivoYCargarLista(tLista *p, const char * path_ctas);

void eliminarDuplicadosListaOrdenadaAcum (tLista *pl,int (*cmp)(const void*, const void*), void (*accion)(void*, const void*));

#endif // PARCIAL_H_INCLUDED
