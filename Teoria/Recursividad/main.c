#include <stdio.h>
#include <stdlib.h>

int imprimirCadena(char *v);

int main()
{
    /////*****EJERCICIOS DE FORMA INDIRECTA*****/////
    /////1- Dada la cadena "abcd", imprimir recursivamente:
   /*
    * a
    * ab
    * abc
    * abcd
    */

    char v[5]="abcd";

    imprimirCadena(v);
    return 0;
}

int imprimirCadena(char *v)
{
    if(*v == '\0')
        return 1;

    printf("%c \n",*v);
    imprimirCadena(v + 1);
    printf("%c",*v);

    return 12;
}
