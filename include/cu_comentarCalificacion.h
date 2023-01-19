#ifndef CU_COMENTARCALIFICACION
#define CU_COMENTARCALIFICACION

#include "fabrica.h"
#include <iostream>

/* El caso de uso comienza cuando un empleado desea comentar una calificación realizada por un huésped. Para ello, el usuario indica el email de
un empleado y el sistema lista todos los comentarios sin responder para
el hostal para el cual trabaja el empleado. El usuario elige de la lista qué
comentario desea responder e ingresa el comentario, ante lo cual el sistema registra el comentario.
*/
void cu_comentarCalificacion(){

    fabrica* fab = fabrica::getInstancia(); //llamo a la instancia de la fabrica
    IHostal* ihostal = fab->getIHostal();   // llamo a la interfaz de hostal
    IUsuario* iusuario = fab->getIUsuario();   // llamo a la interfaz de usuario

    string texto;
    cout << "Por favor, ingrese su email." << endl;
    cin.ignore();
    getline(cin,texto);

    empleado* emp= iusuario->findEmpleado(texto);
    hostal* hos= emp->getHostalTrabaja();

    ihostal->imprimirCalificacionesSR(hos);

    int id;
    cout << "Por favor, ingrese el codigo de reserva de la calificacion que desea comentar:" << endl;
    cin >> id;
    cin.ignore();

    string emailH;
    cout << "Por favor, ingrese el correo electronico del huesped que realizo el comentario:" << endl;
    //cin.ignore();
    getline(cin,emailH);
/*
    while(!ihostal->existeCalificacion(id, emailH, hos)){
        throw("No existe una calificacion con ese identificadir, vuelva a ingresar.");
        cout << endl;
        cout << "Por favor, ingrese el id de la calificacion que desea comentar:" << endl;
        cin >> id;

        cout << "Por favor, ingrese el correo electronico del huesped que realizo el comentario:" << endl;
        cin.ignore();
        getline(cin,emailH);
        cout << "hola 1" << endl;
    }*/
    ihostal->seleccionarEstadia(id,emailH);
    estadia* est = ihostal->getEstadia();
    string rta;
    cout << "Ingrese su respuesta a la calificacion." << endl;
    cin.ignore();
    getline(cin,rta);  

    map<string, calificacion *>::iterator it = hos->getColeccionCalificaciones().find(to_string(id) + emailH);

    //calificacion* cal= ihostal->obtenerCalificacion( id,  emailH, hos);
    //calificacion* cal= est->getCalificacion();
    ihostal->comentarCalificacion(rta,it->second);
    it->second->setRespuesta(rta);
    reloj *r = reloj::getInstancia();
    it->second->setFechaRespuesta(r->getReloj());
};


#endif