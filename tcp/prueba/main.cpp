// Titulo..: programa sobrecarga04.cpp
// Objetivo: demostración de sobrecarga de operadores
// Autor...: Oscar E. Palacios
#include <iostream>
using namespace std;

class Pareja {

private:
    double aa, b;

public:
    // constructor parametrizado
    Pareja(const double a,const double b)
    {
        this->aa = a;
        this->b = b;
    }

    friend Pareja& operator +(const Pareja &p1,const Pareja &p2);
    friend ostream& operator << (ostream &o,const Pareja &p);
};

// Sobrecarga del operador + para la clase Pareja
Pareja& operator +(const Pareja &p1,const Pareja &p2)
{
  return *(new Pareja(p1.aa + p2.aa, p1.b + p2.b) );
}

// Sobrecarga del operador << para la clase Pareja
ostream& operator << (ostream &o,const Pareja &p)
{
    o << "(" << p.aa << ", " << p.b << ")";
    return o;
}

int main()
{
    Pareja A(50, 75 );
    Pareja B(150, 175 );
    Pareja C = A + B;

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << "\n";

    return 0;
}
