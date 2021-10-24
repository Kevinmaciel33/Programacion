#include "Cadena.h"
#include <string.h>

Cadena::Cadena() //ctor
{

    *cadena = ' ';
    //cadena = new char[1];

}

Cadena::Cadena(const char* c) //ctor
{
    char* pCadenaObjeto = cadena;
    char* comienzoCadena = (char*)c;

    while (*comienzoCadena)
    {
        *pCadenaObjeto = *comienzoCadena;
        pCadenaObjeto++;
        comienzoCadena++;
    }

//    cadena = new char[strlen(c) + 1];
//    char* pCadenaObjeto = cadena;
//    char* comienzoCadena = c;
//
//    while (*comienzoCadena)
//    {
//        *pCadenaObjeto = *comienzoCadena;
//        pCadenaObjeto++;
//        comienzoCadena++;
//    }
}

Cadena::Cadena(Cadena &obj) //ctor
{
    char* pCadenaObjeto = cadena;
    char* comienzoCadena = obj.cadena;

    while (*comienzoCadena)
    {
        *pCadenaObjeto = *comienzoCadena;
        pCadenaObjeto++;
        comienzoCadena++;
    }
}
//Sobrecarga del operador << para la clase Cadena
ostream& operator << (ostream &o,const Cadena &c1)
{
    o << c1.cadena;
    return o;
}

Cadena Cadena::operator +(const char* cad)const
{
    Cadena tmp;
	strcpy(tmp.cadena, cadena);
	strcat(tmp.cadena, cad);
	return tmp;
}




