#ifndef IRESERVA
#define IRESERVA

#include "reserva.h"
#include "DTFecha.h"

class IReserva
{
public:
    IReserva(){};
    
    virtual void setContadorReserva() = 0;
    virtual void obtenerReservas(hostal *hos) = 0;
    virtual reserva *seleccionarReserva(int codigo) = 0;
    virtual void eliminarReserva(int codigo, hostal* hos) = 0;
    virtual reserva *getReserva() = 0;
    virtual void cancelarReserva() = 0;
    virtual void confirmarReserva(hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, habitacion *hab, huesped *hue, std::map<std::string, huesped *> coleccionHuespedReserva) = 0;
    virtual void ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva) = 0;
    virtual void obtenerReserva() = 0;
    // virtual calificacion* getCalificacion()=0; Juan, comento esto porque no se está usando y da errores de compilación.
    // virtual huesped* getHuesped()=0;
    virtual void obtenerReservasPorHostal(string nomHostal) = 0;
    virtual void habitacionDisponible(DTFecha* checkIn, DTFecha *checkOut, hostal * h)=0;
    virtual void imprimirReservasHuesped(huesped* hues)=0;

    virtual ~IReserva(){};
};

#endif