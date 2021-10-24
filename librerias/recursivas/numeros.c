#include "funciones.h"
void mostrarNumFinal(int num)
{
    if(num==0)
        return;
    mostrarNumFinal(num/10);
    printf("\n%d",num%10);
    //va hasta el caso base y después imprime
}

void mostrarNumFinal2(int num)
{
    if(num==0)
        return;
    printf("\n%d",num%10);
    mostrarNumFinal2(num/10);
    // y después imprime hasta que llega al caso base
}

void trianguloA(int num)
{
    if(num==0)
        return;
    trianguloA(num/10);
    printf("\n%d",num);
}

void trianguloB(int num)
{
    if(num==0)
        return;
    printf("\n%d",num);
    trianguloB(num/10);
}

void trianguloC(int num)
{
    int digitos=cantDigitos(num),
        pot;
    if(digitos==1)
    {
        printf("\n%d",num);
        return;
    }
    pot=potencia(10,digitos-1);
    trianguloC(num%pot);
    printf("\n%d",num);
}

void trianguloD(int num)
{
    int digitos=cantDigitos(num),
        pot;
    if(digitos==1)
    {
        printf("\n%d",num);
        return;
    }
    printf("\n%d",num);
    pot=potencia(10,digitos-1);
    trianguloD(num%pot);
}

void triangulos(int num)
{
    int pot,
    digitos=cantDigitos(num)
    digitosNumReducido=cantDigitos(num%10)
    pot=potencia(10,digitos);
    num%10
}

int cantDigitos(int num)
{
    int cont=0;
    while(num)
    {
        num/=10;
        cont++;
    }
    return cont;
}
int potencia(int num, int cant)
{
    int i,result=1;

    if(cant<=1)
        return num;

    for(i=0; i<cant; i++)
        result*=num;
    return  result;
}
