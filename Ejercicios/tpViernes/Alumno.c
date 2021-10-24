#include "Alumno.h"
#include "Cadenas.h"
#include "Fecha.h"
#define ERROR 0
#define OK 1
#define ANIOS 10

int valida_alumno(const t_fecha *fecha_proceso, t_alumno *alu)
{
    t_fecha fecha_aux;

    //DNI
    if(alu->dni <= 10000 || alu->dni >= 100000000)
        return ERROR;

    fecha_aux = alu->fecha_nac;
    suma_anios(&fecha_aux, ANIOS);
    compararFechas(&fecha_aux, fecha_proceso );

    ///FechaNacimiento
    if(!fecha_correcta(alu->fecha_nac) || compararFechas(&fecha_aux, fecha_proceso))
        return ERROR;

    //SEXO
    if(alu->sexo != 'F' && alu->sexo != 'M')
        return ERROR;

    //normaliza_apellido_nombre(t_alumno *alumno)
    return OK;
}

//int ingresa_alumno(t_alumno *alumno)
//{
//
//    return 1;
//}

void normaliza_apellido_nombre(t_alumno *alumno)
{
    mayusculasMinusculas(alumno->apyn);
    no_mas_de_un_espacio(alumno->apyn);
    sin_espacios_inicio_fin(alumno->apyn);
    coma(alumno->apyn);

}
