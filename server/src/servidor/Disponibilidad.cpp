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
	// TODO destruir los threadStatus.
}

//void Disponibilidad::setDisponibilidad(int jug, int dispo) {
//	std::map<int,int>::iterator elemento = relaciones.find(jug);
//
//	if(elemento != relaciones.end()){
//		(*elemento).second = dispo;
//	} else {
//		relaciones.insert(pair<int,int>(jug,dispo));
//	}
//}

ThreadStatus* Disponibilidad::getStatus(int jugador) {
	std::map<int,ThreadStatus*>::iterator elemento = relaciones.find(jugador);
	if(elemento != relaciones.end()){
		return (*elemento).second;
	}
	return NULL;
}
