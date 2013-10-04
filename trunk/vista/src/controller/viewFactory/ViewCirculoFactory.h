/*
 *
 * ViewCirculoFactory.h
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCIRCULOFACTORY_H_
#define VIEWCIRCULOFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
class ViewCirculoFactory: public ViewFiguraFactory {
private:
	SimpleEditorNivel * editor;
public:
	ViewCirculoFactory(DropController* controller, SimpleEditorNivel * editor);
	virtual ~ViewCirculoFactory();
	FiguraView * crear(int,int,int,int);
	FactoryView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWCIRCULOFACTORY_H_ */
