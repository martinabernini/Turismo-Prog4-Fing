#ifndef CU_CONSULTADERESERVA
#define CU_CONSULTADERESERVA

#include "fabrica.h"
#include <iostream>

void cu_consultaDeReserva(){
    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IReserva* ireserva = fab->getIReserva();

    ihostal->obtenerHostales();

    string nomHostal;
    cout << "Seleccione un hostal ingresando su nombre: ";
    cin.ignore();
    getline(cin, nomHostal);

    while(!(ihostal->existeHostal(nomHostal))){
        int a=0;
        cout << "Error, no existe un hostal con ese nombre, ¿desea volver a intentar?" << endl;
        cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
        cin >> a;
        if (a==0)
            return; 
        else {
            cout << "Ingrese nombre del hostal: " ;
            cin.ignore();
            getline(cin,nomHostal);
        }
    } 

    ihostal->seleccionarHostal(nomHostal);
    ireserva->obtenerReservasPorHostal(nomHostal);
    
};


#endif