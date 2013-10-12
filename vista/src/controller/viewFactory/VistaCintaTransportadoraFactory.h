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

class EditorDeEstiramientoDeCinta;

class VistaCintaTransportadoraFactory: public ViewFiguraFactory {
public:
	VistaCintaTransportadoraFactory( EditorDeEstiramientoDeCinta* editor);
	virtual ~VistaCintaTransportadoraFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VistaCINTATRANSPORTADORAFACTORY_H_ */
