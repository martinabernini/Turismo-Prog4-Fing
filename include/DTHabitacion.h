#ifndef DTHABITACION
#define DTHABITACION

#include <string>

using namespace std;

class DTHabitacion
{
private:
  int numero;
  float precio;
  int capacidad;

public:
  DTHabitacion(int numero, float precio, int capacidad);
  int getNumero();
  float getPrecio();
  int getCapacidad();
  void setNumero(int numero);
  void setPrecio(float precio);
  void setCapacidad(int capacidad);
};

// Sobrecarga de operadora para los DTReserva
ostream &operator<<(ostream &os, DTHabitacion &dt);

#endif