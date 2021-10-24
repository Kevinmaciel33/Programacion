#include "Archivos.h"
#include <string.h>
#include "Cadenas.h"
#define TAM_LINEA 100

void graba_binario(FILE *arch, t_alumno *alumno)
{
    fwrite(alumno, sizeof(t_alumno),1,arch);
}

void graba_error(FILE *arch_error, const char *cadena_txt)
{
    //
}
int texto_a_alumno(const char *cadena_txt, t_alumno *alumno, t_fecha *fecha_proceso){

    char aux[TAM_LINEA], *ptr;
    strcpy(aux, cadena_txt);
    int no_informa_fecha_proceso = 0;

    //fecha de baja
    alumno->fecha_baja.dia = 31;
    alumno->fecha_baja.mes = 12;
    alumno->fecha_baja.anio = 9999;

    //****************************
    //Estado
    //****************************
    alumno->estado='R';

    //****************************
    //fecha aprobacion ultima materia
    //****************************
    ptr = strchr(aux, '\n');
    *ptr = '\0';

    if(cantidad_apariciones(auxm '|') == 7) ///me informa la fecha de ultima aprobacion
    {
        ptr = strchr(aux, '|');
        sscanf(ptr + 1, "%d/%d/%d", &alumno->fecha_aprob_ult.dia, &alumno->fecha_aprob_ult.mes, &alumno->fecha_aprob_ult.anio);
        *ptr = '\0';
    }
    else
    {
        //asumir la fecha de ingreso
        no_informa_fecha_proceso = 1;
    }

    //cantidad materias aprobadas
    //carrera
    //fecha_ingreso

    return 1;
}

void muestra_binario(const char *nom_arch){
    //
}
