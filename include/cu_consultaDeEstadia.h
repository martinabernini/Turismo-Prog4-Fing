#ifndef CU_CONSULTADEESTADIA
#define CU_CONSULTADEESTADIA

#include "fabrica.h"
#include <iostream>

void cu_consultaDeEstadia(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IReserva* ireserva = fab->getIReserva();   // llamo a la interfaz de reserva
    IHostal* ihostal = fab->getIHostal(); 
    string nomHostal,emailestadia;
    ihostal->obtenerHostales();
    cout << "Escriba el nombre del hostal que desea consultar" << endl;
    cin.ignore();
    getline(cin, nomHostal);
    if (ihostal->existeHostal(nomHostal))
        ihostal->imprimirEstadias(nomHostal);
    else return;
    cout << "Seleccione una de las estadias, ingresando el mail asociado a ella (Enter) y luego su codigo:" << endl;
    getline(cin,emailestadia);
    int cod;
    cin >> cod;
    ihostal->imprimirlnfoEstadia(nomHostal,emailestadia, cod);
};


#endif