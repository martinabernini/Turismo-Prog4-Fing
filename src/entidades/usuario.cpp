#include "../../include/usuario.h"
     
usuario::usuario(){
    this->email = "";
    this->nombre = "";
    this->password = "";
}

usuario::usuario(string email, string nombre, string password) {
  this->email = email;
  this->nombre = nombre;
  this->password = password;
};
     
string usuario::getEmail(){
 return this->email;
}

string usuario::getNombre(){
return this->nombre;
}

 string usuario::getPassword(){
 return this->password;
    }  
       
void usuario::setEmail(string email){
    this->email = email;
}
void usuario::setNombre(string nombre){
    this->nombre = nombre;
}
void usuario::setPassword(string password){
    this->password = password;
}