#include <iostream>
using namespace std;
#include "vista/modelo/ModeloVista.h"
int main() {
	DropManager manager;
	Dropeable * drop1= manager.drag(30,30);
	cout << "Crea un item: " << drop1->getModelo() << " En ("<< drop1->getPosX() <<","<< drop1->getPosY() << ")"<<endl;
	delete drop1;
	drop1= manager.drag(95,30);
	cout << "Crea un item: " << drop1->getModelo() << " En ("<< drop1->getPosX() <<","<< drop1->getPosY() << ")"<<endl;
	delete drop1;

	drop1= manager.drag(160,55);
	cout << "Crea un item: " << drop1->getModelo() << " En ("<< drop1->getPosX() <<","<< drop1->getPosY() << ")"<<endl;
	delete drop1;

	drop1= manager.drag(30,30);
	cout << "Crea un item: " << drop1->getModelo() << " En ("<< drop1->getPosX() <<","<< drop1->getPosY() << ")"<<endl;
	delete drop1;

	drop1 = manager.drag(200,200);
	if(drop1 == NULL){
		cout << "click en espacio vacio";
	}
	return 0;
}
