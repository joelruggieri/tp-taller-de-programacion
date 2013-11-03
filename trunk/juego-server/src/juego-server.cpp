//============================================================================
// Name        : juego-server.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



#include "src/controller/MainController.h"
#include "src/AdministradorDeArchivos.h"
#include "src/servidor/MainServerThread.h"
#include "src/LoggingService.h"
int main(int argc, char *argv[]) {

	LOG::LoggingService servicioLog;
	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		AdministradorDeArchivos::registrar(nivel);
	}
	MainServerThread contr;
	contr.run();

}
