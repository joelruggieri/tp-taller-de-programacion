/*
 * Disponibilidad.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Disponibilidad.h"
#include "ThreadStatus.h"
#include "src/ConstantesComunicacion.h"
Disponibilidad::Disponibilidad(int maxJugadores) {
	for (int i = 0; i < maxJugadores; ++i) {
		relaciones.insert(pair<int, ThreadStatus*>(i, new ThreadStatus(TIMEOUT, i)));
	}
}

Disponibilidad::~Disponibilidad() {
	map<int, ThreadStatus*>::iterator it;
	for (it = relaciones.begin(); it != relaciones.end(); ++it) {
		delete (*it).second;
	}
}

ThreadStatus* Disponibilidad::getStatus(int jugador) {
	std::map<int, ThreadStatus*>::iterator elemento = relaciones.find(jugador);
	if (elemento != relaciones.end()) {
		return (*elemento).second;
	}
	return NULL;
}

ThreadStatus* Disponibilidad::getNextFree() {
	map<int, ThreadStatus*>::iterator it;
	ThreadStatus * actual;
	for (it = relaciones.begin(); it != relaciones.end(); ++it) {
		actual = (*it).second;
		if (actual->allowClient()) {
			return actual;
		}
	}
	return NULL;
}

void Disponibilidad::cleanDeaths() {
	map<int, ThreadStatus*>::iterator it;
	ThreadStatus * actual;
	for (it = relaciones.begin(); it != relaciones.end(); ++it) {
		actual = (*it).second;
		actual->clean();
	}
}

//bool Disponibilidad::exist(int socket) {
//	map<int,ThreadStatus*>::iterator it;
//	bool encontrado = false;
//	for(it=relaciones.begin(); it!= relaciones.end() && !encontrado; ++it){
//		ThreadStatus* second = (*it).second;
//		second->lock();
//		if(second->getThread() != NULL){
//			encontrado= second->getSockedDesc() == socket;
//		}
//		second->unlock();
//	}
//	return encontrado;
//}
