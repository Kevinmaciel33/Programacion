#include "ParcialLista.h"
#include <string.h>

int main()
{
//    int v[20]={1,2,11,4,5,6,7,8,9,10,11,11,11,11,11,11,11,11,11,8};
    tLista p;
    crearLista(&p);
    leerArchivoYCargarLista(&p, "numeros.txt");
    //eliminarDuplicados(&p);


    ordenar(&p,cmp_ent);

    /* Mostrar Lista */
    int d=0;
    for(int i = 0; i < 20; i++ )
    {
        ObtenerInt(&p, &d, sizeof(d), i);
        printf("%d \n", d);
    }
    return 0;
}
