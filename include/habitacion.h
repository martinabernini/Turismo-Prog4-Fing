#ifndef HABITACION
#define HABITACION

#include <string>
#include "hostal.h"
using namespace std;

class hostal;

class habitacion
{
private:
  int numero;
  float precio;
  int capacidad;
  hostal *hostalHabitacion;

public:
  habitacion();
  habitacion(int numero, float precio, int capacidad);
  int getNumero();
  float getPrecio();
  int getCapacidad();
  hostal* getHostal();
  
  void setNumero(int numero);
  void setPrecio(float precio);
  void setCapacidad(int capacidad);
  void setHostalHabitacion(hostal *hos);
  //  void agregarHabitacion(int numero, float precio, int capacidad);
};
#endif