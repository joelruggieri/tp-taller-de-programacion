/*
 * AdministradorDeArchivos.cpp
 *
 *  Created on: 07/09/2013
 *      Author: javier
 */

#include "AdministradorDeArchivos.h"
#include <sstream>
#include <list>

std::list<Archivo*> AdministradorDeArchivos::archivos;
std::list<int> AdministradorDeArchivos::niveles;


AdministradorDeArchivos::~AdministradorDeArchivos() {
	// TODO Auto-generated destructor stub
}


void AdministradorDeArchivos::cargar(){
	if (AdministradorDeArchivos::archivos.size() == 0) {
		AdministradorDeArchivos::archivos.push_back(new Archivo("nivel01", LECTURA));
		AdministradorDeArchivos::niveles.push_back(1);
	}
}

Archivo* AdministradorDeArchivos::obtenerArchivoNivel(int numero) {
	AdministradorDeArchivos::cargar();
	std::list<Archivo*>::iterator it;
	for (it = archivos.begin(); it != archivos.end(); ++it){
		std::string sNumeroNivel = (*it)->getNombre().substr(5,2);
		std::stringstream streamAux;
		streamAux << sNumeroNivel;
		int numeroNivel = 0;
		streamAux >> numeroNivel;
		if (numero == numeroNivel) {
			return *it;
		}
	}
	return NULL;
}

AdministradorDeArchivos::AdministradorDeArchivos() {

}

void AdministradorDeArchivos::cerrarTodo() {
	std::list<Archivo*>::iterator it;
	for (it = archivos.begin(); it != archivos.end(); ++it){
		Archivo *a = *it;
		delete a;
	}
}
