#include "../include/estadia.h"

DTFecha* estadia::getCheckIn(){
    return this->fechaCheckIn;
}
DTFecha* estadia::getCheckOut(){
    return this->fechaCheckOut;
}

string estadia::getPromoCode(){
    return this->promoCode;
}

reserva* estadia::getReserva(){
    return this->reservaEstadia;
}

huesped* estadia::getHuesped(){
    return this->huespedEstadia;
}

calificacion* estadia::getCalificacion(){
    return this->calificacionEstadia;
}

void estadia::setFechaCheckIn(DTFecha* checkIN){
    this->fechaCheckIn=checkIN;
}

void estadia::setFechaCheckOut(DTFecha* checkOUT){
    this->fechaCheckOut=checkOUT;
}

void estadia::setPromoCode(string codigo){
    this->promoCode=codigo;
}


void estadia::setCalificacion(calificacion* cal){
    this->calificacionEstadia=cal;
}

bool estadia::estaFinalizada(){
    return (this->fechaCheckOut->getAnio() == 0); //Si el año es 0, retorna false, en otro caso, retorna true;
}

void estadia::borrarEstadia(){   
    this->reservaEstadia = NULL;
    this->huespedEstadia = NULL;
    this->calificacionEstadia = NULL;
    delete this->fechaCheckIn;
    delete this->fechaCheckOut;

}

estadia::estadia(){}
estadia::estadia(DTFecha* checkIn, DTFecha* checkOut, reserva* reservaEstadia, huesped* huespedEstadia, calificacion* califEstadia){
    this->fechaCheckIn =checkIn;
    this->fechaCheckOut=checkOut;
    this->reservaEstadia = reservaEstadia;
    this->huespedEstadia = huespedEstadia;
    this->calificacionEstadia = califEstadia;
}


estadia:: ~estadia(){
    delete this->fechaCheckIn;
    delete this->fechaCheckOut;
}
