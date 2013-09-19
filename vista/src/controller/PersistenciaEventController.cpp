/*
 * PersistenciaEventController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "PersistenciaEventController.h"
#include "src/Logger.h"
PersistenciaEventController::PersistenciaEventController(ModeloController * m,
		PersistenciaManager* manager) {
	this->modeloController = m;
	this->manager = manager;
}

void PersistenciaEventController::persistir() {
	Logger log;
	log.debug("Ejecutando persistencia de nivel");
	this->manager->persistirFiguras(modeloController->getFiguras());
}

PersistenciaEventController::~PersistenciaEventController() {
	// TODO Auto-generated destructor stub
}

