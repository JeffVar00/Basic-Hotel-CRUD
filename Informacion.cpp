#include "Informacion.h"

Informacion::Informacion() {
   dias= new int;
   *dias=0;
   adultos= new int;
   *adultos=0;
   ninnos= new int;
   *ninnos=0;
   paquete= new bool;
   *paquete= false;
}
Informacion::Informacion(int *dias, int *adultos, int *ninnos, bool *paquete){
   this->dias=dias;
   this->adultos=adultos;
   this->ninnos=ninnos;
   this->paquete=paquete;
}
Informacion::~Informacion() {delete dias; delete adultos; delete ninnos; delete paquete;}

void Informacion::setDias(int *dias){this->dias=dias;}
void Informacion::setAdultos(int *adultos){this->adultos=adultos;}
void Informacion::setNinnos(int *ninnos){this->ninnos=ninnos;}
void Informacion::setPaquete(bool *paquete){this->paquete=paquete;}

int Informacion::getDias(){return *dias;}
int Informacion::getAdultos(){return *adultos;}
int Informacion::getNinnos(){return *ninnos;}
bool Informacion::getPaquete(){return *paquete;}

void Informacion::info(){
	
	string *opc= new string;
	
	cout<<"---Informacion general---"<<endl;
	cout<<endl;
	cout<<"Digite la cantidad de dias de su estadia"<<endl;
	cin>>*dias;
	cout<<"Digite el numero de adultos"<<endl;
	cin>>*adultos;
	cout<<"Si tiene ninnos, digite cuantos se quedaran, si no es el caso digite 0"<<endl;
	cin>>*ninnos;
	cout<<"Desea adquirir el parquete todo incluido? Digite 'si' o 'no' "<<endl;
	cin>>*opc;
	if(*opc=="si"){
		*paquete=true;
	}
	
}
