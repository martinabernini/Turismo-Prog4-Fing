#ifndef DTHUESPED
#define DTHUESPED

#include <string>
using namespace std;

class DTHuesped{
private:
  string nombre;
  string email;
  bool esFinger;

public:
  DTHuesped(string nombre, string email, bool esFinger); // constructor
  // getters si, setters no tiene, hay q crear nuevos
  string getNombre();
  string getEmail();
  bool getEsFinger();
  ~DTHuesped();
};




#endif 