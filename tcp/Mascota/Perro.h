#ifndef PERRO_H_INCLUDED
#define PERRO_H_INCLUDED

#include "Mascota.h"
#include <iostream>

using namespace std;

class Perro : public Mascota
{
public:
    Perro(string);
    void moverCola();
};

#endif // PERRO_H_INCLUDED
