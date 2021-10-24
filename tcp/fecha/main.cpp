#include "Fecha.h"

int main()
{
    Fecha valida(19, 06, 2021);
    Fecha otraFechaValida(15, 10, 2015);

//    try
//    {
//        Fecha invalida(31, 02, 2021);
//    }
//    catch (exception &error)
//    {
//        cout << "Fecha inválida" << endl;
//    }
//
    cout << (valida.antes(otraFechaValida)? "Antes" : "Despues") << endl;
//    cout << (valida.despues(otraFechaValida)? "Despues" : "Antes") << endl;
//    cout << valida << (valida.esBisiesto()? " pertenece a un año bisiesto" : " no pertenece a un año bisiesto") << endl;
//    cout << valida << (valida.pasoUnAnio()? " hace menos de un año." : " hace más de un año.") << endl;
//    cout << "Pasaron " << valida.cantidadDias(otraFechaValida) << "dias entre las fechas." << endl;
//
//    cout << "Le agrego 5 dias a una fecha.";
    valida += 5;
    cout << valida;

    return 0;
}
