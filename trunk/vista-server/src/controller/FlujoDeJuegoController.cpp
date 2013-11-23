#include "FlujoDeJuegoController.h"
#include <src/Logger.h>

void FlujoDeJuegoController::start() {
	if (!objetivo->isCumplido()) {
		this->modeloController->start();
		this->iniciado = true;
	}
}

void FlujoDeJuegoController::stop() {
	if (!objetivo->isCumplido()) {
		modeloController->stop();
		this->iniciado = false;
	}
}

void FlujoDeJuegoController::paso() {
	if (iniciado && !objetivo->isCumplido()) {
		Logger log;
		this->modeloController->step();
	}
}

bool FlujoDeJuegoController::corriendo() {
	return iniciado && !objetivo->isCumplido();
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
	if (iniciadoAnt != iniciado) {
		if (iniciado) {
			start();
		} else {
			stop();
		}
	}
}

void FlujoDeJuegoController::cambiarEstadoJugador(int nroJugador, bool estado) {
	map<int, JuegoEventsController*>::iterator it = estados.find(nroJugador);
	(*it).second->setIniciado(estado);
	actualizarEstado();
}

void FlujoDeJuegoController::addJugador(JuegoEventsController*jugador) {
	jugador->setIniciado(false);
	estados.insert(pair<int, JuegoEventsController*>(jugador->getNumeroJugador(), jugador));
	actualizarEstado();
}

FlujoDeJuegoController::FlujoDeJuegoController(ModeloController* c, ObjetivoJuego* objetivo) {
	list<JuegoEventsController *>::iterator it;
	this->modeloController = c;
	iniciado = false;
	this->objetivo = objetivo;
}

bool FlujoDeJuegoController::isGanado() {
	return objetivo->isCumplido();
}
