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

Dropeable* DropeableFactory::crear() {
	return new Dropeable(this->etiqueta);
}
