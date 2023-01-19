#ifndef CU_CONSULTADEHOSTAL
#define CU_CONSULTADEHOSTAL

#include "fabrica.h"
#include <iostream>

void cu_consultaDeHostal()
{
  fabrica *fab = fabrica::getInstancia();  // llamo a la instancia de la fabrica
  IHostal *ihostal = fab->getIHostal();    // llamo a la interfaz de hostal
  IReserva *ireserva = fab->getIReserva(); // Llamo a la interfaz de reserva

  string hostalSeleccionado;
  ihostal->obtenerHostales();
  cout << "Listado de hostales, por favor seleccione uno ingresando su nombre: " << endl;
  cin.ignore();
  getline(cin, hostalSeleccionado);
  ihostal->seleccionarHostal(hostalSeleccionado);
  ihostal->imprimirInfoBasicaHostal(ihostal->getHostal());
  ihostal->obtenerDetallesHostal(ihostal->getHostal());
  ihostal->imprimirHabitaciones(ihostal->getHostal());
  ireserva->obtenerReservasPorHostal(hostalSeleccionado);
};

#endif