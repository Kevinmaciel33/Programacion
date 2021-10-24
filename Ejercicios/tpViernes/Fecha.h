#ifndef FECHA_H
#define FECHA_H

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

int compararFechas(const t_fecha *fecha1, const t_fecha *fecha2);
void ingresa_fecha(t_fecha *fecha);
void muestra_fecha(t_fecha *fecha);
void suma_anios(t_fecha *fecha, int anios);
int es_bisiesto(int anio);


#endif // FECHA_H
