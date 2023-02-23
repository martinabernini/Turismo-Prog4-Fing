#ifndef CU_CONSULTADEUSUARIO
#define CU_CONSULTADEUSUARIO

#include "fabrica.h"
#include <iostream>

void cu_consultaDeUsuario(){
    
    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IUsuario* iusuario = fab->getIUsuario();   // llamo a la interfaz de usuario
    string rol,email;
    iusuario->imprimirUsuarios();
    
    cout << "Ingrese si el usuario es huesped(H) o empleado(E) y luego (enter) el email del usuario sobre el cual desea consultar" <<endl;
    cin.ignore();
    getline(cin, rol);
    if ((rol != "E")   && (rol!="H")){
        return;
    }
    getline(cin, email);
    iusuario->obtenerInfoUsuario(rol,email);
    
};


#endif