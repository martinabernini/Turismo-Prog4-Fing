#include "../include/empleado.h"
#include "../include/usuario.h"
#include "../include/hostal.h"

empleado::empleado(){}

empleado::empleado(string email, string nombre, string password, cargoEmpleado cargo,hostal* hostalTrabaja):usuario(email,nombre,password){
    this->cargo= cargo;
    this->estaSuscrito= false;
    this->hostalTrabaja=NULL;
}

cargoEmpleado empleado::getCargo(){
    return this->cargo;
}

hostal* empleado::getHostalTrabaja(){
    return this->hostalTrabaja;
}

bool empleado::getEstaSuscrito(){
    return this->estaSuscrito;
}

void empleado::setCargo(cargoEmpleado cargo){
    this->cargo=cargo;
}     

void empleado::setEstaSuscrito(bool estaSuscrito){
    this->estaSuscrito=estaSuscrito;
}

void empleado::setHostalTrabaja(hostal* hos){
    this->hostalTrabaja=hos;
}

void empleado::getNombresito(){
    cout << this->usuario::getNombre();
}

void empleado::notify(calificacion* cal){  //si el empleado esta suscripto, le añade la calificacion a las notificaciones
    cout << "entre al notify";
    if (this->estaSuscrito)
        this->notificaciones.insert(cal);
}

set<calificacion*> empleado::getNotificaciones(){
    return this->notificaciones;
}

void empleado::eliminarNotificaciones(){
    set<calificacion*>::iterator inicio= this->notificaciones.begin();
    set<calificacion*>::iterator fin= this->notificaciones.end();
    this->notificaciones.erase(inicio,fin);
}

empleado::~empleado(){}