#include "../../include/controladorHostal.h"

#include <exception>
/*
        controladorHostal();
        static controladorHostal *instancia; //SINGLETON
        map<string,hostal*> coleccionHostales;  //coleccion de hostales
        map<string,estadia*> coleccionEstadia;  //coleccion de estadia, se identifica con el email del huesped
        map<int,calificacion*> coleccionCalificaciones; //coleccion de  calificaciones

*/
controladorHostal::controladorHostal()
{
  this->numeroHabitacion = 0;
  this->precioHabitacion = 0;
  this->capacidadHabitacion = 0;
  this->hostalSeleccionado = NULL;
  this->habitacionSeleccionada = NULL;
  this->estadiaSeleccionada = NULL;
  this->calificacionIngresada = 0;
  this->comentarioIngresado = "";
}

controladorHostal *controladorHostal::instancia = NULL;

controladorHostal *controladorHostal::getInstancia()
{
  if (instancia == NULL)
    instancia = new controladorHostal(); // NO SE PORQUE ROMPE
  return instancia;
}

// CONTROLADOR HOSTAL//

void controladorHostal::confirmarAltaHostal(string nombre, string direccion, string telefono)
{
  hostal *nuevoHostal = new hostal(nombre, direccion, telefono);
  this->coleccionHostales.insert({nombre, nuevoHostal});
}

void controladorHostal::imprimirCalificacionesSR(hostal *hos){

  map<string, calificacion *> cals = hos->getColeccionCalificaciones();
  map<string, calificacion *>::iterator it;

  cout << "------------------Listado de calificaciones sin responder----------------------------" << endl;
  for (it = cals.begin(); it != cals.end(); it++){

    if (it->second->getRespuesta() == ""){
      calificacion *cal = it->second;
      DTCalificacion *aux = new DTCalificacion(cal->getCalificacion(), cal->getId(), cal->getComentario(), cal->getRespuesta(), cal->getFechaRealizacion());
      cout << "-Calificacion: " << aux->getCalificacion() << endl;
      cout << "-Codigo de reserva: " << cal->getCodigoReserva() << endl;
      cout << "-Correo del huesped: " << cal->getEmailHuesped();
      cout << "-Comentario: " << aux->getComentario() << endl;
      DTFecha *f = aux->getFechaRealizacion();
      cout << "-Fecha de realizacion: ";
      cout << f->getDia() << "/" << f->getMes() << "/" << f->getAnio();
      cout << " a las" << f->getHora() << ":" << f->getMinuto() << endl;
      cout << "----------------------------------";
      delete (aux);
    }
  }
}


void controladorHostal::finalizarEstadia(string email){
  map<string, estadia *> e = getHostal()->getColeccionEstadia();
  map<string, estadia *>::iterator it= e.begin();
  estadia* est;
  string key;
  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if(texto == email){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }

  reloj *r = reloj::getInstancia();
  DTFecha* fecha= r->getReloj();
  est->setFechaCheckOut(fecha);
} // COMPLETAR

bool controladorHostal::existeEstadia(string email)
{ // COMPLETAR
  map<string, estadia *> e = getHostal()->getColeccionEstadia();
  map<string, estadia *>::iterator it= e.begin();
  estadia* est;
  string key;

  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if(texto == email){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }
  return (e.find(key) != e.end());
}

bool controladorHostal::estadiaValida(string email){

  map<string, estadia *> e = getHostal()->getColeccionEstadia();
  map<string, estadia *>::iterator it= e.begin();
  estadia* est;
  string key;
  bool seguir= true;

  while(it != e.end()){
    est= it->second;    //la estadia
    string texto= est->getHuesped()->getEmail();
    if((texto == email) && (est->getCheckOut()==NULL)){
      int cod= est->getReserva()->getCodigo();
      key= to_string(cod) + email;
      it= e.end();
    } else {
      it++;
    }
  }
  return (est->getCheckOut() == NULL);


}

