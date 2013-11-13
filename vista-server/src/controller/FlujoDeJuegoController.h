/*
 * FlujoDeJuegoController.h
 *
 *  Created on: 02/10/2013
 *      Author: jonathan
 */

#ifndef FLUJODEJUEGOCONTROLLER_H_
#define FLUJODEJUEGOCONTROLLER_H_
#include "src/ModeloController.h"
#include "JuegoEventsController.h"
#include <map>
#include <list>
using namespace std;

class FlujoDeJuegoController {
private:
	ModeloController * modeloController;
	map<int, JuegoEventsController*> estados;
	bool iniciado;

	void actualizarEstado();

public:
	FlujoDeJuegoController(ModeloController * c);
	virtual ~FlujoDeJuegoController();
	void cambiarEstadoJugador(int, bool);
	void addJugador(JuegoEventsController *);
	void start();
	void stop();
	void paso();
	bool corriendo();
};

#endif /* FLUJODEJUEGOCONTROLLER_H_ */
