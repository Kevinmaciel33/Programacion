#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
using namespace std;

class Persona
{
private:
    string Nombre = new string();
    string Apellido;
    string Domicilio;
    string Localidad;
    string FechaNacimiento;
    string DNI;
    string Sexo;

public:
    Persona(string,string,string,string,string,string,string);

    friend ostream& operator << (ostream &o, const Persona &c);
};

#endif // PERSONA_H_INCLUDED
