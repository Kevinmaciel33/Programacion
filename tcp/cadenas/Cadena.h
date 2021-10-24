#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <iostream>
using namespace std;

class Cadena
{
private:

    char cadena[100];
    //char* cadena;

public:

    Cadena();
    Cadena(const char* c);
    Cadena(Cadena &obj);

    GetCadena();

    friend ostream& operator << (ostream &o, const Cadena &cadena);
    Cadena operator+(const char* cad)const;

    //~Cadena(){delete cadena;} // Liberando la memoria en el destructor
};

#endif // CADENA_H_INCLUDED


//las sobrecargas devuelven *this
//ostream
