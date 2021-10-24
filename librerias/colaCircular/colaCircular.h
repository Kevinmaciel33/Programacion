#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H
typedef struct s_nodo
{
    void* info;
    unsigned tamInfo;
    struct s_nodo *sig;
}t_nodo_cola;

typedef struct
{
    t_nodo_cola* pri;
    //t_nodo_cola* ult;
}t_cola;

void crearCola(t_cola *c);

int colaVacia(const t_cola* c);

int colaLlena(const t_cola* c, unsigned cantBy);

int ponerEnCola(t_cola *c, const void* d, unsigned cantBy);

int sacarDeCola(t_cola *c, void* d, unsigned cantBy); ///saco siempre el primero q se ingreso

void vaciarCola(t_cola *c);

int verPrimero(const t_cola *c, void *d, unsigned cantBy);



#endif // COLACIRCULAR_H
