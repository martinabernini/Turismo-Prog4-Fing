#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL

#include <string>
using namespace std;
#include "DTReserva.h"
#include "DTFecha.h"

class DTReservaGrupal : public DTReserva{
    private:
		int codigo;
		DTFecha checkIn;
		DTFecha checkOut;
		estadoReserva estado;
		float costo;
		int habitacion;
		DTHuesped **huespedes;
    public:
		DTReservaGrupal(int codigo, DTFecha checkIn, DTFecha checkOut, estadoReserva estado, float costo, int habitacion, DTHuesped **huespedes);
		DTHuesped** getHuespedes();
		~DTReservaGrupal();
};

#endif