#ifndef CU_REGISTRARESTADIA
#define CU_REGISTRARESTADIA

#include "fabrica.h"
#include "DTFecha.h"
#include <iostream>

/*
El caso de uso comienza cuando un usuario desea registrar la estadía de un huésped en una habitación. LISTO
Para ello, el sistema lista todos los hostales registrados y el usuario selecciona uno.               LISTO
A continuación, el usuario ingresa el email del huésped                                                LISTO
y el sistema retorna la lista de las reservas no canceladas en las cuales el huésped está registrado como parte de la reserva.
Luego, el usuario selecciona una de las reservas
y el sistema registra la estadía con fecha y hora de check-in correspondiente a la del sistema y marca la reserva como cerrada.
*/

void cu_registrarEstadia()
{
    fabrica *fab = fabrica::getInstancia(); // llamo a la instancia de la fabrica
    IReserva *ireserva = fab->getIReserva();
    IHostal *ihostal = fab->getIHostal();
    IUsuario *iusuario = fab->getIUsuario();
    string nombreHostal, emailHuesped;
    int codReserva;

    ihostal->obtenerHostales();

    cout << "Ingrese el nombre del hostal al cual desea registrarle una estadia" << endl;
    cin.ignore();
    getline(cin, nombreHostal);
    cout << "Nombre del hostal: " << nombreHostal << endl;
    ihostal->seleccionarHostal(nombreHostal);
    hostal *h = ihostal->getHostal();

    cout << "Ingrese el email del huesped que quiere registrar una estadia" << endl;
    getline(cin, emailHuesped);
    cout << "email del huesped: " << emailHuesped << endl;
    iusuario->seleccionarHuesped(emailHuesped);
    huesped *hue = iusuario->getHuesped();

    ireserva->imprimirReservasHuesped(hue);

    cout << "Ingrese el id de la reserva sobre la cual registrara la estadia" << endl;
    cin >> codReserva;

    reloj *r = reloj::getInstancia();
    estadia *est = new estadia(r->getReloj(), NULL, ireserva->seleccionarReserva(codReserva), hue, NULL);
    string key = to_string(codReserva) + emailHuesped;
    ihostal->agregarEstadia(key, est);
    h->agregarEstadia(to_string(codReserva) + emailHuesped, est);
};

#endif