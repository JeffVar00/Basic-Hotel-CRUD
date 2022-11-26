#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>

using namespace std;

class Cliente {
public:
	Cliente();
	Cliente(string *nombre, int *cedula, string *pago, int *cuenta, int *telefono);
	virtual ~Cliente();
	void setNombre(string *nombre);
	void setCedula(int *cedula);
	void setPago(string *pago);
	void setCuenta(int *cuenta);
	void setTelefono(int *telefono);
	string getNombre();
	int getCedula();
	string getPago();
	int getCuenta();
	int getTelefono();
	void datos();
private:
	string *nombre;
	int *cedula;
	string *pago;
    int *cuenta;
	int *telefono;
};

#endif

