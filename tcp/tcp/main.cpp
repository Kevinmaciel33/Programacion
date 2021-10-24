#include <iostream>

using namespace std;

int main()
{
    cout << "Ingrese un numero: " << endl;
    int numero;
    cin >> numero;
    cout << "Numero: " << numero << endl;

    if(cin.fail())
    {
        cerr << "valor invalido" << endl;
        cerr << "Se utiliza valor por defecto 15" << endl;
        numero = 15;
    }


    return 0;
}
