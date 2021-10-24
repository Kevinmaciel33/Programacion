#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
using namespace std;

class Fecha{

private:
    int day;
    int month;
    int year;

public:
    Fecha(int, int, int);

    bool antes(const Fecha &c);
    bool despues(const Fecha &c);
    bool esBisiesto();
    bool pasoUnAnio();
    bool cantidadDias(const Fecha &c);

    //sobrecargar +=
    Fecha& operator += (const int &c);
    friend ostream& operator << (ostream &o, const Fecha &c);
};

#endif // FECHA_H_INCLUDED
