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

#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[]) {

	LOG::LoggingService servicioLog;
	Logger::setNivel(INFO_N);
	Logger log;
	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		struct dirent *ent;
		bool encontrado = false;
		DIR* resource = opendir("./");
		while((ent = readdir (resource)) != NULL){
			if(strcmp(ent->d_name, nivel)== 0){
				encontrado = true;
				break;
			}
		}
		if (encontrado)
			AdministradorDeArchivos::registrar(nivel);
		else{
			log.fatal("No existe el archivo yaml del nivel especificado");
			sleep(1);
			return -1;
		}
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
