#include <stdio.h>
#include <stdlib.h>
#include "Punto1.h"

int main()
{
    FILE * cuenta, *arch_txt;
    t_info mov[11];
    double importe;
    tLista lista;

    crear_lista(&lista);

    arch_txt = fopen("movimientos.txt","rt");
    if(!arch_txt)
        return 0;

    cuenta = fopen("cuentas.dat","r+b");
    if(!arch)
        return 0;

    while(leer_archivo_txt(arch_txt,&mov))
    {
        poner_orden_lista(&lista,&mov,sizeof(t_info),cmp_codigo); // de menor a mayor o alreves?
    }

    fclose(arch_txt);

    actualizar_cuentas(&lista,cuenta);
    return 0;
}
