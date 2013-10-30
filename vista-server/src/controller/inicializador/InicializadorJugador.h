/*
 * InicializadorJuego.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef INICIALIZADORJUGADOR_H_
#define INICIALIZADORJUGADOR_H_
#include "../JuegoEventsController.h"
#include <map>
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "src/Jugador.h"
using namespace std;

class InicializadorJugador {
private:
	ZonaTablero* tablero;
	map<string, ViewFiguraFactory *> figuraFactory;
	ModeloController * modeloController;
public:
	InicializadorJugador(ZonaTablero * tablero, ModeloController * modeloController);
	virtual ~InicializadorJugador();
	JuegoEventsController * crearController(Jugador *);
};

#endif /* INICIALIZADORJUGADOR_H_ */
