#ifndef IUSUARIO
#define IUSUARIO

#include "usuario.h"
#include "empleado.h"
#include "cargoEmpleado.h"
#include "DTEmpleado.h"

using std::string;
using namespace std;
class IUsuario {
	public:
        IUsuario() {};

        
        virtual void seleccionarEmpleado(string email) =0; 
        virtual usuario* seleccionarUsuario(string email) =0;
        virtual huesped* seleccionarHuesped(string nombre) = 0;
        virtual void imprimirUsuarios()=0;
        virtual void cancelarAltaIngreso()=0;
        virtual huesped* getHuesped()=0;
        
        virtual void asignarCargo(string nombre, cargoEmpleado cargo)=0;
        virtual void setCargo(cargoEmpleado)=0;

        virtual empleado* findEmpleado(string email)=0;
        virtual huesped* findHuesped(string nombre)=0;
        virtual bool existeUsuario()=0;
        virtual void ingresarDatosUsuario()=0;
        virtual void actualizarEmailUsuario(string email)=0;
        virtual void confirmarAltaUsuario()=0;

        //opiti
        virtual void setHostalTrabaja(hostal *hos)=0;
        virtual set<DTEmpleado*> obtenerEmpleadosNoRegistrados(hostal *hos)=0;
        virtual void imprimirReservasHuesped(string emailHuesped)=0;

        virtual void imprimirNotificaciones()=0;

        
        //setters
        virtual void setNombre(string nombre)=0;
        virtual void setEmail(string email)=0;
        virtual void setContrasenia(string contrasenia)=0;
        virtual void setEsFinger(bool finger)=0;

        //OPERACIONES DONDE OBTENGO COSAS
        virtual empleado* getEmpleado()=0;
        virtual void obtenerInfoUsuario(string rol, string email)=0;
        virtual bool obtenerEsFinger()=0;
        virtual void obtenerInfoEmpleado()=0;
        virtual empleado* obtenerEmpleado()=0; 

        //OPERACIONES DONDE PRINTEO SETS DE COSITAS
        virtual void obtenerEmpleados(string nomHostal) =0;
        virtual void obtenerEmpleados() =0; 
        virtual void obtenerReservasHuesped(string email)=0; 
        virtual void obtenerHuespedes()=0; 
        virtual void obtenerUsuarios()=0; 


        //IMPRIMIRINFO
        virtual void imprimirTodaLaInfoDeUsuarios()=0;

        virtual ~IUsuario() {};
};


#endif
