#include "arbol.h"



void crearArbolBinBusq(tArbolBinBusq *p)
{
    *p = NULL;
}


int insertarRecArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,
                            int (*cmp)(const void *, const void *))
{
    tNodoArbol *nue;
    int         rc;
    if(*p)
    {
        if((rc = cmp(d, (*p)->info)) < 0)
            return insertarRecArbolBinBusq(&(*p)->izq, d, tam, cmp);
        if (rc > 0)
            return insertarRecArbolBinBusq(&(*p)->der, d, tam, cmp);
        return CLA_DUP;
    }
    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return SIN_MEM;
    nue->tamInfo = tam;
    memcpy(nue->info, d, tam);
    nue->der = NULL;
    nue->izq = NULL;
    *p = nue;
    return TODO_BIEN;
}

int eliminarRaizArbolBinBusq(tArbolBinBusq * p)
{
    tNodoArbol ** remp,
               * elim;
    if(!*p)
        return 0; ///ARBOL_VACIO
    free((*p)->info);
    if (!(*p)->izq && !(*p)->der)
    {
        free(*p);
        *p = NULL;
        return 1; ///OK
    }
    remp = alturaArbolBin(&(*p)->izq)>alturaArbolBin(&(*p)->der)?        mayorRecNodoArbolBinBusq(&(*p)->izq):
           menorRecNodoArbolBinBusq(&(*p)->der);
    elim = *remp;
    (*p)->info = elim->info;
    (*p)->tamInfo = elim->tamInfo;
    *remp = elim->izq ? elim->izq : elim->der;
    free(elim);

    return 1; ///OK
}


void eliminarElementosArbolNoClave(tArbolBinBusq *p, int(*verificacion)(const void*))
{
    if(!*p)
        return;
    if((*p)->izq)
        eliminarElementosArbolNoClave(&(*p)->izq,verificacion);
    if((*p)->der)
        eliminarElementosArbolNoClave(&(*p)->der,verificacion);
    if(verificacion((*p)->info))
        eliminarRaizArbolBinBusq(p);
}


void mostrarArbol(tArbolBinBusq *p,void(*mostrar)(void*, int ), int profundidad)
{
    if(!*p)
        return;
    mostrarArbol(&(*p)->izq,mostrar, profundidad +1);


    mostrar((*p)->info,profundidad);
    mostrarArbol(&(*p)->der,mostrar,profundidad +1);


}










unsigned alturaArbolBin(const tArbolBinBusq * p)
{
    int hi,
        hd;
    if(!*p)
        return 0;
    hi= alturaArbolBin(&(*p)->izq);
    hd= alturaArbolBin(&(*p)->der);
    return (hi>hd ? hi : hd) +1;
}


tNodoArbol ** buscarRecNodoArbolBinBusq(const tArbolBinBusq * p, const void * d,
                                        int (*cmp)(const void*, const void *))
{
    int rc;
    if(!*p)
        return NULL;
    if(*p && (rc=cmp(d, (*p)->info)))
    {
        if(rc<0)
            return buscarRecNodoArbolBinBusq(&(*p)->izq, d, cmp);
        return buscarRecNodoArbolBinBusq(&(*p)->der, d, cmp);
    }
    return (tNodoArbol **) p;
}

int buscarElemArbolBinBusq(const tArbolBinBusq *p, void *d, unsigned tam,
                           int (*cmp)(const void *, const void *))
{
    if(!(p = buscarRecNodoArbolBinBusq(p,d,cmp)))
        return 0; ///NO_EXISTE
    memcpy(d, (*p)->info, MINIMO(tam, (*p)->tamInfo));
    return 1;
}

tNodoArbol ** mayorRecNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;
    if(!(*p)->der)
        return (tNodoArbol **) p;
    return mayorRecNodoArbolBinBusq(&(*p)->der);
}

tNodoArbol ** menorRecNodoArbolBinBusq(const tArbolBinBusq * p)
{
    if(!*p)
        return NULL;
    if(!(*p)->izq)
        return (tNodoArbol **) p;
    return menorRecNodoArbolBinBusq(&(*p)->izq);
}



