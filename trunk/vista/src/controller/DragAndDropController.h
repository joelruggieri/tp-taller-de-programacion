/*
 * DragAndDropController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef DRAGANDDROPCONTROLLER_H_
#define DRAGANDDROPCONTROLLER_H_

#include "../vista/figura/CirculoView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/TrianguloView.h"
#include "DropController.h"
#include "mouseEventController/MouseEventController.h"
#include "../vista/Dragueable.h"

class Figura;
class FiguraFactory;
class Zona;

class DragAndDropController: public DropController, public MouseEventController, public Dragueable {
private:
	Zona * zona;
	FiguraFactory * figurasFactory;
	FiguraView * figuraDrag;
	void dropear(FiguraView* view, Figura* figura);
public:
	DragAndDropController();
	virtual ~DragAndDropController();
	void dropNuevaFigura(CuadradoView*);
	void dropNuevaFigura(CirculoView*);
	void dropNuevaFigura(TrianguloView*);
	void dropNuevaFigura(RomboView*);
	void dropFigura(FiguraView*);
	void drag(FiguraView*, float, float);
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
	Zona* getZona();
	void setZona(Zona* zona);
	bool isDragging();
	View* getDragueado();
};
#endif /* DRAGANDDROPCONTROLLER_H_ */
