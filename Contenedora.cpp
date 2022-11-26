#include "Contenedora.h"
#include "Habitacion.h"

Contenedora::Contenedora() {
	pisos= new int;
	habitaciones= new int;
	cout<<"Pisos"<<endl;
	cin>>*pisos;
	cout<<"Habitaciones"<<endl;
	cin>>*habitaciones;
	mat= new Habitacion *[*pisos];
	for(int i=0;i<*pisos;i++){
		mat[i] = new Habitacion [*habitaciones];
	}
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			mat[i][j].getEstado();
		}
	}
}

Contenedora::~Contenedora() {
	delete pisos; delete habitaciones;
	for(int i=0; i<*pisos;i++){
		delete [] mat[i];
	}
	delete[] mat;
}

void Contenedora::reportes(){
	
	int opc;
	
	while(opc!=9){
		
		system("cls");
		
		cout<<"---REPORTES---"<<endl;
		cout<<endl;
		cout<<"1-Numero de habitaciones libres"<<endl;
		cout<<"2-Numero de habitaciones en mantenimiento"<<endl;
		cout<<"3-Numero de habitaciones ocupadas"<<endl;
		cout<<"4-Reservar habitacion"<<endl;
		cout<<"5-Liberar habitacion"<<endl;
		cout<<"6-Cantidad de adultos en el hotel"<<endl;
		cout<<"7-Cantidad de ninnos en el hotel"<<endl;
		cout<<"8-Recaudacion del hotel (sub-menu)"<<endl;
		cout<<"9-Salir"<<endl;
		cin>>opc;
		
		if(opc==1){
			cout<<"Habitaciones libres: "<<libres()<<endl;
			system("pause");
		}else if(opc==2){
			cout<<"Habitaciones en mantenimiento: "<<mantenimiento()<<endl;
			system("pause");
		}else if(opc==3){
			cout<<"Habitaciones ocupadas: "<<ocupadas()<<endl;
			system("pause");
		}else if(opc==4){
			ingresar();
			system("pause");
		}else if(opc==5){
			int *p= new int;
			int *h= new int;
			for(int i=0;i<*pisos;i++){
				for(int j=0;j<*habitaciones;j++){
					cout<<" "<<mat[i][j].getEstado();
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<"Digite el piso de la habitacion"<<endl;
			cin>>*p;
			cout<<"Digite el numero de habitacion"<<endl;
			cin>>*h;
			if(mat[*p][*h].getEstado()=='O'){
			mat[*p][*h].liberar();
			}else{
				cout<<"Lo sentimos este cuarto aun no ha sido reservado"<<endl;
			}
			system("pause");
		}else if(opc==6){
			cout<<"Adultos totales: "<<adultos()<<endl;
			system("pause");
		}else if(opc==7){
			cout<<"Ninnos totales: "<<ninnos()<<endl;
			system("pause");
		}else if(opc==8){
			cout<<recaudacion()<<" Dolares "<<endl;
			system("pause");
		}else if(opc==9){
			cout<<"Saliendo..."<<endl;
			system("pause");
		}else{
			cout<<"Comando desconocido"<<endl;
			system("pause");
		}
		
	}
	
}

int Contenedora::libres(){
	int suma=0;
	
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			if(mat[i][j].getEstado()=='L'){
				suma++;
			}
		}
	}
	
	return suma;
}
int Contenedora::mantenimiento(){
	int suma=0;
	
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			if(mat[i][j].getEstado()=='M'){
				suma++;
			}
		}
	}
	
	return suma;
	
}

int Contenedora::ocupadas(){
	int suma=0;
	
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			if(mat[i][j].getEstado()=='O'){
				suma++;
			}
		}
	}
	
	return suma;
}

void Contenedora::ingresar(){
	
	int *ocup= new int;
	int *hora= new int;
	
	cout<<"Ingrese cuantas personas van a ocupar la habitacion"<<endl;
	cin>>*ocup;
	cout<<"Habitaciones libres"<<endl;
	cout<<libres()<<endl;
	cout<<"Habitaciones"<<endl;
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			cout<<" "<<mat[i][j].getEstado();
		}
		cout<<endl;
	}
	cout<<endl;
	
    cout<<"Ingrese la habitacion que desea reservar"<<endl;
	
	int *p= new int;
	int *h= new int;
	
	cout<<"Piso"<<endl;
	cin>>*p;
	cout<<"Numero de Habitacion"<<endl;
	cin>>*h;
	
	if(mat[*p][*h].getEstado()=='L'){
	
	cout<<"Digite la hora de entrada al hotel"<<endl;
	cin>>*hora;
	
	mat[*p][*h].setEntrada(hora);
	mat[*p][*h].setOcupacion(ocup);
	mat[*p][*h].registro();
	
	}else{
	cout<<"Disculpe esta habitacion ya se encuentra reservada o esta en mantenimiento"<<endl;
	}
	
	delete p;
	delete h;
	
}

int Contenedora::adultos(){
	int *totala= new int;
	*totala=0;
	
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			*totala+=mat[i][j].AT();
		}
	}
	
	
	return *totala;
	
}

int Contenedora::ninnos(){
	
	int *totaln= new int;
	*totaln=0;
	
	for(int i=0;i<*pisos;i++){
		for(int j=0;j<*habitaciones;j++){
			*totaln+=mat[i][j].NT();
		}
	}
	
	
	return *totaln;

}

float Contenedora::recaudacion(){
	
	int opc;
	
	float *total= new float;
	*total=0;
	float *totalI= new float;
	*totalI=0;
	float *totalNI= new float;
	*totalNI=0;
	
	cout<<"Seleccione una opcion"<<endl;
	cout<<"1-Clientes TODO INCLUIDO"<<endl;
	cout<<"2-Cliente sin TODO INCLUIDO"<<endl;
	cout<<"3-Todos los clientes"<<endl;
	
	cin>>opc;
	
	if(opc==1){
		
		for(int i=0;i<*pisos;i++){
			for(int j=0;j<*habitaciones;j++){
				*total+=mat[i][j].recaudarI();
				*totalI+=mat[i][j].recaudarI();
			}
		}
		
		return *totalI;
		
	}else if(opc==2){
		
		for(int i=0;i<*pisos;i++){
			for(int j=0;j<*habitaciones;j++){
				*total+=mat[i][j].recaudarNI();
				*totalNI+=mat[i][j].recaudarNI();
			}
		}
	
		return *totalNI;
		
	}else if(opc==3){
		
		for(int i=0;i<*pisos;i++){
			for(int j=0;j<*habitaciones;j++){
				*total+=mat[i][j].costo();
			}
		}
		
		return *total;
		
	}else{
	    cout<<"Comando desconocido"<<endl;
	}
	
}
