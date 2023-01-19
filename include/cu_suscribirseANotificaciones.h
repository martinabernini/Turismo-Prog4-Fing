#ifndef CU_SUSCRIBIRSEANOTIFICACIONES
#define CU_SUSCRIBIRSEANOTIFICACIONES

#include "fabrica.h"
#include <iostream>

/* 
El caso de uso comienza cuando un empleado desea suscribirse para recibir
notificaciones. Para ello el sistema lista todos los empleados y el usuario le indica al
sistema el empleado que desea suscribir a las notificaciones de todos los hostales.
*/

void cu_suscribirseANotificaciones(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IUsuario* iusuario= fab->getIUsuario(); // llamo a la interfaz de usuario

    string email;

    cout << "A continuacion, se listan todos los empleados registrados." << endl;
    iusuario->obtenerEmpleados();
    cout << "Por favor, ingrese el email del empelado seleccionado: ";

    
    cin.ignore();
    getline(cin,email);
    int a=0;

        iusuario->seleccionarEmpleado(email);
        empleado *e = iusuario->getEmpleado();

        a = 0;
        while (e->getEstaSuscrito())
        {
            cout << "Error, el empleado seleccionado ya esta suscripto." << endl;
            cout << "Ingrese 1 si desea volver a intentar, ingrese 0 en caso contrario" << endl;
            cin >> a;
            if (a == 0)
                return;
            else
            {
                cout << "Ingrese el email del empleado: ";
                cin >> email;
                iusuario->seleccionarEmpleado(email);
                e = iusuario->getEmpleado();
            }
        }
        e->setEstaSuscrito(true);
        ihostal->agregarObservador(e);
        cout << "El empleado se ha suscripto exitosamente" << endl;
    };

#endif