void controladorHostal::crearHabitacionHostal(hostal hostal, int numero, int precio, int capacidad)
{
}

void controladorHostal::comentarCalificacion(string texto, calificacion *cal){
  cal->setRespuesta(texto);
}

bool controladorHostal::existeHostal(string nombre)
{
  map<string, hostal *>::iterator iterador = this->coleccionHostales.find(nombre);
  return !(iterador == this->coleccionHostales.end());
}

void controladorHostal::obtenerHostales()
{
  map<string, hostal *> hostales = this->coleccionHostales;
  map<string, hostal *>::iterator it;

  cout << "---------------------Listado de hostales disponibles----------------------------" << endl;
  for (it = hostales.begin(); it != hostales.end(); it++)
  {
    hostal *hostalAux = it->second;
    DTHostal *aux = new DTHostal(hostalAux->getNombre(), hostalAux->getDireccion(), hostalAux->getTelefono());
    cout << "-Nombre del hostal: " << aux->getNombre() << endl;
    cout << "-Direccion: " << aux->getDireccion() << endl;
    cout << "-Telefono: " << aux->getTelefono() << endl;
    cout << "-------------" << endl;
    delete (aux);
  }
}

void controladorHostal::seleccionarHostal(string nomHostal)
{
  map<string, hostal *>::iterator it = this->coleccionHostales.find(nomHostal);
  this->hostalSeleccionado = it->second;
};

hostal *controladorHostal::getHostal()
{
  return this->hostalSeleccionado;
} // COMPLETAR

void controladorHostal::asignarEmpHostal() {} // COMPLETAR

habitacion *controladorHostal::getHabitacion(hostal *hos, int num)
{
  map<int, habitacion *> h = hos->getColeccionHabitaciones();
  map<int, habitacion *>::iterator iterador = h.find(num);
  return (iterador->second);
}

habitacion *controladorHostal::seleccionarHabitacion(int numero)
{
  return NULL;
}

map<string, estadia *> controladorHostal::obtenerEstadias()
{
  return coleccionEstadia;
}
void controladorHostal::agregarEstadia(string key, estadia* e){
    this->coleccionEstadia.insert({key,e});
}

void controladorHostal::imprimirlnfoEstadia(string nomHostal, string emailestadia, int cod)
{
  map<string, hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  hostal *elhostal = iter->second;

  map<string, estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, estadia *>::iterator it = estadias.find(to_string(cod) + emailestadia);

  string PROMO;
  int quiere;

  estadia *res = it->second;
  DTFecha *fecha1 = res->getCheckIn();

  DTFecha *fecha2=NULL;
  if (res->getCheckOut()!=NULL){
    fecha2=res->getCheckOut();
  }

  cout << "Fecha checkIn: ";
  fecha1->imprimirFecha();
  cout << "Fecha de checkOut: ";
  if (fecha2 != NULL){
    fecha2->imprimirFecha();
  } else {
    cout << "aun no realiza checkOut";
  }

  huesped *hue = res->getHuesped();
  // cout << "Huesped: " << hue->getNombre() << endl;

  reserva *reservaAsociada = res->getReserva();
  cout << "Codigo de reserva asociada: " << reservaAsociada->getCodigo() << endl;

  calificacion *calif = res->getCalificacion();
  cout << "Calificacion de la estadia: "; 
  if (calif != NULL){
    cout << res->getCalificacion()->getCalificacion() << endl;
    cout << "Comentario :" << res->getCalificacion()->getComentario() << endl;
    cout << "Respuesta :" << res->getCalificacion()->getRespuesta() << endl;
  } else 
    cout << "No hay calificacion."<< endl;

  cout << "Desea ver la informacion de la reserva asociada? SI = 1, NO = 0" << endl;
  cin >> quiere;

  if (quiere == 1)
  {
    string estado;
    if (reservaAsociada->getEstado() == Abierta){
      estado = "Abierta";
    } else if (reservaAsociada->getEstado()== Cerrada){
      estado = "Cerrada";
    } else if (reservaAsociada->getEstado() == Cancelada){
      estado = "Cancelada";
    }

    cout << "Estado de la reserva: " << estado << endl;
    cout << "Numero de habitacion: " << reservaAsociada->getHabitacion()->getNumero()<< endl;
  }
}

