#include "Perro.h"
#include "Mascota.h"

Perro::Perro(string c) : Mascota(c){}

void Perro::moverCola()
{
    cout << Nombre << " mueve la cola" << endl;
}

