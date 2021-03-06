



void* memmove_MIO(void *dest, void* orig, unsigned tam)
{
    char *d=dest,
          *s=orig,
           *ps,
           *pd;
    unsigned tamAux=tam;
    void* retorno;
    //si la palabra fuente est? antes que la destino y destino empieza antes que termine la fuente.
    if(orig < dest && dest <= orig+tam)
    {
        ps=orig+tam;//voy al final de ambas
        pd=dest+tam;
        while(tamAux--)//copio desde el final hasta el principio de la palabra.
        {
            pd--;
            ps--;
            *pd=*ps;
        }
        //pd+=tam;//me posiciono al final de la palabra
        //*(pd)='\0';//indico que termina la palabra
        retorno=pd;
    }
    else
    {
        while(tam--)//copio desde el principio hasta el final de la palabra.
            *d++ = *s++;
        //*d='\0';//indico que termina la palabra
        retorno=d;
    }
    return retorno;
}
