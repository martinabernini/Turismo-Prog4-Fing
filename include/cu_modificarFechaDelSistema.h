#ifndef CU_MODIFICARFECHADELSISTEMA
#define CU_MODIFICARFECHADELSISTEMA

#include "fabrica.h"
#include "reloj.h"
#include <iostream>

void cu_modificarFechaDelSistema(){
    reloj* fechaSistema = reloj::getInstancia();

    int anio;
    bool existe = false;
    int a=0;
    while (!existe){
        cout << "Ingrese el anio: ";
        cin >> anio;
        if (anio >= 1900){
            existe = true;
        }else{
            cout << "Error, el anio no es acorde, desea reintentar?"<< endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
            existe=!(a==1);
            if (existe)
                return;
        }
    };
    int mes;
    existe = false;
    while (!existe){
        cout << "Ingrese el mes: ";
        cin >> mes;
        if (mes > 0 && mes < 13){
            existe = true;
        }else{
            cout << "Error, el mes no es acorde, desea reintentar?"<< endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
            existe=!(a==1);
            if (existe)
                return;
        }
    };

    int dia;
    existe = false;
    while (!existe){
        cout << "Ingrese el dia: ";
        cin >> dia;
        if (dia > 0 && dia < 32){
            existe = true;
        } else {
            cout << "Error, el dia no es acorde, desea reintentar?"<< endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
            existe=!(a==1);
            if (existe)
                return;
        }
    };

    int hora;
    existe = false;
    while (!existe){
        cout << "Ingrese la hora: ";
        cin >> hora;
        if (hora >= 0 && hora < 24){
            existe = true;
        } else {
            cout << "Error, la hora no es acorde, desea reintentar?"<< endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
            existe=!(a==1);
            if (existe)
                return;
        }
    };

    int minuto;
    existe = false;
    while (!existe){
        cout << "Ingrese el minuto: ";
        cin >> minuto;
        if (minuto >= 0 && minuto < 60){
            existe = true;
        } else {
            cout << "Error, el minuto no es acorde, desea reintentar?"<< endl;
            cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
            cin >> a;
            existe=!(a==1);
            if (existe)
                return;
        }
    };

    fechaSistema->setReloj(dia, mes, anio, hora, minuto);
    cout << "Fecha y Hora ingresada: " << dia << "/" << mes << "/" << anio << " " << hora << ":" << minuto << endl;
};


#endif