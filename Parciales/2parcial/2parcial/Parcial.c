#include "Parcial.h"

int cmp_ent(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}
int cmp_ent_herramienta(const void * a, const void * b)
{
    tHerramienta * h1 = (tHerramienta*) a;

    return h1->stock - *(int *)b;
}
int cmp_precio_precio(const void * a, const void * b)
{
    tHerramienta * h1 = (tHerramienta*) a,
                 * h2 = (tHerramienta*) b;

    return h1->precio - h2->precio;
}

int cmp_herramienta(const void * a, const void * b)
{
    int result;
    tHerramienta * h1 = (tHerramienta*) a,
                   * h2 = (tHerramienta*) b;
    result = strcmpi(h1->herramienta, h2->herramienta);
    return result;
}

int obtenerNodo(const tLista *p, void *d, unsigned cantBytes, int pos)
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

    FILE *arch = fopen(path_ctas, "rb");
    tHerramienta ferre;

    if(!arch)
    {
        printf("No se pudo abrir el archivo");
        return 1;
    }

    fread(&ferre, sizeof(tHerramienta), 1, arch);
    //ponerAlFinal(p, &ferre, sizeof(tHerramienta));
    while(!feof(arch))
    {
        ponerAlFinal(p, &ferre, sizeof(tHerramienta));
        fread(&ferre, sizeof(tHerramienta), 1, arch);

    }
    fclose(arch);
    return 1;
}

void eliminarDuplicadosListaOrdenadaAcum (tLista *pl,
        int (*cmp)(const void*, const void*),
        void (*accion)(void*, const void*))
{
    tNodo *elim;
    tLista *plAux;
    int rc; //  Resultado de la comparacion

    while(*pl && *(plAux = &(*pl)->sig))
    {
        while( *plAux && (rc = cmp((*pl)->info, (*plAux)->info)) == 0)
        {
            elim = *plAux;  // Asigno a elim el nodo a eliminar

            if(accion)  /// AGREGE ESTE IF, PREGUNTANDO SI EXISTE UNA FUNCION QUE HICIERA ALGO. SI EL PARAMETRO ES NULL, NO ENTRA AL IF.
                accion((*pl)->info, (*plAux)->info);

            (*pl)->sig = (*plAux)->sig;    // el siguiente del nodo va a ser el que era el siguiente del nodo eliminado.

            //  ELIMINO EL NODO DUP LICADO.
            free(elim->info);
            free(elim);

            plAux = &(*pl)->sig;
        }
        pl = &(*pl)->sig;
    }
}

void recorrerLista(tLista *pl, void (*accion)(void *), void *param)
{
    while(*pl)
    {
        accion((*pl)->info);
        pl = &(*pl)->sig; // De esta manera me muevo en la lista.
    }
}

//Arbol

void eliminarElementosArbolNoClave(tArbolBinBusq *p, int(*verificacion)(const void*))
{
    if(!*p)
        return;
    if((*p)->izq)
        eliminarElementosArbolNoClave(&(*p)->izq,verificacion);
    if((*p)->der)
        eliminarElementosArbolNoClave(&(*p)->der,verificacion);
    if(verificacion((*p)->info))
        eliminarRaizArbolBinBusq(p);
}
/// 2b
///Cargar desde vector
int cargarDesdeDatosPreOrdenArbol(tArbolBinBusq * p,
                                  void * ds, unsigned cantReg,
                                  unsigned (*leer)(void **, void *, unsigned, void *params),
                                  int(*cmp)(const void*, const void*),
                                  void * params)
{
    int tam, ri, i;
    void * dato;

    for(i = 0; i < cantReg; i++)
    {
        tam = leer(&dato, ds, i, params);
        if( (ri = insertarArbolBinBusqDirecto(p, dato, tam, cmp)) != TODO_BIEN )
            return ri;
    }
    return TODO_BIEN;
}

int insertarArbolBinBusqDirecto(tArbolBinBusq *p, void * d, unsigned tam, int(*cmp)(const void*, const void*))
{
    tNodoArbol *nue;
    int        rc;

    while(*p)
    {
        if((rc = cmp(d, (*p)->info)) > 0)
            p = &(*p)->izq;
        else if(rc < 0)
            p = &(*p)->der;
        else
            return CLA_DUP;
    }

    nue = (tNodoArbol*)malloc(sizeof(tNodoArbol));
    if(!nue)
        return SIN_MEM;
    nue->tamInfo = tam;
    nue->info = (void*)d;
    nue->der = nue->izq = NULL;
    *p = nue;

    return TODO_BIEN;
}
///Cargar desde archivo
//int cargarDesdeArchivoPreOrdenArbol(tArbolBinBusq * p, const char * path,
//                                    unsigned tamInfo, int(*cmp)(const void*, const void*))
//{
//    int cantReg,
//        r;
//    FILE * pf;
//    if(*p)
//        return SIN_INICIALIZAR;
//    if(!(pf= fopen(path, "rb")))
//        return ERROR_ARCH;
//    fseek(pf, 0L, SEEK_END);
//    cantReg = ftell(pf)/tamInfo;
//    r = cargarDesdeDatosPreOrdenArbol(p, pf, cantReg-1, leerDesdeArchivoBin, cmp, &tamInfo);
//    fclose(pf);
//    return r;
//}

