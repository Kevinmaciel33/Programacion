#ifndef HORADELDIA_H_INCLUDED
#define HORADELDIA_H_INCLUDED

#include <iostream>
using namespace std;

class HoraDelDia
{

private :
    int hora;
    int minutos;
    int segundos;

public:
    HoraDelDia(int = 0, int = 0, int = 0);
    static HoraDelDia getHoraMaxima();

    friend istream& operator >> (istream &o, HoraDelDia &p);
    friend ostream& operator << (ostream &o, const HoraDelDia &p);

    int operator >= ( HoraDelDia &b);
    int operator < ( HoraDelDia &b);


    friend HoraDelDia operator +(const HoraDelDia &p1,const HoraDelDia &p2);
    friend HoraDelDia operator +(const int &p1,const HoraDelDia &p2);

    HoraDelDia& operator+=(const int& rhs);


    HoraDelDia operator++(int unused);





};

#endif // HORADELDIA_H_INCLUDED
