#include "../../include/calificacion.h"

int contador=1;

calificacion::calificacion(int calificacion, string comentario, DTFecha* fechaRealizacion, huesped* huespedComentario, int codReserva){
    this->Calificacion=calificacion;
    this->id= contador;
    this->comentario=comentario;
    this->respuesta= "";
    this->fechaRealizacion=fechaRealizacion;
    this->huespedComentario = huespedComentario;
    this->codReserva = codReserva;
    contador++;
}

int calificacion::getCalificacion(){
    return this->Calificacion;
}

int calificacion::getId(){
    return this->id;
}

string calificacion::getComentario(){
    return this->comentario;
}

string calificacion::getRespuesta(){
    return this->respuesta;
}

DTFecha* calificacion::getFechaRealizacion(){
    return this->fechaRealizacion;
}

int calificacion::getCodigoReserva(){
    return this->codReserva;
}

string calificacion::getEmailHuesped(){
    return this->huespedComentario->getEmail();
}

void calificacion::setCalificacion(int calificacion){
    this->Calificacion=calificacion;
}

void calificacion::setComentario(string comentario){
    this->comentario=comentario;
}

void calificacion::setRespuesta(string respuesta){
    this->respuesta=respuesta;
}

void calificacion::setFechaRealizacion(DTFecha* fecha){
    this->fechaRealizacion=fecha;
}

void calificacion::borrarCalificacion(){
    this->huespedComentario = NULL;    
    delete this->fechaRealizacion;
}
void calificacion::setFechaRespuesta(DTFecha *fecha){
    this->fechaRespuesta = fecha;
}
DTFecha* calificacion::getFechaRespuesta(){
    return this->fechaRespuesta;
}

calificacion::~calificacion(){}

