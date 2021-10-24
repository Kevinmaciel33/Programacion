#include "Matrices.h"

int main()
{
//    char cadenas [][20]= {"Hola Mundo"},
//                         {"Hello world"},
//                         {"bonjour monde"};

    int mat [3][3]  = {{  1,  2,  3},
                        { 4,  5,  6},
                        { 7,  8, 44}};

    int mat1 [3][3]= {{  1,  0,  0},
                      {  0,  1,  0},
                      {  0,  0,  1}
                     };

    int matrizOrden4[4][4]={{1,2,3,4},
                            {1,2,3,4},
                            {1,2,3,4},
                            {1,2,3,4}};

    int mat2 [7][7]= {{    1,  2,  3, 78, 26, 27, 28},
                        { 44,  5,  6, 55, 42, 47, 48},
                        {  7,  8,  4, 56, 22, 27, 28},
                        { 45, 25, 16,  5, 12, 17, 18},
                        { 14, 12,  1,  3, 55, 57, 58},
                        { 11, 11, 11,  1, 51, 51, 58},
                        { 12, 12, 12,  2, 52, 52, 58}
                        };

    int mat3 [7][7]= {{    1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1},
                        {  1,  1, 1, 1, 1, 1, 1}
                        };
    int mat4 [7][7]= {{    1,  0, 0, 0, 0, 0, 8},
                        {  0,  1, 0, 0, 0, 0, 0},
                        {  0,  0, 1, 0, 0, 0, 0},
                        {  0,  0, 0, 1, 0, 0, 0},
                        {  0,  0, 0, 0, 1, 0, 0},
                        {  0,  0, 0, 0, 0, 1, 0},
                        {  8,  0, 0, 0, 0, 0, 1}
                        };
    int result[TAM][TAM];

    int ord = TAM;
    //void debajo_diag_ppal(int mat[][TAM], int ord)
    //printf("La suma de la traza es: %d \n",sumatoriaTrianguloInferior( mat, ord));

//    if(matrizSimetrica(mat4, ord))
//       printf("La matriz es simetrica \n" );
//    else
//        printf("La matriz no es simetrica \n" );

    cuadranteT2(mat2, TAM);
    //mostrarMatriz(result, ord);
    return 0;
}


