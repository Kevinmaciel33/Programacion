#ifndef UTILITARIAS_H_INCLUDED
#define UTILITARIAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct{
    long dni;
    int nota;
}tAlumno;

int comparar_int(const void* a, const void* b);

void tratamiento_int(const void* dato);

void mostrar_int(const void* dato);
int verificar_nota(const void* dato);
void mostrar_alumno(void* alumno, int profundidad);

int comparar_alumno(const void* alu1, const void *alu2);
#endif // UTILITARIAS_H_INCLUDED
