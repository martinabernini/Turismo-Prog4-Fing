//#include "../include/reserva.h"
#include "../../include/reserva.h"
#include "../../include/reservaGrupal.h"


#include <string>
#include <iostream>
using namespace std;

reservaGrupal::reservaGrupal(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, map<string,huesped*> huespedes, habitacion *habitacion):reserva(codigo,checkIn,checkOut,estado,habitacion){
    this->coleccionHuespedGrupal=huespedes;
}

float reservaGrupal::calcularCosto(){
    //falta el código
    return 0;
}

string reservaGrupal::tipoReserva() { return "Grupal"; };

map<string, huesped*> reservaGrupal::getHuespedes(){
    return this->coleccionHuespedGrupal;
}


void reservaGrupal::borrarReserva(){
	map<string, huesped*>::iterator inicio= this->getHuespedes().begin();
	map<string, huesped*>::iterator fin= this->getHuespedes().end();
	this->getHuespedes().erase(inicio,fin);
}


reservaGrupal::~reservaGrupal(){

}
