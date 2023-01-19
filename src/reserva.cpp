//#include "../include/reserva.h"
#include "../include/reserva.h"


#include <string>
#include <iostream>
using namespace std;

// Operaciones de clase 'Reserva'
reserva::reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, habitacion* hab){
	this->codigo = codigo;
	this->checkIn = checkIn;
	this->checkOut = checkOut;
	this->estado =estado;
	this->hab= hab;
}

int reserva::getCodigo()
{
	return this->codigo;
}

DTFecha* reserva::getCheckIn()
{
	return this->checkIn;
}

DTFecha* reserva::getCheckOut()
{
	return this->checkOut;
}

estadoReserva reserva::getEstado()
{
	return this->estado;
}

void reserva::setCodigo(int codigo)
{
	this->codigo = codigo;
}

void reserva::setCheckIn(DTFecha* checkIn)
{
	this->checkIn = checkIn;
}

void reserva::setCheckOut(DTFecha* checkOut)
{
	this->checkOut = checkOut;
}

void reserva::setEstado(estadoReserva estado)
{
	this->estado = estado;
}

habitacion *reserva::getHabitacion(){
	return this->hab;
}


void reserva::setHabitacion(habitacion *habitacion)
{
	this->hab = habitacion;
}

