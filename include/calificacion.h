#ifndef CALIFICACIONES
#define CALIFICACIONES

#include <string>
using namespace std;
#include "reloj.h"
#include "DTFecha.h"
#include "huesped.h"

class calificacion {
    private:
        int Calificacion;
        int id;
        string comentario;
        string respuesta;
        DTFecha* fechaRespuesta;
        DTFecha* fechaRealizacion;
        huesped* huespedComentario;
        int codReserva;

    public:
        int getCalificacion();
        int getId();
        string getComentario();
        string getRespuesta();
        DTFecha* getFechaRealizacion();
        int getCodigoReserva();
        string getEmailHuesped();
        calificacion(int calificacion, string comentario, DTFecha* fechaRealizacion, huesped* huespedComentario, int codReserva);
        void setCalificacion(int calificacion);
        void setComentario(string comentario);
        void setRespuesta(string respuesta);
        void setFechaRealizacion(DTFecha* fecha);
        void borrarCalificacion();
        void setFechaRespuesta(DTFecha *fecha);
        DTFecha* getFechaRespuesta();
        //constructor para CU
        ~calificacion();

};

#endif