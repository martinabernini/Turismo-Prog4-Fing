#include <string>
#include <iostream>
#include <iomanip>

#include "fabrica.h"

#include "usuario.h"
#include "estadia.h"
#include "reserva.h"
#include "hostal.h"
#include "habitacion.h"
#include "empleado.h"
#include "huesped.h"

using namespace std;

void cu_cargarDatosDePrueba()
{
  fabrica* fab = fabrica::getInstancia();
  IUsuario* iusuario = fab->getIUsuario();
  IReserva* ireserva = fab->getIReserva();
  IHostal* ihostal = fab->getIHostal();

  
  //empleados (ref,nombre,email,contraseña,cargo)
  empleado *E1, *E2, *E3, *E4;

  iusuario->setNombre("Emilia");
  iusuario->setEmail("emilia@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setCargo(Recepcion);
  iusuario->confirmarAltaUsuario();
  E1 = iusuario->findEmpleado("emilia@mail.com");

  iusuario->setNombre("Leonardo");
  iusuario->setEmail("leo@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setCargo(Recepcion);
  iusuario->confirmarAltaUsuario();
  E2 = iusuario->findEmpleado("leo@mail.com");

  iusuario->setNombre("Alina");
  iusuario->setEmail("alina@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setCargo(Administracion);
  iusuario->confirmarAltaUsuario();
  E3 = iusuario->findEmpleado("alina@mail.com");

  iusuario->setNombre("Barliman");
  iusuario->setEmail("barli@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setCargo(Recepcion);
  iusuario->confirmarAltaUsuario();
  E4 = iusuario->findEmpleado("barli@mail.com");

  //huespedes (ref, nombre, email, contraseña, finger)
  huesped *H1, *H2, *H3, *H4, *H5, *H6;

  iusuario->setNombre("Sofia");
  iusuario->setEmail("sofia@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(true);
  iusuario->confirmarAltaUsuario();
  H1 = iusuario->findHuesped("sofia@mail.com");


  iusuario->setNombre("Frodo");
  iusuario->setEmail("frodo@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(true);
  iusuario->confirmarAltaUsuario();
  H2 = iusuario->findHuesped("frodo@mail.com");


  iusuario->setNombre("Sam");
  iusuario->setEmail("sam@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(false);
  iusuario->confirmarAltaUsuario();
  H3 = iusuario->findHuesped("sam@mail.com");


  iusuario->setNombre("Merry");
  iusuario->setEmail("merry@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(false);
  iusuario->confirmarAltaUsuario();
  H4 = iusuario->findHuesped("merry@mail.com");


  iusuario->setNombre("Pippin");
  iusuario->setEmail("pippin@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(false);
  iusuario->confirmarAltaUsuario();
  H5 = iusuario->findHuesped("pippin@mail.com");


  iusuario->setNombre("Seba");
  iusuario->setEmail("seba@mail.com");
  iusuario->setContrasenia("123");
  iusuario->setEsFinger(true);
  iusuario->confirmarAltaUsuario();
  H6 = iusuario->findHuesped("seba@mail.com");
  
  //hostales (ref, nombre, direccion, tel)
  hostal *HO1, *HO2, *HO3, *HO4, *HO5;

  cout<< "LLegue al hostal" << endl;
  ihostal->confirmarAltaHostal("La posada del finger", "Av de la playa 123, Maldonado", "099111111");
  ihostal->seleccionarHostal("La posada del finger");
  HO1 = ihostal->getHostal();

  ihostal->confirmarAltaHostal("Mochileros", "Rambla Costanera 333, Rocha", "42579512");
  ihostal->seleccionarHostal("Mochileros");
  HO2 = ihostal->getHostal();

  ihostal->confirmarAltaHostal("El Pony Pisador", "Bree (preguntar por Gandalf)", "000");
  ihostal->seleccionarHostal("El Pony Pisador");
  HO3 = ihostal->getHostal();

  ihostal->confirmarAltaHostal("Altos de Fing", "Av del Toro 1424", "099892992");
  ihostal->seleccionarHostal("Altos de Fing");
  HO4 = ihostal->getHostal();

  ihostal->confirmarAltaHostal("Caverna Lujosa", "Amaya 2515", "233233235");
  ihostal->seleccionarHostal("Caverna Lujosa");
  HO5 = ihostal->getHostal();


  habitacion *HAB1 ,*HAB2, *HAB3, *HAB4, *HAB5, *HAB6;

  cout<< "LLegue a la habitacion" << endl;

  ihostal->seleccionarHostal(HO1->getNombre());
  ihostal->ingresarInformacionHabitacion(1, 40, 2);
  ihostal->confirmarAltaHabitacion();
  HAB1 = ihostal->getHabitacion(HO1, 1);

  cout<< "LLegue a la habitacion 1" << endl;

  ihostal->seleccionarHostal(HO1->getNombre());
  ihostal->ingresarInformacionHabitacion(2, 10, 7);
  ihostal->confirmarAltaHabitacion();
  HAB2 = ihostal->getHabitacion(HO1, 2);

  cout<< "LLegue a la habitacion 2" << endl;

  ihostal->seleccionarHostal(HO1->getNombre());
  ihostal->ingresarInformacionHabitacion(3, 30, 3);
  ihostal->confirmarAltaHabitacion();
  HAB3 = ihostal->getHabitacion(HO1, 3);

  cout<< "LLegue a la habitacion 3" << endl;

  ihostal->seleccionarHostal(HO1->getNombre());
  ihostal->ingresarInformacionHabitacion(4, 5, 12);
  ihostal->confirmarAltaHabitacion();
  HAB4 = ihostal->getHabitacion(HO1, 4);

  cout<< "LLegue a la habitacion 4" << endl;

  ihostal->seleccionarHostal(HO5->getNombre());
  ihostal->ingresarInformacionHabitacion(1, 3, 2);
  ihostal->confirmarAltaHabitacion();
  HAB5 = ihostal->getHabitacion(HO5, 1);

  cout<< "LLegue a la habitacion 5" << endl;

  ihostal->seleccionarHostal(HO3->getNombre());
  ihostal->ingresarInformacionHabitacion(1, 9, 5);
  ihostal->confirmarAltaHabitacion();
  HAB6 = ihostal->getHabitacion(HO3, 1);

  cout<< "LLegue a la habitacion 6" << endl;

  //finalizar estadias
  //calificar estadias 
  //comentar calificacion
  //asignar emp hostal  
  E1->setHostalTrabaja(HO1);
  E2->setHostalTrabaja(HO2);
  E3->setHostalTrabaja(HO2);
  E4->setHostalTrabaja(HO3);

  //reservas (ref, hostel, habitacion, tipo, check in, check out, huespedes)
  reserva *R1, *R2, *R3, *R4; 

  //confirmarReserva(hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, habitacion *hab, huesped *hue, map<string, huesped *> coleccionHuespedReserva)
  
  string emailH1 = "sofia@mail.com";
  string emailH2 = "frodo@mail.com";
  string emailH3 = "sam@mail.com";
  string emailH4 = "merry@mail.com";
  string emailH5 = "pippin@mail.com";
  string emailH6 = "seba@mail.com";

  
  DTFecha *fechaInR1 = new DTFecha(01,05,2022,14,00);
  DTFecha *fechaOutR1 = new DTFecha(10,05,2022,10,00);
  DTFecha *fechaInR2 = new DTFecha(04,01,2001,20,00);
  DTFecha *fechaOutR2 = new DTFecha(05,01,2001,02,00);
  DTFecha *fechaInR3 = new DTFecha(07,06,2022,14,00);
  DTFecha *fechaOutR3 = new DTFecha(30,06,2022,11,00);
  DTFecha *fechaInR4 = new DTFecha(10,06,2022,14,00);
  DTFecha *fechaOutR4 = new DTFecha(30,06,2022,11,00);
  map<string, huesped*> huespedNull;
  huespedNull.begin() = huespedNull.end();

  cout<< "1" << endl;
  map<string, huesped*> huespedes;
  huespedes.insert({emailH2,H2});
  huespedes.insert({emailH3,H3});
  huespedes.insert({emailH4,H4});
  huespedes.insert({emailH5,H5});

  map<string, huesped*>::iterator it;

  cout<< "2" << endl;

  ireserva->confirmarReserva(HO1,fechaInR1,fechaOutR1,0,HAB1,H1,huespedNull);
  R1 = ireserva->seleccionarReserva(1);
  ireserva->confirmarReserva(HO3,fechaInR2,fechaOutR2,1,HAB6,NULL,huespedes);
  R2 = ireserva->seleccionarReserva(2);
  ireserva->confirmarReserva(HO1,fechaInR3,fechaOutR3,0,HAB3,H1,huespedNull);
  R3 = ireserva->seleccionarReserva(3);
  ireserva->confirmarReserva(HO5,fechaInR4,fechaOutR4,0,HAB5,H6,huespedNull);
  R4 = ireserva->seleccionarReserva(4);


  cout<< "3" << endl;


  //estadias (ref, reserva, huesped, check in)


DTFecha *fecha1 = new DTFecha(01,05,2022,18,00);
DTFecha *fecha2 = new DTFecha(04,01,2001,21,00);
DTFecha *fecha6 = new DTFecha(07,06,2022,18,00);
DTFecha *fecha7 = new DTFecha(10,05,2022,9,00);
DTFecha *fecha8 = new DTFecha(5,01,2001,2,00);
DTFecha *fecha9 = new DTFecha(15,06,2022,10,00);

cout<< "4" << endl;

estadia *ES1 = new estadia(fecha1, fecha7, R1, H1, NULL);
HO1->agregarEstadia(to_string(R1->getCodigo()) + H1->getEmail(), ES1);

estadia *ES2 = new estadia(fecha2, fecha8, R2, H2, NULL);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H2->getEmail(), ES2);

estadia *ES3 = new estadia(fecha2, NULL, R2, H3, NULL);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H3->getEmail(), ES3);

estadia *ES4 = new estadia(fecha2, NULL, R2, H4, NULL);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H4->getEmail(), ES4);

estadia *ES5 = new estadia(fecha2, NULL, R2, H5, NULL);
HO3->agregarEstadia(to_string(R2->getCodigo()) + H5->getEmail(), ES5);

estadia *ES6 = new estadia(fecha6, fecha8, R4, H6, NULL);
HO5->agregarEstadia(to_string(R4->getCodigo()) + H6->getEmail(), ES6);

cout<< "5" << endl;

  //calificar estadias
    string comentarioES1 = "Un poco caro para lo que ofrecen. El famoso gimnasio era una caminadora (que hacía tremendo ruido) y 2 pesas, la piscina parecía el lago del Parque Rodó y el desayuno eran 2 tostadas con mermelada. Internet se pasaba cayendo. No vuelvo.";
    string comentarioES2 = "Se pone peligroso de noche, no recomiendo. Además no hay caja fuerte para guardar anillos.";
    string comentarioES6 = "Había pulgas en la habitación. Que lugar más mamarracho!!";
    DTFecha *fechaC1 = new DTFecha(11,05,2022,18,00);
    DTFecha *fechaC2 = new DTFecha(05,01,2001,3,00);
    DTFecha *fechaC3 = new DTFecha(15,06,2022,23,00);

cout<< "6" << endl;

    calificacion *C1 = new calificacion(3,comentarioES1,fechaC1,H1,1);
    HO1->agregarCalificacion(to_string(1) + emailH1, C1);
    ES1->setCalificacion(C1);

    calificacion *C2 = new calificacion(2,comentarioES2,fechaC2,H2,2);
    HO3->agregarCalificacion(to_string(2) + emailH2, C2);
    ES2->setCalificacion(C2);

    calificacion *C3 = new calificacion(1,comentarioES6,fechaC3,H6,4);
    HO5->agregarCalificacion(to_string(4) + emailH6, C3);
    ES3->setCalificacion(C3);
    
cout<< "7" << endl;

  //comentar calificacion
  string respuesta = "Desaparecio y se fue sin pagar";
  DTFecha *fechaRta = new DTFecha(06,01,2001,15,00);
  C2->setRespuesta(respuesta);
  C2->setFechaRespuesta(fechaRta);

}