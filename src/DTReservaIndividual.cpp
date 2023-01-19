#include "../include/DTReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, estadoReserva estado, float costo, int habitacion, bool pagado){
    this->codigo=codigo;
    this->checkIn=checkIn;
    this->checkOut=checkOut;
    this->estado=estado;
    this->costo=costo;
    this->habitacion=habitacion;
    this->pagado=pagado;
}

bool DTReservaIndividual::getEstadoPago(){
    return this->pagado;
}

void DTReservaIndividual::setEstaPago(bool pagado){
    this->pagado=pagado;
}