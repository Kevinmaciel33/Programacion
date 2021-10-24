#include "colaCircular.h"
#include <stdio.h>
#include <stdlib.h>
void crearCola(t_cola *c)
{
    *c=NULL;
}

int colaVacia(const t_cola* c)
{
    return *c == NULL;
}

int colaLlena(const t_cola* c, unsigned cantBy)
{
    t_nodo_cola *aux = (t_nodo_cola*)malloc(sizeof(t_nodo_cola));
    if(!aux)
        return 1;

    aux->info = malloc(cantBy);
    if(!aux->info)
    {
        free(aux);
        return 1;
    }

    free(aux->info);
    free(aux);

    return 0;
}

int ponerEnCola(t_cola *c, const void* d, unsigned cantBy)
{
    t_nodo_cola *nue = (t_nodo_cola*)malloc(sizeof(t_nodo_cola));
    if(!nue)
        return 0;

    nue->info = malloc(cantBy);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, d, cantBy);
    nue->tamInfo = cantBy;

    ///ENGANCHE
    if(!*c)
        nue->sig = nue; ///si no hay nada, se apuntara a si mismo
    else ///si hay algo ya cargado en cola
    {
        nue->sig = (*c)->sig; ///como cola apunta al ult q se ingreso, su sig sera el primero, haciendo un bucle. ahora el sig de nue apuntara al pri
        (*c)->sig = nue; ///engancho el ult con el nue
    }
    *c = nue; ///el ingresado sera el nuevo ult, x lo q cola apuntara aqui

    return 1;
}

int sacarDeCola(t_cola *c, void* d, unsigned cantBy) ///saco siempre el primero q se ingreso
{
    t_nodo_cola *elim;

    if(!*c)
        return 0;

    elim = (*c)->sig;
    memcpy(d, elim->info, minimo(cantBy, elim->tamInfo));

    ///ENGANCHE
    if(elim == *c) ///cuando hay un unico nodo, q se apunta a si mismo
        *c = NULL;
    else
        (*c)->sig = elim->sig; ///lo q apunta cola, su sig debe apuntar al sig del primero(q es elim y recien se saco)

    free(elim->info);
    free(elim);

    return 1;
}

void vaciarCola(t_cola *c)
{
    t_nodo_cola *elim;

    while(*c)
    {
        elim = (*c)->sig;

        if(*c == elim)
            *c = NULL;
        else
            (*c)->sig = elim->sig;

        free(elim->info);
        free(elim);
    }
}

int verPrimero(const t_cola *c, void *d, unsigned cantBy)
{
    if(!*c)
        return 0;

    memcpy(d, (*c)->sig->info, minimo(cantBy, (*c)->sig->tamInfo));

    return 1;
}
