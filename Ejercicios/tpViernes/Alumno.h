#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

#include "Fecha.h"

typedef struct{

    long dni;
    char apyn;
    t_fecha fecha_nac;
    char sexo;
    t_fecha fecha_ingreso;
    char carrera[4];
    int cant_mat_aprob;
    t_fecha fecha_aprob_ult;
    char estado;
    t_fecha fecha_baja;
}t_alumno;

int valida_alumno(const t_fecha *fecha_proceso, t_alumno *alumno ); //0 -> es valido  1 -> no es valido
void ingresa_alumno(t_alumno *alumno);
void normaliza_apellido_nombre(t_alumno *alumno);

#endif // ALUMNO_H_INCLUDED
