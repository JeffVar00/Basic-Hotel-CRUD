#include<iostream>
#include "Contenedora.h"


using namespace std;

int main () {
	
	Contenedora *a= new Contenedora();

	a->reportes();
	
	delete a;
	
	return 0;
}

