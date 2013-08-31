/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"

ZonaTablero::ZonaTablero(Cuerpo cuerpo):ZonaDragAndDrop(cuerpo) {

}

bool ZonaTablero::dropTemplate(Dropeable* dragueable) {
	this->dropeables.push_back(dragueable);
	return true;
}

Dropeable* ZonaTablero::dragTemplate(float x, float y) {
	std::list<Dropeable*>::const_iterator iterator;
	Dropeable* result = NULL;
	for (iterator = dropeables.begin(); iterator != dropeables.end(); ++iterator) {
	    Cuerpo c =(*iterator)->getCuerpo();
	    if(c.isAdentro(x,y)){
	    	result = *iterator;
	    	break;
	    }
	}
	if(result != NULL){
		dropeables.remove(result);
	}
	return result;
}

ZonaTablero::~ZonaTablero() {
	std::list<Dropeable*>::const_iterator iterator;
	for (iterator = dropeables.begin(); iterator != dropeables.end(); ++iterator) {
		delete *iterator;
	}

}

