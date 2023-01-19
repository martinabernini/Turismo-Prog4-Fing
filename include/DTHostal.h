#ifndef DTHOSTAL
#define DTHOSTAL

#include <string>
using namespace std;

class DTHostal{
    private:
        string nombre;
        string direccion;
        string telefono;

    public:
        DTHostal(string nombre, string direccion, string telefono);
        string getNombre();
        string getDireccion();
        string getTelefono();
        ~DTHostal();
};

#endif