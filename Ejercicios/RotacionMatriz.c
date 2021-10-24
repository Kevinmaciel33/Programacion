#include <stdio.h>
#include <stdlib.h>

#define TAM 7
int main()
{
    int aux, aux2;

    int vi[3][3]=   {{1,1,1}, //{3,2,1}
        {2,2,2}, //{3,2,1}
        {3,3,3}  //{3,2,1}
    };

    int va[4][4]=   {{1,1,1,1}, //{4,3,2,1}
        {2,2,2,2}, //{4,3,2,1}
        {3,3,3,3}, //{4,3,2,1}
        {4,4,4,4}  //{4,3,2,1}
    };

    int v[7][7]= {{1,1,1,1,1,1,1},
        {2,2,2,2,2,2,2},
        {3,3,3,3,3,3,3},
        {4,4,4,4,4,4,4},
        {5,5,5,5,5,5,5},
        {6,6,6,6,6,6,6},
        {7,7,7,7,7,7,7}
    };
    /*
    ////////////////
    aux = v[1][2];
    v[1][2] = v[0][1];

    aux2 = v[2][1];
    v[2][1] = aux;
    aux = v[1][0];
    v[1][0] = aux2;
    v[0][1] = aux;

    ////////////////aumentan
    aux = v[0+i][2];
    v[0+i][2] = v[0][0+i];
    ////////////////restan
    aux2 = v[2][2-i];
    v[2][2-i] = aux;
    aux = v[2-i][0];
    v[2-i][0] = aux2;
    v[0][2-i] = aux;*/

    //rotarla horario 90deg
    for(int i = 0; i <= 1; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            ////////////////aumentan
            aux = v[i+j][TAM-1-i];

            v[i+j][TAM-1-i] = v[i][j];

            ////////////////restan
            aux2 = v[TAM-1-i][TAM-1-i-j];
            v[TAM-1-i][TAM-1-i-j] = aux;

            aux = v[TAM-1-i-j][i];
            v[TAM-1-i-j][i] = aux2;

            v[i][j] = aux;
        }

    }

    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }




    return 0;
}
