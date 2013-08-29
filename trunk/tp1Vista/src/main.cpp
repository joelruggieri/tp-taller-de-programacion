#include <iostream>
using namespace std;
#include "vista/modelo/ModeloVista.h"
int main() {

	Cuerpo cuerpo(30, 30, 60, 60);
	Cuerpo cuerpo2(95, 30, 60, 60);
	DropeableFactory * factory1 = new DropeableFactoryA();
	DropeableFactory * factory2 = new DropeableFactoryB();
	EslabonCreacion eslabon1(factory1, cuerpo);
	EslabonCreacion * eslabon2 = new EslabonCreacion(factory2, cuerpo2);
	eslabon1.setSiguiente(eslabon2);
	Dropeable * drop1= eslabon1.antender(30,30);
	cout << "Crea un item: " << drop1->getModelo() << endl;
	delete drop1;
	drop1= eslabon1.antender(95,30);
	cout << "Crea un item: " << drop1->getModelo() << endl;
	delete drop1;
	drop1 = eslabon1.antender(200,200);
	if(drop1 == NULL){
		cout << "click en espacio vacio";
	}
	return 0;
}
