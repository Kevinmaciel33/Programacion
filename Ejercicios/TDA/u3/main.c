
#include "u3.h"

int main()
{

    tPila pila1,
          pila2,
          pilaResultado;

    int num=1,
        numP1 = 1,
        numP2 = 1;

    //char cad1[100]= {'1', '2', '3', '4'};
   //char cad2[100]= {'2', '1', '1', '5'};
    char cad1[100]= {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};
    char cad2[100]= {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'};

    //CREAR PILA
    crearPila(&pila2);
    crearPila(&pilaResultado);

    //1-Cargar pila1 y pila2 con los numeros
    crearPila(&pila1);
    cargarPila(cad1, &pila1);
    cargarPila(cad2, &pila2);

    //2-Sumar teniendo en cuenta el carry y almacenar en pilaResultado

    int carry = 0,
        resultado;

    while( !pilaVacia(&pila1) || !pilaVacia(&pila2))
    {
        sacarDePila(&pila1, &numP1, sizeof(num));
        sacarDePila(&pila2, &numP2, sizeof(num));
        resultado = numP1 + numP2 + carry;
        carry = 0;
        if(resultado > 9 )
        {
            resultado -= 10;
            carry = 1;
        }
        ponerEnPila(&pilaResultado, &resultado, sizeof(resultado));
    }



    ////////////////////////////////////////////////////////////////////

    while(!pilaVacia(&pila1))
    {
        sacarDePila(&pila1, &num, sizeof(num));
        printf("%d \n", num);
    }

    while(!pilaVacia(&pila2))
    {
        sacarDePila(&pila2, &num, sizeof(num));
        printf("%d \n", num);
    }

    printf("Pila Resultado \n");
    while(!pilaVacia(&pilaResultado))
    {
        sacarDePila(&pilaResultado, &num, sizeof(num));
        printf("%d", num);
    }

    return 0;
}


