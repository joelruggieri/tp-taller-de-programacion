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
	} else if (tipo == ESCRITURA){
		archivo.open(nombre, std::ios::out);
	} else if (tipo == APPEND){
		archivo.open(nombre, std::ios::out | std::ios::app);
	}
	if (! archivo.is_open()){
		throw "Error al abrir archivo";
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
	if (archivo.is_open() ) archivo.close();
}

std::string Archivo::getNombre(){
	return nombre;
}

YAML::Node Archivo::obtenerNodo(std::string nombreNodo) {
	YAML::Node objetos = YAML::LoadFile(this->nombre.c_str());
	return objetos[nombreNodo];
}

void Archivo::sobreescribir(YAML::Node nodo) {
	if (archivo.is_open()) archivo.close();
	archivo.open(nombre.c_str(), std::ios::out | std::ios::trunc);
	archivo << nodo;
	archivo.close();
}

Archivo::Archivo(const Archivo& a) {
	this->nombre = a.nombre;
	this->archivo.open(a.nombre.c_str());
}

void Archivo::cerrar() {
	archivo.close();
}
