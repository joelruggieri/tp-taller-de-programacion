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
		relaciones.insert(pair<int,ThreadStatus*>(i,new ThreadStatus(i,10000)));
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
	map<int,ThreadStatus*>::iterator it;
	ThreadStatus * actual;
	for(it=relaciones.begin(); it!= relaciones.end(); ++it){
		actual =(*it).second;
		if(actual->getThread() == NULL){
			return actual;
		}
		if(!actual->isAlive()) {
			delete (actual->getThread());
			actual->setThread(NULL);
			return actual;
		}
	}
	return NULL;
}

void Disponibilidad::cleanDeaths() {
	map<int,ThreadStatus*>::iterator it;
	ThreadStatus * actual;
	for(it=relaciones.begin(); it!= relaciones.end(); ++it){
		actual =(*it).second;
		if(actual->getThread() && !actual->isAlive()){
			delete actual->getThread();
			actual->setThread(NULL);
		}
	}
}
