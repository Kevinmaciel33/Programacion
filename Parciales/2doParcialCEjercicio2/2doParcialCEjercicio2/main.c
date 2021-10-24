#include <stdio.h>
#include <stdlib.h>
#include "utilitarias.h"
#include "arbol.h"

int main()
{
    tArbolBinBusq arbol;
    tAlumno arr[]=
    {
        {42394000, 2},
        {42393900, 2},
        {42393800, 2},
        {42394900, 2},
        {42394800, 2},
        {42394700, 2},
        {42393600, 2},
        {42394600, 2},
        {42394001, 4},
        {42394002, 7},
        {42393000, 7},
        {42393050, 4},
        {42393055, 10},
        {42395000, 7},
        {42395100, 7}
    };
    crearArbolBinBusq(&arbol);
    for(int i=0; i*sizeof(tAlumno)<sizeof(arr); i++)
    {
        insertarRecArbolBinBusq(&arbol,&arr[i],sizeof(tAlumno),comparar_alumno);
    }
    printf("\n\n");
    mostrarArbol(&arbol, mostrar_alumno,0);
    eliminarElementosArbolNoClave(&arbol,verificar_nota);


    puts("\n\n");
    mostrarArbol(&arbol, mostrar_alumno,0);
    return 0;
}
