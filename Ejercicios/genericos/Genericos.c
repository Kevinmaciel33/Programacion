#include "Genericos.h"

void intercambiar(void* e1, void* e1, size_t tam);
void *buscarMenor(const void *vec, const void *fin, size_t tam, int (*cmp)(const void*, const void*));


void intercambiart(void* e1, void* e1, size_t tam)
{
    void * aux = malloc(tam);
    if(!aux)
        return;

    memcpy(aux, e1, tam);
    memcpy(e1, e2, tam);
    memcpy(e2, aux, tam);

    free(aux);

}

void *buscarMenor(const void *vec, const void *fin, size_t tam, int (*cmp)(const void*, const void*)){

    cons void * men = vec;
    vec+= tam;
    while(vec<= fin)
    {
        if( cmp(vec, men)< 0 )
        {
            men = vec;
        }

    }
    return (void *) men;
}


 ordenarSeleccion(void * vec , size_t ce, size_t tam, int (*cmp)(const void*, const void*))
{
    void *fin = vec + (ce - 1) * tam,
         *men;

    while(vec < fin)
    {
        men = buscarMenor(vec, fin, cmp);
        if (vec != men)
        {
            intercambiar(vec, men, tam );
        }
        vec+=tam;
    }
    return ini;
}
