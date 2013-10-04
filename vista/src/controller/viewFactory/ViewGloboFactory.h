/*
 * ViewGloboFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWGLOBOFACTORY_H_
#define VIEWGLOBOFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
class ViewGloboFactory: public ViewFiguraFactory{
private:
	SimpleEditorNivel * editor;
public:
	ViewGloboFactory(DropController* controller, SimpleEditorNivel * editor);
	virtual ~ViewGloboFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWGLOBOFACTORY_H_ */
