#include "Mascota.h"
#include "Gato.h"

Gato::Gato(string c) : Mascota(c)
{
    Nombre = c;
}

void Gato::jugarConLaser()
{
    cout << Nombre << " esta jugando con el laser" << endl;
}



