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
#include "src/NivelInexistenteException.h"
int main(int argc, char *argv[]) {

	LOG::LoggingService servicioLog;
	Logger log;
	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		AdministradorDeArchivos::registrar(nivel);
	}
	string nivel = argv[1];
	try {
		MainServerThread contr(nivel.c_str());
		contr.run();
	} catch (ConexionException & e) {
		log.error("No pudo inicializarse el servidor, ha habido un error de conexion local");
	} catch (NivelInexistenteException & e){
		log.error("No pudo inicializarse el servidor, no existe el archivo de nivel");
	}
	sleep(1);
}
