#ifndef CONTENEDORA_H
#define CONTENEDORA_H
#include "Habitacion.h"
#include <iostream>

using namespace std;

class Contenedora {
public:
	Contenedora();
	virtual ~Contenedora();
	void reportes();
	int libres();
	int mantenimiento();
	int ocupadas();
	void ingresar();
	float recaudacion();
	int ninnos();
	int adultos();
private:
	Habitacion **mat;
	int *pisos;
	int *habitaciones;
};

#endif