void controladorHostal::imprimirHabitaciones(hostal *h)
{
  map<int, habitacion *> habitaciones = h->getColeccionHabitaciones();
  map<int, habitacion *>::iterator it;

  cout << "---------------------Listado de habitaciones disponibles----------------------------" << endl;
  for (it = habitaciones.begin(); it != habitaciones.end(); it++)
  {
    habitacion *habAux = it->second;
    DTHabitacion *aux = new DTHabitacion(habAux->getNumero(), habAux->getPrecio(), habAux->getCapacidad());
    cout << "-Numero de habitacion: " << aux->getNumero() << endl;
    cout << "-Precio: " << aux->getPrecio() << endl;
    cout << "-Capacidad: " << aux->getCapacidad() << endl;
    cout << "-------------" << endl;
    delete (aux);
  }
}

estadia *controladorHostal::getEstadia()
{
  return this->estadiaSeleccionada;
} // COMPLETAR

bool controladorHostal::existeCalificacion(int id, string email, hostal *hos)
{
  map<string, calificacion *> cals = hos->getColeccionCalificaciones();
  map<string, calificacion *>::iterator iterador = cals.find("" + id + email);
  return !(iterador == cals.end());
}

calificacion *controladorHostal::obtenerCalificacion(int id, string email, hostal *hos)
{
  map<string, calificacion *> cals = hos->getColeccionCalificaciones();
  map<string, calificacion *>::iterator iterador = cals.find(to_string(id) + email);
  return (iterador->second);
} // COMPLETAR

void controladorHostal::seleccionarEstadia(int cod, string email)
{
  map<string, estadia *>::iterator iterador = this->coleccionEstadia.find(to_string(cod) + email);
  estadia *res = iterador->second;
  this->estadiaSeleccionada = res;
}

void controladorHostal::obtenerTop3Hostales()
{
  hostal *h1 = NULL;
  hostal *h2 = NULL;
  hostal *h3 = NULL;
  for (map<string, hostal *>::iterator it = this->coleccionHostales.begin(); it != this->coleccionHostales.end(); ++it)
  {
    if (!h1 || h1->getPromedioCalificaciones() < it->second->getPromedioCalificaciones())
    {
      if (!h2 || h1->getPromedioCalificaciones() > h2->getPromedioCalificaciones())
        h2 = h1;
      else if (!h3 || h1->getPromedioCalificaciones() > h3->getPromedioCalificaciones())
        h3 = h1;
      h1 = it->second;
    }
    else if (!h2 || h2->getPromedioCalificaciones() < it->second->getPromedioCalificaciones())
    {
      if (!h3 || h2->getPromedioCalificaciones() > h3->getPromedioCalificaciones())
        h3 = h2;
      h2 = it->second;
    }
    else if (!h3 || h3->getPromedioCalificaciones() < it->second->getPromedioCalificaciones())
      h3 = it->second;
  };
  cout << ("Top 3 hostales por calificacion") << endl;
  cout << "Hostal 1: " << endl;
  cout << "-Nombre del hostal: " << h1->getNombre() << endl;
  cout << "-Direccion: " << h1->getDireccion() << endl;
  cout << "-Telefono: " << h1->getTelefono() << endl;
  cout << "-------------" << endl;
  cout << "Hostal 2: " << endl;
  cout << "-Nombre del hostal: " << h2->getNombre() << endl;
  cout << "-Direccion: " << h2->getDireccion() << endl;
  cout << "-Telefono: " << h2->getTelefono() << endl;
  cout << "-------------" << endl;
  cout << "Hostal 3: " << endl;
  cout << "-Nombre del hostal: " << h3->getNombre() << endl;
  cout << "-Direccion: " << h3->getDireccion() << endl;
  cout << "-Telefono: " << h3->getTelefono() << endl;
  cout << "-------------" << endl;
}

