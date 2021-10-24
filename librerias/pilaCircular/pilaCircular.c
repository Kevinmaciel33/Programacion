#include "pilaCircular.h"

/*p apunta al primer elemento que puse en pila. Pero este apunta al ultimo
y en sacar de pila saco el siguiente de p, o sea el ultimo.
a su vez este ultimo elemento apunta al anterior como en toda pila.*/
void crearPila (t_pila *p)
{
    *p=NULL;
}
int pilaVacia (const t_pila *p)
{
    return *p==NULL;
}
int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes)
{
    t_nodo *nue;
    nue=malloc(sizeof(t_nodo));
    if(!nue)
    {
        return 0;
    }
    nue->info=malloc(cantBytes);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->info,dato,cantBytes);
    nue->tam=cantBytes;
    if(*p==NULL)
    {
        nue->sig=nue;
        *p=nue;
    }
    else
    {
        nue->sig=(*p)->sig;
        (*p)->sig=nue;
    }
    return 1;
}
int sacarDePila (t_pila *p, void *dato, unsigned cantBytes)
{
    t_nodo *elim;
    if(*p==NULL)
        return 0;
    elim=(*p)->sig;
    memcpy(dato,elim->info,MINIMOBYTES(elim->tam,cantBytes));
    if((*p)==elim)
    {
        *p=NULL;
    }
    else
    {
        (*p)->sig=elim->sig;
    }
    free(elim->info);
    free(elim);
    return 1;
}
void vaciarPila (t_pila *p)
{
    while(*p)
    {
        t_nodo *elim;//se puede definir adentro y afuera del while
        elim=(*p)->sig;
        if(elim==(*p))
        {
            (*p)=NULL;
        }
        else
        {
            (*p)->sig=elim->sig;
        }
        free(elim->info);
        free(elim);
    }
}
