#include "../include/DTReserva.h"

DTReserva::DTReserva(){}
DTReserva::DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado/* float costo, int habitacion*/){
    this->codigo=codigo;
    this->checkIn=checkIn;
    this->checkOut=checkOut;
   // this->costo=costo;
    this->estado=estado;
  //  this->habitacion=habitacion;
}

int DTReserva::getCodigo(){
    return this->codigo;
}

DTFecha* DTReserva::getCheckIn(){
    return this->checkIn;
}

DTFecha* DTReserva::getCheckOut(){
    return this->checkOut;
}

estadoReserva DTReserva::getEstado(){
    return this->estado;
}
/*
float DTReserva::getCosto(){
    return this->costo;
}*/

habitacion* DTReserva::getHabitacion(){
    return this->habitacionReserva;
}

huesped* DTReserva::getHuespedDTReserva(){
    return this->huespedReserva;
}

DTReserva::DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, huesped *huespedReserva, habitacion *habitacionReserva){
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->huespedReserva = huespedReserva;
    this->habitacionReserva = habitacionReserva;
}
DTReserva::~DTReserva(){}
