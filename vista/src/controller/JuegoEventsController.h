/*
 * JuegoEventsController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef JuegoEventsController_H_
#define JuegoEventsController_H_

#include <SDL2/SDL_rect.h>
#include "SDL2/SDL.h"

#include "../vista/Dibujable.h"
#include "../vista/Dragueable.h"
#include "mouseEventController/MouseEventController.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaPlay.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "ResizerController.h"
#include "src/mensajes/userEvents/MouseMotionMsj.h"
#include "StatusJuego.h"
namespace CLIENTE {
//ENTREGA3 APARENTEMENTE YA RECIBE COMO PARAMETRO UNA ZONAPLAY ASI QUE HABRÍA QUE VER QUE FUNCIONEN N EN SIMULTANEO (MISMO THREAD)
//ENTREGA3 HAY QUE ADEMAS DARLE UNA ZONA DONDE SI SE SALE QUE NO TENGA EFECTO EL EVENTO DE SCROLL O PICKUP/DROP. PARA ESO SE PUEDE USAR EL OBJETO CUADRADO DE LA VISTA
class JuegoEventsController: public MouseEventController, public ResizerController {
private:
	ZonaTablero * tablero;
	ZonaCreacion * creacion;
	ZonaPlay * zplay;
	Transformacion * tl;
	StatusJuego * status;
public:
	JuegoEventsController(ZonaPlay * zplay,ZonaTablero *tablero, ZonaCreacion * creacion,StatusJuego * statusjuego, Transformacion * tl);
	virtual ~JuegoEventsController();
	bool clickDown(int,int);
	bool clickUp(int, int);
	bool mouseMotion(int, int);
	bool rightClickDown(int,int);
	bool rightClickUp(int,int);
	bool mouseWheelMoved(int, int, int);
	void resize(Transformacion * tl);
};
}
#endif /* JuegoEventsController_H_ */
