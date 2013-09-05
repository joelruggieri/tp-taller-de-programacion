/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"

//ZonaTablero::ZonaTablero(Cuerpo cuerpo):ZonaDragAndDrop(cuerpo) {
//
//}
//
bool ZonaTablero::dropTemplate(FiguraView* dragueable) {
	this->figuras.push_back(dragueable);
	return true;
}

FiguraView* ZonaTablero::dragTemplate(float x, float y) {
	std::list<FiguraView*>::const_iterator iterator;
	FiguraView* result = NULL;
	for (iterator = figuras.begin(); iterator != figuras.end(); ++iterator) {
	    Figura * c =(*iterator)->getModelo();
	    if(c->contacto(x,y)){
	    	result = *iterator;
	    	break;
	    }
	}
	if(result != NULL){
		figuras.remove(result);
	}
	return result;
}

ZonaTablero::~ZonaTablero() {
	std::list<FiguraView*>::const_iterator iterator;
	for (iterator = figuras.begin(); iterator != figuras.end(); ++iterator) {
		delete *iterator;
	}

	delete this->mapa;
}

