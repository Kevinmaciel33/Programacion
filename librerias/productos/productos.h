#ifndef PRODUCTOS_H
#define PRODUCTOS_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct
{
    int codProd;
    float precio;
    char descrip[46];
} tProd;
int ingresarProducto(tProd* prod);
void mostrarProducto(tProd* prod);
void sacarSalto(char* p);
void aplicarDescuento10(void* pnodo, int porcentaje);
void mostrarProductoDeLista(const void* pnodo);
int compararProductos(const void *d1, const void *d2);
void mostrarProductoDeLista(const void* pnodo);
int compararProductosMenorMayor(const void *d1, const void *d2);
int compararProductosPorDescripcion(const void *d1, const void *d2);
void agruparProductos(const void *d1, const void *d2);
#endif // PRODUCTOS_H
