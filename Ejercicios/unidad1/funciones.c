#include "header.h"

void hola()
{
    int a;
   printf("Hello world!\n");
   printf("ingrese un numero:" );

   scanf("%d",&a);

   printf("La variable ingresada es: %d",a);
}

int factorial(int n) //Ejercicio 1
{
    int acumFactorial = 1;

    for(int i = n; i>0; i--)
    {
        acumFactorial *= i;
    }

    return acumFactorial;
}


int combinatoria(int n, int m) //Ejercicio 2
{
    int resultCombinatoria;

    resultCombinatoria = (factorial(m))/( (factorial(n)) * (factorial(m-n)) );

    return resultCombinatoria;
}

float naturalElevado(int tol, int x) //Ejercicio 3
{
    float resultado = 1,
          termino = 0;

    int cont = 1,
        bandera = 1;

    while((termino > tol) || bandera == 1)
    {
        bandera =0;
        resultado += termino;
        termino = (pow(x,cont)) / (float)(factorial(cont));
        cont++;
        printf("%f\n",termino);
    }

    return resultado;
}

int fibonacci (int n) //ejercicio 5
{
    int i = 1,
        suma = 1,
        ant;


    while(i < n)
    {
        ant = suma;
        suma = i + ant;
        i = ant;
    }

    return (i == n)? 1 : 0;
}

int sumaPrimerosNumerosPrimos(int n) // ejercicio 11
{
    int suma=0;

    for(int i = 0; i <= n; i++)
    {
        if(i%2 == 0)
            suma += i;
    }

 return suma;
}

int validarFecha(int d, int m, int a) //ejercicio 14
{

    return validarDia(d, m, a) && validarMes(m) && validarAnio(a);
}

int validarDia(int d,int m,int a)
{
    int max;
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        max = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        max = 30;
        break;
    case 2:
        if(esBiciesto(a))
            max = 29;
        else
            max = 28;
    }

    return ( d>=1 && d<=max )? 1 : 0;
}

int esBiciesto(int a)
{

    return ( ((a % 4 == 0) && (a % 100 != 0)) || ((a % 4 == 0) && (a % 100 == 0) && (a % 400 == 0)) )? 1: 0;
}

int validarMes(int m)
{
    return (1<=m && m<=12)? 1 : 0;
}

int validarAnio(int a)
{
    return (999<a && a<9999)? 1: 0;
}

//int diaSiguiente(t_Fecha fecha)
//{
//    diasMeses = cantDiasMeses(fecha.mes);
//    diasAnios = cantDiasAnios(fecha.anio);
//    return fecha.dia + meses + anios;
//}

//int cantDiasMeses(int mes, int anio)
//{
//    int dias[][]={
//        {0,31,28,31,30,31,30,31,31,30,31,30,31},
//        {0,31,29,31,30,31,30,31,31,30,31,30,31}
//        };
//
//    int cantDias = 0,
//        bisiesto = 0;
//
//    if(esBiciesto(anio))
//        bisiesto = 1;
//
//    for(int i = 1;i<mes-1;i++)
//        cantDias += dias[bisiesto][i];
//
//
//    return cantDias;
//}

//int sumarNDias(t_Fecha fecha, int aSumar) //ejercicio 15 -> sumar n dias a una fecha
//{
//    int aniosBisiestos = 0,
//        aniosNoBisiestos = 0,
//        cantDiasAnios,
//        cantMes,
//        totDias
//        ;
//
//    for(int i = 1600; i<= fecha.anio; i++)
//    {
//        if(esBiciesto(i))
//            aniosBisiestos++;
//        else
//            aniosNoBisiestos++;
//    }
//
//    cantDiasAnios = (aniosBisiestos * 366) + (aniosNoBisiestos * 365);
//    cantMes = cantDiasMeses(fecha.mes, fecha.anio);
//
//    totDias = fecha.dia + cantMes + cantDiasAnios + aSumar;
//
//    //------Ingenieria inversa-----//
//
//    anio = TotDias/(fecha.anio-1600);
//
//}

