#ifndef HUESPED
#define HUESPED

#include <string>
#include "usuario.h"
using namespace std;

class huesped : public usuario{
    private:
        bool esFinger;
    public:
        huesped();
        huesped(string email, string nombre, string password, bool esFinger);
        bool getEsFinger();
        void setEsFinger(bool esFinger);
        ~huesped();
};
#endif