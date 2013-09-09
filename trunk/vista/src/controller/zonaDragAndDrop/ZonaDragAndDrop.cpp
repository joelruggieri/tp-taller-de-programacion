/*
 * ZonaDragAndDrop.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaDragAndDrop.h"
#include "../../vista/figura/FiguraView.h"


ZonaDragAndDrop::ZonaDragAndDrop(Cuadrado * cuerpo) {
	this->cuerpo = cuerpo;
	this->scrollY = 0;
}

ZonaDragAndDrop::~ZonaDragAndDrop() {
}


//TODO: Si hay scroll lo almacena con la posicion cambiada.
bool ZonaDragAndDrop::drop(FiguraView* vista) {

	if (this->cuerpo->contieneCentro(vista->getModelo())) {
		return this->dropTemplate(vista);
	}
	return false;
}

float ZonaDragAndDrop::getScrollY() const {
	return scrollY;
}

void ZonaDragAndDrop::setScrollY(float scrollY) {
	this->scrollY = scrollY;
}

//TODO :Si hay scroll lo devuelve con la posicion cambiada.
FiguraView * ZonaDragAndDrop::drag(float x, float y) {
	FiguraView * drop  = NULL;
	if (this->cuerpo->contacto(x, y)) {
		drop = this->dragTemplate(x,y);
	}
//	if(drop != NULL){
//		drop->getCuerpo()->setPosY(
//				drop->getCuerpo()->getPosY() - this->scrollY);
//	}
	return drop;
}

void ZonaDragAndDrop::setCuerpo(Cuadrado* cuerpo) {
	this->cuerpo = cuerpo;
}

Cuadrado*& ZonaDragAndDrop::getCuerpo() {
	return cuerpo;
}
