#ifndef DTRESERVA
#define DTRESERVA


#include <string>
using namespace std;
#include "DTHuesped.h"
#include "huesped.h"
#include "estadoReserva.h"
#include "DTFecha.h"
#include "habitacion.h"

class DTReserva {
	private:
		int codigo;
		DTFecha* checkIn;
		DTFecha* checkOut;
		estadoReserva estado;
		//float costo;
		huesped* huespedReserva;
		habitacion* habitacionReserva;
	public:
		DTReserva();
		DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado/*, float costo, int habitacion*/);
		DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, huesped *huespedReserva, habitacion *habitacionReserva);

		int getCodigo(); //getters
		DTFecha* getCheckIn();
		DTFecha* getCheckOut();
		estadoReserva getEstado();
		huesped* getHuespedDTReserva();
		habitacion* getHabitacion();
		~DTReserva();
};

//Sobrecarga de operadora para los DTReserva
ostream& operator<<(ostream& os, DTReserva& dt);

#endif