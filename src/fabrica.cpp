#include "../include/fabrica.h"
#include "../include/controladorUsuario.h"
#include "../include/controladorReserva.h"
#include "../include/controladorHostal.h"

fabrica::fabrica() {};

fabrica* fabrica::instancia = NULL;

fabrica* fabrica::getInstancia() {
	if (instancia == NULL) instancia = new fabrica();
	return instancia;
};

void fabrica::releaseInstancia() {
	if ( instancia != NULL) {
		delete instancia;
		instancia = NULL;
	};
};

IReserva* fabrica::getIReserva() {
	return controladorReserva::getInstancia();
};

IUsuario* fabrica::getIUsuario() {
	return controladorUsuario::getInstancia();
};

IHostal* fabrica::getIHostal() {
	return controladorHostal::getInstancia();
};

fabrica::~fabrica() {};