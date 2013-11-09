/*
 * JuegoControllerFactory.h
 *
 *  Created on: 08/11/2013
 *      Author: joel
 */

#ifndef JUEGOCONTROLLERFACTORY_H_
#define JUEGOCONTROLLERFACTORY_H_
#include "../JuegoEventsController.h"
#include "src/Jugador.h"

class JuegoControllerFactory {
private:
	ZonaTablero* tablero;
	ModeloController* modeloController;
	map<string, ViewFiguraFactory* > factoriesDelJuego;
	FiguraFactory* factory;
	std::list<DropController*> editores;
public:
	JuegoControllerFactory(ZonaTablero* tablero, ModeloController* modeloController);
	JuegoEventsController* crearConfiguracionJugador(Jugador* jugador);
	virtual ~JuegoControllerFactory();
};

#endif /* JUEGOCONTROLLERFACTORY_H_ */
