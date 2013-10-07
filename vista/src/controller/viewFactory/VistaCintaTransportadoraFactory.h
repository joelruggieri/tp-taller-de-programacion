/*
 * VistaCintaTransportadoraFactory.h
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#ifndef VistaCINTATRANSPORTADORAFACTORY_H_
#define VistaCINTATRANSPORTADORAFACTORY_H_

#include "ViewFiguraFactory.h"
#include "../editor/SimpleEditorNivel.h"
#include "../editor/SimpleEditorAnguloFijo.h"
#include "../editor/SimpleEditorEstirar.h"
#include "../DropController.h"

class VistaCintaTransportadoraFactory: public ViewFiguraFactory {
public:
	VistaCintaTransportadoraFactory(DropController * editor);
	virtual ~VistaCintaTransportadoraFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
private:
	DropController * editor;
};

#endif /* VistaCINTATRANSPORTADORAFACTORY_H_ */
