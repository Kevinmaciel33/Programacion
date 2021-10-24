#include "Main.h"

struct s_vecRes
{
    int vecRes[12];
    int ce;
};

void impr_ent(void * i, FILE* pf)
{
    fprintf(pf, "%d ", *((int*)i));
}
int main()
{
    tArbolBinBusq ar;
    //int vec[] = {10,25,50,60,75,100,110,125,150,175,200},
    int vec[] = {10,25,50,60},
                tamVec = sizeof(vec)/sizeof(int);
    //int vec[] = {25,50,75,100,125,150,175};
    int vecPre []= {100, 50, 25, 10, 75, 150, 125},
                   tamVecPre = sizeof(vecPre)/sizeof(int),
                   i;
    struct s_vecRes res= {{0}, 0};

    unsigned tamDato = sizeof(int);
    int dato;
    FILE * pf;


    crearArchivo("ordenado.dat", vec, sizeof(int),sizeof(vec)/sizeof(int));

    crearArbolBinBusq(&ar);

    cargarArchivoBinOrdenadoArbolBinBusq(&ar, "ordenado.dat", sizeof(int));

//    cargarDesdeDatosOrdenadosArbolBinBusq(&ar,
//                                          vec,
//                                          sizeof(vec)/sizeof(int),
//                                          leerDesdeVector,
//                                          &tamDato);
///eliminarRaizArbolBinBusq(&ar);

    dato = alturaArbolBin(&ar);

//    for(i=0; i< tamVecPre; i++)
//    {
//      insertarArbolBinBusq(&ar, vecPre+i, sizeof(int), cmp_ent);
//    }
//    for(i=0; i< tamVec; i++)
//    {
//        insertarArbolBinBusq(&ar, vec+i, sizeof(int), cmp_ent);
//    }

///cargar el arbol en un archivo de texto

    pf = fopen("arbol.txt", "wt");

    if(!pf)
        return 1;

    recorrerEnOrdenArbolBinBusq(&ar,pf,imprimir_arch);
    fclose(pf);

    ///cargar el arbol en un vector de enteros
    recorrerEnOrdenArbolBinBusq(&ar,&res,guardarVecEnteros);
    for(i=0; i<res.ce; i++)
    {
        printf("-%d-", res.vecRes[i]);
    }
    printf("\n\n");

    ///imprimir el arbol

    recorrerEnOrdenArbolBinBusq(&ar,NULL,imprimir);
    printf("\n\n");
    recorrerPreOrdenArbolBinBusq(&ar,NULL,imprimir);
    printf("\n\n");
    recorrerPosOrdenArbolBinBusq(&ar,NULL,imprimir);
    printf("\n\n");
    recorrerEnOrdenInversoArbolBinBusq(&ar,NULL,imprimirConForma);
    printf("\n\n");

    if (esCompletoArbolBin(&ar))
        printf("\nCompleto");
    if (esBalanceadoArbolBin(&ar))
        printf("\nBalanceado");
    if (esAVLArbolBin(&ar))
        printf("\nAVL");

    printf("\n\n");
    if (esCompleto2ArbolBin(&ar))
        printf("\n2 Completo");
    if (esBalanceado2ArbolBin(&ar))
        printf("\n2 Balanceado");
    if (esAVL2ArbolBin(&ar))
        printf("\n2 AVL");

    mayorElemNoClaveArbolBinBusq(&ar, &dato, sizeof(dato),cmp_ent);
    printf("\n\nMayor No Clave: %d", dato);

    menorElemNoClaveArbolBinBusq(&ar, &dato, sizeof(dato),cmp_ent);
    printf("\n\nMenor No Clave: %d", dato);

    return 0;
}

void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int *) info;
    printf("%*s-%3d-\n",n*3,"", *i);
}
void imprimir(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int *) info;
    printf("-%d*%d-", *i, n);
}
unsigned leerDesdeVectorEnteros(void ** d, void * vec, unsigned pos, void * params)
{
    *d = malloc(sizeof(int));
    if(!*d)
        return 0;
    memcpy(*d, vec+(sizeof(int)*pos), sizeof(int));
    return sizeof(int);
}
unsigned leerDesdeVector(void ** d, void * vec, unsigned pos, void * params)
{
    unsigned tam = *((unsigned*)params);
    *d = malloc(tam);
    if(!*d)
        return 0;
    memcpy(*d, vec+(tam*pos), tam);
    return tam;
}
int cmp_ent(const void *v1, const void *v2)
{
    return *((int*)v1)-*((int*)v2);
}
void imprimir_arch(void *info, unsigned tam, unsigned n, void *params)
{
    int * i = (int *) info;
    fprintf((FILE*) params,"-%d-", *i);
}
int crearArchivo(char*path, void * vec, unsigned tam, unsigned ce)
{
    FILE * pf = fopen(path, "wb");
    if (!pf)
        return 0;
    fwrite(vec, tam, ce, pf);
    fclose(pf);
    return 1;
}
void guardarVecEnteros(void *info, unsigned tam, unsigned n, void *params)
{
    struct s_vecRes * res = (struct s_vecRes*)params;
    int * infoEnt = (int*) info;
    res->vecRes[res->ce] = *infoEnt;
    res->ce++;
}
