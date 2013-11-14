/*
 * viewClavoFactory.h
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWCLAVOFACTORY_H_
#define VIEWCLAVOFACTORY_H_
#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorAnguloFijo.h"



class viewClavoFactory : public ViewFiguraFactory {
public:
	viewClavoFactory(SimpleEditorAnguloFijo* editor, int cantidad);
	virtual ~viewClavoFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
	View * crearVistaPropia(float,float,float,float);
	ViewFiguraFactory* clone(int);
};


#endif /* VIEWCLAVOFACTORY_H_ */
