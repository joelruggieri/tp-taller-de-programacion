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


AdministradorDeArchivos::~AdministradorDeArchivos() {
	// TODO Auto-generated destructor stub
}

/* En este metodo debemos declarar todos los archivos de nivel que existen.
 * Tambien se podira buscar todos los archivos ".yaml" de
 * alguna carpeta y cargarlos aca. */
void AdministradorDeArchivos::cargar(){
	if (AdministradorDeArchivos::archivos.size() == 0) {
		AdministradorDeArchivos::archivos.push_back(new Archivo("nivel1.yaml", LECTURA));
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
	return AdministradorDeArchivos::crearArchivoNivel(numero);
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

Archivo* AdministradorDeArchivos::crearArchivoNivel(int numero) {
	std::stringstream streamAux;
	streamAux << "nivel" << numero << ".yaml";
	Archivo *nuevo = new Archivo(streamAux.str().c_str(), ESCRITURA);
	AdministradorDeArchivos::archivos.push_back(nuevo);
	return nuevo;
}
