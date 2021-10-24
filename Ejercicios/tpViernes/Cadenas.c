#include "Integrador.h"
#include "Cadenas.h"
#define TAM 41

#define mi_toupper(c) (c)>='a' && (c)<='z'? (c)-('a'-'A'):(c)
#define mi_tolower(c) (c)>='A' && (c)<='Z'? (c)+('a'-'A'):(c)

char *mayusculasMinusculas(char *s)
{
    int es_principio = 1;

    while(*s != '\0'){
        if(es_principio || *(s - 1) == ' ')
            *(s) = mi_toupper(*(s));
        else
            *(s) = mi_tolower(*(s));
        s++;
    }

    return s;
}

char *coma(char *s)
{
    char *aux = s;

    if( strchr(s, ',') == NULL)
    {
        if((aux = strchr(s, ' ')) != NULL)
        {
            memmove(aux + 1, aux, TAM - 1 > strlen(s)? strlen(aux) : strlen(aux) + 1 );
            *aux = ',';
        }
    }

    return s;
}
char *no_mas_de_un_espacio(char *s)
{
    char *aux= s;

    while( (aux= strstr(aux, "  ")) != NULL)
        strcpy(aux, aux + 1);

    return s;
}
char *sin_espacios_inicio_fin(char *s)
{
    if(*s == ' ')
    {
        strcpy(s, s + 1);
    }

    if( *(s + strlen(s)) == ' ')
        *(s + strlen(s)) = '\0';

    return s;
}
int cantidad_apariciones(const char *s, char c){
    int cantidad = 0;

    while(*s != '\0')
    {
        if(*s == c)
            cantidad++;
        s++;
    }
}
