#include "../../include/controladorUsuario.h"
#include <iostream>
#include <set>
#include "../../include/DTCalificacion.h"


using namespace std;
controladorUsuario::controladorUsuario(){
    this->nombre = "";
    this->email = "";
    this->password = "";
    this->cargo = NoInicializado;
    this->esFinger = false;
    this->huespedSeleccionado = NULL;
    this->empleadoSeleccionado = NULL;
    this->hostalTrabaja = NULL;
};


controladorUsuario* controladorUsuario::instancia = NULL;

controladorUsuario* controladorUsuario::getInstancia() {
	if (instancia == NULL) instancia = new controladorUsuario();
	return instancia;
};

void controladorUsuario::setHostalTrabaja(hostal *hos){
    this->hostalTrabaja = hos;
};

void controladorUsuario::imprimirReservasHuesped(string emailHuesped){

};

set<DTEmpleado*> controladorUsuario::obtenerEmpleadosNoRegistrados(hostal *hos){

    set<DTEmpleado*> res;

    map<string, usuario*>::iterator itU;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (empleado* e = dynamic_cast<empleado*>(itU->second)){
            if(e->getHostalTrabaja() == NULL){
                DTEmpleado *aux = new DTEmpleado(e->getEmail(), e->getNombre() , e->getPassword(), e->getCargo(),e->getEstaSuscrito() ,e->getHostalTrabaja());
                res.insert(aux);
            } 
        }
    }

    return res;
};

huesped* controladorUsuario::findHuesped(string nombre){
    map<string, usuario*>::iterator it;
	it = this->coleccionUsuarios.find(nombre);
	huesped *res = dynamic_cast<huesped*>(it->second);
	return res;
}

void controladorUsuario::setNombre(string nombre){
    this->nombre = nombre;
};

void controladorUsuario::setEmail(string email){
    this->email = email;
};

void controladorUsuario::setContrasenia(string contrasenia){
    this->password = contrasenia;
};

void controladorUsuario::setCargo(cargoEmpleado cargo){
    this->cargo = cargo;
};

void controladorUsuario::setEsFinger(bool finger){
    this->esFinger = finger;
};


void controladorUsuario::seleccionarEmpleado(string email){
    map<string, usuario*>::iterator it = this->coleccionUsuarios.find(email);
    empleado* e = dynamic_cast<empleado*>(it->second);
	this->empleadoSeleccionado = e;
};

empleado* controladorUsuario::getEmpleado(){
    return this->empleadoSeleccionado;
}

usuario* controladorUsuario::seleccionarUsuario(string nombre){
    usuario *user = new usuario();
    return user;
};

void controladorUsuario::asignarCargo(string nombre, cargoEmpleado cargo){}
	
    huesped* controladorUsuario::seleccionarHuesped(string email) {
	map<string, usuario*>::iterator it= this->coleccionUsuarios.find(email);
    huesped* h = dynamic_cast<huesped*>(it->second);
	this->huespedSeleccionado = h;
    return huespedSeleccionado;
}

huesped* controladorUsuario::getHuesped() {
  return this->huespedSeleccionado;
} 

empleado* controladorUsuario::findEmpleado(string email){
    map<string,usuario*>::iterator it = this->coleccionUsuarios.find(email);
    empleado* e = dynamic_cast<empleado*>(it->second);
    return e;
}


bool controladorUsuario::existeUsuario(){
    return (this->coleccionUsuarios.count(this->email) > 0);
};

