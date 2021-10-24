#include "Cola.h"
int minimo(int a, int b)
{
    return a<b?a:b;
}

void crearCola(t_cola* p)
{
    p->pri=5;
    p->ult=5;//pri y ult pueden tener cualquier valor, siempre que sea el mismo y que esté en la cola
    p->tamDisponible=TAM_COLA;
}
int colaVacia(const t_cola* p)
{
    return TAM_COLA == p->tamDisponible;
}
int colaLlena(const t_cola* p, unsigned cantBytes)
{
    return p->tamDisponible<(cantBytes+sizeof(unsigned));
}
void vaciarCola(t_cola* p)
{
    p->pri=0;
    p->ult=0;
    p->tamDisponible=TAM_COLA;
}
int ponerEnCola(t_cola* p,const void *dato,unsigned cantBytes)
{
    unsigned ini;
    unsigned fin;
    if(p->tamDisponible<sizeof(unsigned)+cantBytes)
            return 0;
            p->tamDisponible -= sizeof(unsigned)+cantBytes;
            if((ini = minimo(sizeof(cantBytes), TAM_COLA - p->ult)) !=0 )
                memcpy(p->cola + p->ult, &cantBytes, ini);
                if((fin = sizeof(cantBytes) - ini) != 0)
                    memcpy(p->cola, ((char*)&cantBytes)+ini, fin);
                    p->ult = fin? fin: p->ult+ini;

                    if((ini = minimo(cantBytes, TAM_COLA - p->ult)) != 0)
                        memcpy(p->cola + p->ult, dato, ini);
                        if((fin = cantBytes - ini) != 0)
                            memcpy(p->cola,((char*)dato) + ini, fin);
                            p->ult = fin? fin: p->ult+ini;
                            return 1;
                }

int sacarDeCola(t_cola* p,void *dato,unsigned cantBytes)
{
    unsigned tamInfo,
             ini,
             fin;

    if(p->tamDisponible == TAM_COLA)
            return 0;
    if((ini = minimo(sizeof(unsigned), TAM_COLA - p->pri))!=0)
        memcpy(&tamInfo,p->cola + p->pri, ini);
    if((fin = sizeof(unsigned)-ini)!=0)
        memcpy(((char*)&tamInfo)+ini, p->cola,fin);
    p->pri=fin? fin : p->pri + ini;
    p->tamDisponible += sizeof(unsigned)+ tamInfo;
    tamInfo = minimo(tamInfo, cantBytes);
    if((ini = minimo(tamInfo, TAM_COLA - p->pri)) !=0)
        memcpy(dato, p->cola + p->pri, ini);
    if((fin = tamInfo-ini)!=0)
        memcpy(((char*)dato) + ini, p->cola, fin);
    p->pri = fin? fin: p->pri + ini;
    return 1;
}

int verPrimero(const t_cola* p, void *dato, unsigned cantBytes)
{
    unsigned tamInfo,
             ini,
             fin,
             pos= p->pri;
    if(p->tamDisponible == TAM_COLA)
        return 0;

    if((ini = minimo(sizeof(unsigned), TAM_COLA - p->pri))!=0)
        memcpy(&tamInfo,p->cola + p->pri, ini);
    if((fin = sizeof(unsigned)-ini)!=0)
        memcpy(((char*)&tamInfo)+ini, p->cola,fin);
    pos=fin? fin :  pos + ini;
    tamInfo = minimo(tamInfo, cantBytes);
    if((ini = minimo(tamInfo, TAM_COLA - pos)) !=0)
        memcpy(dato, p->cola + pos, ini);
    if((fin = tamInfo-ini)!=0)
        memcpy(((char*)dato) + ini, p->cola, fin);
}
