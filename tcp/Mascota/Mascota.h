#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include <iostream>
using namespace std;

class Mascota
{
protected:
    string Nombre;

public:
    Mascota(string);
    void dormir();
    void comer();

    friend ostream& operator << (ostream &o, const Mascota &c);

    virtual const char* hablar() = 0; // clase abstracta pura
};


#endif // MASCOTA_H_INCLUDED
