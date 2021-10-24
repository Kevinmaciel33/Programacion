#include "HoraDelDia.h"

HoraDelDia::HoraDelDia(int _hora,int _minutos,int _segundos)
{
    hora = _hora;
    minutos = _minutos;
    segundos = _segundos;


}

istream& operator >> (istream &i, HoraDelDia &p)
{
    char c;
    i >> p.hora >> c >> p.minutos >> c >> p.segundos;
    i.ignore();
    return i;
}

HoraDelDia HoraDelDia::getHoraMaxima()
{
    return *(new HoraDelDia(23, 59, 59));
}

ostream& operator << (ostream &o, const HoraDelDia &p)
{
    o << p.hora << ":" << p.minutos << ":" << p.segundos << endl;
    return o;
}

int HoraDelDia::operator >= ( HoraDelDia &b)
{
    int h1 = this->segundos + (this->segundos * 60) + (this->segundos * 3600),
        h2 = b.segundos + (b.minutos * 60) + (b.hora * 3600);
    return (h1 >= h2);
}

int HoraDelDia::operator < ( HoraDelDia &b)
{
    int h1 = this->segundos + (this->segundos * 60) + (this->segundos * 3600),
        h2 = b.segundos + (b.minutos * 60) + (b.hora * 3600);
    return (h1 < h2);
}

//HoraDelDia HoraDelDia::operator ++(int unused) // postfix
//{
//    HoraDelDia result = *this;
//    ++segundos;
//    return result;
//}

HoraDelDia HoraDelDia::operator++(int unused) {
    HoraDelDia copia = *this;
    this->segundos++;
    if (this->segundos > 59) {
        this->segundos = 0;
        this->minutos++;
        if (this->minutos > 59) {
            this->minutos = 0;
            this->hora++;
            if (this->hora > 23) {
                this->hora = 0;
            }
        }
    }
    return copia;
}


HoraDelDia operator +(const HoraDelDia &p1,const HoraDelDia &p2)
{
//    HoraDelDia h1;
//
//    h1.segundos = p1.segundos + p2.segundos;
//    h1.minutos = p1.minutos + p2.minutos;
//    h1.hora = p1.hora + p2.hora;

    HoraDelDia h1( p1.hora + p2.hora, p1.minutos + p2.minutos, p1.segundos + p2.segundos);

    if(h1.segundos >59)
    {
        h1.segundos = 0;
        h1.minutos++;
        if(h1.minutos > 59)
        {
            h1.minutos = 0;
            h1.hora++;
            if(h1.hora > 23)
                h1.hora = 0;
        }
    }


//return *(new HoraDelDia(p1.hora + p2.hora, p1.minutos + p2.minutos, p1.segundos + p2.segundos) );
    return h1;
}

HoraDelDia operator +(const int &p1,const HoraDelDia &p2)
{
    HoraDelDia h1( p2.hora, p2.minutos, p1 + p2.segundos);


    if(h1.segundos >59)
    {
        h1.segundos = 0;
        h1.minutos++;
        if(h1.minutos > 59)
        {
            h1.minutos = 0;
            h1.hora++;
            if(h1.hora > 23)
                h1.hora = 0;
        }
    }
    return h1;

}



HoraDelDia& HoraDelDia::operator+=(const int& rhs)
{

    this->segundos += rhs;
    if(this->segundos > 59)
    {
        this->segundos = 0;
        this->minutos++;
        if(this->minutos > 59)
        {
            this->minutos = 0;
            this->hora++;
            if(this->hora > 23)
                this->hora = 0;
        }
    }
    return *this;
}






