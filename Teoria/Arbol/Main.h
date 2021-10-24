#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbol.h"

int cmp_ent(const void *v1, const void *v2);
void imprimirConForma(void *info, unsigned tam, unsigned n, void *params);
void imprimir(void *info, unsigned tam, unsigned n, void *params);
void imprimir_arch(void *info, unsigned tam, unsigned n, void *params);
void guardarVecEnteros(void *info, unsigned tam, unsigned n, void *params);
unsigned leerDesdeVectorEnteros(void **d, void *vec, unsigned pos, void *params);
unsigned leerDesdeVector(void ** d, void * vec, unsigned pos, void * params);
int crearArchivo(char*path, void * vec, unsigned tam, unsigned ce);

#endif // MAIN_H_INCLUDED
