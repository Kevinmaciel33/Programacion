#include "Fecha.h"

Fecha::Fecha(int _day, int _month, int _year)
{
    day = _day;
    month = _month;
    year = _year;
}


bool Fecha::antes(const Fecha &c)
{

    if(year < c.year)
        return 1;
    else if(month < c.month && year == c.year)
        return 1;
    else if(day < c.month && month == c.month && year == c.year)
        return 1;

    return 0;
}



Fecha& Fecha::operator += (const int &c)
{
    day += c;
    return *this;
}

ostream& operator << (ostream &o,const Fecha &c)
{
    o << c.day << "/"<< c.month << "/"<< c.year;
    return o;
}
