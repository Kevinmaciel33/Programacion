#include "Header.h"

void ordenarSeleccionGen (void * base, int nMemb, int tam, int (*compararDato)(const void *,const void *))
/**b,c,a**/
/**a,c,b**/
/**a,c,b**/
{
  void *i,
      *ini=base,
      *fin=base+(nMemb-1)*tam;
  void* min;
  for(i=ini; i<fin; i+=tam, base+=tam)
  {
      min=buscarMinimoGen(base, fin, tam, compararDato);
      if(base!=min)
        intercambiarGen(base, min,tam);
  }

}

void* buscarMinimoGen (void * base, void * fin, int tam, int (*compararDato)(const void *,const void*))
{
    void *i,
         *min=base;
    int res;
         base+=tam;
    for(i=base;i<=fin;i+=tam, base+=tam)
    {
        if((res=compararDato(min,base))>0)
            min=base;
    }
    return min;
}

int compararEnteros(const void * d1,const void * d2)
{
    return *(int*)d1-*(int*)d2;
}
int compararCaracteres(const void * d1,const void * d2)
{
    return *(char*)d1-*(char*)d2;
}

int compararAlum(const void * d1,const void * d2)
{
    return (((tAlum*)d1)->dni)-(((tAlum*)d2)->dni);
}


void mostrarVec(char * vec, int ce)
{
    int i;
    for(i=0;i<ce;i++)
     {
        printf("%c ", *vec);
        vec++;
     }
}
void mostrarGen(int * vec, int ce)
{
    int i;
    for(i=0;i<ce;i++)
     {
        printf("%c ", *vec);
        vec++;
     }
}


 void intercambiarEnt(void * n1, void * n2)
 {
     int aux=*(int*)n1;
     *(int*)n1=*(int*)n2;
     *(int*)n2=aux;
 }

 int intercambiarGen(void * n1, void * n2, int tam)
 {
     void* aux;
     int retorno;
     if(!(aux=malloc(tam)))
     retorno = 0;
         memcpy(aux,n1,(size_t)tam);
         memcpy(n1,n2,(size_t)tam);
         memcpy(n2,aux,(size_t)tam);
         retorno = 1;
         free(aux);
    return retorno;
 }
