
#include "Punto21.h"

void buscarMiniCadena(char *cad, char *ini, char *fin)
{
    int cantini;
    int cantfin;
    int resucant;
    while(*cad)
    {
        cad=buscar(cad,ini);
        cantini=miStrlen(ini);
        cantfin=miStrlen(fin);
        resucant=cantini-cantfin;

        remplazarCadena(cad,fin,resucant);
        cad+=cantfin;
    }
}


char* buscar( const char* s1, const char *s2)
{
    const char *ps1=s1;
    const char *ps2=s2;
    const char *encontrado=s1;
    while(*ps1 && *ps1 !=*ps2)
        ps1++;
    while(*ps1 && *ps2 )
    {
        encontrado=ps1;
        while(*ps1 && *ps2 && *ps1== *ps2)
        {
            ps1++;
            ps2++;
        }
        if(!*ps2)
            return (char *)encontrado;
        else
        {
            ps2=s2;
            if(*ps1!=*ps2)
            ps1++;

        }

    }
    return NULL;
}

void remplazarCadena(char *cad,char *fin,int resucant)
{
    while(*fin )
    {

        *cad=*fin;
        cad++;
        fin++;
    }
        memmove(cad,cad+resucant,miStrlen(cad));

}


int miStrlen(const char *str)
{
    const char *s;

    for (s = str; *s; ++s);

    return (s - str);
}

void miMemmove(void *dest, void *src, size_t n)
{
    char *p_src = (char *)src;
    char *p_dest = (char *)dest;
    char temp[n+1];

    for (int i=0; i<n; i++)
        temp[i] = p_src[i];

    for (int i=0; i<n; i++)
        p_dest[i] = temp[i];

}
