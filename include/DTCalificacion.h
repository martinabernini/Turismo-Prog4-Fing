#ifndef DTCALIFICACION
#define DTCALIFICACION

#include "../include/DTFecha.h"
using namespace std;

#include <string>

class DTCalificacion{
    private:
        int calificacion;
        int id;
        string comentario;
        string respuesta;
        DTFecha* fechaRealizacion;

    public:
        DTCalificacion(int calificacion, int id, string comentario, string respuesta, DTFecha* fechaRealizacion);
		~DTCalificacion();

		int getCalificacion();
        int getId();
        string getComentario();
        string getRespuesta();
        DTFecha* getFechaRealizacion();

};
 
#endif