void controladorHostal::obtenerDetallesHostal(hostal *hos)
{
  map<string, calificacion *> cals = hos->getColeccionCalificaciones();
  map<string, calificacion *>::iterator it;
  cout << "Promedio de calificaciones: " << hos->getPromedioCalificaciones() << endl;
  for (it = cals.begin(); it != cals.end(); it++)
  {
    calificacion *cal = it->second;
    DTCalificacion *aux = new DTCalificacion(cal->getCalificacion(), cal->getId(), cal->getComentario(), cal->getRespuesta(), cal->getFechaRealizacion());
    cout << "-Calificacion: " << aux->getCalificacion() << endl;
    cout << "-Identificador: " << aux->getId() << endl;
    cout << "-Comentario: " << aux->getComentario() << endl;
    DTFecha *f = aux->getFechaRealizacion();
    cout << "-Fecha de realizacion: ";
    cout << f->getDia() << "/" << f->getMes() << "/" << f->getAnio();
    cout << " a las" << f->getHora() << endl;
    delete (aux);
  }
}

void controladorHostal::imprimirInfoBasicaHostal(hostal *hos)
{
  cout << "-Nombre del hostal: " << hos->getNombre() << endl;
  cout << "-Direccion: " << hos->getDireccion() << endl;
  cout << "-Telefono: " << hos->getTelefono() << endl;
  cout << "-------------" << endl;
};

void controladorHostal::obtenerDetallesHabitacion() {} // NO SE USA: VER imprimirHabitaciones()

void controladorHostal::obtenerInfoHabitacion() {} // NO SE USA

void controladorHostal::obtenerConsumos() {} // NO SE USA: ES DE CONSUMOS

void controladorHostal::seleccionarConsumos(int cod) {} // NO SE USA: ES DE CONSUMOS

void controladorHostal::confirmarAltaHabitacion()
{
  habitacion *hab = new habitacion(this->numeroHabitacion, this->precioHabitacion, this->capacidadHabitacion);
  this->coleccionHabitaciones.insert({to_string(numeroHabitacion) + this->hostalSeleccionado->getNombre(), hab});
  this->hostalSeleccionado->agregarHabitacion(numeroHabitacion, hab);
  hab->setHostalHabitacion(this->hostalSeleccionado);

  this->numeroHabitacion = 0;
  this->precioHabitacion = 0;
  this->capacidadHabitacion = 0;
  this->hostalSeleccionado = NULL;

} // COMPLETAR

void controladorHostal::ingresaristarEstadíasFinalizadas(string emailUsuario) {} // COMPLETAR

void controladorHostal::ingresarlnfoCalificacion(string mensaje, int calificacion)
{
  this->calificacionIngresada = calificacion;
  this->comentarioIngresado = mensaje;
} // COMPLETAR

void controladorHostal::ingresarInformacionHabitacion(int num, float precio, int capacidad)
{
  this->numeroHabitacion = num;
  this->precioHabitacion = precio;
  this->capacidadHabitacion = capacidad;
}

