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
	ViewBalancinFactory(SimpleEditorAnguloFijo* editor);
	virtual ~ViewBalancinFactory();
	FiguraView * crear(int, int, int, int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWBALANCINFACTORY_H_ */
