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
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "src/Area.h"
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
	Area * area;
public:
	JuegoEventsController(ZonaTablero*,ModeloController*,ZonaCreacion*,Area* a, int numero);
	virtual ~JuegoEventsController();
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
	bool rightClickDown(float,float);
	bool rightClickUp(float,float);
	void crearVista(string, float, float);
	void setZonas(ZonaTablero *tablero, ZonaCreacion * creacion);
	ViewMsj* dibujarEdicion();
	void setIniciado(bool);
	bool isIniciado();
	bool isCtrl() const;
	bool isShift() const;
	void setControl(bool);
	void setShift(bool);
	bool isEditando();
	int getNumeroJugador() const;
	void setNumeroJugador(int numeroJugador);
	void getEstadoCreacion(list<ViewMsj*> &,int);
};
#endif /* JuegoEventsController_H_ */
