/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"

ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories) :
		ZonaDragAndDrop(new Cuadrado()) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
//	float xInicial = 7;
	float yDefault = 10;
	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end(); ++iterator) {
		this->agregarEslabon(new EslabonCreacion(*iterator, new Cuadrado(), 1));
		yDefault += 12;
	}
}

bool ZonaCreacion::dropTemplate(FiguraView* dragueable) {
	return false;

}

FiguraView* ZonaCreacion::dragTemplate(float x, float y) {
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
