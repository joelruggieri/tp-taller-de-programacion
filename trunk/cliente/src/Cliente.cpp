//============================================================================
// Name        : Cliente.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "clientethread/MainClienteThread.h"
#include "src/LoggingService.h"
#include <sys/types.h>
#include <dirent.h>
using namespace std;

#define IMG_ERROR "error.jpg"

void corroborar_existencia(DIR* resource, bool& existe_fuente, bool& existe_imagen_error){
	struct dirent *ent;
	while((ent = readdir (resource)) != NULL){
		if(strcmp(ent->d_name, "Arial Bold.ttf")== 0)
				existe_fuente = true;
		std::string nombre = IMG_ERROR;
		if(strcmp(ent->d_name, nombre.c_str()) == 0)
				existe_imagen_error = true;
		if(existe_fuente && existe_imagen_error)
			break;
	}
}

bool inexistenciaDeArchivos(bool existe_fuente, bool existe_imagen_error){
	Logger log;
	if(!existe_fuente || !existe_imagen_error){
		if(!existe_fuente)
			log.fatal("No existe el archivo que proporciona la fuente para el text box en el directorio resource");
		if(!existe_imagen_error)
			log.fatal("No existe la imagen de error en el directorio resource");
		return true;
	}
	return false;
}

int main(int arg, char** argv) {
	LOG::LoggingService loggingService;
	Logger log;
	DIR* resource = opendir("./resource");
	bool existe_fuente = false;
	bool existe_imagen_error = false;
	if (resource == NULL){
		log.fatal("No se encontró el directorio resource, se procede a salir de la aplicacion");
		sleep(1);
		return -1;
	}else{
		corroborar_existencia(resource,existe_fuente,existe_imagen_error);
		if(inexistenciaDeArchivos(existe_fuente,existe_imagen_error)){
			sleep(1);
			return -1;
		}
	}

	string ip ;
	if (arg == 1) ip = "0";
	else
	ip = argv[1];
	MainClienteThread main(ip);
	main.run();
}
