/*
 * ViewGanchoFactory.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef VIEWGANCHOFACTORY_H_
#define VIEWGANCHOFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;

class ViewGanchoFactory: public ViewFiguraFactory {
public:
	ViewGanchoFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewGanchoFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWGANCHOFACTORY_H_ */
