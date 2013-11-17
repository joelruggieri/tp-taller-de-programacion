/*
 * ViewTijeraFactory.h
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#ifndef VIEWTIJERAFACTORY_H_
#define VIEWTIJERAFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorAnguloFijo.h"

class ViewTijeraFactory: public ViewFiguraFactory {
public:
	ViewTijeraFactory(SimpleEditorAnguloFijo* editor, int cantidad);
	virtual ~ViewTijeraFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};

#endif /* VIEWTIJERAFACTORY_H_ */
