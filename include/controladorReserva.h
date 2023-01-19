#ifndef CONTROLADORRESERVA
#define CONTROLADORRESERVA

#include <map>
#include <set>
#include "IReserva.h"
#include "reserva.h"
#include "calificacion.h"
#include "estadia.h"

#include "hostal.h"
using namespace std;

class controladorReserva : public IReserva
{
private:
    controladorReserva();
    static controladorReserva *instancia; // SINGLETON

    map<int, reserva *> coleccionReservas; // coleccion de reservas

    int contadorReserva;

public:
    static controladorReserva *getInstancia();

    void setContadorReserva();
    void obtenerReservas(hostal *hos);
    reserva *seleccionarReserva(int codigo);
    void eliminarReserva(int codigo, hostal *hos);
    reserva *getReserva();
    void cancelarReserva();
    void confirmarReserva(hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, habitacion *hab, huesped *hue, map<string, huesped *> coleccionHuespedReserva);
    void ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva);
    void obtenerReserva();
    void habitacionDisponible(DTFecha *checkIn, DTFecha* checkOut, hostal * h);
    void obtenerReservasPorHostal(string nomHostal);

    void imprimirReservasHuesped(huesped *hues);

    ~controladorReserva();
};

#endif