void controladorUsuario::ingresarDatosUsuario(){
    bool tipoUsuarioInvalido;
    cout << "Indique si el usuario es un empleado (E) o un huesped (H): ";
    string tipoUsuario; 

    do {  
        cin >> tipoUsuario; 
        
        if (tipoUsuario == "E" || tipoUsuario == "e"){
            tipoUsuarioInvalido = false;

            bool cargoIngresoInvalido;
            string cargoIngreso;
            cargoEmpleado cargo;

            do {
                cout << "Indicar si el empleado pertenece al area de limpieza (L), administracion (A), recepcion (R) o infraestructua (I): ";
                cin >> cargoIngreso;

                if (cargoIngreso == "L" || cargoIngreso == "l"){
                    cargoIngresoInvalido = false;
                    cargo = Limpieza;

                } else if (cargoIngreso == "A" || cargoIngreso == "a"){
                    cargoIngresoInvalido = false;
                    cargo = Administracion;

                } else if (cargoIngreso == "R" || cargoIngreso == "r"){
                    cargoIngresoInvalido = false;
                    cargo = Recepcion;

                } else if (cargoIngreso == "I" || cargoIngreso == "i"){
                    cargoIngresoInvalido = false;
                    cargo = Infraestructura;

                } else {
                    cargoIngresoInvalido = true;
                    cout << "Se ha ingresado un valor invalido, por favor intentelo nuevamente"<< endl;

                }
            } while (cargoIngresoInvalido);       

            this->cargo = cargo;

        } else if (tipoUsuario == "H" || tipoUsuario == "h"){
            tipoUsuarioInvalido = false;
            
            cout << "Si el usuario es finger ingrese (S), si no lo es ingrese (N): ";
            string ingresoEsFinger;
            bool ingresoEsFingerInvalido;
            bool esFinger;

            do {
                cin >> ingresoEsFinger;

                if (ingresoEsFinger == "S" || ingresoEsFinger == "s"){
                    ingresoEsFingerInvalido = false;
                    esFinger = true;

                } else if (ingresoEsFinger == "N" || ingresoEsFinger == "n"){
                    ingresoEsFingerInvalido = false;
                    esFinger = false;

                } else {
                    ingresoEsFingerInvalido = true;
                    cout << "Se ha ingresado un valor invalido. Si el usuario es finger ingrese (S), si no lo es ingrese (N): ";
                }
                
            } while (ingresoEsFingerInvalido);

            this->esFinger = esFinger;

        } else {
            tipoUsuarioInvalido = true;
            cout << "Se ha ingresado un valor invalido, por favor indique si el usuario es un empleado (E) o un huesped (H)" << endl;

        }
    } while (tipoUsuarioInvalido);
}

void controladorUsuario::actualizarEmailUsuario(string email){
    this->email = email;
}

void controladorUsuario::confirmarAltaUsuario(){
    if (this->cargo == NoInicializado){
        huesped *nuevoHuesped = new huesped(this->email, this->nombre, this->password, this->esFinger);
        this->coleccionUsuarios.insert({this->email, nuevoHuesped});
    } else {
        empleado *nuevoEmpleado = new empleado(this->email, this->nombre, this->password, this->cargo, NULL);
        this->coleccionUsuarios.insert({this->email, nuevoEmpleado});
    }

    cout << "Se ha dado de alta el usuario exitosamente\n";

    this->nombre = "";
    this->email = "";
    this->password = "";
    this->cargo = NoInicializado;
    this->esFinger = false;
}

void controladorUsuario::cancelarAltaIngreso(){
    cout << "Se ha cancelado el ingreso del usuario\n";
    
    this->nombre = "";
    this->email = "";
    this->password = "";
    this->cargo = NoInicializado;
    this->esFinger = false;
}

void controladorUsuario::imprimirUsuarios(){ //imprime solo los nombres de los usuarios
    
    map<string,usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,usuario*> :: iterator itU; 

    map<string, empleado*> empleados;
    map<string, empleado*>::iterator itER;

    map<string, huesped*> huespedes;
    map<string, huesped*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (empleado* e = dynamic_cast<empleado*>(itU->second)){
            empleados.insert({e->getEmail(), e});
        } else {
            huesped* h = dynamic_cast<huesped*>(itU->second);
            huespedes.insert({h->getEmail(), h});
        }
    }

    cout << "---------------------Listado de huespedes registrados en el sistema----------------------------" << endl;
    for (it = huespedes.begin(); it != huespedes.end(); it++){
    huesped *hueAux = it->second;
    DTHuesped *aux = new DTHuesped(hueAux->getNombre(), hueAux->getEmail(), hueAux->getEsFinger());
    cout << "-Nombre del huesped: " << aux->getNombre() << endl;
    cout << "-Email: " << aux->getEmail() << endl;
    delete(aux);
    }


     cout << "---------------------Listado de empleados registrados en el sistema----------------------------" << endl;
    for (itER = empleados.begin(); itER != empleados.end(); itER++){
    empleado *empAux = itER->second;
    string nomhos;
    hostal* h = empAux->getHostalTrabaja();
    DTEmpleado *aux = new DTEmpleado(empAux->getEmail(),empAux->getNombre(),"", empAux->getCargo(),empAux->getEstaSuscrito(),h);
    cout << "-Nombre del empleado: " << aux->getNombre() << endl;
    cout << "-Email: " << aux->getEmail() << endl;
    delete(aux);
    }
}



