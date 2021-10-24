#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <stdio.h>
#include "Alumno.h"

void graba_binario(FILE *arch, t_alumno *alumno);
void graba_error(FILE *arch_error, const char *cadena_txt);
int texto_a_alumno(const char *cadena_txt, t_alumno *alumno, t_fecha *fecha_proceso);
void muestra_binario(const char *nom_arch);
#endif // ARCHIVOS_H_INCLUDED
