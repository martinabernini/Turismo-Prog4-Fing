#include <iostream>
#include <string>
using namespace std;
#include <stdlib.h>

#include "include/cu_AltaDeUsuario.h"
#include "include/cu_AltaDeHostal.h"
#include "include/cu_AltaDeHabitacion.h"
#include "include/cu_asignarEmpleadoAHostal.h"
#include "include/cu_realizarReserva.h"
#include "include/cu_consultarTop3DeHostales.h"
#include "include/cu_registrarEstadia.h"
#include "include/cu_finalizarEstadia.h"
#include "include/cu_calificarEstadia.h"
#include "include/cu_comentarCalificacion.h"
#include "include/cu_consultaDeUsuario.h"
#include "include/cu_consultaDeHostal.h"
#include "include/cu_consultaDeReserva.h"
#include "include/cu_consultaDeEstadia.h"
#include "include/cu_bajaReserva.h"
#include "include/cu_suscribirseANotificaciones.h"
#include "include/cu_consultaDeNotificaciones.h"
#include "include/cu_eliminarSuscripcion.h"
#include "include/cu_modificarFechaDelSistema.h"
#include "include/cu_cargarDatosDePrueba.h"

#include "include/fabrica.h"
#include "include/reloj.h"

int menuPrincipal()
{

  cout << "----------------------------------------------" << endl;
  cout << "-                Bienvenid@                  -" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "-            Ingrese una opcion:             -" << endl;
  cout << "----------------------------------------------" << endl;

  cout << "1 - Alta de Usuario" << endl; //Implementado y testeado
  cout << "2 - Alta de Hostal" << endl; //Implementado y testeado
  cout << "3 - Alta de Habitacion" << endl; //Implementado y testeado
  cout << "4 - Asignar empleado a hostal" << endl; //Implementado y testeado
  cout << "5 - Realizar Reserva" << endl; //Implementado, falta probar
  cout << "6 - Consultar top 3 de hostales" << endl;
  cout << "7 - Registrar estadia" << endl;  //Implementado, falta probar
  cout << "8 - Finalizar Estadia" << endl; //Implementado, falta probar
  cout << "9 - Calificar estadia" << endl; //Implementado, falta probar
  cout << "10 - Comentar calificacion" << endl; //Implementado, falta probar
  cout << "11 - Consulta de Usuario" << endl; //Implementado y testeado
  cout << "12 - Consulta de Hostal" << endl;
  cout << "13 - Consulta de Reserva" << endl; //Implementado, falta probar
  cout << "14 - Consulta de Estadia" << endl; //Implementado, falta probar
  cout << "15 - Baja de reserva" << endl; //Implementado, falta probar
  cout << "16 - Suscribirse a Notificaciones" << endl;  //Implementado, falta probar
  cout << "17 - Consulta de Notificaciones" << endl;  //Implementado, falta probar
  cout << "18 - Eliminar Suscripcion" << endl;  //Implementado, falta probar
  cout << "19 - Modificar Fecha del Sistema" << endl; //Implementado, falta probar
  cout << "20 - Cargar datos de prueba" << endl;
  cout << "21 - Salir" << endl;
  int opcion = 0;
  cin >> opcion;
  return opcion;
};

int main(){

  fabrica* fab = fabrica::getInstancia();
  IUsuario* iusuario = fab->getIUsuario();
  IReserva* ireserva = fab->getIReserva();
  IHostal* ihostal = fab->getIHostal();

  bool salir=true;
  
  while (salir){
    int opcion;
    opcion = menuPrincipal();
    switch (opcion){
      case 1:{
        cu_altaDeUsuario();
        break;
      };
      case 2:{
        cu_altaDeHostal();
        break;
      };
      case 3:{
        cu_altaDeHabitacion();
        break;
      };
      case 4:{
        cu_asignarEmpleadoAHostal();
        break;
      };
      case 5:{
        cu_realizarReserva();
        break;
      };
      case 6:{
        cu_consultaTop3DeHostales();
        break;
      };
      case 7:{
        cu_registrarEstadia();
        break;
      };
      case 8:{
        cu_finalizarEstadia();
        break;
      };
      case 9:{
        cu_calificarEstadia();
        break;
      };
      case 10:{
        cu_comentarCalificacion();
        break;
      };
      case 11:{
        cu_consultaDeUsuario();
        break;
      };
      case 12:{
        cu_consultaDeHostal();
        break;
      };
      case 13:{
        cu_consultaDeReserva();
        break;
      };
      case 14:{
        cu_consultaDeEstadia();
        break;
      };
      case 15:{
        cu_bajaReserva();
        break;
      };
      case 16:{
        cu_suscribirseANotificaciones();
        break;
      };
      case 17:{
        cu_consultaDeNotificaciones();
        break;
      };
      case 18:{
        cu_eliminarSuscripcion();
        break;
      };
      case 19:{
        cu_modificarFechaDelSistema();
        break;
      };
      case 20:{
        cu_cargarDatosDePrueba();
        break;
      };
      case 21:{
        salir=false;
        break;
      }
      default:{
        cout << "Comando incorrecto, por favor reintentar" << endl;
        cin.clear();
        cin.ignore(100, '\n');
      };
    } //case
  } //while
  delete iusuario;
  delete ireserva;
  delete ihostal;
  fabrica::releaseInstancia();
  reloj::releaseInstancia();
  return 0;
}
