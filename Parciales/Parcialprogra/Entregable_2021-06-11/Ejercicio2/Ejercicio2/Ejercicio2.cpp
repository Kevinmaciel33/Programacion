#include "Ejercicio2.h"

Complejo::Complejo()
{
    real = 0;
    imaginario = 0;
}

Complejo::Complejo(int r, int i)
{
    real = r;
    imaginario = i;
}

Complejo& operator +(const Complejo &a, const Complejo &b)
{
    return *(new Complejo(a.real + b.real, a.imaginario + b.imaginario) );
}

ostream& operator << (ostream &o,const Complejo &a)
{
    o << "(" << a.real << ", " << a.imaginario << ")";
    return o;
}

Complejo& operator * (const int &i, const Complejo &a)
{
    return *(new Complejo(i * a.real, i * a.imaginario) );
}

Complejo& operator *(const Complejo &a, const Complejo &b)
{
    return *(new Complejo(a.real * b.real - a.imaginario * b.imaginario, a.real * b.imaginario + a.imaginario * b.real) );
}
