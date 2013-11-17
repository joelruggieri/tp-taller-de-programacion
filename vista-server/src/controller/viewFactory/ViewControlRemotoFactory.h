/*
 * ViewControlRemotoFactory.h
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWCONTROLREMOTOFACTORY_H_
#define VIEWCONTROLREMOTOFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;
class ViewControlRemotoFactory : public ViewFiguraFactory {
public:
	ViewControlRemotoFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewControlRemotoFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWCONTROLREMOTOFACTORY_H_ */
