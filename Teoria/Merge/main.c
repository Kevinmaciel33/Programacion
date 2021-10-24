#include "Merge.h"

typedef struct
{
    int d, m, a;
} t_fecha;

typedef struct
{
    int dni;
    char apyn[30];
    char sexo;
    float promedio;
    int notas[50];
    t_fecha f_ing;
    char estado;
} t_alumno;

int cargar_archivo1(char * path);
int cargar_archivo2(char * path);


int main()
{
    FILE * pf1, *pf2, *pfr;
    t_alumno alu1, alum2;

    //TODO: Validar se hayan cargado los arch
    pf1 = fopen("alu1.dat", "rb");
    if(!pf1)
    {
        return 1;
    }

    pf2 = fopen("alu2.dat", "rb");
    if(!pf2)
    {
        return 1;
    }


    pfr = fopen("alu_res.dat", "wb");
    if(!pf1)
    {
        fclose(pf1);
        fclose(pf2);
        return 3;
    }

    fread(&alu1, sizeof(t_alumno), 1, pf1);
    fread(&alu2, sizeof(t_alumno), 1, pf2);
    while(!feof(pf1) && !feof(pf2))
    {
        if(alu1.dni < alu2.dni)
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
        }
        else if (alu1.dni > alu2.dni)
        {
            fwrite(&alu2, sizeof(t_alumno), 1, pfr)
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }
        else
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }

    }
    while(!feof(pf1))
    {
        fwrite(&alu1, sizeof(t_alumno), 1, pfr);
        fread(&alu1, sizeof(t_alumno), 1, pf1);
    }
    while(!feof(pf2))
    {
        fwrite(&alu2, sizeof(t_alumno), 1, pfr)
        fread(&alu2, sizeof(t_alumno), 1, pf2);
    }

    //interseccion
    fread(&alu1, sizeof(t_alumno), 1, pf1);
    fread(&alu2, sizeof(t_alumno), 1, pf2);
    while(!feof(pf1) && !feof(pf2))
    {
        if(alu1.dni < alu2.dni)
        {
            fread(&alu1, sizeof(t_alumno), 1, pf1);
        }
        else if (alu1.dni > alu2.dni)
        {
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }
        else
        {
            fwrite(&alu1, sizeof(t_alumno), 1, pfr);
            fread(&alu1, sizeof(t_alumno), 1, pf1);
            fread(&alu2, sizeof(t_alumno), 1, pf2);
        }

    }

    fclose(pf1);
    fclose(pf2);
    fclose(pfr);

    pfr = fopen("alu_res.dat", "rb");
    if(!pfr)
    {
        return 1;
    }
    fread(&alu1, sizeof(t_alumno), 1, pf1);
    while(!feof(pfr))
    {
        printf("\n%ld - %d, %s, %02d/%02d/%d, %c", ftell(pfr), alu1.dni, alu1.apyn, alu1.f_ing.d, alu1.f_ing.m, alu1.f_ing.a, alu1.estado );
        fread(&alu1, sizeof(t_alumno), 1, pf1);
    }
    fclose(pfr);

    return 0;
}
