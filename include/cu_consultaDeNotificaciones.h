#ifndef CU_CONSULTADENOTIFICACIONES
#define CU_CONSULTADENOTIFICACIONES

#include "fabrica.h"
#include <iostream>

/*
El caso de uso comienza cuando un empleado desea consultar las notificaciones recibidas. 
Para ello el sistema lista todos los empleados y el usuario selecciona uno deellos. 
A continuación, el sistema lista todas las notificaciones recibidas por elempleado, las que deben contener el nombre del autor, el puntaje y el comentario.
Finalmente, el sistema elimina las notificaciones que haya recibido el empleado.
*/

void cu_consultaDeNotificaciones(){

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
    bool seguir=true;
    while ((!e->getEstaSuscrito()) && seguir){
        cout << "Error, el empleado seleccionado no cuenta con una suscripcion." << endl;
        cout << "Ingrese 1 si desea volver a intentar, ingrese 0 en caso contrario" << endl;
        cin >> a;
        if (a==0)
            seguir=false; 
        else {
            cout << "Ingrese el email del empleado: " ;
            cin >> email;
            iusuario->seleccionarEmpleado(email);
            e= iusuario->getEmpleado();
        }
    }
    if (seguir){
        iusuario->imprimirNotificaciones();
        e->eliminarNotificaciones();
    }   
};


#endif