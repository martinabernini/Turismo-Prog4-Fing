#include "../include/reloj.h"
#include "../include/DTFecha.h"

#include <iostream>
using namespace std;
#include <iomanip> 

reloj::reloj(int diaN, int mesN, int anioN, int horaN, int minutoN) {
    this->dia = diaN;
    this->mes = mesN;
    this->anio = anioN;
    this->hora = horaN;
    this->minuto = minutoN;
};

reloj *reloj::instancia = NULL;

reloj *reloj::getInstancia(){
    if (instancia == NULL){
        instancia = new reloj(20, 6, 2022, 15, 0);
    };
    return instancia;
};

void reloj::releaseInstancia() {
    if ( instancia != NULL) {
        delete instancia;
        instancia = NULL;
    };
}

reloj::~reloj() {
};

int reloj::getDia() {
    return this->dia;
};

int reloj::getMes() {
    return this->mes;
};

int reloj::getAnio() {
    return this->anio;
};

int reloj::getHora() {
    return this->hora;
};

int reloj::getMinuto() {
    return this->minuto;
};

void reloj::setReloj(int diaN, int mesN, int anioN, int horaN, int minutoN) {
    this->dia = diaN;
    this->mes = mesN;
    this->anio = anioN;
    this->hora = horaN;
    this->minuto = minutoN;
};

DTFecha* reloj::getReloj() {
    DTFecha* res = new DTFecha(this->dia, this->mes, this->anio, this->hora, this->minuto);
    return res;
};


