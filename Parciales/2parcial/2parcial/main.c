#include "Parcial.h"

void mostrarHerramienta(void *vHerramienta);
unsigned leerDesdeVector(void ** d, void * vec, unsigned pos, void * params);
void imprimirConForma(void * info, unsigned tam, unsigned n, void * params);
int verificar_herramienta(const void* dato);

int main()
{
    tLista p;
    int i = 0;
    unsigned tamDato = sizeof(tHerramienta);
    tHerramienta d,
                 ferre[]=
    {
        {"Martillo", 12, 100},
        {"Pala", 12, 70},
        {"Martillo", 5, 80},
        {"Torno", 14, 150},
        {"Torno", 100, 120}
    };

//***Arbol
    tArbolBinBusq arbol;
//***fin-Arbol

    FILE *arch = fopen("datos.dat", "wb");
    if(!arch)
    {
        printf("No se pudo abrir el achivo");
        return 1;
    }
//****Cargar Archivo****
    if ((fwrite(ferre,sizeof(tHerramienta),5,arch))!=5)
        printf("No se han escrito todos los %d números del array.\n", 5);
    fclose(arch);
//****Fin-Cargar Archivo****

    crearLista(&p);

//1 - Cargar Lista
    leerArchivoYCargarLista(&p,"datos.dat");
//2 - Eliminar duplicados
    eliminarDuplicadosListaOrdenadaAcum(&p, cmp_herramienta, acumularStock);
//Mostrar Lista
    printf("\n");
    recorrerLista(&p,mostrarHerramienta,NULL);
    printf("\n\n");






//***** Punto 2 ARBOL
    crearArbolBinBusq(&arbol);

    cargarDesdeDatosPreOrdenArbol(&arbol,
                                  ferre,
                                  sizeof(ferre)/sizeof(tHerramienta),
                                  leerDesdeVector,
                                  cmp_precio_precio,
                                  &tamDato);

//    cargarDesdeDatosOrdenadosArbolBinBusq(&arbol,
//                                          ferre,
//                                          sizeof(ferre)/sizeof(tHerramienta),
//                                          leerDesdeVector,
//                                          &tamDato);
//
//    recorrerEnOrdenArbolBinBusq(&arbol,NULL,imprimirConFormaHerramienta);
//    eliminarElementosArbolNoClave(&arbol,verificar_herramienta);
//
//    printf("\n\n");

    recorrerEnOrdenArbolBinBusq(&arbol,NULL,imprimirConFormaHerramienta);

    return 0;
}

void acumularStock(void* a, const void* b)
{
    tHerramienta * h1 = (tHerramienta*) a,
                   * h2 = (tHerramienta*) b;
    (*h1).stock += (*h2).stock;
}

void mostrarHerramienta(void *vHerramienta)
{
    tHerramienta *d = (tHerramienta*)vHerramienta;
    printf("%s - %d - %d \n", d->herramienta, d->stock, d->precio );
}
//*** ARBOL
unsigned leerDesdeVector(void ** d, void * vec, unsigned pos, void * params)
{
    unsigned tam = *((unsigned*)params);
    *d = malloc(tam);
    if(!*d)
        return 0;
    memcpy(*d, vec+(tam*pos), tam);
    return tam;
}

void imprimirConForma(void * info, unsigned tam, unsigned n, void * params)
{
    int * i = (int *) info;
    printf("%*s-%3d-\n",n*3,"", *i);
}

void imprimirConFormaHerramienta(void * info, unsigned tam, unsigned n, void * params)
{
    tHerramienta * d = (tHerramienta*) info;
    printf("%*s- %3d -\n",n*3,"", d->precio);
}

int verificar_herramienta(const void* dato)
{
    tHerramienta* herr=(tHerramienta*)dato;
    return herr->stock<50;
}
//*** fin - ARBOL

