/*
 * ZonaSeguraMemoria.cpp
 *
 *  Created on: 31/10/2013
 *      Author: jonathan
 */

#include "ZonaSeguraMemoria.h"

ZonaSeguraMemoria::ZonaSeguraMemoria(void *(*cleaner)(void *), void * paramsFunc) {
	this->cleaner = cleaner;
	this->liberable = 0;
	this->params = paramsFunc;
}

ZonaSeguraMemoria::~ZonaSeguraMemoria() {

}

void ZonaSeguraMemoria::cancel() {
	if (cleaner && liberable) {
		(void *) cleaner(this->liberable);
	}
}

void ZonaSeguraMemoria::setDatosLiberables(void* liberables) {
	this->liberable = liberables;
}

void * ZonaSeguraMemoria::getParams() {
	return this->params;
}
