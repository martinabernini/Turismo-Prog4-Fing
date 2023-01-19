#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

#include  <string>
#include "DTReserva.h"
#include "DTFecha.h"

class DTReservaIndividual : public DTReserva{
    private:
		int codigo;
		DTFecha checkIn;
		DTFecha checkOut;
		estadoReserva estado;
		float costo;
		int habitacion;
		bool pagado;
    public:
		DTReservaIndividual(int codigo, DTFecha checkIn, DTFecha checkOut, estadoReserva estado, float costo, int habitacion, bool pagado);
		bool getEstadoPago();
		void setEstaPago(bool pagado);
};

#endif