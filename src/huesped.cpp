#include "../include/huesped.h"
#include "../include/usuario.h"
#include <string>
#include <iostream>
using namespace std;

huesped::huesped(){}

huesped::huesped(string email, string nombre, string password, bool esFinger):usuario(email, nombre, password){
	this->esFinger=esFinger;
}

bool huesped::getEsFinger(){
    return this->esFinger;
}

void huesped::setEsFinger(bool esFinger){
    this->esFinger = esFinger;
}
huesped::~huesped(){}
