/*
 * VistaCintaTransportadoraFactory.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VistaCINTATRANSPORTADORAFACTORY_H_
#define VistaCINTATRANSPORTADORAFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../DropController.h"

class SimpleEditorEstirar;

class VistaCintaTransportadoraFactory: public ViewFiguraFactory {
public:
	VistaCintaTransportadoraFactory( SimpleEditorEstirar* editor, int cantidad);
	virtual ~VistaCintaTransportadoraFactory();
	FiguraView * crear(float,float);
	View * crearVistaPropia();
	string getTagRemoto();
};

#endif /* VistaCINTATRANSPORTADORAFACTORY_H_ */
