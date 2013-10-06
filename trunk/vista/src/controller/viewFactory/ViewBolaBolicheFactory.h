/*
 * ViewBolaBolicheFactory.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWBOLABOLICHEFACTORY_H_
#define VIEWBOLABOLICHEFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewBolaBolicheFactory : public ViewFiguraFactory {
public:
	ViewBolaBolicheFactory(SimpleEditorAnguloFijo * editor);
	virtual ~ViewBolaBolicheFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWBOLABOLICHEFACTORY_H_ */
