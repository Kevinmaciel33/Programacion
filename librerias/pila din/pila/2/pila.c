/// Pila.c

#include "Pila.h"

void crearPila (t_pila *p)
{
    p->tope = TAMPILA;
}

int pilaVacia (const t_pila *p)
{
    return p->tope == TAMPILA;
}

void vaciarPila (t_pila *p)
{
    p->tope = TAMPILA;
}

int pilaLlena (const t_pila *p, unsigned cantBytes)
{
    return (sizeof(unsigned)+cantBytes) > p->tope;
}

int ponerEnPila (t_pila *p, const void *dato, unsigned cantBytes)
{
    if ((sizeof(unsigned)+cantBytes) > p->tope)
        return 0; /// NO HAY LUGAR PARA ESTE DATO

    p->tope -= cantBytes;
    memcpy (p->pila + p->tope, dato, cantBytes);

    p->tope -= sizeof(unsigned);
    //memcpy (p->pila + p->tope, &cantBytes, sizeof(unsigned));
    *(unsigned *)(p->pila + p->tope) = cantBytes;

    return 1;
}

int sacarDePila (t_pila *p, void *dato, unsigned cantBytes)
{
    unsigned tamDatoPila;

    if (p->tope == TAMPILA)
        return 0; //PILA VACIA

        ///RECUPERO EL TAMAÑO DEL DATO A LEER
    //memcpy (&tamDatoPila, p->pila + p->tope, sizeof(unsigned));
    tamDatoPila = *(unsigned *)(p->pila + p->tope);

        ///MOVER A TOPE AL COMIENZO DE LA INFO
    p->tope += sizeof(unsigned);

        ///RECUPERAR EL DATO A LEER
        ///SIEMPRE VA A SER LA MENOR CANT DE BYTES ENTRE tamDatoPila y cantBytes
    memcpy (dato, p->pila + p->tope, MINIMOBYTES(tamDatoPila, cantBytes));

        ///MOVER EL PUNTERO tamDatoPila
    p->tope += tamDatoPila;

    return 1;
}

int verTope (const t_pila *p, void *dato, unsigned cantBytes)
{
    unsigned tamDatoPila;

    if (p->tope == TAMPILA)
        return 0; ///PILA VACIA

    ///memcpy (&tamDatoPila, p->pila + p->tope, sizeof(unsigned));
    tamDatoPila = *(unsigned *)(p->pila + p->tope);

        ///RECUPERAR EL DATO A LEER
        ///SIEMPRE VA A SER LA MENOR CANT DE BYTES ENTRE tamDatoPila y cantBytes
    memcpy (dato, p->pila + p->tope + sizeof (unsigned),
            MINIMOBYTES(tamDatoPila, cantBytes));

    return 1;
}
