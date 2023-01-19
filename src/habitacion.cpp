#include "../include/habitacion.h"

#include <string>
#include <iostream>
using namespace std;

// Operaciones de la clase 'Habitacion'
habitacion::habitacion(){
  this->numero = 0;
  this->capacidad = 0;
  this->precio = 0;
}

habitacion::habitacion(int numero, float precio, int capacidad){
  this->numero = numero;
  this->capacidad = capacidad;
  this->precio = precio;
}

int habitacion::getNumero(){
  return this->numero;
}

float habitacion::getPrecio(){
  return this->precio;
}

int habitacion::getCapacidad(){
  return this->capacidad;
}

hostal* habitacion::getHostal(){
  return this->hostalHabitacion;
}

void habitacion::setNumero(int numero){
  this->numero = numero;
}

void habitacion::setPrecio(float precio){
  this->precio = precio;
}

void habitacion::setCapacidad(int capacidad){
  this->capacidad = capacidad;
}

void habitacion::setHostalHabitacion(hostal *hos){
  this->hostalHabitacion = hos;
}


