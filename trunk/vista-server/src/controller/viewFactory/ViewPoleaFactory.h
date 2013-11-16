/*
 * ViewPoleaFactory.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef VIEWPOLEAFACTORY_H_
#define VIEWPOLEAFACTORY_H_
#include "ViewFiguraFactory.h"
class SimpleEditorAnguloFijo;

class ViewPoleaFactory: public ViewFiguraFactory {
public:
	ViewPoleaFactory(SimpleEditorAnguloFijo * editor, int cantidad);
	virtual ~ViewPoleaFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWPOLEAFACTORY_H_ */
