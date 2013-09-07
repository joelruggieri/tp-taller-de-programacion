/*
 * DragAndDropController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef DRAGANDDROPCONTROLLER_H_
#define DRAGANDDROPCONTROLLER_H_
#include "src/figuraFactory/FiguraFactory.h"
#include "../vista/figura/FiguraView.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/TrianguloView.h"
#include "DropController.h"
class DragAndDropController: public DropController {
private:
	ZonaDragAndDrop * zona;
	FiguraFactory * figurasFactory;
	void dropear(FiguraView* view, Figura* figura);
	FiguraView * figuraDrag;
public:
	DragAndDropController();
	virtual ~DragAndDropController();
	void dropNuevaFigura(CuadradoView*);
	void dropNuevaFigura(CirculoView*);
	void dropNuevaFigura(TrianguloView*);
	void dropNuevaFigura(RomboView*);
	void dropFigura(FiguraView*);
	bool clickDown(float,float);
	bool clickUp(float, float);
	bool mouseMotion(float, float);
};
#endif /* DRAGANDDROPCONTROLLER_H_ */
