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

Archivo* AdministradorDeArchivos::obtenerArchivoNivel(const std::string &nombre) {
	return obtenerArchivoNivel(nombre.c_str());
}

Archivo* AdministradorDeArchivos::obtenerArchivoNivel(const char *nombre) {
	std::list<Archivo*>::iterator it;
	std::string nombreArchivoBuscado = nombre;
	nombreArchivoBuscado += ".yaml";
	for (it = archivos.begin(); it != archivos.end(); ++it){
		Archivo *archivo = *it;
		if (archivo->getNombre().compare(nombreArchivoBuscado) == 0) {
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

Archivo* AdministradorDeArchivos::crearArchivoNivel(const char* numero) {
	std::string streamAux = numero;
	streamAux.append(".yaml");
	Archivo *nuevo = new Archivo(streamAux.c_str(), ESCRITURA);
	AdministradorDeArchivos::archivos.push_back(nuevo);
	return nuevo;
}

void AdministradorDeArchivos::registrar(std::string nombre) {

	std::list<Archivo*>::iterator it;
	for (it = archivos.begin(); it != archivos.end(); ++it){
		Archivo *archivo = *it;
		if (archivo->getNombre().compare(nombre) == 0) {
			// El archivo ya existe
			return;
		}
	}

	Archivo *nuevo = new Archivo(nombre.c_str(), LECTOESCRITURA);
	AdministradorDeArchivos::archivos.push_back(nuevo);
}
