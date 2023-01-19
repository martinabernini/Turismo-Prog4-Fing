#ifndef CU_ALTADEHOSTAL
#define CU_ALTADEHOSTAL

#include "fabrica.h"
#include <exception>
#include <iostream>


void cu_altaDeHostal(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal

    string nombre, direccion, telefono;
    cout << "Ingrese nombre del hostal a crear: ";
    cin.ignore();
    getline(cin, nombre);


    while(ihostal->existeHostal(nombre)){
        int a=0;
        cout << "Error, ya existe un hostal con ese nombre, ¿desea volver a intentar?" << endl;
        cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
        cin >> a;
        if (a==0)
            return; 
        else {
            cout << "Ingrese nombre del hostal a crear: " ;
            cin.ignore();
            getline(cin, nombre);
        }
    }

    cout << "Ingrese direccion del hostal a crear: ";
    getline(cin, direccion);
    cout << "Ingrese telefono del hostal a crear: ";
    getline(cin, telefono);

    ihostal->confirmarAltaHostal(nombre,direccion,telefono);
};

#endif