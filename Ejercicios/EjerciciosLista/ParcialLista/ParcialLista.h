#ifndef PARCIALLISTA_H_INCLUDED
#define PARCIALLISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void recorrerListaEnteros(const tLista *p);
int ObtenerInt(const tLista *p, void *d, unsigned cantBytes, int pos);
int leerArchivoYCargarLista(tLista *p, const char * path_ctas);
void eliminarDuplicados(tLista *p);
int cmp_ent(const void * v1, const void * v2);
void ordenar(tLista *p, int (*comparar)(const void *,const void *));

#endif // PARCIALLISTA_H_INCLUDED
