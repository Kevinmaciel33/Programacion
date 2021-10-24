#include "lista.h"
void crearLista(t_lista *pl)
{
    *pl=NULL;;
}

int ponerEnListaAlFinal(t_lista *pl, const void * dato, unsigned tamDato)
{
    t_nodo *nue;

    //avanzo en la lista
    while(*pl)
    {
        pl=&(*pl)->sig;
    }

    //reservo memoria para nue
    nue= (t_nodo*)malloc(sizeof(t_nodo));
    nue->info= malloc(tamDato);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }


    //lleno nue con los datos
    nue->cantBy= tamDato;
    memcpy(nue->info, dato, tamDato);

    nue->sig=NULL;

    //enlace
    *pl=nue;
    return 1;
}

void recorrer (const t_lista *pl, void (*accion)(const void *d))
//si mi lista tiene tam variable por ej cadenas.No vamos a modificarla
{
    while(*pl)
    {
        //accion((*pl)->info);//le paso la info
        accion(*pl);//le paso el *tnodo
        pl=&(*pl)->sig;
    }
}
void imprimirListaEnArchivo (const t_lista *pl,
                             void (*imprimir)(const void* dato, FILE **fp),
                             FILE**fp)
//si mi lista tiene tam variable por ej cadenas.No vamos a modificarla
{
    while(*pl)
    {
        //accion((*pl)->info);//le paso la info
        imprimir((*pl)->info,fp);//le paso el *tnodo
        pl=&(*pl)->sig;
    }
}
/*ingreso un elemento a una lista. Si ya está el elemento, se actualiza su precio*/

int insertarEnListaOrdenadaAgrupar
(t_lista *pl, const void *dato, unsigned tamDato,
 int (*comparar)(const void *d1, const void *d2),
 int (*accion)(const void *d1, const void *d2))
{
    t_nodo* nue;
    int comparacion = 1;

    while(*pl && (comparacion=comparar(dato,(*pl)->info))>0)
    {
        pl=&(*pl)->sig;
    }

    if(!comparacion)//son duplicados
    {
        accion(dato,(*pl)->info);
        return 0;
    }
    nue = malloc(sizeof(t_nodo));

    if(!nue)
        return 0;

    nue->info=malloc(sizeof(tamDato));

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    memcpy(nue->info, dato, tamDato);
    nue->cantBy=tamDato;

    nue->sig=*pl;
    *pl = nue;

    return 1;
}

int insertarEnListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,\
                            int(*comparar)(const void *d1, const void *d2),\
                            int duplicado)
{
    t_nodo *nue;
    int comparacion = 1;

    ///Recorrer lista hasta lugar correcto
    while(*pl && (comparacion = comparar(dato,(*pl)->info) < 0))
    {
        pl = &(*pl)->sig;
    }
    /*
    ///Duplicado = 0
    if(!duplicado && !comparacion) //SON DUPLICADOS
    {
        ///PROCESAR LA INFO
        //accion();
        return 0;
    }*/

    ///Reservar memoria
    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->info = malloc(tamDato);

    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    ///Copiar la informacion
    memcpy(nue->info, dato, tamDato+1);//sin el +1 no funciona para cadenas
    //*((char*)nue->info+(tamDato+1))='\0';//para cadenas
    nue->cantBy = tamDato;

    ///Enlace
    nue->sig = *pl;
    *pl = nue;

    return 1;
}



int actualizarEnListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,\
                              int(*comparar)(const void *d1, const void *d2),
                              void(*actualizar)(const void *d1, const void *d2))
{
    t_nodo *nue;
    int comparacion = 1;

    ///Recorrer lista hasta lugar correcto
    while(*pl && (comparacion = comparar(dato,(*pl)->info) > 0))
    {
        pl = &(*pl)->sig;
    }

    if(!*pl)
    {
        ///Reservar memoria
        nue = (t_nodo*)malloc(sizeof(t_nodo));
        if(!nue)
            return 0;
        nue->info = malloc(tamDato);

        if(!nue->info)
        {
            free(nue);
            return 0;
        }

        ///Copiar la informacion
        memcpy(nue->info, dato, tamDato+1);//para cadenas
        *((char*)nue->info+(tamDato+1))='\0';//para cadenas
        nue->cantBy = tamDato;

        ///Enlace
        nue->sig = *pl;
        *pl = nue;
    }
    else
    {
        actualizar((*pl)->info,dato);
    }


    return 1;
}



int eliminarDeListaOrdenada(t_lista *pl, const void *dato, unsigned tamDato,
                            int(*comparar)(const void *d1, const void *d2))
{
    int comparacion;
    //t_nodo* elim;
    if(*pl)
        comparacion = comparar(dato, (*pl)->info);

    while(*pl)
        if(comparacion>0)
        {
            pl=&(*pl)->sig;
        }
    return 0;
}

