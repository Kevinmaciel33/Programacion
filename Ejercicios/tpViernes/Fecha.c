#include "Fecha.h"
#define ES_MAYOR 1
#define ES_IGUAL 0
#define ES_MENOR -1
int es_bisiesto(int anio)
{
    if(anio%400 == 0 || (anio%4 == 0 && anio%100 != 0) )
        return 1;

    return 0;
}

int compararFechas(const t_fecha *fecha1, const t_fecha *fecha2)
{
    if( fecha1->anio > fecha2->anio
       || (fecha1->anio == fecha2->anio && fecha1->mes > fecha2->mes)
       || (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia > fecha2->dia))
        return ES_MAYOR;

    if( (fecha1->anio == fecha2->anio && fecha1->mes == fecha2->mes && fecha1->dia == fecha2->dia))
        return ES_IGUAL;

    return ES_MENOR;
}


void ingresa_fecha(t_fecha *fecha)
{
    int es_correcta;
    do {
        scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
        es_correcta = fecha_correcta(fecha);

        if(!es_correcta){
            printf("Fecha Iconrrecta\n");
        }
    }

    while(!es_correcta);
}

void muestra_fecha(t_fecha *fecha)
{
    printf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
}

void suma_anios(t_fecha *fecha, int anios)
{
    fecha->anio += anios;

    if(fecha->mes == 2 && fecha->dia == 29 && !es_bisiesto(fecha->anio)) {
        fecha->dia = 28;
    }
}
