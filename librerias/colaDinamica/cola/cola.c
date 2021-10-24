#include "cola.h"
void crearCola(t_cola *pc)
{
    pc->pri=NULL;
    pc->ult=NULL;
}
int colaVacia(const t_cola *pc)
{
        return pc->pri==NULL;
}
//colaLlena se hace para mantener compatibilidad. Podrìa devolver 0 siempre.
int colaLlena(const t_cola *pc,unsigned cantBy)
{
    t_nodo* aux=(t_nodo*)malloc(sizeof(t_nodo));
    aux->dato = malloc(cantBy);
    free(aux->dato);
    free(aux);
    return aux==NULL || aux->dato == NULL;
}
void vaciarCola(t_cola *pc)
{
    while(pc->pri)
    {
        t_nodo *aux = pc->pri;
        pc->pri = aux->sig;
        free(aux->dato);
        free(aux);
    }
    pc->ult=NULL;
}
int sacarDeCola(t_cola *pc,void *dato, unsigned cantBy)
{
    t_nodo *aux=pc->pri;
    if(aux==NULL)
        return 0;
    pc->pri = aux->sig;
    memcpy(dato,aux->dato,MINIMO(cantBy,aux->tamDato));
    free(aux->dato);
    free(aux);
    if(pc->pri==NULL)
        pc->ult=NULL;
    return 1;
}

int ponerEnCola(t_cola *pc,const void *dato, unsigned cantBy)
{
    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(nue==NULL || (nue->dato = malloc(cantBy)) ==NULL)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,dato,cantBy);
    nue->tamDato=cantBy;
    nue->sig=NULL;
    if(pc->ult)
        pc->ult->sig=nue;
    else
        pc->pri=nue;
    pc->ult = nue;
    return 1;
}


int verPrimero(const t_cola *pc, void *dato, unsigned cantBy)
{
    if(pc->pri==NULL)
        return 0;
    memcpy(dato,pc->pri->dato,MINIMO(cantBy,pc->pri->tamDato));
    return 1;
}
