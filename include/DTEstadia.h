#ifndef DTESTADIA
#define DTESTADIA

#include "../include/DTFecha.h"
using namespace std;

#include <string>

class DTEstadia{
    private:
        DTFecha *fechaCheckIn;
        DTFecha *fechaCheckOut;
        int codigoReserva;
        string emailHuesped;

    public:
        DTEstadia(DTFecha* fechaCheckIn, DTFecha* fechaCheckOut, int codigoReserva, string emailHuesped);
        DTFecha* getFechaCheckIn();
        DTFecha* getFechaCheckOut();
        int getCodigoReserva();
        string getEmailHuesped();
		~DTEstadia();
};
 
#endif