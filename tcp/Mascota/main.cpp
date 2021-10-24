#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"

using namespace std;

int main()
{
    //Perro pluto("Pluto");
    //cout << "pluto: " << pluto << endl;
    //pluto.dormir();
    //pluto.comer();
    //pluto.moverCola();

    Gato garfield("Garfield");
    garfield.dormir();
    garfield.comer();
    garfield.jugarConLaser();

    return 0;
}
