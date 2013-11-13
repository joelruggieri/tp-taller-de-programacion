#include "FlujoDeJuegoController.h"
#include <src/Logger.h>

FlujoDeJuegoController::FlujoDeJuegoController(ModeloController* c) {
	list<JuegoEventsController *>::iterator it;
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

void FlujoDeJuegoController::actualizarEstado() {
	map<int, JuegoEventsController*>::iterator it;
	bool iniciadoAnt = iniciado;
	iniciado = true;
	for (it = estados.begin(); it != estados.end(); ++it) {
		iniciado = iniciado && it->second->isIniciado();
	}
	if(iniciadoAnt != iniciado){
		if(iniciado){
			start();
		} else {
			stop();
		}
	}
}

void FlujoDeJuegoController::cambiarEstadoJugador(int nroJugador, bool estado) {
	map<int,JuegoEventsController*>::iterator it = estados.find(nroJugador);
	(*it).second->setIniciado(estado);
	actualizarEstado();
}

void FlujoDeJuegoController::addJugador(JuegoEventsController*jugador) {
	jugador->setIniciado(false);
	estados.insert(pair<int,JuegoEventsController*>(jugador->getNumeroJugador(), jugador));
	actualizarEstado();
}
