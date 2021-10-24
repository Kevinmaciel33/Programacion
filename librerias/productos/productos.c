#include "productos.h"
#include "../lista/lista.h"

int ingresarProducto(tProd* prod)
{
    char descIngresada[30];
    int codigo;

    puts("Ingreso de producto (para finalizar ingrese precio -1)");

    puts("Codigo:");
    scanf("%d",&codigo);

    if(codigo==-1)return 0;
    prod->codProd=codigo;

    puts("Precio:");
    scanf("%f",&prod->precio);

    puts("Descripcion:");
    fflush(stdin);
    fgets(descIngresada,sizeof(prod->descrip),stdin);
    sacarSalto(descIngresada);
    strcpy(prod->descrip,descIngresada);
    return 1;
}

void mostrarProducto(tProd* prod)
{
    if(!prod)
        printf
        ("\n\nDescripcion---------------------Precio----------CodProducto\n");
    else
        printf
        ("\n%-32s%-16.2f%11d", prod->descrip, prod->precio,prod->codProd);
}

void mostrarProductoDeLista(const void* pnodo)
{
    tProd prod=*(tProd*)((t_nodo*)pnodo)->info;
    if(!pnodo)
        printf
        ("\n\nDescripcion---------------------Precio----------CodProducto\n");
    else
        printf("\n%-32s%-16.2f%11d", prod.descrip, prod.precio,prod.codProd);
}


void sacarSalto(char* p)
{
    while(*p)
    {
        if(*p=='\n')
            *p='\0';
        else
            p++;
    }
}

void aplicarDescuento10(void* pnodo, int porcentaje)
{
    tProd prod=*(tProd*)((t_nodo*)pnodo)->info;
    prod.precio-=prod.precio*porcentaje/100;
    *(tProd*)((t_nodo*)pnodo)->info=prod;
}
int compararProductos(const void *d1, const void *d2)
{
    tProd prod1=*(tProd*)d1;
    tProd prod2=*(tProd*)d2;
    return prod1.codProd==prod2.codProd;
}
int compararProductosPorDescripcion(const void *d1, const void *d2)
{
    tProd prod1=*(tProd*)d1;
    tProd prod2=*(tProd*)d2;
    return strcmp(prod1.descrip,prod2.descrip)==0;
}
int compararProductosMenorMayor(const void *d1, const void *d2)
{
    tProd prod1=*(tProd*)d1;
    tProd prod2=*(tProd*)d2;
    return prod1.codProd-prod2.codProd;
}

void agruparProductos(const void *d1, const void *d2)
{
    tProd prod1=*(tProd*)d1;
    tProd prod2=*(tProd*)d2;
    //prod2.cant+=prod1.cant;//lo hago en precio porque mis productos no tienen cantidad
    prod2.precio+=prod1.precio;
    *(tProd*)d2=prod2;
    printf("Se actualizo el precio del producto\n %s %f",
           prod2.descrip, prod2.precio);
}
