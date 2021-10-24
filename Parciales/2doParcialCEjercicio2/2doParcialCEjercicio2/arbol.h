#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


#define CLA_DUP 0
#define SIN_MEM 0
#define SIN_INICIALIZAR 0
#define ERROR_ARCH 0
#define TODO_BIEN 1
#define MINIMO(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
               *der;
} tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;


#define reservarMemoriaNodo( X , Y , Z , W ) (( ( X ) = (tNodoArbol*)malloc( Y ) ) == NULL || ( ( Z ) = malloc( W ) ) == NULL   ? free( X ), 0 : 1  )


void crearArbolBinBusq(tArbolBinBusq *p);

int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,
    int (*cmp)(const void *, const void *));

int eliminarRaizArbolBinBusq(tArbolBinBusq * p);

void eliminarElementosArbolNoClave(tArbolBinBusq *p, int(*verificacion)(const void*));


void mostrarArbol(tArbolBinBusq *p,void(*mostrar)(void*, int ), int profundidad);



unsigned alturaArbolBin(const tArbolBinBusq * p);


tNodoArbol ** buscarRecNodoArbolBinBusq(const tArbolBinBusq * p, const void * d,
                                        int (*cmp)(const void*, const void *));
int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,
                           int (*cmp)(const void *, const void *));

tNodoArbol ** mayorRecNodoArbolBinBusq(const tArbolBinBusq * p);
tNodoArbol ** menorRecNodoArbolBinBusq(const tArbolBinBusq * p);



#endif // ARBOL_H_INCLUDED
