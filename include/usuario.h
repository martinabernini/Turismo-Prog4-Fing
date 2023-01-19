#ifndef USUARIO
#define USUARIO

#include <string>
using namespace std;

class usuario {
    private:
        string email;
        string nombre;
        string password;
    public:
        usuario(); 
        usuario(string email, string nombre, string password);
        string getEmail();
        string getNombre();
        string getPassword();  
        void setEmail(string email);
        void setNombre(string nombre);
        void setPassword(string password);
        virtual ~usuario(){};  
};
#endif