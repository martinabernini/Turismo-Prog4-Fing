#ifndef CU_REALIZARRESERVA
#define CU_REALIZARRESERVA

#include "fabrica.h"
#include <exception>
#include <iostream>

void cu_realizarReserva()
{
    fabrica *fab = fabrica::getInstancia(); // Llamo a la instancia de la fabrica
    IHostal *ihostal = fab->getIHostal();   // Llamo a la interfaz de hostal
    IUsuario *iusuario = fab->getIUsuario();
    IReserva *ireserva = fab->getIReserva();
    map<string, huesped *> coleccionHuespedReserva;

    string nombreH, email;
    int anio, mes, dia, hora, minuto, tipoDeReserva, numero, cantidadH, confirmar;

    ihostal->obtenerHostales();
    cout << "Ingrese el nombre del hostal seleccionado: ";
    cin.ignore();
    getline(cin, nombreH);

    while (!(ihostal->existeHostal(nombreH)))
    {
        int a = 0;
        cout << "Error, no existe un hostal con ese nombre, ¿desea volver a intentar?" << endl;
        cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
        cin >> a;
        if (a == 0)
            return;
        else
        {
            cout << "Ingrese nombre del hostal: ";
            cin.ignore();
            getline(cin, nombreH);
        }
    }

    ihostal->seleccionarHostal(nombreH);
    hostal *h = ihostal->getHostal();

    cout << "Ingrese la fecha de check In: anio, mes, dia, y la hora en formato hh:mm" << endl;
    cout << "Ingrese anio: ";
    cin >> anio;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese hora: ";
    cin >> hora;
    cout << "Ingrese minuto: ";
    cin >> minuto;
    DTFecha *fechaCheckIn = new DTFecha(dia, mes, anio, hora, minuto);

    cout << "Ingrese la fecha de check Out: anio, mes, dia, y la hora en formato hh:mm" << endl;
    cout << "Ingrese anio: ";
    cin >> anio;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese hora: ";
    cin >> hora;
    cout << "Ingrese minuto: ";
    cin >> minuto;
    DTFecha *fechaCheckOut = new DTFecha(dia, mes, anio, hora, minuto);

    cout << "ingrese si la reserva sera grupal o individual (Individual = 0, Grupal = 1): ";
    cin >> tipoDeReserva;

    ireserva->habitacionDisponible(fechaCheckIn, fechaCheckOut, h);

    cout << "Ingrese el numero de la habitacion seleccionada: ";
    cout << "---------------------------" << endl;
    


    cin >> numero;
    habitacion *hab = ihostal->getHabitacion(h, numero);

    iusuario->obtenerHuespedes();
    cout << "Ingrese el email del huesped que realizara la reserva: ";
    cin.ignore();
    getline(cin, email);

    iusuario->seleccionarHuesped(email);
    huesped *hue = iusuario->getHuesped();
    coleccionHuespedReserva.insert({email, hue}); // agrego el primer huesped

    if (tipoDeReserva == 1)
    { // Si la reserva es grupal
        cout << "Ingrese la cantidad de huespedes que se hospedaran con usted: ";
        cin >> cantidadH;
        cin.ignore();

        for (int i = 0; i < cantidadH; i++)
        {
            cout << "Ingrese el nombre del nuevo huesped: ";
            getline(cin, email);

            iusuario->seleccionarHuesped(email);
            huesped *hues = iusuario->getHuesped();

            coleccionHuespedReserva.insert({email, hues});
        };
    }
    cout << "Desea confirmar la reserva? (Si = 1, No = 0): ";
    cin >> confirmar;
    if (confirmar == 1)
    {
        ireserva->confirmarReserva(h, fechaCheckIn, fechaCheckOut, tipoDeReserva, hab, hue, coleccionHuespedReserva);
    }
};

#endif