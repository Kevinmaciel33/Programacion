#include "funciones.h"
void mostrarCadena(char* cad)
{
    if(!*cad)
        return;
    printf("%c\n",*cad);
    mostrarCadena(cad+1);
}
void mostrarCadenaOrdenInverso(char* cad)
{
    if(!*cad)
        return;
    mostrarCadenaOrdenInverso(cad+1);
    printf("%c\n",*cad);
}
void mostrarCadenaDesplazada(char* cad)
{
    if(!*cad)
        return;
    printf("%s\n",cad);
    mostrarCadenaDesplazada(cad+1);
}
void mostrarCadenaDesplazadaOrdenInverso(char* cad)
{
    if(!*cad)
        return;
    mostrarCadenaDesplazadaOrdenInverso(cad+1);
    printf("%s\n",cad);
}

void mostrarDerechoRevez(char* cad)
{
    if(!*cad)
        return;
    printf("%c\n",*cad);
    mostrarDerechoRevez(cad+1);
    printf("%c\n",*cad);
}

void mostrarDerechoRevez2(char* cad)
{
    if(!*cad)
        return;
    printf("%c\n",*cad);
    mostrarDerechoRevez2(cad+1);
    if(*(cad+1))
    printf("%c\n",*cad);
}
