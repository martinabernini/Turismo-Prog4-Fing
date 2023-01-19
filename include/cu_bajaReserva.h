#ifndef CU_BAJARESERVA
#define CU_BAJARESERVA

#include "fabrica.h"
#include <iostream>

void cu_bajaReserva(){
    fabrica *fab = fabrica::getInstancia();
    IReserva *ireserva = fab->getIReserva();
    IHostal *ihostal = fab->getIHostal();
    IUsuario *iusuario = fab->getIUsuario();
    string nombreHostal, confirmar;
    int codReserva;
    ihostal->obtenerHostales();

    cout << "Ingrese el nombre del hostal en el cual desea dar de baja una reserva" << endl;
    cin.ignore();
    getline(cin,nombreHostal);
    ihostal->seleccionarHostal(nombreHostal);
    hostal *h = ihostal->getHostal();

    ireserva->obtenerReservasPorHostal(nombreHostal); 

    cout << "Ingrese el id de la reserva que quiere dar de baja" << endl;
    cin >> codReserva;
    cin.ignore();



    reserva *res = ireserva->seleccionarReserva(codReserva);

    cout << "¿Desea confirmar la baja? Ingrese (S) para confirmar la baja o cualquier otro caracter para cancelarlo: ";
            getline(cin,confirmar);
            cout << "" << confirmar << endl;
            if (confirmar == "S" || confirmar == "s"){
                ireserva->eliminarReserva(codReserva,h);
                cout << "Se ha dado de baja la reserva exitosamente\n";
            } else {
                cout << "Se ha cancelado la baja";
            }

}

#endif