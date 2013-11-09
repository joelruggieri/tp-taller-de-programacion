/*
 * ViewBalancinFactory.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef VIEWBALANCINFACTORY_H_
#define VIEWBALANCINFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorAnguloFijo.h"

class ViewBalancinFactory: public ViewFiguraFactory {

public:
	ViewBalancinFactory(SimpleEditorAnguloFijo* editor, int cantidad);
	virtual ~ViewBalancinFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);

};

#endif /* VIEWBALANCINFACTORY_H_ */
