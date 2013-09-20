/*
 * Archivo.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Archivo.h"
#include <iostream>

Archivo::Archivo(const char* nombre, TIPO tipo) {
	this->nombre = nombre;
	if (tipo == LECTURA) {
		archivo.open(nombre, std::ios::in);
		if (! archivo.is_open()){
			// El archivo no existe, se creara vacio.
			archivo.open(nombre, std::ios::in | std::ios::trunc);
		}
	} else if (tipo == ESCRITURA){
		archivo.open(nombre, std::ios::out | std::ios::trunc);
		if (! archivo.is_open()){
			throw std::exception();
		}
	} else if (tipo == APPEND){
		archivo.open(nombre, std::ios::out | std::ios::app);
		if (! archivo.is_open()){
			// El archivo no existe, se creara vacio.
			archivo.open(nombre, std::ios::out | std::ios::trunc);
		}
	}
}

void Archivo::escribir(std::string dato) {
	archivo << dato.c_str() << "\n";
}

std::string Archivo::leer(){
	std::string linea = "";
	archivo >> linea;
	return linea;
}

Archivo::~Archivo() {
//	if (archivo.is_open() ) archivo.close();
}

std::string Archivo::getNombre(){
	return nombre;
}

YAML::Node Archivo::obtenerNodo(std::string nombreNodo) {
	YAML::Node objetos = YAML::LoadFile(this->nombre.c_str());
	return objetos[nombreNodo];
}

void Archivo::sobreescribir(YAML::Node &nodo) {
//	archivo.open(nombre.c_str(), std::ios::out | std::ios::trunc);
	YAML::Emitter out;
	out << nodo;
	archivo << out.c_str();
}



void Archivo::cerrar() {
	archivo.close();
}
