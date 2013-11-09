/*
 * SimpleEditorOrientacionCambiable.h
 *
 *  Created on: 10/10/2013
 *      Author: ezequiel
 */

#ifndef SIMPLEEDITORORIENTACIONCAMBIABLE_H_
#define SIMPLEEDITORORIENTACIONCAMBIABLE_H_
#include "SimpleEditorNivel.h"

class SimpleEditorOrientacionCambiable : public SimpleEditorNivel {
private:
	typedef SimpleEditorNivel super;
public:
	SimpleEditorOrientacionCambiable(ModeloController * , ZonaTablero *,FiguraFactory* factory, float yMaxDrag);
	virtual ~SimpleEditorOrientacionCambiable();
	void mouseMotion(float x, float y);
	void rightClickDown(float x, float y);
	void dropNuevaFigura(MotorView * m);
	EditorNivel * clone();
};

#endif /* SIMPLEEDITORORIENTACIONCAMBIABLE_H_ */
