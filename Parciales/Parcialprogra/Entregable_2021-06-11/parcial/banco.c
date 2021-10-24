#include<banco.h>
#include<utilitarias.h>
#include<string.h>
#include<stdlib.h>
#include<cola_estatica.h>

int actualizar_cuentas(const char * path_ctas, const char * path_movs, const char * clave)
{

    FILE * arch_cuentas = fopen(path_ctas, "r+b");
    FILE * arch_movs = fopen(path_movs, "rt");
    FILE * arch_movs_desc = fopen("../Archivos/movimientos_descubierto.txt","wt");

    t_movimiento_banco mov, mov_cola;
    t_cuenta_banco cuenta;
    int lectura_mov;

    tCola cola_movs;

    crear_cola_res(&cola_movs);

    if(!arch_movs)
    {
        printf("No se pudo abrir movimientos\n");
        fclose(arch_cuentas);
        return 1;
    }
    if(!arch_cuentas)
    {
        printf("No se pudo abrir cuentas\n");
        return 2;
    }
    if(!arch_cuentas)
    {
        printf("No se pudo abrir desc\n");
        fclose(arch_cuentas);
        fclose(arch_movs);
        return 3;
    }

    fread(&cuenta, sizeof(t_cuenta_banco), 1, arch_cuentas);
    lectura_mov = leer_movimiento_res( &mov, arch_movs, clave);

    while(!feof(arch_cuentas) && lectura_mov)
    {
        if(strcmp(mov.cod_cta,cuenta.cod_cta) < 0)
        {
            lectura_mov = leer_movimiento_res( &mov, arch_movs, clave);
        }
        else if(strcmp(mov.cod_cta,cuenta.cod_cta) > 0)
        {
            fread(&cuenta, sizeof(t_cuenta_banco), 1, arch_cuentas);
        }
        else
        {
            while(strcmp(mov.cod_cta,cuenta.cod_cta) == 0 && lectura_mov)
            {
                if(mov.tipo_mov == 'C')
                {
                    cuenta.saldo += mov.importe;
                }
                else
                {
                    cuenta.saldo -= mov.importe;
                }
                //Encolar
                poner_en_cola_res(&cola_movs, &mov, sizeof(t_movimiento_banco));

                lectura_mov = leer_movimiento_res( &mov, arch_movs, clave);
            }

            fseek(arch_cuentas, -(int)sizeof(t_cuenta_banco), SEEK_CUR);
            fwrite(&cuenta, sizeof(t_cuenta_banco), 1, arch_cuentas);
            fseek(arch_cuentas, 0L, SEEK_CUR);

            if(cuenta.saldo < 0)
            {
                ///sacar de cola y poner en el archivo
                while(sacar_de_cola_res(&cola_movs, &mov_cola, sizeof(t_movimiento_banco)))
                {
                    fprintf(arch_movs_desc, "%7s %c %09.2f\n",mov_cola.cod_cta, mov_cola.tipo_mov, mov_cola.importe);
                }

            }
            else{
                vaciar_cola_res(&cola_movs);
            }

            fread(&cuenta, sizeof(t_cuenta_banco), 1, arch_cuentas);
        }


    }

    fclose(arch_cuentas);
    fclose(arch_movs);
    fclose(arch_movs_desc);
    return 0;
}
