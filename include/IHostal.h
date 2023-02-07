#ifndef IHOSTAL
#define IHOSTAL

#include "hostal.h"
#include "habitacion.h"
#include "estadia.h"
#include "IObserver.h"
#include "DTCalificacion.h"
#include <map>


class IHostal{
    public:
     
        IHostal() {};

        virtual void confirmarAltaHostal(string nombre, string direccion, string telefono)=0;

        virtual void imprimirCalificacionesSR(hostal* hos)=0;
        virtual void imprimirHabitaciones(hostal * h)=0;
        virtual bool existeEstadia(string email)=0;
        virtual bool existeCalificacion(int id, string email, hostal* hos)=0;
        virtual bool existeHostal(string nombre)=0;
        virtual void finalizarEstadia(string email)=0;
        virtual bool estadiaValida(string email)=0;
        virtual void obtenerHostales()=0; 
        virtual void seleccionarHostal(string nomHostal)=0;  

        
        virtual void imprimirEstadias(string nomHostal)=0;
        virtual habitacion* seleccionarHabitacion(int numero)=0;
        virtual hostal* getHostal()=0; 
        virtual void asignarEmpHostal()=0;
        virtual habitacion* getHabitacion(hostal* hos, int num)=0; 
        virtual void imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod)=0;
        virtual estadia* getEstadia()=0; 
        virtual calificacion* obtenerCalificacion(int id, string email, hostal* hos)=0; 
        virtual void seleccionarEstadia(int cod, string email)=0;
        virtual void comentarCalificacion(string texto,calificacion* cal)=0;  
        virtual void obtenerTop3Hostales()=0; 
        virtual void obtenerDetallesHostal(hostal *hos)=0;
        virtual void confirmarAltaHabitacion()=0; 
        virtual void ingresaristarEstadíasFinalizadas(string emailUsuario)=0;
        virtual void ingresarlnfoCalificacion(string mensaje, int calificacion)=0;
        virtual void ingresarInformacionHabitacion(int num, float precio, int capacidad)=0;
        virtual void altaCalificacion()=0;
        virtual void listarEstadiasFinalizadas(string email)=0;
        virtual void imprimirInfoBasicaHostal(hostal *hos)=0;

        virtual void agregarEstadia(string key, estadia* est)=0;

        virtual void agregarObservador(IObserver *o)=0;
        virtual void eliminarObservador(IObserver *o)=0;
        virtual void notificarObservadores(calificacion* cal)=0;

        virtual ~IHostal() {};

};

#endif