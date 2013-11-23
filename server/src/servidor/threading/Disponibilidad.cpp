/*
 * Disponibilidad.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Disponibilidad.h"
#include "ThreadStatus.h"
#include "src/ConstantesComunicacion.h"
Disponibilidad::Disponibilidad(std::list<Jugador*>& jugadoresNivel) {
	std::list<Jugador*>::iterator iter;
	int i = 0;
	for (iter = jugadoresNivel.begin(); iter != jugadoresNivel.end(); ++iter) {
		relaciones.insert(pair<int, ThreadStatus*>(i, new ThreadStatus(TIMEOUT,(*iter))));
		i++;
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

list<ThreadStatus*> Disponibilidad::getStatuses() {
	map<int,ThreadStatus*>::iterator it;
	list<ThreadStatus*>result;
	for(it=relaciones.begin(); it!=relaciones.end(); ++it){
		result.push_back(it->second);
	}
	return result;

}
