#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

#include <string>
using namespace std;
#include "DTFecha.h"
#include "reserva.h"

class reservaIndividual : public reserva
{ // heredan los atributos private de Reserva
	private:
	huesped *hues;
	public:
	reservaIndividual();
	reservaIndividual(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, huesped *huesped, habitacion *habitacion);
	float calcularCosto(); // aca tiene metodo
	string tipoReserva();
	huesped* getHuesped();
	void setHuesped(huesped* hues);
  void borrarReserva();

	~reservaIndividual();
};

#endif