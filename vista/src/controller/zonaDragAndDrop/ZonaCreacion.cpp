/*
 * ZonaCreacion.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaCreacion.h"
#include "src/figura/Cuadrado.h"
//#include "../../modelo/figura/Cuadrado.h"

ZonaCreacion::ZonaCreacion(list<ViewFiguraFactory*> * factories, float x, float margenSuperior) :
		ZonaDragAndDrop(NULL) {
	//TODO ADAPTAR TAMANIO DE LA ZONA SEGUN LA CANTIDAD DE FACTORIES QUE VENGAN.
	float ancho = ANCHO_VIEW_DEF *2;
	//50% de margen alrededor de todo el panel
	float xInicial = x;
	float yInicial = margenSuperior +  ANCHO_VIEW_DEF / 2;
	float y = yInicial;
	std::list<ViewFiguraFactory*>::const_iterator iterator;
	this->inicioCadena = NULL;
	this->ultimo = NULL;
	//por cada factory crea un eslabon.
	for (iterator = factories->begin(); iterator != factories->end(); ++iterator) {
		this->agregarEslabon(
				new EslabonCreacion(*iterator,
						new Cuadrado(xInicial, y, ANCHO_VIEW_DEF, ANCHO_VIEW_DEF),
						1));
		y += 12;
	}

	y = factories->size() > 0 ? y-12: y;
	float alto = (y - margenSuperior) + ANCHO_VIEW_DEF;
	this->setCuerpo(new Cuadrado(x,(margenSuperior + alto) / 2, ancho, alto));
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
