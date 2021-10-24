typedef struct sNodoArbol
{
    void *info;
    unsigned tamInfo;
    struct sNodoArbol *izq,
                      *der;
}tNodoArbol;

typedef tNodoArbol *tArbolBinBusq;

int insertarNodoArbolBinBusq(tArbolBinBusq *p, const void *d, unsigned tam,
                             int (*cmp)(const void *,const void *))
{
    tNodoArbol *nue;
    int rc;

    if(*p)
    {
        if(rc=cmp(d, (*p)->info))<0)
            return insertarRecArbolBinBusq(&(*p)->izq, d, tam, cmp);
        if(rc>0)
            return insertarRecArbolBinBusq(&(*p)->der, d, tam, cmp);
        return CLA_DUP;
    }
    if(!reservarMemoriaNodo(nue, sizeof(tNodoArbol), nue->info, tam))
        return SIN_MEM;
    nue->tamInfo=tam;
    memcpy(nue->info, d, tam);
    nue->der = NULL;
    nue->izq = NULL;

    *p= nue;
    return TODO_BIEN;
}
