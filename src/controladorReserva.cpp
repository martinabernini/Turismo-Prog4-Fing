#include "../include/controladorReserva.h"
#include "../include/controladorHostal.h"
#include "../include/reservaIndividual.h"
#include "../include/reservaGrupal.h"
#include "../include/DTReserva.h"
#include "../include/reserva.h"
#include "../include/DTFecha.h"

#include "../include/IHostal.h"
#include "../include/fabrica.h"

controladorReserva::controladorReserva()
{
	this->contadorReserva = 0;
}

controladorReserva *controladorReserva::instancia = NULL;

controladorReserva *controladorReserva::getInstancia()
{
	if (instancia == NULL)
		instancia = new controladorReserva();
	return instancia;
};

void controladorReserva::setContadorReserva()
{
	this->contadorReserva = 0;
}

reserva *controladorReserva::seleccionarReserva(int codigo)
{
	map<int, reserva *>::iterator it;
	it = this->coleccionReservas.find(codigo);
	reserva *res = it->second;
	return res;
}

void controladorReserva::eliminarReserva(int codigo, hostal *hos){
	map<int, reserva *> reservas = this->coleccionReservas;
	map<int, reserva *>::iterator itR;
	itR = reservas.find(codigo);

	cout << "ENTRE 1" << endl;

	if (itR != reservas.end()){ 	//mientras exista la reserva
		reserva *res = itR->second;
		map<string, estadia *> estadias = hos->getColeccionEstadia();
		map<string, estadia *>::iterator itE= estadias.begin();		//arranco del inicio del iterador
		estadia* est;
		calificacion* calif;
		cout << "ENTRE 2" << endl;
		if (res->tipoReserva() == "Individual"){
			huesped *hues = res->getHuesped();
			cout << "ENTRE 3" << endl;
			while(itE != estadias.end()){
				est = itE->second;
				cout << "ENTRE 4" << endl;
				if (est->getReserva() == res){
					calif = est->getCalificacion();
					if (calif !=NULL)
						calif->borrarCalificacion();
					hos->eliminarEstadia(to_string(codigo) + hues->getEmail());
					itE=estadias.end();
					cout << "ENTRE 7" << endl;
				} else {
					itE++;
				} //if
			}//while
			delete(res);
			this->coleccionReservas.erase(codigo);
			cout << "ENTRE 10" << endl;
		} else { //IF
			huesped* hues;
			map<string, huesped*> hg= res->getHuespedes();
			map<string,huesped*>:: iterator iterG, iterGG;
			cout << "ENTRE 3" << endl;
			for(itE= estadias.begin() ; itE != estadias.end(); itE++){		//voy recorriendo estadias
				est = itE->second;
				cout << "ENTRE 4" << endl;
				for (iterG= hg.begin() ; iterG != hg.end(); iterG++){		//voy recorriendo los  huespedes
					if ((est !=NULL) &&(est->getReserva() == res)){
						hues=iterG->second;
						cout << "ENTRE 5" << endl;
						calif = est->getCalificacion();
						cout << "ENTRE 6" << endl;
						if (calif !=NULL)
							calif->borrarCalificacion();
						cout << "ENTRE 7" << endl;
						hos->eliminarEstadia(to_string(codigo) + hues->getEmail());
					} //if
				} // for chico
			} //for grande
			cout << "ENTRE 8" << endl;
			delete(res);
			cout << "ENTRE 9" << endl;
			this->coleccionReservas.erase(codigo);
		} //if 
	}
	else{
		cout << "No existe la reserva" << endl;
	}
}

reserva *controladorReserva::getReserva()
{
	return NULL;
}

void controladorReserva::cancelarReserva() {}

void controladorReserva::confirmarReserva(hostal *h, DTFecha *fechaCheckIn, DTFecha *fechaCheckOut, int tipoDeReserva, habitacion *hab, huesped *hue, map<string, huesped *> coleccionHuespedReserva)
{
	this->contadorReserva++;
	if (tipoDeReserva == 0)
	{ // reserva individual
		reservaIndividual *res = new reservaIndividual(contadorReserva, fechaCheckIn, fechaCheckOut, Abierta, hue, hab);
		coleccionReservas.insert({contadorReserva, res});
	}
	else
	{ // reserva grupal
		reservaGrupal *res = new reservaGrupal(contadorReserva, fechaCheckIn, fechaCheckOut, Abierta, coleccionHuespedReserva, hab);
		coleccionReservas.insert({contadorReserva, res});
	}
}

void controladorReserva::ingresarInformacionReserva(DTFecha checkIN, DTFecha checkOUT, DTReserva *tipoReserva) {}

void controladorReserva::obtenerReserva()
{
}

void controladorReserva::obtenerReservas(hostal *hos)
{
}

