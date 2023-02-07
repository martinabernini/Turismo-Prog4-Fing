#include "../../include/DTHabitacion.h"

#include <string>
#include <iostream>
using namespace std;


// Operaciones del dataType 'DTHabitacion'

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad){
  this->numero = numero;
  this->precio = precio;
  this->capacidad = capacidad;
}

int DTHabitacion::getNumero(){
  return this->numero;
};

float DTHabitacion::getPrecio(){
  return this->precio;
};

int DTHabitacion::getCapacidad(){
  return this->capacidad;
};

void DTHabitacion::setNumero(int numero){
  this->numero = numero;
};

void DTHabitacion::setPrecio(float precio){
  this->precio = precio;
};

void DTHabitacion::setCapacidad(int capacidad){
  this->capacidad = capacidad;
};

ostream &operator<<(ostream &os, DTHabitacion &habitacion){
  os << "Numero: " << habitacion.getNumero() << endl;
  os << "Precio: " << habitacion.getPrecio() << endl;
  os << "Capacidad: " << habitacion.getCapacidad() << endl;

  return os; // Retornar el objeto 'os'
  // Después de implementada esta función al escribir:
  // cout << *habitacion;
  // Se ejecutará el código escrito acá.
}