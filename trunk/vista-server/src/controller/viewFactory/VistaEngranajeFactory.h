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
	VistaEngranajeFactory(SimpleEditorCambiarRadio * editor, int cantidad);
	virtual ~VistaEngranajeFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VISTAENGRANAJEFACTORY_H_ */
