#include "Pila.h"

void crearPila (t_pila *p)
{
    *p = NULL;
}

int pilaVacia (const t_pila *p)
{
    return (*p == NULL);
}

int pilaLlena (const t_pila *p, unsigned cantBytes)
{
    t_nodoPila* aux= (t_nodoPila*)malloc(sizeof(t_nodoPila));

    if(!aux)
        return 1;

    aux->info= malloc(cantBytes);

    if(!aux->info)
    {
        free(aux);
        return 1;
    }

    free(aux->info);
    free(aux);

    return 0;
}


int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes)
{
    t_nodoPila* nue= (t_nodoPila*)malloc(sizeof(t_nodoPila));

    if(!nue)
        return 0;

    nue->info= malloc(cantBytes);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, cantBytes);

    //memcpy(nue->tam, &cantBytes, sizeof(unsigned));
    nue->tam= cantBytes;

    nue->sig = *p;

    *p= nue;



    return 1;
}


int sacarDePila (t_pila *p, void *dato, unsigned cantBytes)
{
    if(!*p)
        return 0;

    t_nodoPila *elim=*p;

    memcpy(dato, elim->info, MINIMO(cantBytes, elim->tam));

    *p=elim->sig;

    return 1;
}


int verTope (const t_pila *p, void *dato, unsigned cantBytes)
{
    if(!*p)
        return 0;

    memcpy(dato, (*p)->info, MINIMO(cantBytes, ((*p)->tam) ));

    return 1;
}


void vaciarPila (t_pila *p)
{
    while(*p)
    {
        t_nodoPila *elim= *p;
        *p=elim->sig;
        free(elim->info);
        free(elim);
    }
}



