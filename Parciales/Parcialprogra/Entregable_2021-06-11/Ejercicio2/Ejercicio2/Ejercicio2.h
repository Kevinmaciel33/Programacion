#ifndef EJERCICIO2_H_INCLUDED
#define EJERCICIO2_H_INCLUDED

#include <iostream>
using namespace std;

class Complejo
{
private:
    int real;
    int imaginario;

public:
    Complejo();
    Complejo(int real, int imaginario);

    friend Complejo& operator +(const Complejo &a, const Complejo &b);
    friend ostream& operator << (ostream &o,const Complejo &a);
    friend Complejo& operator * (const int &i, const Complejo &a);
    friend Complejo& operator *(const Complejo &a, const Complejo &b);

};

#endif // EJERCICIO2_H_INCLUDED
