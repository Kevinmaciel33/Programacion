#include "Mascota.h"

Mascota::Mascota(string c) ///ctor
{
    Nombre = c;
}

void Mascota::dormir()
{
    cout << Nombre << " esta durmiendo" <<endl;
}

void Mascota::comer()
{
    cout << Nombre << " esta comiendo"<<endl;
}

ostream& operator << (ostream &o,const Mascota &c)
{
    o << c.Nombre;
    return o;
}
