/*
 * ViewGloboFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWGLOBOFACTORY_H_
#define VIEWGLOBOFACTORY_H_

#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewGloboFactory: public ViewFiguraFactory{
public:
	ViewGloboFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewGloboFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VIEWGLOBOFACTORY_H_ */
