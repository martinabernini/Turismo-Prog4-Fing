#include "../../include/hostal.h"
#include "../../include/estadia.h"

hostal::hostal(string nombre, string direccion, string telefono){
  this->nombre = nombre;
  this->direccion = direccion;
  this->telefono = telefono;
}

map<string, calificacion *> hostal::getColeccionCalificaciones(){
  return this->coleccionCalificaciones;
}

map<int, habitacion *> hostal::getColeccionHabitaciones(){
  return this->coleccionHabitaciones;
}

map<string, estadia *> hostal::getColeccionEstadia(){
  return this->coleccionEstadia;
}

float hostal::getPromedioCalificaciones(){
  map<string, calificacion *> cals = this->coleccionCalificaciones;
  map<string, calificacion *>::iterator it;
  float total = 0;
  float cantCalificaciones = 0;
  for (it = cals.begin(); it != cals.end(); it++)
  {
    total += it->second->getCalificacion();
    cantCalificaciones++;
  }
  if (cantCalificaciones != 0)
    total = total / cantCalificaciones;
  return total;
}

string hostal::getNombre(){
  return this->nombre;
}

string hostal::getDireccion(){
  return this->direccion;
}

string hostal::getTelefono(){
  return this->telefono;
}

habitacion* hostal::getHabitacion(int num){
  return (this->coleccionHabitaciones.find(num))->second;
}


estadia* hostal::getEstadia(string cod){
  return (this->coleccionEstadia.find(cod))->second;
}


void hostal::setNombre(string nombre){
  this->nombre = nombre;
}

void hostal::setDireccion(string direccion){
  this->direccion = direccion;
}
void hostal::setTelefono(string telefono){
  this->telefono = telefono;
}

void hostal::agregarCalificacion(string cod, calificacion* calif){
    this->coleccionCalificaciones.insert({cod, calif});
}

void hostal::agregarHabitacion(int num, habitacion* hab){
    this->coleccionHabitaciones.insert({num, hab});
}

void hostal::agregarEstadia(string cod, estadia* e){
  this->coleccionEstadia.insert({cod, e });
}

void hostal::eliminarEstadia(string cod){
  this->coleccionEstadia.erase(cod);
}
hostal:: ~hostal(){}
