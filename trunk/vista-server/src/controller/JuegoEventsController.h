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
#include "mouseEventController/MouseEventController.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaPlay.h"
#include "zonaDragAndDrop/ZonaTablero.h"

//ENTREGA3 APARENTEMENTE YA RECIBE COMO PARAMETRO UNA ZONAPLAY ASI QUE HABRÍA QUE VER QUE FUNCIONEN N EN SIMULTANEO (MISMO THREAD)
//ENTREGA3 HAY QUE ADEMAS DARLE UNA ZONA DONDE SI SE SALE QUE NO TENGA EFECTO EL EVENTO DE SCROLL O PICKUP/DROP. PARA ESO SE PUEDE USAR EL OBJETO CUADRADO DE LA VISTA
class JuegoEventsController: public MouseEventController, public Dibujable, public FlujoDeJuegoController {
private:
	ZonaTablero * tablero;
	ZonaCreacion * creacion;
	ZonaPlay * zplay;
	ModeloController * modeloController;
	bool iniciado;
	EditorNivel * editor;
public:
	JuegoEventsController(ModeloController*,ZonaPlay * zplay);
	virtual ~JuegoEventsController();
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
	bool rightClickDown(float,float);
	bool rightClickUp(float,float);
	bool mouseWheelMoved(float, float, int);
	void setZonas(ZonaTablero *tablero, ZonaCreacion * creacion);
	void dibujarse(list<ViewMsj*> & lista);
	void start();
	void stop();
	void paso();
	bool corriendo();
};
#endif /* JuegoEventsController_H_ */