/*elimino un elemento de una lista desordenada
el campo que busco depende de la funcion comparar*/
int eliminarDeLista(t_lista *pl, const void *dato, unsigned tamDato,
                    int(*comparar)(const void *d1, const void *d2))
{
    int comparacion;
    t_nodo *elim;
//evaluo el primer elemento

    if(*pl)
        comparacion = comparar(dato, (*pl)->info);
    if(comparacion)
    {
        elim=(*pl);
        pl=&(*pl)->sig;
        free(elim->info);
        free(elim);
        return 1;
    }
    /*else
    {
        pl=&(*pl)->sig;
    }*/
//evaluo el resto de los elementos
    while(*pl && (*pl)->sig != NULL)
    {
        comparacion = comparar(dato, &(*((*pl)->sig)->info));
        if(comparacion)
        {
            elim=(*pl)->sig;
            (*pl)->sig=(*elim).sig;
            free((*elim).info);
            free(elim);
            return 1;
        }
        else
        {
            pl=&(*pl)->sig;
        }
    }
    return 0;
}
/*elimino todos los elementos cuyos campos sean iguales al pasado por parametro
(en una lista desordenada)
el campo que busco depende de la funcion comparar*/
int eliminarDeListaMuchos(t_lista *pl, const void *dato, unsigned tamDato,
                          int(*comparar)(const void *d1, const void *d2))
{
    int comparacion=0;
    t_nodo *elim;
    if(*pl)
        comparacion = comparar(dato, (*pl)->info);
    while(comparacion)
    {
        elim=(*pl);
        (*pl)=(*elim).sig;
        free(elim->info);
        free(elim);
        comparacion = comparar(dato, (*pl)->info);
    }
    while(*pl && (*pl)->sig != NULL)
    {
        comparacion = comparar(dato, ((*pl)->sig)->info);
        if(comparacion)
        {
            elim=(*pl)->sig;
            (*pl)->sig=(*elim).sig;
            free((*elim).info);
            free(elim);
        }
        else
        {
            pl=&(*pl)->sig;
        }
    }
    return comparacion;
}

void recorreAccionEnLOrd(t_lista * pl, void (*accion)(const void *d1, void *d2),\
                         int(*comparar)(const void *d1, const void *d2))
{
    t_nodo * elim;
    //  int comparacion = 1;
    while(*pl && (*pl)->sig != NULL)
    {
        if(comparar((*pl)->info, (*pl)->sig->info)==0)
        {
            accion((*pl)->sig->info,(*pl)->info);
            elim = (*pl)->sig;
            //*pl = elim->sig;///enlace
            (*pl)->sig = elim->sig;
            free(elim->info);
            free(elim);

        }
        else
            pl = &(*pl)->sig;
    }
}

int ordenarLista(t_lista *pl, int(*comparar)(const void *d1, const void *d2))
{
    t_nodo *pact=NULL;//nodo actual
    t_nodo *pant=NULL;//nodo anterior
    t_nodo *pbusc=NULL;//anterior a buscado o null
    t_nodo *pini=NULL;//primero de la lista ordenada
    int priVez=1;

    if(*pl == NULL)
        return 0;

    while( (*pl)->sig != NULL )
    {
        pbusc = buscarMinimo(pl, comparar);

        /*buscarMinimo devuelve la dirección del nodo anterior al minimo,
         o NULL si el minimo es el primero*/

        if(pbusc!=NULL)
        {
            if(pact!=NULL)
                pant=pact;
            pact=(*pbusc).sig;//apunto al actual
            if(priVez)
            {
                priVez=0;
                pini=pact;//apunto al primer minimo
            }
            (*pbusc).sig=(*pact).sig;//saco de la lista al minimo que encontré
            if(pant!=NULL)
                (*pant).sig = pact;//enlace
        }
        else
        {
            if(pact!=NULL)
                pant=pact;
            pact=*pl;//apunto al actual
            if(priVez)
            {
                priVez=0;
                pini=pact;//apunto al primer minimo
            }
            //pact=*pl;
            if(pant!=NULL)
                (*pant).sig = pact;//enlace
            (*pl)=(*pl)->sig;//saco de la lista al minimo que encontré
        }
    }
    (*pact).sig=*pl;
    *pl=pini;
    return 0;
}

t_nodo *buscarMinimo(t_lista *pl, int(*comparar)(const void *d1, const void *d2))
{

    t_nodo *pmin = *pl;
    t_nodo *pant=NULL;
    while((*pl)->sig != NULL)
    {

        if(comparar((*pmin).info,(*pl)->sig->info) > 0)
        {
            pmin=(*pl)->sig;
            pant=*pl;
        }
        pl=&(*pl)->sig;
    }
    return pant;
}

int compararEnterosMenorMayor(const void *dato1, const void *dato2)
{
    return *(int*)dato1 - *(int*)dato2;
}

int compararEnterosMayorMenor(const void *dato1, const void *dato2)
{
    return *(int*)dato2 - *(int*)dato1;
}

int maximosEnLista(t_lista *pl,int tope,const void* dato,unsigned tamDato,
                    int(*comparar)(const void *d1, const void *d2))
{
    /*            maximosEnLista(plMaximos,3,(*pl)->info,sizeof(t_venta),
                           compararVentas);*/
    t_nodo *nue,
            *elim;
    while(*pl)
    {
        if(comparar(dato,(*pl)->info)>0)
        {
            //memcpy((*pl)->info,dato,sizeof(tamDato));
            ///Reservar memoria
            nue = (t_nodo*)malloc(sizeof(t_nodo));
            if(!nue)
                return 0;
            nue->info = malloc(tamDato);

            if(!nue->info)
            {
                free(nue);
                return 0;
            }

            ///Copiar la informacion
            memcpy(nue->info, dato, tamDato+1);//para cadenas
            *((char*)nue->info+(tamDato+1))='\0';//para cadenas
            nue->cantBy = tamDato;

            ///Enlace
            nue->sig = *pl;
            *pl = nue;

            while((*pl)->sig->sig)
                pl=&(*pl)->sig;

            elim=(*pl)->sig;
            (*pl)->sig=elim->sig;
            free(&(elim->info));//está bien esto?
            free(elim->info);
            free(elim);

            return 1;
        }
        pl=&(*pl)->sig;
    }
    return 0;

}
void recorrerListaR(t_lista* lista, void (*accion)(const void*))
{
    if( !(*lista) )
        return;

    recorrerListaR(&(*lista)->sig, accion);
    accion(*lista);

}
