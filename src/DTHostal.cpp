#include "../include/DTHostal.h"

DTHostal::DTHostal(string nombre, string direccion, string telefono){
    this->nombre=nombre;
    this->direccion=direccion;
    this->telefono=telefono;
}  

string DTHostal::getNombre(){
    return this->nombre;
}

string DTHostal::getDireccion(){
    return this->direccion;
}

string DTHostal::getTelefono(){
    return this->telefono;
}

DTHostal::~DTHostal(){}
