#include "u3.h"

void cargarPila(char* v, tPila* p)
{
    char* pV = v;
    int num;


    while(*pV)
    {
        num = (*pV - 48);
        ponerEnPila(p, &num, sizeof(int));

        pV++;

    }
}
