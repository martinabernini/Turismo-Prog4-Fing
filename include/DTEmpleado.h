#ifndef DTEMPLEADO
#define DTEMPLEADO

#include <string>
#include "usuario.h"
#include "cargoEmpleado.h"
#include "hostal.h"

using namespace std;

class DTEmpleado{
    private:
        string email;
        string nombre;
        string password;

        cargoEmpleado cargo;
        bool estaSuscrito;
        hostal *hostalTrabaja;
    public:
        DTEmpleado(string email, string nombre, string password, cargoEmpleado cargo, bool estaSuscrito, hostal *nomHostal);

        string getEmail();
        string getNombre(); 
        cargoEmpleado getCargo(); 
        bool getEstaSuscrito();
        hostal* getHostalTrabaja();

        void setEmail(string email);
        void setNombre(string nombre);
        void setCargo(cargoEmpleado cargo);
        void setEstaSuscrito(bool suscripcion);
        void setHostalTrabaja(hostal *hostalTrabaja);
        ~DTEmpleado();
};


#endif
