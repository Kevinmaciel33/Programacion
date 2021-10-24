#include "Unidad2.h"
void mostrarCadena(char* v)
{
    char *p = v;

    while(*p)
    {
        printf("%c",*p);
        p++;
    }
}

size_t MI_STRLEN(char* v)
{
    char* p = v;
    size_t len = 0;

    while(*p)
    {
        p++;
        len++;
    }

    return len;
}
char* MI_STRSTR(char* v, char* aBuscar)
{
    char *pV = v,
         *pABuscar = aBuscar,
         *aMandar;

    while(*pV)
    {
        aMandar = pV;
        while(*pV == *pABuscar && *pV != '\0' && *pABuscar != '\0')
        {
            pV++;
            pABuscar++;
        }
        if(*pABuscar == '\0')
            return aMandar;
        pABuscar = aBuscar;
        pV++;
    }
    return NULL;
}

//Ejercicio 8
//Dado un array de char que contiene un texto compuesto por palabras que termina en '.' (o en su defecto en carácter nulo -'\0'-), escriba un programa en que determine e informe:
//a- cuál es la primera palabra y cuántas veces se repite en el texto
void primeraPalabra(char* v, char* primerPalabra)
{
    char *p = v;

    while(*p && *p != '.')
    {
        if(*p != ' ')
        {
            *primerPalabra = *p;
            primerPalabra++;
        }
        p++;
    }
    *primerPalabra = '\0';
}

int repeticionPrimeraAparicion(char* v,char* primerPalabra)
{
    char *pV = v,
         *posPalabra;

    int cantPalabra = 0,
        LenPrimerPalabra = MI_STRLEN(primerPalabra);

    posPalabra = MI_STRSTR(pV, primerPalabra);
    if(posPalabra != NULL)
    {
        posPalabra += LenPrimerPalabra;
        cantPalabra++;
    }

    while( posPalabra != NULL)
    {
        posPalabra = MI_STRSTR(posPalabra, primerPalabra);
        if(posPalabra != 0)
        {
            posPalabra += LenPrimerPalabra;
            cantPalabra++;
        }
    }

    return cantPalabra;
}

//Ejercicio 10

int esCapicua(char* v)
{
    int len = MI_STRLEN(v);

    char *pInicio = v,
         *pFin = v + len - 1;

    for(int i = 0; i < len/2; i++)
    {
        if(*pInicio != *pFin)
            return 0;

        pInicio++;
        pFin--;
    }

    return 1;
}

int esMultiplo5(char* v)
{
    char* p = v + MI_STRLEN(v) - 1;

    if( *p == '0' || *p == '5' )
        return 1;

    return 0;

}

int esMultiplo6(char* v)
{
    char* p = v + MI_STRLEN(v) - 1;

    return ( (*p=='0' || *p=='2' || *p=='4' || *p=='6' || *p=='8') && esMultiplo3(v) ) ? 1 : 0;
}

int esMultiplo3(char* v)
{
    char *p = v;
    int suma = 0;

    while(*p)
    {
        suma += (*p - 48);
        p++;
    }

    return (suma%3 == 0) ? 1 : 0;
}

int esMultiplo11(char* v)
{
    return 1;
}

int esMayorQue100(char* v)
{
    char* p = v;
    int numero,
        j = 1,
        len = MI_STRLEN(v);

    char* porFin = v + len - 1;

    for(char* i = porFin ; i >= p; i--, j *= 10)
        numero += (*i - 48) * j;

    printf("numero: %d \n", numero);
    return (numero > 100) ? 1 : 0;
}

void Ejercicio10()
{
    char cadena[1000]="21";

    //(esCapicua(cadena)) ? printf("Es capicua") : printf("No es capicua");
    //(esMultiplo5(cadena)) ? printf("Es multiplo de 5") : printf("No es multiplo de 5");
    //(esMultiplo6(cadena)) ? printf("Es multiplo de 6") : printf("No es multiplo de 6");
    (esMayorQue100(cadena)) ? printf("Es mayor que 100") : printf("Es menor que 100");
}




