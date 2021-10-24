#include "ParcialLista.h"

int cmp_ent(const void * a, const void * b)
{
//    int  e1 = *(int *)v1,
//         e2 = *(int *)v2;
        return *(int *)a - *(int *)b;
}

void recorrerListaEnteros(const tLista *p)
{
//    int d = 0;
//    while(*p)
//    {
//        memcpy(d, (*p)->info, (*p)->tamInfo);
//
//        printf("%d \n",d);
//
//        p=&(*p)->sig;
//    }
}

int ObtenerInt(const tLista *p, void *d, unsigned cantBytes, int pos)
{
    if(*p == NULL)
        return 0;

    int posicion = 0;
    while(posicion < pos && (*p)->sig)
    {
        p=&(*p)->sig;
        posicion++;
    }
    if(posicion != pos)
        return 0;

    memcpy(d, (*p)->info, (*p)->tamInfo);

    return 1;

}

int leerArchivoYCargarLista(tLista *p, const char * path_ctas)
{

    FILE *arch = fopen(path_ctas, "rt");
    char numArch[5];
    int entero;

    if(!arch)
    {
        printf("No se pudo abrir el archivo");
        return 1;
    }
    for(int i = 0; i < 20; i++)
    {
        fgets(numArch, 5, arch);
        entero = (int) strtol(numArch, NULL, 10);
        ponerAlFinal(p, &entero, sizeof(entero));
    }
    return 1;
}

void eliminarDuplicados(tLista *p){


}

void ordenar(tLista *p, int (*comparar)(const void *,const void *))
{
    tLista *pri = p;

    if(*p == NULL)
        return;
    while((*p)->sig)
    {
        if(comparar((*p)->info,(*p)->sig->info) > 0)
        {
            tLista *q = pri;
            tNodo *aux = (*p)->sig;
// 1 10 2 3
//10
//1 2 3 12
            (*p)->sig = aux->sig;
            while(comparar((*q)->info, aux->info) < 0)
                q = &(*q)->sig;
            aux->sig = *q;
            *q = aux;
        }
        else
            p = &(*p)->sig;
    }
}
