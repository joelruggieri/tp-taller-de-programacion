/*
 * ViewCorreaFactory.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef VIEWCORREAFACTORY_H_
#define VIEWCORREAFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/EditorUnion.h"

class ViewCorreaFactory: public ViewFiguraFactory{

public:
	ViewCorreaFactory(EditorUnion* editor, int cantidad);
	virtual ~ViewCorreaFactory();
	FiguraView * crear(float,float);
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWCORREAFACTORY_H_ */
