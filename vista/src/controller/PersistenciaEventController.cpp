/*
 * PersistenciaEventController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "PersistenciaEventController.h"

PersistenciaEventController::PersistenciaEventController(Mapa* m,
		PersistenciaManager* manager) {
	this->mapa = m;
	this->manager = manager;
}

void PersistenciaEventController::persistir() {
//	void & figuras = mapa->getFiguras();
//	this->manager->persistirFiguras(figuras);
}

PersistenciaEventController::~PersistenciaEventController() {
	// TODO Auto-generated destructor stub
}

