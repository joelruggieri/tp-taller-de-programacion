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
	VistaEngranajeFactory(SimpleEditorCambiarRadio * editor);
	virtual ~VistaEngranajeFactory();
	FiguraView * crear(float,float,float,float);
	View * crearVistaPropia(float,float,float,float);
};

#endif /* VISTAENGRANAJEFACTORY_H_ */
