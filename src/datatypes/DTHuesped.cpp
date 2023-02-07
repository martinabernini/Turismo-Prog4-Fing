#include "../../include/DTHuesped.h"
#include <iostream>

  DTHuesped::DTHuesped(string nombre, string email, bool esFinger){
    this->nombre=nombre;
    this->email=email;
    this->esFinger=esFinger;
  } // constructor
  string DTHuesped::getNombre(){
    return this->nombre;
  }

  string DTHuesped::getEmail(){
    return this->email;
  }

  bool DTHuesped::getEsFinger(){
    return this->esFinger;
  }

  DTHuesped::~DTHuesped(){}

  ostream &operator<<(ostream &os, DTHuesped &huesped){
	os << "Nombre: " << huesped.getNombre() << endl;
	os << "Email: " << huesped.getEmail() << endl;
	os << "Es Finger: " << huesped.getEsFinger() << endl;

	return os; // Retornar el objeto 'os'
						 // Después de implementada esta función al escribir:
						 // cout << *habitacion;
						 // Se ejecutará el código escrito acá.
}

