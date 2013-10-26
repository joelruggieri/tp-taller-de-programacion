/*
 * Disponibilidad.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Disponibilidad.h"
#include "ThreadStatus.h"
Disponibilidad::Disponibilidad(int maxJugadores) {
	for (int i = 0; i < maxJugadores; ++i) {
		relaciones.insert(pair<int,ThreadStatus*>(i,new ThreadStatus(10000)));
	}
}

Disponibilidad::~Disponibilidad() {
	map<int,ThreadStatus*>::iterator it;
	for(it=relaciones.begin(); it!= relaciones.end(); ++it){
		delete (*it).second;
	}
}

ThreadStatus* Disponibilidad::getStatus(int jugador) {
	std::map<int,ThreadStatus*>::iterator elemento = relaciones.find(jugador);
	if(elemento != relaciones.end()){
		return (*elemento).second;
	}
	return NULL;
}

ThreadStatus* Disponibilidad::getNextFree() {
}
