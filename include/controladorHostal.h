#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL

#include <map>
#include <set>
#include "IHostal.h"
#include "DTHostal.h"
#include "hostal.h"
#include "calificacion.h"
#include "DTCalificacion.h"
#include "reloj.h"
#include "empleado.h"
#include "DTEstadia.h"

#include "habitacion.h"

using namespace std;


class controladorHostal: public IHostal{
    private: 
        controladorHostal();
        static controladorHostal *instancia; //SINGLETON

        //a chequear
        string nombre;
        string direccion;
        string telefono;   
        //setters habitaciones

        
        map<string,hostal*> coleccionHostales;  //coleccion de hostales
        map<string,habitacion*> coleccionHabitaciones;  //coleccion de hostales, la KEY de la habitación es el concatenado de las strings "codhabitación+nomHostal"
        map<string,estadia*> coleccionEstadia;  //coleccion de estadia, se identifica con el email del huesped


        //Memoria de atributos de habitación
        int numeroHabitacion;
        float precioHabitacion;
        int capacidadHabitacion;

        //Memoria de selección de hostal
        hostal *hostalSeleccionado;

        //Memoria de seleccion de habitacion
        habitacion *habitacionSeleccionada;

        //Memoria de seleccion de estadia
        estadia *estadiaSeleccionada;

        //Memoria de información de calificación
        int calificacionIngresada;
        string comentarioIngresado;

        //Observers
        set<IObserver *> observers;
        

    public:
        static controladorHostal* getInstancia();
        map<string,habitacion*>obtenerHabitaciones();
        void crearHabitacionHostal(hostal hostal, int numero, int precio, int capacidad);
        void confirmarAltaHostal(string nombre, string direccion, string telefono);
        void imprimirEmpleadosNoRegistrados(hostal* hos);
        void imprimirEstadias(string nomHostal);
        void imprimirCalificacionesSR(hostal* hos);
        void imprimirHabitaciones(hostal * h);
        void finalizarEstadia(string email);
        bool existeEstadia(string email);
        bool existeCalificacion(int id, string email, hostal* hos);
        bool existeHostal(string nombre);
        bool estadiaValida(string email);
        void obtenerHostales(); 
        void seleccionarHostal(string nomHostal);
        hostal* getHostal(); 
        void asignarEmpHostal();
        habitacion* getHabitacion(hostal* hos, int num); 
        map<string,estadia*> obtenerEstadias();
        void imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod);
        estadia* getEstadia(); 
        calificacion* obtenerCalificacion(int id, string email, hostal* hos); 
        void seleccionarEstadia(int cod, string email);
        void comentarCalificacion(string texto, calificacion* cal); 
        void obtenerTop3Hostales(); 
        void obtenerDetallesHostal(hostal *hos);
        void obtenerDetallesHabitacion();
        void obtenerInfoHabitacion(); 
        void obtenerConsumos(); 
        void seleccionarConsumos(int cod); 
        void confirmarAltaHabitacion(); 
        void ingresaristarEstadíasFinalizadas(string emailUsuario);
        void ingresarlnfoCalificacion(string mensaje, int calificacion);
        void ingresarInformacionHabitacion(int num, float precio, int capacidad);
        void altaCalificacion();
        habitacion * seleccionarHabitacion(int numero);
        void listarEstadiasFinalizadas(string email);
        void imprimirInfoBasicaHostal(hostal *hos);
        void agregarEstadia(string key, estadia* e);

        void agregarObservador(IObserver *o);
        void eliminarObservador(IObserver *o);
        void notificarObservadores(calificacion* cal);

        ~controladorHostal();


};

#endif