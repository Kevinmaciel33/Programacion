#include "/home/bruno/Desktop/Unlam/Programacion/ejercicios/TP2/librerias/funciones.h"
//#include "E:\Unlam\Programacion\ejercicios\TP2\librerias\funciones.h"

int cantCaracteres(char* p)
{
    int cont=0;
    while (*p != '\0')
    {
        p++;
        ++cont;
    }
    return cont;
}

int esShortInt(char* cad1)
{
    int neg=0;
    if(*cad1=='-')
    {
        neg=1;
        cad1++;
    }
    int posicion = cantCaracteres(cad1);//usando el Teorema fundamental de la numeración
    int num=0;
    while(*cad1!='\0')
    {
        posicion--;
    num += (neg==1)?pow1(10,posicion)*((*cad1)- '0')*-1:pow1(10,posicion)*((*cad1)- '0')*1;//Aproligar. Si hay un caracter -. Multiplico el num resultante por -1.
    cad1++;
    }
    return num>32767||num<-32768?0:1;
}
int pow1(int base, int exp)
{
    int i,result=base;
    if(exp==0)return 1;
    for(i=0;i<exp-1;i++)
    {
        result*=base;
    }
    return result;
}

int esMayorQue(char* cad1, char*cad2)
{
    char* ptr;
    long num1 = strtol(cad1, &ptr, 10);
    long num2 = strtol(cad2, &ptr, 10);
    return num1>num2?1:0;
}
char* proximaPalabra(char* proxima)
{
    char* p=proxima;
    while(*p!=' ')
    {
        if(*p=='\n')return p;
        p++;
    }
    while(*p==' ')
    {
        if(*p=='\n')return p;
        p++;
    }
    return p;
}
