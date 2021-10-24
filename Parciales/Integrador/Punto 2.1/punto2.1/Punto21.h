#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdio.h>
#include <string.h>


void buscarMiniCadena(char *cad, char *ini, char *fin);
char* buscar(const char* s1, const char *s2);
int miStrlen(const char *str);
void remplazarCadena(char *ini,char *fin, int resucant);
//void remplazar(char *ini,char *fin);
void miMemmove(void *dest, void *src, size_t n);

#endif // CADENA_H_INCLUDED
