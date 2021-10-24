#include "Pila_dinamica.h"

#define minimo( X , Y )      ( ( X ) <= ( Y ) ? ( X ) : ( Y ) )



void crearPila(tPila * p)
{
    *p = NULL; //inicializa puntero
}

int pilaVacia(const tPila * p)
{
    return *p == NULL;
}

int ponerEnPila(tPila * p, const void *d, unsigned cantBytes)
{
    tNodo * nue;

    ///se castea para que no de error, porque recibe un void
    if((nue = (tNodo *)malloc(sizeof(tNodo))) == NULL ||
            (nue->info = malloc(cantBytes)) == NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info, d, cantBytes);
    nue->tamInfo = cantBytes;
    nue->sig = *p;
    *p = nue;
    return 1; ///Ok
}

///antes verificar !pila_vacia
int sacarDePila(tPila * p, void * d, unsigned cantBytes)////////
{
    tNodo * aux = *p;

    if(aux == NULL)
        return 0; ///Pila vacia

    *p = aux->sig;
    memcpy(d, aux->info, minimo(aux->tamInfo, cantBytes));
    free(aux->info);
    free(aux);
    return 1; ///OK

}

int pilaLlena(const tPila *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);
    return aux == NULL || info == NULL;
}

int verTope(const tPila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return 0;

    memcpy(d, (*p)->info, minimo(cantBytes, (*p)->tamInfo));
    return 1;
}
void vaciarPila(tPila *p)
{
    while(*p)
    {
        tNodo *aux = *p;

        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}