void controladorReserva::obtenerReservasPorHostal(string nomHostal)
{
	map<int, reserva *> reservas = this->coleccionReservas; // coleccion de reservas
	map<int, reserva *>::iterator it;

	cout << "---------------------Listado de reservas registradas en el sistema----------------------------" << endl;
	for (it = reservas.begin(); it != reservas.end(); it++){

		if ((it->second != NULL) && (it->second->getHabitacion()->getHostal()->getNombre() == nomHostal))
		{

			cout << "Codigo de reserva: " << it->second->getCodigo() << endl;
			cout << "Numero de habitacion: " << it->second->getHabitacion()->getNumero() << endl;
			cout << "Fecha de check-in: ";
			it->second->getCheckIn()->imprimirFecha();
			cout << "Fecha de check-out: ";
			it->second->getCheckOut()->imprimirFecha();
			string estado;
			if (it->second->getEstado() == Abierta)
			{
				estado = "Abierta";
			}
			else if (it->second->getEstado() == Cerrada)
			{
				estado = "Cerrada";
			}
			else if (it->second->getEstado() == Cancelada)
			{
				estado = "Cancelada";
			}

			cout << "Estado de la reserva: " << estado << endl;

			if (it->second->tipoReserva() == "Individual")
			{
				cout << "Tipo de reserva: Individual" << endl;
				cout << "Nombre del huesped: " << it->second->getHuesped()->getNombre() << endl;
				cout << "-----------------------------------";
			}
			else if (it->second->tipoReserva() == "Grupal")
			{
				cout << "Tipo de reserva: Grupal" << endl;
				map<string, huesped *> huespedes = it->second->getHuespedes();
				map<string, huesped *>::iterator itHuespedes;
				int cont = 1;
				cout << "--------------------------" << endl;

				for (itHuespedes = huespedes.begin(); itHuespedes != huespedes.end(); itHuespedes++)
				{
					cout << "Nombre del huesped " << cont << ": " << itHuespedes->second->getNombre() << endl;
					cont++;
					cout << "--------------------------" << endl;
				}
			}
		}
	}
	cout << endl;
}









void controladorReserva::imprimirReservasHuesped(huesped *hues){
	map<int, reserva *> reservas = this->coleccionReservas;
	map<int, reserva *>::iterator it;

	for (it = reservas.begin(); it != reservas.end(); it++){
		if (it->second->tipoReserva() == "Individual"){ //SI ES INDIVIDUAL
			if (it->second->getHuesped() == hues){
			reserva *resAux = it->second;
			DTReserva *aux = new DTReserva(resAux->getCodigo(), resAux->getCheckIn(), resAux->getCheckOut(), resAux->getEstado(), hues, resAux->getHabitacion());

			cout << "-----------------------------------" << endl;
			cout << "Codigo: " << aux->getCodigo() << endl;
			cout << "Fecha check in: ";
			aux->getCheckIn()->imprimirFecha();
			cout << "Fecha check out: ";
			aux->getCheckOut()->imprimirFecha();
			cout << "Estado: " << aux->getEstado() << endl;
			cout << "A nombre de: " << aux->getHuespedDTReserva()->getNombre() << endl;
			cout << "Habitacion: " << aux->getHabitacion()->getNumero() << endl;
			
			}
		} else {	//SI ES GRUPAL
			map<string, huesped*> h= it->second->getHuespedes();
			map<string, huesped*>::iterator itEr= h.begin();
			for(itEr = h.begin(); itEr != h.end(); itEr++){
				if (itEr->second == hues){
					reserva *resAux = it->second;
					DTReserva *aux = new DTReserva(resAux->getCodigo(), resAux->getCheckIn(), resAux->getCheckOut(), resAux->getEstado(), hues, resAux->getHabitacion());

					cout << "-----------------------------------" << endl;
					cout << "Codigo: " << aux->getCodigo() << endl;
					cout << "Fecha check in: ";
					aux->getCheckIn()->imprimirFecha();
					cout << "Fecha check out: ";
					aux->getCheckOut()->imprimirFecha();
					cout << "Estado: " << aux->getEstado() << endl;
					cout << "A nombre de: " << itEr->second->getNombre() << endl;
					cout << "Habitacion: " << aux->getHabitacion()->getNumero() << endl;
				} //if
			} //for
			
		}	//if
		
	}	//for
	cout << "-----------------------------------" << endl;
}

void controladorReserva::habitacionDisponible(DTFecha *checkIn, DTFecha *checkOut, hostal *h)
{
	map<int, reserva*> reservas = this->coleccionReservas;
	map<int, reserva*>::iterator it;
	fabrica *fab = fabrica::getInstancia(); // Llamo a la instancia de la fabrica
	IHostal *ihostal = fab->getIHostal();

	map<string, habitacion*> habitaciones = ihostal->obtenerHabitaciones();
	map<string, habitacion*>::iterator iter;
	bool reservada = false;
	bool disponible;

	for (iter = habitaciones.begin(); iter != habitaciones.end(); iter++){ //Por cada habitacion dentro del hostal seleccionado
		for (it = reservas.begin(); it != reservas.end(); it++){
			if ((iter->second->getNumero() == it->second->getHabitacion()->getNumero()) 
					&& (iter->second->getHostal()->getNombre() == it->second->getHabitacion()->getHostal()->getNombre())){
				if (checkIn->esMayor(it->second->getCheckOut())){
					reservada = false;
					cout << "La fecha de checkin es mayor que al de checkout" << endl;

				} else if (it->second->getCheckIn()->esMayor(checkOut)){
					reservada = false;
					cout << "La fecha de checkout es mayor que al de checkout" << endl;

				} else {
					cout << "Ese dia esta ocupada" << endl;
					reservada = true;
				}
			}
		}
		
		if(it == reservas.end()){
			if (iter->second->getHostal()->getNombre() == h->getNombre()){
				disponible = true;
			} else {
				disponible = false;
			}
		}

	if (!(reservada) && disponible){
			cout << "----------------------------" << endl;
			cout << "Habitacion " << iter->second->getNumero() << endl;
			cout << "Precio: " << iter->second->getPrecio() << endl;
		}
	reservada = false;
	}
}

controladorReserva::~controladorReserva() {}
