#ifndef INFORMACION_H
#define INFORMACION_H
#include <iostream>

using namespace std;

class Informacion {
public:
	Informacion();
	Informacion(int *dias, int *adultos, int *ninnos, bool *paquete);
	virtual ~Informacion();
	void setDias(int *dias);
	void setAdultos(int *adultos);
	void setNinnos(int *ninnos);
	void setPaquete(bool *paquete);
	int getDias();
	int getAdultos();
    int getNinnos();
	bool getPaquete();
	void info();
private:
	int *dias;
	int *adultos;
	int *ninnos;
	bool *paquete;
};

#endif