void controladorHostal::altaCalificacion()
{
  cout << "Fecha checkIn: ";
  this->estadiaSeleccionada->getCheckIn()->imprimirFecha();
  reloj *r = reloj::getInstancia();

  cout << "Fecha checkIn: ";
  this->estadiaSeleccionada->getCheckIn()->imprimirFecha();
  
  string clave = to_string(this->estadiaSeleccionada->getReserva()->getCodigo()) + this->estadiaSeleccionada->getHuesped()->getEmail();
  calificacion *cal = new calificacion(this->calificacionIngresada, this->comentarioIngresado,
                                       r->getReloj(), this->estadiaSeleccionada->getHuesped(), this->estadiaSeleccionada->getReserva()->getCodigo());
  this->estadiaSeleccionada->setCalificacion(cal);
  string claveCalificacion =  to_string(this->estadiaSeleccionada->getReserva()->getCodigo()) + this->estadiaSeleccionada->getHuesped()->getEmail();
  this->hostalSeleccionado->agregarCalificacion(claveCalificacion, cal);


  this->hostalSeleccionado = NULL;
  this->estadiaSeleccionada = NULL;
  this->calificacionIngresada = 0;
  this->comentarioIngresado = "";

  cout << "por entrar a notificar";
  notificarObservadores(cal);
} // COMPLETAR

void controladorHostal::listarEstadiasFinalizadas(string email)
{
  map<string, hostal *>::iterator it2 = this->coleccionHostales.find(this->hostalSeleccionado->getNombre());
  hostal *elHostal = it2->second;
  cout << "Hostal seleccionado: " << elHostal->getNombre() << endl;
  map<string, estadia *> estad = elHostal->getColeccionEstadia();
  map<string, estadia *>::iterator it;

  cout << "---------------------Listado de estadias finalizadas----------------------------" << endl;
  for (it = estad.begin(); it != estad.end(); it++)
  {
    /*
    cout << "Primero:" << it->second->getReserva()->getHabitacion()->getHostal()->getNombre() << " and " << this->hostalSeleccionado->getNombre() << endl;
    cout << "Segundo:" << it->second->getHuesped()->getEmail() << " and " << email << endl;
    bool test = (it->second->getCheckOut() != NULL);
    if (test){
      cout << "Es true" << endl;
    }*/
    if (it->second->getReserva()->getHabitacion()->getHostal()->getNombre() == this->hostalSeleccionado->getNombre() &&
        it->second->getHuesped()->getEmail() == email && (it->second->getCheckOut() != NULL))
    {
      estadia *est = it->second;
      DTEstadia *aux = new DTEstadia(est->getCheckIn(), est->getCheckOut(), est->getReserva()->getCodigo(), est->getHuesped()->getEmail());
      cout << "-Numero de reserva: " << aux->getCodigoReserva() << endl;
      cout << "-Correo del huesped: " << aux->getEmailHuesped() << endl;
      cout << "-Fecha de checkIn: "; 
      aux->getFechaCheckIn()->imprimirFecha();
      cout << "-Fecha de checkOut: "; 
      aux->getFechaCheckOut()->imprimirFecha();

      delete (aux);
    }
  }
}

void controladorHostal::agregarObservador(IObserver *o){
  observers.insert(o);
}

void controladorHostal::eliminarObservador(IObserver *o)
{
  observers.erase(o);
}

void controladorHostal::notificarObservadores(calificacion *cal){
  set<IObserver *>::iterator it;
  for (it = observers.begin(); it != observers.end(); ++it){
    IObserver* papa = *it;
    papa->getNombresito();
    cout << "ya mande";
    papa->notify(cal);
  }
}

void controladorHostal::imprimirEstadias(string nomHostal){ // imprime todas las estadias (no la info)

  map<string, hostal *>::iterator iter = this->coleccionHostales.find(nomHostal);
  hostal *elhostal = iter->second;
  map<string, estadia *> estadias = elhostal->getColeccionEstadia();
  map<string, estadia *>::iterator it;
  cout << "---------------------Listado de estadias del hostal----------------------------" << endl;
  for (it = estadias.begin(); it != estadias.end(); it++)
  {
    cout << "Estadia: " << it->second->getHuesped()->getEmail();
    cout << "     Codigo de reserva: " << it->second->getReserva()->getCodigo() << endl;
  }
}

map<string, habitacion *> controladorHostal::obtenerHabitaciones()
{
  return coleccionHabitaciones;
}

controladorHostal::~controladorHostal() {} // COMPLETAR
