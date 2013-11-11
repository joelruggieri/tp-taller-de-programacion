/*
 * JuegoEventsController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef JuegoEventsController_H_
#define JuegoEventsController_H_

#include <SDL2/SDL_rect.h>
#include <src/ModeloController.h>
#include "SDL2/SDL.h"

#include "../vista/Dibujable.h"
#include "../vista/Dragueable.h"
#include "FlujoDeJuegoController.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaTablero.h"

//ENTREGA3 HAY QUE ADEMAS DARLE UNA ZONA DONDE SI SE SALE QUE NO TENGA EFECTO EL EVENTO DE SCROLL O PICKUP/DROP. PARA ESO SE PUEDE USAR EL OBJETO CUADRADO DE LA VISTA
class JuegoEventsController {
private:
	ZonaTablero * tablero;
	ZonaCreacion * creacion;
	ModeloController * modeloController;
	bool iniciado;
	bool shift;
	bool control;
	EditorNivel * editor;
	int numeroJugador;
public:
	JuegoEventsController(ZonaTablero*,ModeloController*,ZonaCreacion*, int numero);
	virtual ~JuegoEventsController();
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
	bool rightClickDown(float,float);
	bool rightClickUp(float,float);
	void crearVista(string, float, float);
	void setZonas(ZonaTablero *tablero, ZonaCreacion * creacion);
	ViewMsj* dibujarEdicion();
	void start();
	void stop();
	void paso();
	bool corriendo();
	bool isCtrl() const;
	bool isShift() const;
	void setControl(bool);
	void setShift(bool);
	int getNumeroJugador() const;
	void setNumeroJugador(int numeroJugador);
};
#endif /* JuegoEventsController_H_ */
