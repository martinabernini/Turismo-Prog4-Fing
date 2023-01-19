#ifndef RESERVA
#define RESERVA

#include <string>
using namespace std;

#include "huesped.h"
#include "habitacion.h"
#include "DTReserva.h"
#include "DTHabitacion.h"
#include "DTFecha.h"

class habitacion;

class reserva { //clase abstracta no instanciable porque no hay reservas que no sean grupales o individuales
    private:
		int codigo;
		DTFecha* checkIn;
		DTFecha* checkOut;
		estadoReserva estado;
		habitacion *hab;

    public:
		reserva(); 
        reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, estadoReserva estado, habitacion* hab);
		virtual float calcularCosto() = 0; //No tiene método
		virtual string tipoReserva() = 0; //No tiene método
		int getCodigo(); //getters
		DTFecha* getCheckIn();
		DTFecha* getCheckOut();
		estadoReserva getEstado();
		habitacion* getHabitacion();
		virtual map<string, huesped*> getHuespedes(){map<string, huesped*> res; return res;};
		virtual bool estaPago(){ /*Nunca se deberia llegar a llamar esta funcion*/ return false; };
		virtual void borrarReserva(){ /*Nunca se deberia llegar a llamar esta funcion*/};
		void setCodigo(int codigo); //setters 
		virtual huesped* getHuesped(){return NULL;};
		virtual void setHuesped(huesped* hues){};
		void setCheckIn(DTFecha* checkIn); 
		void setCheckOut(DTFecha* chechOut);
		void setEstado(estadoReserva estado);
		void setHabitacion(habitacion *hab);

		virtual ~reserva(){};
};

#endif