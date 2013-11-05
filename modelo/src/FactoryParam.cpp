/*
 * FactoryParam.cpp
 *
 *  Created on: 05/11/2013
 *      Author: joel
 */

#include "FactoryParam.h"

FactoryParam::FactoryParam() {

}

FactoryParam::FactoryParam(const FactoryParam& factory){
	this->nombre = factory.nombre;
	this->cantDisponible = factory.getCantidad();
}

void FactoryParam::setNombre(std::string nombre){
	this->nombre = nombre;
}

std::string FactoryParam::getNombre() const{
	return this->nombre;
}

void FactoryParam::setCantidad(int numero){
	this->cantDisponible = numero;
}

int FactoryParam::getCantidad() const{
	return this->cantDisponible;
}


FactoryParam::~FactoryParam() {
	// TODO Auto-generated destructor stub
}

