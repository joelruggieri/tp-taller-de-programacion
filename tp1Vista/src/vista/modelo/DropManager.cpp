/*
 * DropManager.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "DropManager.h"

DropManager::DropManager() {
	Cuerpo cuerpo(30, 30, 60, 60);
	Cuerpo cuerpo2(95, 30, 60, 60);
	Cuerpo cuerpo3(200, 100, 100, 100);
	DropeableFactory * factory1 = new DropeableFactory("A");
	DropeableFactory * factory2 = new DropeableFactory("B");
	DropeableFactory * factory3 = new DropeableFactory("JONY");
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	this->agregarEslabon(new EslabonCreacion (factory1, cuerpo));
	this->agregarEslabon(new EslabonCreacion (factory2, cuerpo2));
	this->agregarEslabon(new EslabonCreacion (factory3, cuerpo3));

}

Dropeable* DropManager::drag(float x, float y) {
	return this->inicioCadena->antender(x,y);
}

DropManager::~DropManager() {
	delete this->inicioCadena;
}

void DropManager::agregarEslabon(EslabonCreacion* eslabon) {
	if(this->inicioCadena == NULL){
		this->inicioCadena = eslabon;
		this->ultimo = eslabon;
	} else {
		this->ultimo->setSiguiente(eslabon);
		this->ultimo = eslabon;
	}
}
