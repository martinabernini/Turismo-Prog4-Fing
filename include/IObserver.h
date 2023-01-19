#ifndef IOBSERVER
#define IOBSERVER
#include "calificacion.h"

class IObserver{
    public:
        IObserver() {};
        virtual void notify(calificacion *cal)=0;
        virtual void getNombresito()=0;
        ~IObserver() {};
};

#endif