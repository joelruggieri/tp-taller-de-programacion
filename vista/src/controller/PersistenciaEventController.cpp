/*
 * PersistenciaEventController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "PersistenciaEventController.h"
#include "src/Logger.h"
PersistenciaEventController::PersistenciaEventController(ModeloController * m, CanvasController * c,
		PersistenciaManager* manager) {
	this->modeloController = m;
	this->manager = manager;
	this->canvasController = c;
}

void PersistenciaEventController::persistir() {
	Logger log;
	log.debug("Ejecutando persistencia de nivel");
	this->manager->setFiguras(modeloController->getFiguras());
	this->manager->cambiarImagenFondo(canvasController->getRutaFondo());
	this->manager->persistir();
}

PersistenciaEventController::~PersistenciaEventController() {
	// TODO Auto-generated destructor stub
}

