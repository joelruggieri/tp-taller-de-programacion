/*
 * ZonaDragAndDrop.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaDragAndDrop.h"

ZonaDragAndDrop::ZonaDragAndDrop(Cuerpo cuerpo) {
	this->cuerpo = cuerpo;
}

ZonaDragAndDrop::~ZonaDragAndDrop() {
}

bool ZonaDragAndDrop::drop(Dropeable* dragueable) {
	if (this->cuerpo.isAdentro(dragueable->getPosX(),dragueable->getPosY())){
		return this->dropTemplate(dragueable);
	}
	return false;
}

Dropeable* ZonaDragAndDrop::drag(float x, float y) {
	if(this->cuerpo.isAdentro(x,y)){
			return this->dragTemplate(x,y);
	}
	return NULL;
}
