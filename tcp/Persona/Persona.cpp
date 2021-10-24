#include "Persona.h"



ostream& operator << (ostream &o,const Persona &c)
{
    o << c.Nombre;
    return o;
}
