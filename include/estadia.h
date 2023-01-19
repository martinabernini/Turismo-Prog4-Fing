#ifndef _ESTADIA_H
#define _ESTADIA_H


#include <string>
using namespace std;

#include "../include/reserva.h"
#include "../include/calificacion.h"
//#include "../include/consumiciones.h"
#include "../include/reloj.h"
#include "../include/DTFecha.h"

class habitacion;

class estadia {
    private:
        DTFecha* fechaCheckIn;
        DTFecha* fechaCheckOut;
        reserva* reservaEstadia;
        huesped* huespedEstadia;

        calificacion* calificacionEstadia;


        string promoCode;
    public:
        DTFecha* getCheckIn();
        DTFecha* getCheckOut();
        string getPromoCode();
        reserva* getReserva();
        huesped* getHuesped();
        calificacion* getCalificacion();
        void setFechaCheckIn(DTFecha* checkIN);
        void setFechaCheckOut(DTFecha* checkOUT);
        void setPromoCode(string codigo);

        bool estaFinalizada();
        void setCalificacion(calificacion* cal);

        void borrarEstadia();

        estadia();
        estadia(DTFecha* checkIn, DTFecha* checkOut, reserva* reservaEstadia, huesped* huespedEstadia, calificacion *califEstadia);

        //constructor con reservas etc según CU
        virtual ~estadia();
};


/*
getCheckIn() : DTFecha
getCheckOut : DTFecha
getPROMO() : string
setPROMO(string)
setCheckIn(DTFecha)
setCheckOout(DTFecha)

*/
#endif