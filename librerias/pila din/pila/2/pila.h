/// Pila.h
 
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define TAMPILA 200
#define MINIMOBYTES(x,y) (((x) < (y)) ? (x) : (y))
 
typedef struct
{
    char pila[TAMPILA];
    unsigned int tope;
} t_pila;
 
void crearPila (t_pila *p);
int pilaVacia (const t_pila *p);
int pilaLlena (const t_pila *p, unsigned cantBytes);
void vaciarPila (t_pila *p);
int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes);
int sacarDePila (t_pila *p, void *dato, unsigned cantBytes);
int verTope (const t_pila *p, void *dato, unsigned cantBytes);
 
 
#endif // PILA_H_INCLUDED