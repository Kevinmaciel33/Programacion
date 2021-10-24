#include "Lista.h"

int main()
{
    int v[]={1,2,3,4,5},
        i=0;

    tLista Lsta;

    crearLista(&Lsta);

    ponerAlComienzo(&Lsta, &v[i], sizeof(int));
    i++;
    while(i < 5)
    {
        ponerAlFinal(&Lsta, &v[i], sizeof(int));
        i++;
    }





    return 0;
}

//void mostrarEntero( void * vEnt)
//{
//
//    printf("*%d*", ((int*)vEnt));
//}
//void mostrarPersona( void *vPersona)
//{
//    tPersona * per = (tPersona*) vPersona;
//    printf("\n -%d %s", per->dni, per->apyn);
//}
//
//
//void recorrerLista(tLista * pl, void (*mostrar)(const void *))
//{
//
//    while(*pl)
//    {
//        mostrar((*pl)->info);
//
//    }
//}
