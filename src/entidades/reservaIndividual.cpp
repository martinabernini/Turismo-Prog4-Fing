//#include "../include/reserva.h"
#include "../../include/reserva.h"
#include "../../include/reservaIndividual.h"
#include "../../include/habitacion.h"

#include <string>
#include <iostream>
using namespace std;

reservaIndividual::reservaIndividual(int codigo, DTFecha *checkIn, DTFecha *checkOut, estadoReserva estado, huesped *huesped, habitacion *habitacion) : reserva(codigo, checkIn, checkOut, estado, habitacion)
{
  this->hues = huesped;
}

float reservaIndividual::calcularCosto()
{
  // Falta el código
  return 0;
}

void reservaIndividual::borrarReserva(){
  this->hues=NULL;
  reserva::setHabitacion(NULL);
  delete(this->getCheckIn());
  delete(this->getCheckOut());
}

string reservaIndividual::tipoReserva() { return "Individual"; }

reservaIndividual::~reservaIndividual() {}

huesped *reservaIndividual::getHuesped()
{
  return this->hues;
}
void reservaIndividual::setHuesped(huesped *hues)
{
  this->hues = hues;
}
