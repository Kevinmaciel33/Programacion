#include <stdio.h>
#include <stdlib.h>

int main()
{
    int elem = 1;
    int i;
    tPila pila_ent //declaro pila de enteros
    crear_pila(&pila);



    for(i=0;i<26;i++)
    {
        int r = poner_en_pila(&pila_ent, &i, sizeof(i));
        if(!r)
            printf("Pila llena\n");

        printf("\n Ingreso -%d ",i);
    }

    system("pause");

    ///ver_tope_pila(&pila_ent, &i, sizeof(i));

    printf("\n tope: %d \n ", i);

    while(!pila_vacia(&pila_ent))
    {
        sacar_de_pila(&pila_ent, &elem, sizeof(elem));
        printf("-%d", elem);
    }

    return 0;
}