void controladorUsuario::obtenerInfoUsuario(string rol, string email){
    if(rol=="H"){
        huesped* h=findHuesped(email);
        DTHuesped * aux = new DTHuesped(h->getNombre(),h->getEmail(),h->getEsFinger());
        cout << "-Nombre del empleado: " << aux->getNombre() << endl;
        cout << "-Email: " << aux->getEmail() << endl;
        if (aux->getEsFinger())
            cout << "-Es Finger: Si" << endl;
        else
            cout << "-Es Finger: No" << endl;
    } else {
        empleado* e=findEmpleado(email);
        hostal* h= e->getHostalTrabaja();
        DTEmpleado* aux=new DTEmpleado(e->getEmail(),e->getEmail(),"",e->getCargo(),e->getEstaSuscrito(),h);

        cout << "-Nombre del empleado: " << aux->getNombre() << endl;
        cout << "-Email: " << aux->getEmail() << endl;
        cout << "-Cargo: " << aux->getCargo() << endl;
        if (h==NULL)
            cout << "-Hotel donde trabaja: aun no se le asigna un hostal" << endl;
        else 
            cout << "-Hotel donde trabaja: " << h->getNombre() << endl;
    }
}

bool controladorUsuario::obtenerEsFinger(){
        return true;
}

void controladorUsuario::obtenerInfoEmpleado(){}

empleado* controladorUsuario::obtenerEmpleado(){
    return NULL;
}

void controladorUsuario::obtenerEmpleados(string nomHostal){}

void controladorUsuario::obtenerReservasHuesped(string email){}

void controladorUsuario::obtenerHuespedes(){

    map<string,usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,usuario*> :: iterator itU; 

    map<string, huesped*> huespedes;
    map<string, huesped*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (huesped* h = dynamic_cast<huesped*>(itU->second)){
            huespedes.insert({h->getEmail(), h});
        }
    }

     cout << "---------------------Listado de usuarios registrados en el sistema----------------------------" << endl;
    for (it = huespedes.begin(); it != huespedes.end(); it++){
        huesped *hueAux = it->second;
        DTHuesped *aux = new DTHuesped(hueAux->getNombre(), hueAux->getEmail(), hueAux->getEsFinger());
        cout << "-Nombre del huesped: " << aux->getNombre() << endl;
        cout << "-Email: " << aux->getEmail() << endl;
        cout << "-Es finger: " << aux->getEsFinger() << endl;
        cout << "-------------" << endl;
        delete(aux);
    }
}

void controladorUsuario::obtenerUsuarios(){}


void controladorUsuario::obtenerEmpleados(){

    map<string,usuario*> usuarios =this->coleccionUsuarios; //coleccion de usuarios
    map<string,usuario*> :: iterator itU; 

    map<string, empleado*> empleados;
    map<string, empleado*>::iterator it;

    for (itU = this->coleccionUsuarios.begin() ; itU != this->coleccionUsuarios.end(); itU ++){
        if (empleado* e = dynamic_cast<empleado*>(itU->second)){
            empleados.insert({e->getEmail(), e});
        }
    }

    for (it = empleados.begin(); it != empleados.end(); it++){
        empleado *empAux = it->second;
        DTEmpleado *aux = new DTEmpleado(empAux->getEmail(), empAux->getNombre() , empAux->getPassword(), empAux->getCargo(),empAux->getEstaSuscrito() ,empAux->getHostalTrabaja());
        cout<< "-Nombre: "<< aux->getNombre() << endl;
        cout<< "-Email: "<< aux->getEmail() << endl;
        delete(aux);
        cout << "----------------------------"<< endl;
    }//for
}

void controladorUsuario::imprimirNotificaciones(){
    set<calificacion*> cal= this->empleadoSeleccionado->getNotificaciones();
    set<calificacion*>::iterator it= cal.begin();
    for (it = cal.begin(); it != cal.end(); it++){
        calificacion* cal= *it;
        DTCalificacion* c= new DTCalificacion(cal->getCalificacion(), cal->getId(), cal->getComentario(), "", cal->getFechaRealizacion());
        cout<< "-Calificacion: "<< c->getCalificacion() << endl;
        cout<< "-Id: "<< c->getId() << endl;
        cout<< "-Comentario: "<< c->getComentario() << endl;
        DTFecha* f= c->getFechaRealizacion();
        cout << "-Fecha de realizacion: "<< f->getDia() << "/" << f->getMes() << "/" << f->getAnio() << " a las" << f->getHora() << endl; 
        cout<< "-----------" << endl;
        delete(c);
    }
}

controladorUsuario::~controladorUsuario(){}
