/*
 * DragAndDropManager.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef DRAGANDDROPMANAGER_H_
#define DRAGANDDROPMANAGER_H_
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/RomboView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/TrianguloView.h"
class DragAndDropManager {
public:
	DragAndDropManager();
	virtual ~DragAndDropManager();
	virtual void dropNuevaFigura(CirculoView*) = 0;
	virtual void dropNuevaFigura(CuadradoView*) = 0;
	virtual void dropNuevaFigura(TrianguloView*) = 0;
	virtual void dropNuevaFigura(RomboView*) = 0;
	virtual void dropFigura(FiguraView*) = 0;
	virtual  FiguraView* drag(float, float) =0;
};

#endif /* DRAGANDDROPMANAGER_H_ */

