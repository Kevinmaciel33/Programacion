#include "Boolean.h"

// :: operador de ambito


//Boolean::Boolean()
//{
//    _valor = 8;
//}
Boolean::Boolean( int valor)
    :_valor(valor)
{
   //this-> _valor = _valor;
}
//Boolean::Boolean( int _valor)
int Boolean::getValue()
{
    return _valor;
    //return this-> _valor;
}
