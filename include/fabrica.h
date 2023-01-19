#ifndef FABRICA
#define FABRICA

#include <stdexcept>
#include "IHostal.h"
#include "IUsuario.h"
#include "IReserva.h"
#include <string>

class fabrica {
	
	private:
		fabrica();
		static fabrica* instancia;
		~fabrica();
	public:
		static fabrica* getInstancia();
		static void releaseInstancia();
		IHostal* getIHostal();
		IUsuario* getIUsuario();
		IReserva* getIReserva();
};
#endif
