#ifndef CU_ELIMINARSUSCRIPCION
#define CU_ELIMINARSUSCRIPCION

#include "fabrica.h"
#include <iostream>

/*
El caso de uso comienza cuando un empleado desea eliminar una suscripción. Para
ello el sistema lista todos los empleados y el usuario le indica al sistema el empleado
que desea eliminar su suscripción.

*/

void cu_eliminarSuscripcion(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IUsuario* iusuario= fab->getIUsuario(); // llamo a la interfaz de usuario
    
    cout << "A continuacion, se listan todos los empleados registrados." << endl;
    iusuario->obtenerEmpleados();
    cout << "Por favor, ingrese el email del empelado seleccionado: ";

    string email;
    cin.ignore();
    getline(cin,email);
    iusuario->seleccionarEmpleado(email);
    empleado* e= iusuario->getEmpleado();

    int a=0;
    while (!(e->getEstaSuscrito())){
        cout << "Error, el empleado seleccionado no cuenta con una suscripcion." << endl;
        cout << "Ingrese 1 si desea volver a intentar, ingrese 0 en caso contrario" << endl;
        cin >> a;
        if (a==0)
            return; 
        else {
            cout << "Ingrese el email del empleado: " ;
            cin >> email;
            iusuario->seleccionarEmpleado(email);
            e= iusuario->getEmpleado();
        }
    }
    
    e->setEstaSuscrito(false);
    e->eliminarNotificaciones();
    ihostal->eliminarObservador(e);
       
};

#endif