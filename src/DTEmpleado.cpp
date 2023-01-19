#include "../include/DTEmpleado.h"

DTEmpleado::DTEmpleado(string email, string nombre, string password, cargoEmpleado cargo, bool estaSuscrito, hostal *nomHostal){
    this->email=email;
    this->nombre=nombre;
    this->password=password;
    this->cargo=cargo;
    this->estaSuscrito=estaSuscrito;
    this->hostalTrabaja=nomHostal;
}

string DTEmpleado::getEmail(){
    return this->email;
}
string DTEmpleado::getNombre(){
    return this->nombre;
}
cargoEmpleado DTEmpleado::getCargo(){
    return this->cargo;
} 
bool DTEmpleado::getEstaSuscrito(){
    return this->estaSuscrito;
}

hostal* DTEmpleado::getHostalTrabaja(){
    return this->hostalTrabaja;
}

void DTEmpleado::setEstaSuscrito(bool suscripcion){
    this->estaSuscrito=suscripcion;
}
void DTEmpleado::setHostalTrabaja(hostal *hostalTrabaja){
    this->hostalTrabaja=hostalTrabaja;
}

DTEmpleado::~DTEmpleado(){}