#include "FlujoDeJuegoController.h"
#include <src/Logger.h>

FlujoDeJuegoController::FlujoDeJuegoController(ModeloController* c) {
	this->modeloController = c;
	iniciado = false;
}

void FlujoDeJuegoController::start() {

	this->modeloController->start();
	this->iniciado = true;
}

void FlujoDeJuegoController::stop() {
	modeloController->stop();
	this->iniciado = false;
}

void FlujoDeJuegoController::paso() {
	if (iniciado) {
		Logger log;
		this->modeloController->step();
	}
}

bool FlujoDeJuegoController::corriendo() {
	return iniciado;
}

FlujoDeJuegoController::~FlujoDeJuegoController() {

}

void FlujoDeJuegoController::cambiarEstadoJugador(int nroJugador, bool estado) {
	if(estado){
		start();
	} else{
		stop();
	}
}