//void mostrarVec(int vector[])
//{
//    int cantElemen = sizeof(vector) / sizeof(int);
//
//    printf("%d \n", sizeof(vector));
//    printf("%d \n", sizeof(int));
//
//    for(int* i = 0; i < vector + cantElemen; i++)
//        printf("%d \n", *i++);
//
////    for (i=0; i < 10; i++)
////        printf ("\n%d", *p++);
//}                ------------------------maniana preguntar---------------------

void mostrarVec(int vector[], int tam)
{
    int* p = vector;

    if(tam == 0)
        printf("El vector esta vacio");
    else{
        for(int i = 0; i < tam; i++)
        printf("%d ", *p++);
    }
}


void insertarElementoArray(int* vec, int n, int pos, int cantElem) //Exercise 22
{
    int  *p = vec + pos,
         *tam = vec + cantElem;

    int x1, x2;

    x1 = *p;
    *p = n;
    p++;
    x2 = *p;

    while( *p && p < tam)
    {
        *p = x1;
        p++;
        x1 = *p;
        *p = x2;
        p++;
        x2 = *p;
    }
}

                                                            // exercise 23
//desarrollar una función que inserte un elemento en un arreglo de enteros,
//ordenado en forma ascendente, de forma de no alterar el orden.
void insertarElementoArrayOrdenado(int* vec, int n, int cantElem)
{
    int *p = vec,
        pos = 0;


    while(*p && n>*p) //busca la posicion en donde insertar el elemento son alterar el orden ascendente
    {
        pos++;
        p++;
    }
    insertarElementoArray(vec, n, pos, cantElem);
}

                                                //exercise 24
//Desarrollar una función que elimine el elemento que ocupa una
//determinada posición de un arreglo de enteros
int eliminarElementoArray(int* vec, int pos, int cantElem)
{   // pos -> posicion que quiero eliminar
    int *p = vec + pos,
        *pPost = p + 1,
        *pFin = vec + cantElem;

    while(pFin != pPost)
    {
        *p = *pPost;
        p++;
        pPost++;
    }
    return cantElem - 1;
}
                                                //exercise 25
//Desarrollar una función que elimine la primera aparición de un
//elemento determinado de un arreglo de enteros.

int buscarElemento(int* vec, int n, int cantElem)
{
    int *p = vec,
        pos = 0;

    while(*p && n != *p && (pos+1) < cantElem)
    {
        p++;
        pos++;
    }


    return (n == *p)? pos : -1;
}

int eliminarPrimeraAparicionElementoArray(int* vec, int n, int cantElem)
{
    int pos, tam;
    pos = buscarElemento(vec, n, cantElem);
    if( pos == -1)
    {
        printf("No se encontro el elemento a buscar");
        return 0;
    }
    tam = eliminarElementoArray(vec, pos, cantElem);

    return tam;
}

                                                                //exercise 26
//Desarrollar una función que elimine todas las apariciones de un determinado
//elemento de un arreglo de enteros.
int eliminarTodasAparicionElementoArray(int* vec, int n, int tam)
{
    int pos;

    pos = buscarElemento(vec, n, tam);
    if( pos == -1)
        {
            printf("No se encontro el elemento a buscar");
            return 0;
        }

    while(pos != -1 && tam != 0)
    {
        tam = eliminarElementoArray(vec, pos, tam);

        pos = buscarElemento(vec, n, tam);
    }
    return tam;
}
                                                //exercise 27
//Desarrollar una función que determine si una cadena de
//caracteres es un palíndromo.
int palindromo(char* v, int tam)
{
    //tam es strlen(vec)

    char *pInicio = v,
        *pFin = v + tam -1; //el (-1) es para omitir el caracter \0 de fin de cadena
    int i = 0,
        repeticiones = tam / 2;

    while(*pInicio == *pFin && i < repeticiones)
    {
        pInicio++;
        pFin--;
        i++;
    }
    return (i == repeticiones) ? 1 : 0;

}
                                                //exercise 28
//Desarrollar una función que devuelva el valor numérico de
//una cadena de caracteres (asumiendo que los caracteres representan dígitos).
int valorNumericoCadena(char* v, int tam)
{
    char* p = v;
    int numero = 0,
        i = 1;

    while(tam - i >= 0)
    {
        numero += (*p - 48)* pow(10,tam-i);
        p++;
        i++;
    }

    return numero;
}




