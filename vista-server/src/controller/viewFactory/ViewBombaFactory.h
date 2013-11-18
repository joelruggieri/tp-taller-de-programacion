/*
 * ViewBombaFactory.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWBOMBAFACTORY_H_
#define VIEWBOMBAFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewBombaFactory : public ViewFiguraFactory{
public:
	ViewBombaFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewBombaFactory();
	FiguraView * crear(float,float);
		View * crearVistaPropia();
		string getTagRemoto();
		View * crearVistaPropia(float,float,float,float);
		ViewFiguraFactory* clone(int);
};

#endif /* VIEWBOMBAFACTORY_H_ */
