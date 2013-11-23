/*
 * DrawController.h
 *
 *  Created on: 04/10/2013
 *      Author: jonathan
 */

#ifndef DRAWCONTROLLER_H_
#define DRAWCONTROLLER_H_
#include <src/threading/ColaEventos.h>
#include "JuegoEventsController.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include <list>
#include "src/objeto/Plataforma.h"
#include "../vista/objeto/PlataformaView.h"
using namespace std;

class DrawController {
private:
	list<JuegoEventsController *> controllers;
	ZonaTablero * tablero;
	ColaEventos * salida;
	int angulo;
	PlataformaView * plat;
	bool ganado;
public:
	DrawController(ColaEventos * salida);
	virtual ~DrawController();
	void addJugador(JuegoEventsController *);
	void removeJugador(JuegoEventsController *);
	void setTablero(ZonaTablero *);
	void dibujar();
	void pasarAGanado();

};

#endif /* DRAWCONTROLLER_H_ */
