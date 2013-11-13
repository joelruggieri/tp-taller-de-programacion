/*
 * ViewYunqueFactory.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWYUNQUEFACTORY_H_
#define VIEWYUNQUEFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewYunqueFactory : public ViewFiguraFactory {
public:
	ViewYunqueFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewYunqueFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWYUNQUEFACTORY_H_ */
