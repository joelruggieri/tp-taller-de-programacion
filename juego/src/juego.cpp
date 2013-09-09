//============================================================================
// Name        : juego.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "src/controller/MainController.h"
#include "src/vista/figura/Resizer.h"

using namespace std;

int main() {
//	MainController contr;
//	contr.run();

	Resizer* unResizer = Resizer::Instance(10,10);
	unResizer->setearResizer(28,30);
	cout << unResizer->resizearDistanciaX(5);

	return 0;
}
