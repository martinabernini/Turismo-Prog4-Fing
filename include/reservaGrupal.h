#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL
#include <map>
#include <string>
#include <map>

#include "DTFecha.h"
#include "reserva.h"

#include "usuario.h"
#include "empleado.h"
#include "huesped.h"

using namespace std;
class reservaGrupal : public reserva { //clase derivada de Reserva
	private:
		map<string, huesped*> coleccionHuespedGrupal;
    public:
		reservaGrupal(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, map<string,huesped*>, habitacion *habitacion);
		float calcularCosto(); //aca tiene metodo
		string tipoReserva();
		void borrarReserva();
		map<string, huesped*> getHuespedes();
		~reservaGrupal();
};



#endif