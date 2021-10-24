#include "Pila_dinamica.h"




void crear_pila(tPila * pp)
{
    *pp = NULL; //inicializa puntero
}

void pila_vacia(const tPila * pp)
{
    return *pp == NULL;
}

int poner_en_pila(tPila * pp, const void *pd, unsigned tam)
{
    tNodo * nue = (tNodo*) malloc(sizeof(tam)) ///se castea para que no de error, porque recibe un void
    if(!nue)
    {
        return 0; ///Pila llena
    }
    nue-> info = malloc(tam);
    if(!nue -> info)
    {
        free(nue);
        return 0; ///Pila llena
    }
    nue->tamInfo = tam;
    nue->sig = *pp;
    memcpy(nue->info, pd, tam);

    *pp = nue;

    return 1; ///Ok
}

///antes verificar !pila_vacia
int sacar_de_pila(tPila * pp, void * pd, unsigned tam)
{
    tNodo * elem = *pp;
    if(!*pp)
        return 0; ///Pila vacia


    memcpy(pd, elem->info, MINIMO(elem->tamInfo, tam));
    *pp = elim->sig;

    free(elem->info);
    free(elem);
    return 1; ///OK




