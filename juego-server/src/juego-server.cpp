//============================================================================
// Name        : juego-server.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;



//#include "src/controller/MainController.h"
#include "src/AdministradorDeArchivos.h"
#include "src/servidor/MainServerThread.h"
#include "src/LoggingService.h"
#include "src/ConexionException.h"
#include "src/Logger.h"
int main(int argc, char *argv[]) {

	LOG::LoggingService servicioLog;
	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		AdministradorDeArchivos::registrar(nivel);
	}
	string nivel = argv[1];
	MainServerThread contr(nivel.c_str());
	try{

	contr.run();
	}catch (ConexionException & e) {
//		log.error("No se ha podido realizar la partida por un problema de conexion");
	}



}
