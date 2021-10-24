#include "Archivos.h"


int main()
{
    FILE *archivo;
    FILE *pArchivoBin;

    char nombre[20];
    char nombres[10][10];
    int k = 0;

    archivo=fopen("prueba.txt","r+");

    if(archivo!=NULL)   /* Apertura correcta */
    {
        while(fgets(nombre,20,archivo))  /* Se lee hasta llegar al final */
        {
            strcpy(nombres[k], nombre);

            k++;
        }
        fclose(archivo);
    }
    else
    {
        printf("Error");
    }

    for(int i = 0; i < k; i++)
    {
        printf("%s", nombres[i]);
    }

    pArchivoBin=fopen("datos.dat","wb");

    if(pArchivoBin!=NULL)
    {
        for(int i = 0; i < k; i++)
        {
            printf("%s", nombres[i]);
            fwrite(&nombres[i],sizeof(char), 1, pArchivoBin);
        }
        fclose(pArchivoBin);
    }
    else
    {
        printf("Error en la apertura del archivo");
    }

    getch();
}
