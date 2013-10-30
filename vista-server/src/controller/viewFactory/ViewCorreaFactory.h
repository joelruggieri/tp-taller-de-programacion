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
	ViewCorreaFactory(EditorUnion* editor);
	virtual ~ViewCorreaFactory();
	FiguraView * crear(float,float,float,float);
	View * crearVistaPropia(float,float,float,float);
};

#endif /* VIEWCORREAFACTORY_H_ */
