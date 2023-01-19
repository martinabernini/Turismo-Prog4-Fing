#include "../include/DTReservaGrupal.h"
#include "../include/DTReserva.h"

DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, estadoReserva estado, float costo, int habitacion, DTHuesped **huespedes){
    this->codigo=codigo;
    this->checkIn=checkIn;
    this->checkOut=checkOut;
    this->estado=estado;
    this->costo=costo;
    this->habitacion=habitacion;
    this->huespedes=huespedes;
}

DTHuesped** DTReservaGrupal::getHuespedes(){
    return this->huespedes;
}

DTReservaGrupal::~DTReservaGrupal(){}