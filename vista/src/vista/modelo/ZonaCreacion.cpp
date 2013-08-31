/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "DropeableFactory.h"

ZonaCreacion::ZonaCreacion(Cuerpo cuerpo) :
		ZonaDragAndDrop(cuerpo) {
	Cuerpo cuerpo1(30, 30, 60, 60);
	Cuerpo cuerpo2(95, 30, 60, 60);
	Cuerpo cuerpo3(200, 100, 100, 100);
	DropeableFactory * factory1 = new DropeableFactory("A");
	DropeableFactory * factory2 = new DropeableFactory("B");
	DropeableFactory * factory3 = new DropeableFactory("JONY");
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	this->agregarEslabon(new EslabonCreacion(factory1, cuerpo1, 1));
	this->agregarEslabon(new EslabonCreacion(factory2, cuerpo2, 1));
	this->agregarEslabon(new EslabonCreacion(factory3, cuerpo3, 1));
}

bool ZonaCreacion::dropTemplate(Dropeable* dragueable) {
	return false;

}

Dropeable* ZonaCreacion::dragTemplate(float x, float y) {
	return this->inicioCadena->antender(x, y);
}

ZonaCreacion::~ZonaCreacion() {
	delete this->inicioCadena;
}

void ZonaCreacion::agregarEslabon(EslabonCreacion* eslabon) {
	if (this->inicioCadena == NULL) {
		this->inicioCadena = eslabon;
		this->ultimo = eslabon;
	} else {
		this->ultimo->setSiguiente(eslabon);
		this->ultimo = eslabon;
	}
}
