/*
 * Nivel.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Nivel.h"
#include <iostream>
using namespace std;

Nivel::Nivel(std::string nombre) {
	this->nombre = nombre;
}

Nivel::~Nivel() {
	std::list<Figura*>::iterator it;
	for(it = this->objetos.begin(); it!= this->objetos.end(); ++it ){
		delete (*it);
	}

}

void Nivel::agregar(Figura* figura) {
	objetos.push_back(figura);
}

int Nivel::cantidadFiguras() const{
	return objetos.size();
}

std::list<Figura*> &Nivel::getFiguras() {
	return objetos;
}

const std::string& Nivel::getNombre() const {
	return nombre;
}

void Nivel::setNombre(const std::string& nombre) {
	this->nombre = nombre;
}

void Nivel::setFondo(std::string fondo) {
	this->fondo = fondo;
}

 std::string Nivel::getFondo() const{
	return fondo;
}

Nivel::Nivel() {
}
