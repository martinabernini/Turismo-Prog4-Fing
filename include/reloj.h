#ifndef RELOJ
#define RELOJ

#include "DTFecha.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class reloj
{
private:
    
    static reloj *instancia;
    ~reloj();
    reloj(int diaN, int mesN, int anioN, int horaN, int minutoN);

    // Atributos
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

public:
    static reloj *getInstancia();
    static void releaseInstancia();
    
    // Getters
    int getDia();
    int getMes();
    int getAnio();
    int getHora();
    int getMinuto();
    // Setters
    void setReloj(int diaN, int mesN, int anioN, int horaN, int minutoN);
    DTFecha* getReloj();
};

#endif