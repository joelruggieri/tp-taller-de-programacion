//============================================================================
// Name        : juego.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "src/controller/MainController.h"
#include "src/AdministradorDeArchivos.h"

using namespace std;

int main(int argc, char *argv[]) {
	MainController contr;
	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		AdministradorDeArchivos::registrar(nivel);
	}
	contr.run();


	return 0;
}
