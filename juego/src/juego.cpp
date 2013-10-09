//============================================================================
// Name        : juego.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "src/controller/MainController.h"
#include "src/AdministradorDeArchivos.h"
#include "src/ConstantesVista.h"

using namespace std;

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
	if(!existe_fuente || !existe_imagen_error){
		if(!existe_fuente)
			cout<<"Generador Niveles: no existe el archivo que proporciona la fuente para el text box en el directorio resource" <<endl;
		if(!existe_imagen_error)
			cout<<"Generador Niveles: no existe la imagen de error en el directorio resource" <<endl;
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
	MainController contr;
	DIR* resource = opendir("./resource");
	bool existe_fuente = false;
	bool existe_imagen_error = false;

	if (resource == NULL){
		cout << "Generador Niveles: No se encontró el directorio resource, se procede a salir de la aplicacion" <<endl;
		return -1;
	}else{
		corroborar_existencia(resource,existe_fuente,existe_imagen_error);
		if(inexistenciaDeArchivos(existe_fuente,existe_imagen_error))
			return -1;
	}

	// Carga del nivel por parametro
	if (argc > 1) {
		char * nivel = argv[1];
		AdministradorDeArchivos::registrar(nivel);
	}
	contr.run();


	return 0;
}
