/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"

//TODO UN CUADRADO DE 100X100 CENTRADO EN X,Y
ZonaTablero::ZonaTablero(Mapa * mapa, float x, float y):ZonaDragAndDrop(new Cuadrado()) {
	this->mapa = mapa;
}

bool ZonaTablero::dropTemplate(FiguraView* view) {
	if(view->getModelo() == NULL){
		return false;
	}
	this->figuras.push_back(view);
	this->mapa->addFigura(view->getModelo());
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

