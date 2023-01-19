#ifndef CU_CALIFICARESTADIA
#define CU_CALIFICARESTADIA

#include "fabrica.h"
#include <iostream>

void cu_calificarEstadia(){
    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IReserva* ireserva = fab->getIReserva();
    string email, nomHostal;

    ihostal->obtenerHostales();
    
    cout << "Seleccione un hostal ingresando su nombre:" << endl;
    cin.ignore();
    getline(cin, nomHostal);

    ihostal->seleccionarHostal(nomHostal);

    cout << "Ingrese el correo electronico del huesped que desea calificar una estadia:" << endl;
    getline(cin, email);

    ihostal->listarEstadiasFinalizadas(email);

    cout << "Seleccione una estadia ingresando su codigo de reserva:" << endl;
    int cod;
    cin >> cod;    

    ihostal->seleccionarEstadia(cod, email);

    while (ihostal->getEstadia()->getCalificacion() != NULL){
        int a=0;
        cout << "Error, ya existe una calificacion para esa estadia, ¿desea volver a intentar?" << endl;
        cout << "Ingrese 1 si desea volver a intentar,ingrese 0 en caso contrario: ";
        cin >> a;
        if (a==0)
            return; 
        else {
            cout << "Seleccione una estadia ingresando su codigo de reserva:" ;
            cin >> cod;
        }
    }

    cout << "Ingrese a continuacion la calificacion que le desea dar a esta estadia, esta puede ser un numero entre 1 y 5:" << endl;
    int calificacion;
    cin >> calificacion;

    if (calificacion < 1 || calificacion > 5){
        cout << "Calificacion no valida, debe ingresar un numero entre 1 y 5. Ingrese nuevamente la calificacion:" << endl;
        cin >> calificacion;
    }

    string mensaje; 
    cout << "Ingrese a continuacion el comentario que desea asociar a su calificacion:" << endl;
    cin.ignore();
    getline(cin, mensaje);


    ihostal->ingresarlnfoCalificacion(mensaje, calificacion);

    ihostal->altaCalificacion(); 
};


#endif