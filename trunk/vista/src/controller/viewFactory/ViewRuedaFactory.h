/*
 * ViewRuedaFactory.h
 *
 *  Created on: 19/09/2013
 *      Author: joel
 */

#ifndef VIEWRUEDAFACTORY_H_
#define VIEWRUEDAFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
class ViewRuedaFactory: public ViewFiguraFactory {
private:
	SimpleEditorNivel * editor;
public:
	ViewRuedaFactory(DropController* controller, SimpleEditorNivel * editor);
	virtual ~ViewRuedaFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWRUEDAFACTORY_H_ */
