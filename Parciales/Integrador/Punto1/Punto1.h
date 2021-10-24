#ifndef PUNTO1_H_INCLUDED
#define PUNTO1_H_INCLUDED

typedef struct
{
    char cod_cta[10];
    long dni;
    char apyn[40];
    double saldo;
}t_cuenta_banco;

typedef struct
{
    char fecha[15];
    char cod_cta[9];
    char tipo_mov;
    char importe[10];
}t_movimiento_banco;

typedef t_movimiento_banco t_info;

int actualizar_cuentas(const char * path_ctas, const char * path_movs, const char * clave);
int actualizar_cuentas_res(const char * path_ctas, const char * path_movs, const char * clave);

#endif // PUNTO1_H_INCLUDED
