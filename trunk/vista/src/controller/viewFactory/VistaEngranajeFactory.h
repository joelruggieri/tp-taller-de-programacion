/*
 * VistaEngranajeFactory.h
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#ifndef VISTAENGRANAJEFACTORY_H_
#define VISTAENGRANAJEFACTORY_H_

#include "ViewFiguraFactory.h"

class SimpleEditorAnguloFijo;

class VistaEngranajeFactory: public ViewFiguraFactory {
public:
	VistaEngranajeFactory(SimpleEditorAnguloFijo * editor);
	virtual ~VistaEngranajeFactory();
	FiguraView * crear(int, int, int, int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VISTAENGRANAJEFACTORY_H_ */
