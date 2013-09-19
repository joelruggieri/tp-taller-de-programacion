/*
 * JuegoEventsController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef JuegoEventsController_H_
#define JuegoEventsController_H_

#include "../vista/figura/CirculoView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/TrianguloView.h"
#include "DropController.h"
#include "mouseEventController/MouseEventController.h"
#include "../vista/Dragueable.h"
#include "../vista/Rotable.h"
#include "../modelo/Rotacion.h"
#include "src/EventosModeloController.h"
#include "../vista/Dibujable.h"
#include "SDL2/SDL.h"
class Figura;
class FiguraFactory;
class Zona;

class JuegoEventsController: public DropController, public MouseEventController, public Dragueable, public Rotable, public Dibujable {
private:
	Zona * zona;
	FiguraFactory * figurasFactory;
	FiguraView * figuraDrag;
	FiguraView * figuraRotacion;
	Rotacion * rot;
	float posStartDragX;
	float posStartDragY;
	void dropear(FiguraView* view, Figura* figura);
	ModeloController * modeloController;
public:
	JuegoEventsController();
	virtual ~JuegoEventsController();
	void dropNuevaFigura(CuadradoView*);
	void dropNuevaFigura(CirculoView*);
	void dropNuevaFigura(TrianguloView*);
	void dropNuevaFigura(RomboView*);
	void dropFigura(FiguraView*);
	void drag(FiguraView*, float, float);
	bool clickDown(int,int);
	bool clickUp(int, int);
	bool mouseMotion(int, int);
	bool rightClickDown(int,int);
	bool rightClickUp(int,int);
	Zona* getZona();
	void setZona(Zona* zona);
	bool isDragging();
	View* getDragueado();
	bool isRotando();
	View* getRotado();
	void resizear();
	void dibujarse(SDL_Renderer *);
};
#endif /* JuegoEventsController_H_ */
