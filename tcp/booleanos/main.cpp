#include <iostream>
#include "Boolean.h"
using namespace std;

// Desarrollar una clase que simule el comportamiento de tipo de dato bool
//(el cual tiene 2 valores (true y false), sin utilizar el tipo bool de C++
void mostrar ( int valor);

int main()
{

    Boolean falseBoolean,
            trueBoolean(1); //true

    Boolean resultFalseAndTrue = falseBoolean._and(trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean._or(trueBoolean);
    //Boolean resultNotFalse = falseBoolean._not();

    Boolean resultFalseAndTrue = falseBoolean * trueBoolean);
    Boolean resultTrueOrTrue = trueBoolean + trueBoolean);

    cout << "resultFalseAndTrue:" << resultFalseAndTrue.getValue() << endl;
    cout << "resultTrueAndTrue :" << resultTrueOrTrue.getValue() << endl;
    //cout << "resultNotFalse    :"<< resultNotFalse.getValue()<< endl;

    cout << "resultFalseAndTrue:" << resultFalseAndTrue << endl;
    cout << "resultTrueAndTrue :" << resultTrueOrTrue << endl;

         cout << "falseBoolean    :"
         << falseBoolean.getValue()
         << endl;

         cout << "trueBoolean    :"
         << trueBoolean.getValue()
         << endl;


    return 0;
}

void mostrar(int valor)
{
    cout << "Valor: " <<valor << endl;
}
