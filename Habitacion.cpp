#include "Habitacion.h"
#include "Cliente.h"
#include "informacion.h"

Habitacion::Habitacion() {
	c= new Cliente();
	i= new Informacion();
	ocupacion= new int;
	*ocupacion=0;
	estado= new char;
	*estado='L';
	id= new string();
	entrada= new int;
	*entrada=0;
}
Habitacion::Habitacion(Cliente *c, Informacion *i,int *ocupacion, char *estado, string *id, int *entrada){
	this->ocupacion=ocupacion;
	this->estado=estado;
	this->id=id;
	this->entrada=entrada;
}
Habitacion::~Habitacion() { delete ocupacion; delete estado; delete id; }

void Habitacion::setOcupacion(int *ocupacion){this->ocupacion=ocupacion;}
void Habitacion::setEstado(char *estado){this->estado=estado;}
void Habitacion::setId(string *id){this->id=id;}
void Habitacion::setEntrada(int *entrada){this->entrada=entrada;}

int Habitacion::getOcupacion(){return *ocupacion;}
char Habitacion::getEstado(){return *estado;}
string Habitacion::getId(){return *id;}
int Habitacion::getEntrada(){return *entrada;}

void Habitacion::registro(){
	
	c->datos();
	i->info();
	*estado='O';
	cout<<"El monto a pagar por esta habitacion es de: "<<costo()<<" dolares"<<endl;

}

void Habitacion::liberar(){
	int *vaciar= new int;
	*vaciar=0;
	int ced;
	cout<<"Digite su numero de cedula"<<endl;
	cin>>ced;
	if(ced==c->getCedula()){
		cout<<"El costo por esta habitacion fue de: "<<costo()<<endl;
		cout<<"Gracias por venir!!!"<<endl;
		i->setAdultos(vaciar);
		i->setNinnos(vaciar);
		i->setDias(vaciar);
		c->setCedula(vaciar);
		*ocupacion=0;
		*estado='L';
	}else{
		cout<<"Lo sentimos su numero de cedula no es igual a la registrada en esta habitacion"<<endl;
	}
	
	delete vaciar;
	
}
float Habitacion::costo(){
	
	float *monto=new float;
	*monto=0.0;
	float *descuento= new float;
	*descuento=0.0;
	float incluidoN=200.00, incluidoA=300.00, uno=150.00, dos=250.00, tres=350.00, varios=400.00;
	
	if(i->getPaquete()==true){
		for(int j=0;j<i->getAdultos();j++){
		    *monto+=i->getDias() * incluidoA;
		}
		if(i->getNinnos()>0){
		   for(int j=0;j<i->getNinnos();j++){
			*monto+=i->getDias() * incluidoN;
		   }
		}
		return *monto;
		
	}else{
		if(*ocupacion==1){
			*monto+=i->getDias() * uno;
			if(*entrada>=6 && *entrada<=12){
				*descuento=*monto*0.25;
				*monto-=*descuento;
			}
			return *monto;
		}else if(*ocupacion==2){
			*monto+=i->getDias() * dos;
			if(*entrada>=6 && *entrada<=12){
				*descuento=*monto*0.20;
				*monto-=*descuento;
			}
			return *monto;
	    }else if(*ocupacion==3){
			*monto+=i->getDias() * tres;
			if(*entrada>=6 && *entrada<=12){
				*descuento=*monto*0.15;
				*monto-=*descuento;
			}
			return *monto;
	    }else if(*ocupacion>3){
			*monto+=i->getDias() * varios;
			if(*entrada>=6 && *entrada<=12){
				*descuento=*monto*0.10;
				*monto-=*descuento;
			}
			return *monto;
	    }else{
			return *monto=0.0;
		}
	}
	
	delete descuento;
	
}


int Habitacion::AT(){ return i->getAdultos() ;}
int Habitacion::NT(){ return i->getNinnos() ;}

float Habitacion::recaudarNI(){ 
	
	if(i->getPaquete()!=true){
		return costo();
	}else{
		return 0;
	}
	
}

float Habitacion::recaudarI(){ 
	
	if(i->getPaquete()==true){
	return costo();
	}else{
    return 0;
	}
}

