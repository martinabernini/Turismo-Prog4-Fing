#ifndef HOSTAL
#define HOSTAL

#include <string>
#include <iostream>
#include <map>
#include "calificacion.h"
#include "habitacion.h"

using namespace std;

class habitacion;
class estadia;

class hostal
{
private:
    string nombre;
    string direccion;
    string telefono;
    map<string, calificacion *> coleccionCalificaciones;
    map<int, habitacion *> coleccionHabitaciones;
    map<string, estadia *> coleccionEstadia;

public:
    hostal(string nombre, string direccion, string telefono);
    map<string, calificacion *> getColeccionCalificaciones();
    map<int, habitacion *> getColeccionHabitaciones();
    map<string, estadia *> getColeccionEstadia();
    float getPromedioCalificaciones();
    string getNombre();
    string getDireccion();
    string getTelefono();
    void setNombre(string nombre);
    void setDireccion(string direccion);
    void setTelefono(string telefono);
    void agregarHabitacion(int num, habitacion* hab);
    void agregarCalificacion(string cod, calificacion* calif);
    void agregarEstadia(string cod, estadia* e);
    void eliminarEstadia(string cod);

    ~hostal();

};

#endif