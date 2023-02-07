#ifndef CONTROLADORUSUARIO
#define CONTROLADORUSUARIO

#include "usuario.h"
#include "empleado.h"
#include "huesped.h"
#include "IUsuario.h"
#include "DTHuesped.h"
#include "DTEmpleado.h"
#include <map>
#include <set>

using namespace std;

class controladorUsuario: public IUsuario{

    private: 
        controladorUsuario();
        static controladorUsuario *instancia; //SINGLETON

        map<string,usuario*> coleccionUsuarios;  //coleccion de usuarios
        map<string,empleado*> coleccionEmpleados; ///coleccion de empleados
        map<string,huesped*> coleccionHuesped; //coleccion de huespedes
        
        //Memoria
        string nombre;
        string email;
        string password;
        bool esFinger;
        cargoEmpleado cargo;
        hostal* hostalTrabaja;


        huesped* huespedSeleccionado;
        empleado* empleadoSeleccionado;

    public:

        static controladorUsuario* getInstancia();
        void imprimirUsuarios();

        //constructor empleado
        //empleado Empleado(string email, string nombre, string contrasenia, cargoEmpleado cargo);
        //constructor huesped
        //huesped Huesped(string email, string nombre, string contrasenia, bool esFinger);

        //opiti
        void setNombre(string nombre);
        void setEmail(string email);
        void setContrasenia(string contrasenia);
        void setEsFinger(bool finger);

        void imprimirEmpleadosNoRegistrados(hostal *hos);

        void setHostalTrabaja(hostal *hos);
        void imprimirReservasHuesped(string emailHuesped);

        void seleccionarEmpleado(string email);
        usuario* seleccionarUsuario(string email);
        huesped* seleccionarHuesped(string nombre);
        huesped* getHuesped();
        void asignarCargo(string nombre, cargoEmpleado cargo);
        void setCargo(cargoEmpleado); //Re
        empleado* findEmpleado(string email);
        huesped* findHuesped(string email); 
        void ingresarDatosUsuario(); // Código realizado
        bool existeUsuario();
        void actualizarEmailUsuario(string email);
        void confirmarAltaUsuario();
        void cancelarAltaIngreso();
        void obtenerInfoUsuario(string rol, string email);
        bool obtenerEsFinger();
        void obtenerInfoEmpleado();
        empleado* obtenerEmpleado(); 
        void obtenerEmpleados(string nomHostal); 
        void obtenerReservasHuesped(string email); 
        void obtenerHuespedes(); 
        void obtenerUsuarios(); 
        void obtenerEmpleados();
        void imprimirNotificaciones();
        empleado* getEmpleado();

        ~controladorUsuario();
};


#endif
