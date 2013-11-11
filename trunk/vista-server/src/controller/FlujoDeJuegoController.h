/*
 * FlujoDeJuegoController.h
 *
 *  Created on: 02/10/2013
 *      Author: jonathan
 */

#ifndef FLUJODEJUEGOCONTROLLER_H_
#define FLUJODEJUEGOCONTROLLER_H_
#include "src/ModeloController.h"

class FlujoDeJuegoController {
private:
	ModeloController * modeloController;
	bool iniciado;
public:
	FlujoDeJuegoController(ModeloController * c);
	virtual ~FlujoDeJuegoController();
	void cambiarEstadoJugador(int, bool);
	void start();
	void stop();
	void paso();
	bool corriendo();
};

#endif /* FLUJODEJUEGOCONTROLLER_H_ */
