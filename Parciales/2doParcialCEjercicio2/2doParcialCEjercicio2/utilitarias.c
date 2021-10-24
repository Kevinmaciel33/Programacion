#include "utilitarias.h"

int comparar_int(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}
int comparar_alumno(const void* alu1, const void *alu2)
{
    tAlumno* al1=(tAlumno*)alu1;
    tAlumno* al2=(tAlumno*)alu2;
    return al1->dni-al2->dni;
}

int verificar_nota(const void* dato)
{
    tAlumno* alu=(tAlumno*)dato;
    return alu->nota<7;
}
void tratamiento_int(const void* dato)
{
    printf("\n se encontro un duplicado con valor %d \n", *((int*)dato));
}

void mostrar_int(const void* dato)
{
    printf("\n La lista contiene: %d \n", *((int*)dato));
}

void mostrar_alumno(void* alumno, int profundidad)
{
    tAlumno* alu=(tAlumno*)alumno;
    printf("\n %*d dni: %ld nota: %d",3*profundidad,0,alu->dni,alu->nota);
}
