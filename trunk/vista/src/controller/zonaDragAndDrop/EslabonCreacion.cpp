/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
#include "../Resizer.h"
#include "src/Logger.h"
using namespace std;
namespace CLIENTE {
EslabonCreacion::EslabonCreacion(string tag, Cuadrado * cuerpo) {
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
	this->tag = tag;
}
//
EslabonCreacion::~EslabonCreacion() {
	if (this->siguiente != NULL)
		delete this->siguiente;
	delete this->cuerpo;
}
//
void EslabonCreacion::setSiguiente(EslabonCreacion* sig) {
	this->siguiente = sig;
}
//
string EslabonCreacion::atender(float posX, float posY, float corrimientoScroll) {

	if (this->cuerpo->contacto(posX, posY)) {
		Logger log;
		log.debug("Se llama a factory de vista");
		return tag;
	}
	if (this->siguiente != NULL) {
		return this->siguiente->atender(posX, posY, corrimientoScroll);
	}
	return "";
}
}
