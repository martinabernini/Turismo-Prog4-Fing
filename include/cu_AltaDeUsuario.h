#ifndef CU_ALTADEUSUARIO
#define CU_ALTADEUSUARIO

#include "fabrica.h"
#include <exception>
#include <iostream>

using namespace std;

void cu_altaDeUsuario(){

    fabrica* fab = fabrica::getInstancia();     // Llamo a la instancia de la fabrica
    IUsuario* iusuario = fab->getIUsuario(); // Llamo a la interfaz de usuarios

    cout << "Ingrese un nombre: ";
    string nombre;
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese un email: ";
    string email;
    getline(cin, email);
    
    cout << "Ingrese una contrasenia: ";
    string password;
    getline(cin, password);

    iusuario->setNombre(nombre);
    iusuario->setEmail(email);
    iusuario->setContrasenia(password);

    iusuario->ingresarDatosUsuario();
    bool existeUsuario = iusuario->existeUsuario();
    
    if (existeUsuario){
        do {
            cout << "Se ha encontrado un usuario en el sistema con el correo electrónico ingresado, ingrese otro correo electronico para el usuario: ";
            string email;
            cin >> email;
            iusuario->actualizarEmailUsuario(email);

            existeUsuario = iusuario->existeUsuario();
        } while (existeUsuario);
    }

    cout << " ¿Desea confirmar y dar de alta al usuario? Ingrese (S) para confirmar el ingreso o cualquier otro caracter para cancelarlo: ";
    string confirmar;
    cin >> confirmar;

    if (confirmar == "S" || confirmar == "s"){
        iusuario->confirmarAltaUsuario();

    } else {
        iusuario->cancelarAltaIngreso();
        cout << "Se ha cancelado el alta del usuario" << endl;
    }


};

#endif