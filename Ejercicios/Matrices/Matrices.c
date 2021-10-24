#include "Matrices.h"


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

//int cmp_ent(const void * v1, const void * v2)
//{
//    int * e1 = v1,
//        * e2 = v2;
//        return *e1 - *e2;
//}

int* buscarMenorInt(const int * vec, const int * fin)
{
    const int * men = vec;
    vec++;
    while( vec <= fin )
    {
        if (*vec < *men)
            men = vec;

        vec++;
    }
    return (int*)men;


}


void intercambiarInt(int* e1, int* e2)
{
    int aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}

void ordenarSeleccionInt(int* vec, size_t ce)
{
    int * fin = vec + ce,
        * menor;

    while(vec < fin)
    {
        menor = buscarMenorInt(vec, fin);
        if(vec != menor)
            intercambiarInt(vec, menor);
        vec++;
    }

}

void debajo_diag_ppal(int mat[][TAM], int ord)
{
    int i, j;

    for(i = 1; i < TAM; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(i < j)
                printf("%3d |", mat[i][j]);
        }
        printf("\n");
    }
}

                                                                //Ejercicio 29
//Desarrollar una función para que, dada una matriz cuadrada de reales de orden
//N, obtenga la sumatoria de los elementos que están por encima de la diagonal principal (excluida ésta).
//Lo mismo para la diagonal secundaria. Lo mismo incluyendo la
//diagonal. Lo mismo, con los que están por debajo de la diagonal.
int sumatoriaTrianguloSuperior(int v[][TAM], int ord)
{
    int suma = 0,numero;

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 1 + i; j < TAM; j++)
        {
            numero= v[i][j];
            suma += numero;
        }
    }
    return suma;
}

int sumatoriaTrianguloInferior(int v[][TAM], int ord)
{
    int suma = 0,numero;

    for(int i = 1; i < TAM; i++)
    {
        for(int j = 0; j < i; j++)
        {
            numero= v[i][j];
            suma += numero;
        }
    }
    return suma;
}

int sumatoriaTrianguloSuperiorSecundaria(int v[][TAM], int ord)
{
    int suma = 0,numero;

    for(int i = 0; i < TAM ; i++)
    {
        for(int j = 0; j < TAM - 1 - i; j++)
        {
            numero= v[i][j];
            suma += numero;
        }
    }
    return suma;
}

void mostrarMatriz(int v[][TAM], int ord)
{
    for(int i = 0; i < ord; i++)
    {
        for(int j = 0; j < ord; j++)
        {
            printf("%5d",v[i][j]);
        }
    printf("\n");
    }
}

                                                        //Ejercicio 30
//Desarrollar una función para que, dada una matriz cuadrada de enteros
//de orden N, obtenga la traza de la misma (sumatoria de los elementos
//de la diagonal principal).Lo mismo, pero con la diagonal secundaria

int sumaTrazaDiagonalPrincipal(int v[][TAM], int ord)
{
    int suma = 0;
    for(int i = 0; i < ord; i++)
    {
        suma += v[i][i];
    }

    return suma;
}

int sumaTrazaDiagonalSecundaria(int v[][TAM], int ord)
{
    int suma = 0;
    for(int i = 0; i < ord; i++)
    {
        suma += v[i][ord - 1 - i];
    }
    return suma;
}

                                        //Ejercicio 31
//Desarrollar una función que determine si una matriz
//cuadrada de enteros de orden N es matriz diagonal
//(ceros en todos sus elementos excepto en la diagonal principal).
int matrizDiagonal(int v[][TAM], int ord)
{
    return (
            (sumatoriaTrianguloSuperior( v, ord) + sumatoriaTrianguloInferior( v, ord)) == 0 &&
            (sumaTrazaDiagonalPrincipal(v, ord)) > 0)? 1: 0;
}

                                        //Ejercicio 32
//Desarrollar una función que determine si una matriz
//cuadrada de enteros de orden N es matriz identidad
//(matriz diagonal, con unos en la diagonal principal y ceros en
//los restantes).
int matrizIdentidad(int v[][TAM], int ord)
{
    return (
            (sumatoriaTrianguloSuperior( v, ord) + sumatoriaTrianguloInferior( v, ord)) == 0 &&
            (sumaTrazaDiagonalPrincipal(v, ord)) == ord)? 1: 0;
}

//Ejercicio 33
//Desarrollar una función que determine si una matriz
//cuadrada de enteros de orden N es simétrica.
int matrizSimetrica(int v[][TAM], int ord)
{
    int simetria = 1;
    for(int i = 0; i < ord/2; i++)
    {
        for(int j = 0; j < ord; j++)
        {
            if(v[i][j] != v[j][i])
                simetria = 0;
        }
    }

    return (simetria == 1)? 1: 0;
}

                                            //Ejercicio 34
//Desarrollar una función para trasponer, in situ, una matriz cuadrada.
void transponerMatriz(int v[][TAM], int ord)
{
    int aux;
    for(int i = 0; i < ord; i++)
    {
        for(int j = 1 + i; j < ord; j++)
        {
            aux = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = aux;
        }
    }
}
                                        //Ejercicio 36
//Desarrollar una función para obtener la matriz producto entre dos matrices de
//enteros.
void productoMatriz(int v1[][TAM], int v2[][TAM], int v3[][TAM],int ord)
{
    for(int i = 0; i < ord; i++)
    {
        for(int j = 0; j < ord; j++)
        {
            v3[i][j] = v1[i][j] * v2[i][j];
        }
    }
}

//Mostrar cuadrante t1
void cuadranteT1(int v[][TAM], int ord)
{
    for(int i = 0; i < ord; i++)
    {
        for(int k = 0; k < i; k++)
        {
            printf(" ");
        }
        for(int j = 0 + i; j < ord - i; j++)
        {
            printf("%d", v[i][j]);
        }

        printf("\n");

    }
}

////Mostrar cuadrante t2
//void cuadranteT2(int v[][TAM], int ord)
//{
//    int j= ord - 1, l = 0, m = 0;
//
//    for(int i = 0; i < ord; i++)
//    {
//       for(int k = 0; k < ord -1 - i + m; k++)
//        {
//            printf(" ");
//        }
//
//        if(ord - 1 - i > ord/2 )
//        {
//           for(j = ord - 1 - i; j < ord; j++)
//            {
//                printf("%d", v[i][j]);
//            }
//        }else{
//
//            for(l = ord/2 + m; l < ord; l++)
//            {
//                printf("%d", v[i][l]);
//
//            }
//
//            m++;
//printf(" ");
//        }
//
//
//        printf("\n");
//
//    }
//}

void cuadranteT2(int v[][TAM], int ord)
{
    int inij;
    for(int i = 0; i < ord; i++)
    {
        inij = ord - i - 1 > i ? ord - i - 1 : i;
        printf("\n%*s", inij*3,"");
        for(int j = inij ; j < ord; j++)
        {
            printf("%3d", v[i][j]);
        }

        printf("\n");

    }
}










