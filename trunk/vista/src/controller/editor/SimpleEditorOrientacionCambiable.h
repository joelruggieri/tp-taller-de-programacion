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
	SimpleEditorOrientacionCambiable(ModeloController * , ZonaTablero *,FiguraFactory* factory, int yMaxDrag);
	virtual ~SimpleEditorOrientacionCambiable();
	void mouseMotion(int x, int y);
	void rightClickDown(int x, int y);
};

#endif /* SIMPLEEDITORORIENTACIONCAMBIABLE_H_ */
