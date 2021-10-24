#include "Integrador.h"
#include "Fecha.h"
#include "Alumno.h"
#include "Cadenas.h"
#include "Archivos.h"
#define TAM 100
#define TAM_LINEA 100


void mostrarCadena(char cad[]);

int main()
{
    t_fecha fecha_proceso;
    char path_txt[100], cadena_txt[TAM_LINEA];
    FILE *arch_txt, *arch_bin, *arch_error;
    t_alumno alumno;

    printf("Ingrese la fecha del proceso: \n");
    ingresa_fecha(&fecha_proceso);
    muestra_fecha(&fecha_proceso);

    do
    {
        printf("Ingrese path de archivo de texto:\n");
        fflush(stdin);
        gets(path_txt);

        arch_txt = fopen(path_txt, "rt");

        if(!arch_txt)
        {
            printf("No se encuentra el archivo de texto. Reintente");
        }
    }
    while(!arch_txt);

    arch_bin = fopen("archivos/mi_archivo.bin", "wb");
    if(!arch_bin)
    {
        printf("Error de creacion de archivo Binario.\n");
        exit(1);
    }

    arch_error = fopen("archivos/error.txt", "wt");
    if(!arch_error)
    {
        printf("Error de creacion de archivo Binario.\n");
        exit(1);
    }

//***************************************************************//
            ///Procesamiento de los archivos
//***************************************************************//
    fgets(cadena_txt, TAM_LINEA, arch_txt);

    while(!feof(arch_txt)) {

        if(texto_a_alumno(cadena_txt, &alumno, &fecha_proceso))
            graba_binario(arch_bin, &alumno);
        else
            graba_error(arch_error, cadena_txt);
        fgets(cadena_txt, TAM_LINEA, arch_txt);
    }


//***************************************************************//
                    // Cerrar archivos
//**************************************************************//

    fclose(arch_txt);
    fclose(arch_bin);
    fclose(arch_error);
    muestra_binario("archivos/mi_archivo.bin");

//    char opcion;
//
//    opcion = menuMsjOpc("\n Elija una opcion: \n\n "
//                        "I- Ingreso y validacion del alumno\n"
//                        "L- Listado de alumnos\n"
//                        "E- Listado de alumnos con error\n"
//                        "S- Salir\n\n",
//                        "ILES");
//    printf("\n La opcion elegida es: %c \n", opcion);


    char nombres[5][41] =
    {
        {" Jonatan, Uran "},
        {" Paola Ghigo "},
        {" JuaN CARLOS , gutierrez"},
        {" DIEgO RUiz "},
        {" jUAn,ROdriguez "}
    };


    ///ingresa_alumno(&alumno);

    ///valida_alumno(&fecha_proceso, &alumno);


    return 0;
}



