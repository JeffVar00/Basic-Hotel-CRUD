#include "Cliente.h"

Cliente::Cliente() {
   nombre=new string();
   cedula= new int; 
   pago= new string(); 
   cuenta= new int; 
   telefono= new int;
}
Cliente::Cliente(string *nombre, int *cedula, string *pago, int *cuenta, int *telefono){
   this->nombre=nombre; 
   this->cedula=cedula;
   this->pago=pago;
   this->cuenta=cuenta; 
   this->telefono=telefono;
}

Cliente::~Cliente() { delete nombre; delete cedula; delete pago; delete cuenta; delete telefono; }

void Cliente::setNombre(string *nombre){this->nombre=nombre;}
void Cliente::setCedula(int *cedula){this->cedula=cedula;}
void Cliente::setPago(string *pago){this->pago=pago;}
void Cliente::setCuenta(int *cuenta){this->cuenta=cuenta;}
void Cliente::setTelefono(int *telefono){this->telefono=telefono;}

string Cliente::getNombre(){return *nombre;}
int Cliente::getCedula(){return *cedula;}
string Cliente::getPago(){return *pago;}
int Cliente::getCuenta(){return *cuenta;}
int Cliente::getTelefono(){return *telefono;}

void Cliente::datos(){
	
	cout<<"---Datos Personales---"<<endl;
	cout<<endl;
	cout<<"Digite su nombre"<<endl;
	cin.ignore();
	getline(cin,*nombre);
	cout<<"Digite su numero de cedula"<<endl;
	cin>>*cedula;
	cout<<"Digite su metodo de pago"<<endl;
	cin.ignore();
	getline(cin,*pago);
	cout<<"Digite su numero de cuenta"<<endl;
	cin>>*cuenta;
	cout<<"Digite su numero de telefono"<<endl;
	cin>>*telefono;
}
