/*
 * Zona.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaDragAndDrop.h"
#include "../../vista/figura/FiguraView.h"


Zona::Zona(Cuadrado * cuerpo) {
	this->cuerpo = cuerpo;
	this->scrollY = 0;
}

Zona::~Zona() {
	delete this->cuerpo;
}


//Si hay scroll lo almacena con la posicion cambiada.
bool Zona::agregarFigura(FiguraView* vista) {

	if (this->cuerpo->contieneCentro(vista->getModelo())) {
		return this->agregarTemplate(vista);
	}
	return false;
}

float Zona::getScrollY() const {
	return scrollY;
}

void Zona::setScrollY(float scrollY) {
	this->scrollY = scrollY;
}

//Si hay scroll lo devuelve con la posicion cambiada y adapta la posicion algo del modelo.
FiguraView * Zona::getVista(float x, float y) {
	FiguraView * drop  = NULL;
	if (this->cuerpo->contacto(x, y)) {
		drop = this->getFiguraTemplate(x,y);
	}
	return drop;
}

void Zona::setCuerpo(Cuadrado* cuerpo) {
	this->cuerpo = cuerpo;
}

Cuadrado*& Zona::getCuerpo() {
	return cuerpo;
}
