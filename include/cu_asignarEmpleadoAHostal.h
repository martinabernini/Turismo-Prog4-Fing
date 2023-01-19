#ifndef CU_ASIGNAREMPLEADOAHOSTAL
#define CU_ASIGNAREMPLEADOAHOSTAL

#include "fabrica.h"
#include <iostream>

/*
El caso de uso comienza cuando un usuario desea asignar empleados a una hostal.
Para ello, el sistema lista todos los hostales registrados
 y el usuario selecciona uno.
  A continuación, el sistema lista los empleados registrados en el sistema que todavía no
han sido asignados a dicho hostal
 y el usuario selecciona uno, junto con el cargo que desempeñará en dicho hostal (administración, limpieza, recepción, infraestructura).
Luego, el usuario puede confirmar la asignación o bien cancelarla.
 Finalmente, el usuario puede seguir agregando empleados al hostal seleccionado, o finalizar.
*/
void cu_asignarEmpleadoAHostal(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IUsuario* iusuario = fab->getIUsuario(); //llamo a la interfaz de usuario
    string nombreHostal, emailEmpleado, confirmar;
    bool seguir = true;

    ihostal->obtenerHostales();

    cout << "Ingrese el nombre del hostal al cual desee asignar un empleado: ";
    cin.ignore();
    getline(cin,nombreHostal);

    ihostal->seleccionarHostal(nombreHostal);
    hostal *h = ihostal->getHostal();
    
    while (seguir == true){    
        iusuario->imprimirEmpleadosNoRegistrados(h);

        cout << "Ingrese el email del empleado al que quiere asignar: "; //controlar q este en la lista?
        getline(cin,emailEmpleado);
        empleado *emp  = iusuario->findEmpleado(emailEmpleado);

        cout << "¿Desea confirmar y realizar la asignacion? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo\n";
        cin >> confirmar;
            if (confirmar == "S" || confirmar == "s"){
                emp->setHostalTrabaja(h);
                cout << "Se ha asignado al empleado exitosamente\n";
            } else {
                cout << "Se ha cancelado la asignacion\n";
            }
        cout << "-------------\n";
        cout << "¿Desea realizar otra asignacion? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo\n";
        cin >> confirmar;
            if (confirmar != "S" || confirmar != "s"){
                seguir = false;
            }
    }


};


#endif