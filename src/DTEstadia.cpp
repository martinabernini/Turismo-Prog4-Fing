#include "../include/DTEstadia.h"

DTEstadia::DTEstadia(DTFecha* fechaCheckIn, DTFecha* fechaCheckOut, int codigoReserva, string emailHuesped){
    this->fechaCheckIn = fechaCheckIn;
    this->fechaCheckOut = fechaCheckOut;
    this->codigoReserva = codigoReserva;
    this->emailHuesped = emailHuesped;
}

DTFecha* DTEstadia::getFechaCheckIn(){
    return this->fechaCheckIn;
}

DTFecha* DTEstadia::getFechaCheckOut(){
    return this->fechaCheckOut;
}

int DTEstadia::getCodigoReserva(){
    return this->codigoReserva;
}
string DTEstadia::getEmailHuesped(){
    return this->emailHuesped;
}

DTEstadia::~DTEstadia(){
    delete this->fechaCheckIn;
    delete this->fechaCheckOut;
}