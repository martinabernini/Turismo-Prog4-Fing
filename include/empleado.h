#ifndef EMPLEADO
#define EMPLEADO

#include <string>
#include <set>
#include "usuario.h"
#include "cargoEmpleado.h"
#include "hostal.h"
#include "IObserver.h"
#include "calificacion.h"

using namespace std;

class empleado : public usuario, public IObserver{
    private:
        cargoEmpleado cargo;
        bool estaSuscrito;
        hostal* hostalTrabaja;
        set<calificacion*> notificaciones;

    public:
        empleado();
        empleado(string email, string nombre, string password, cargoEmpleado cargo,hostal* hostalTrabaja);
        string getCargo();
        hostal* getHostalTrabaja();
        void setHostalTrabaja(hostal *hos);
        bool getEstaSuscrito();
        void setCargo(cargoEmpleado cargo);      
        void setEstaSuscrito(bool estaSuscrito);
        void notify(calificacion* cal);
        ~empleado();
        void getNombresito();
        set<calificacion*> getNotificaciones();
        void eliminarNotificaciones();

};
#endif