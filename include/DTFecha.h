#ifndef DTFECHA
#define DTFECHA

#include <iostream>
#include <time.h>
using namespace std;

class DTFecha{

	private:
		int dia;
		int mes;
		int anio;
		int hora;
		int minuto;

	public:
		DTFecha();
		DTFecha(int diaN, int mesN,	int anioN, int horaN, int minutoN);
		~DTFecha();

		int getDia();
		int getMes();
		int getAnio();
		int getHora();
		int getMinuto();
		//bool DTFecha::operator<(DTFecha f1);
		bool esMayor(DTFecha *f);
		friend bool operator<(DTFecha &f1, DTFecha &f2);
		friend ostream& operator<< (ostream& out, DTFecha& dtfh);
		friend int operator-(DTFecha &f1, DTFecha &f2);
		void imprimirFecha();
};

#endif
