///FuncionesListaDE.c
#include "listaDoblementeEnlazada.h"

void crearListaDE (t_listaDE *p)
{
    *p = NULL;
}
////////////////////////////////////////////////////////////////////////////////
int ponerEnListaDEOrdenada (t_listaDE *p, const void *dato, unsigned cantBytes,
                            int (*cmp)(const void*, const void*))
{
    t_nodo *actual=*p, *nue;
    //t_listaDE actual=*p;//idem 16

    t_nodo *auxAnt;
    t_nodo *auxSig;

    if (*p != NULL)
    {
        ///ACOMODAR ACTUAL PARA VER DONDE INSERTO
        while( cmp(dato, actual->dato) > 0 && actual->sig != NULL)
        {
            actual = actual->sig;
        }

        while( cmp(dato, actual->dato) < 0 && actual->ant != NULL)
        {
            actual = actual->ant;
        }

        ///UBICO AUXANT Y AUXSIG SIEMPRE VOY A INSERTARE
        if(cmp(dato, actual->dato) > 0)
        {
            auxAnt = actual;
            auxSig = actual->sig;
        }
        else
        {
            auxSig=actual;
            auxAnt= actual->ant;
        }
        ///ETRE ESTOS DOS AUXILIARES
    }
    else ///Si lo que estoy insertando es el primer elemento de la lista
    {
        auxAnt=NULL;
        auxSig=NULL;
    }

    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato = malloc(cantBytes);

    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    memcpy(nue->dato,dato,cantBytes);
    nue->tam = cantBytes;

    ///ENGANCHE
    nue->ant = auxAnt;
    nue->sig = auxSig;

    ///ENGANCHE DE LISTA
    if (auxSig != NULL) //if (auxSig)
        auxSig->ant = nue;
    if (auxAnt != NULL) //if (auxAnt)
        auxAnt->sig = nue;

    *p=nue;
    return 1;
}
////////////////////////////////////////////////////////////////////////////////
int cmp_int (const void *d1,const void *d2)
{
    return *(int*)d1 - *(int*)d2;
}
////////////////////////////////////////////////////////////////////////////////
int mostrarDelPrincipio(t_listaDE *p,void (*accion)(const void*))
{
    if(!*p)
        return 0;

    while((*p)->ant != NULL)///Ubicamos el primer nodo
    {
        p = &(*p)->ant;
    }

    ///Recorremos
    while((*p))
    {
        accion(*p);
        p = &(*p)->sig;
    }
    return 1;
}
////////////////////////////////////////////////////////////////////////////////
void mostrarEnt (const void *pnodo)
{
    int dato;
    dato = *(int*)((t_nodo*)pnodo)->dato;
    printf("[%d]\t", dato);
}
