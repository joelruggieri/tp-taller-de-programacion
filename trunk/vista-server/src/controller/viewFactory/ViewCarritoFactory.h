/*
 * ViewCarritoFactory.h
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#ifndef VIEWCARRITOFACTORY_H_
#define VIEWCARRITOFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
#include "../editor/SimpleEditorEstirar.h"

class ViewCarritoFactory: public ViewFiguraFactory {
public:
	ViewCarritoFactory(SimpleEditorNivel* editor, int cantidad);
	virtual ~ViewCarritoFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWCARRITOFACTORY_H_ */
