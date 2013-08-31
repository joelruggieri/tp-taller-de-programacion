/*
 * DropeableFactory.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "DropeableFactory.h"


DropeableFactory::~DropeableFactory() {
}

DropeableFactory::DropeableFactory(string etiqueta) {
	 this->etiqueta = etiqueta;
}

Dropeable* DropeableFactory::crear(float x, float y) {
	return new Dropeable(this->etiqueta, Cuerpo(x,y,10,10));
}
