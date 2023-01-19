#ifndef CU_CONSULTATOP3DEHOSTALES
#define CU_CONSULTATOP3DEHOSTALES

#include "fabrica.h"
#include <exception>
#include <iostream>
using namespace std;

void cu_consultaTop3DeHostales()
{
  fabrica *fab = fabrica::getInstancia(); // llamo a la instancia de la fabrica
  IHostal *ihostal = fab->getIHostal();   // llamo a la interfaz de hostal

  string nombreHostalSeleccionado = "";
  ihostal->obtenerTop3Hostales();
  cout << "Si desea ver comentarios y calificaciones de algun hostal, ingrese el nombre: " << endl;
  cout << "De lo contrario, ingrese 'salir' " << endl;
  cin.ignore();
  getline(cin, nombreHostalSeleccionado);
  if (nombreHostalSeleccionado != "salir" && ihostal->existeHostal(nombreHostalSeleccionado))
  {
    ihostal->seleccionarHostal(nombreHostalSeleccionado);
    ihostal->obtenerDetallesHostal(ihostal->getHostal());
  };
};

#endif