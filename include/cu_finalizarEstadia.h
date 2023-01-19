#ifndef CU_FINALIZARESTADIA
#define CU_FINALIZARESTADIA

#include "fabrica.h"
#include <iostream>


/* 
El caso de uso comienza cuando un usuario desea finalizar la estadía de
un huésped en una habitación. 
Para ello, el sistema lista todos los hostales registrados y el usuario selecciona uno de ellos. 
A continuación, elusuario indica el email del huésped y, en caso de existir una estadía activa para el huésped (que no haya finalizado), 
el empleado indica la finalización de la estadía. Finalmente, el sistema registra en la estadía la fecha
y hora de check-out correspondiente a la del sistema.
*/

void cu_finalizarEstadia(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal

    string hostal, email;
    cout << "A continuacion, se listan los hostales registrados" << endl;
    ihostal->obtenerHostales();
    cout << "Por favor, ingrese el nombre del hostal seleccionado: ";
    cin.ignore();
    getline(cin,hostal);
    ihostal->seleccionarHostal(hostal);
    cout << "Ingrese el email del huesped: ";
    getline(cin,email);
    bool seguir=true;

    while(!(ihostal->existeEstadia(email) && ihostal->estadiaValida(email)) && (seguir)){
        int a=0;
        
        if (ihostal->existeEstadia(email)){
            cout << "Error, no existe una estadia valida asociada a ese email, ¿desea volver a intentar?" << endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
        } else {
            cout << "Error, la estadia asociada a ese email ya ha finalizado, ¿desea volver a intentar?" << endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
        }
        if (a==0)
            seguir=false; 
        else {
            cout << "Ingrese el email del huesped: " ;
            cin >> email;
        }
    }
    if (seguir){
        ihostal->finalizarEstadia(email); 
    }
};

#endif