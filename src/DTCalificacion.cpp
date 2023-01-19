#include "../include/DTCalificacion.h"

DTCalificacion::DTCalificacion(int calificacion, int id, string comentario, string respuesta, DTFecha* fechaRealizacion){
    this->calificacion=calificacion;
    this->id=id;
    this->comentario=comentario;
    this->respuesta=respuesta;
    this->fechaRealizacion= fechaRealizacion;
}
		
int DTCalificacion::getCalificacion(){
    return this->calificacion;
}

int DTCalificacion::getId(){
    return this->id;
}

string DTCalificacion::getComentario(){
    return this->comentario;
}

string DTCalificacion::getRespuesta(){
    return this->respuesta;
}

DTFecha* DTCalificacion::getFechaRealizacion(){
    return this->fechaRealizacion;
}

DTCalificacion::~DTCalificacion(){}
