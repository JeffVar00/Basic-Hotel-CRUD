#ifndef HABITACION_H
#define HABITACION_H
#include "Cliente.h"
#include "Informacion.h"
#include <iostream>

using namespace std;

class Habitacion {
public:
	Habitacion();
	Habitacion(Cliente *c, Informacion *i, int *ocupacion, char *estado, string *id, int *entrada);
	virtual ~Habitacion();
	void setOcupacion(int *ocupacion);
	void setEstado(char *estado);
	void setId(string *id);
	void setEntrada(int *entrada);
	int getOcupacion();
	char getEstado();
	string getId();
	int getEntrada();
	void registro();
	void liberar();
	float costo();
	int AT();
	int NT();
	float recaudarNI();
	float recaudarI();
	
private:
	Cliente *c;
	Informacion *i;
	int *ocupacion;
	char *estado;
	string *id;
	int *entrada;
};

#endif

