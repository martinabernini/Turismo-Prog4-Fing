#ifndef IMPRIMIRINFO
#define IMPRIMIRINFO

#include "fabrica.h"
#include <iostream>

void imprimirInfo(){
    
    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IUsuario* iusuario = fab->getIUsuario();   // llamo a la interfaz de usuario
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IReserva* ireserva = fab->getIReserva();   // llamo a la interfaz de reserva

    cout << "--------------------------------------------------------" <<endl;
    cout << "--------------INFORMACION DE LOS USUARIOS---------------" <<endl;
    cout << "--------------------------------------------------------" <<endl;

    iusuario->imprimirTodaLaInfoDeUsuarios();

    cout << "--------------------------------------------------------" <<endl;
    cout << "--------------INFORMACION DE LOS HOSTALES---------------" <<endl;
    cout << "--------------------------------------------------------" <<endl;

    cout << "-                                                      -" <<endl;
    cout << "------------------- PROXIMAMENTE -----------------------" <<endl;
    cout << "-                                                      -" <<endl;

    cout << "--------------------------------------------------------" <<endl;
    cout << "--------------INFORMACION DE LAS RESERVAS---------------" <<endl;
    cout << "--------------------------------------------------------" <<endl;

    cout << "-                                                      -" <<endl;
    cout << "------------------- PROXIMAMENTE -----------------------" <<endl;
    cout << "-                                                      -" <<endl;
};


#endif