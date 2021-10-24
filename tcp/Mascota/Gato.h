#ifndef GATO_H_INCLUDED
#define GATO_H_INCLUDED

#include "Mascota.h"
#include <iostream>

using namespace std;

class Gato : public Mascota
{
public:
    Gato(string);
    void jugarConLaser();
};

#endif // GATO_H_INCLUDED
